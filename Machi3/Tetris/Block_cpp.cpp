#include "Block.h"
#include "DxLib.h"
#include "InputControl.h"

/***************************************
*マクロ定義
***************************************/
#define FIELD_HEIGHT (21)       //フィールドのマスの高さ
#define FIELD_WIDTH (12)       //フィールドのマスの幅
#define BLOCK_TROUT_SIZE (4)   //ブロックのマスサイズ
#define BLOCK_SIZE  (36)       //１ブロックの当たりのサイズ
#define BLOCK_TYPE_MAX (7)     //落ちてくるブロックの種類
#define BLOCK_NEXT_POS_X (700) //次のブロックの座標(x座標)
#define BLOCK_NEXT_POS_Y (500) //次のブロックの座標(y座標)
#define BLOCK_STOCK_POS_X (500)//ストックされたブロックの座標(x座標)
#define BLOCK_STOCK_POS_Y (350)//ストックされたブロックの座標(ｙ座標)
#define DROP_BLOCK_INIT_X (4)  //落ちてくるブロックの初期ｘ座標
#define DROP_BLOCK_INIT_Y (-1) //落ちてくるブロックの初期ｙ座標
#define DROP_SPEED  (60)       //落下時間
#define TURN_CROCKWICE (0)     //時計回りに回転させる
#define TURN_ANTICROKWICE (1)  //反時計回りに回転させる

/****************************************
*型定義
****************************************/
enum BLOCK_STATE
{
	E_BLOCK_EMPTY,             //空ブロック
	E_BLOCK_LIGHT_BLUE,        //水色
	E_BLOCK_YELLOW_GREEN,      //黄緑
	E_BLOCK_YELLOW,            //黄色
	E_BLOCK_ORANGE,            //オレンジ
	E_BLOCK_BLUE,              //青
	E_BLOCK_PINK,              //ピンク
	E_BLOCK_RED,               //赤
	E_BLOCK_GLAY,              //灰色
	E_BLOCK_WALL,              //壁
	E_BLOCK_IMAGE_MAX,
};

/******************************************
*定数定義
*******************************************/
const int C_BLOCK_TABLE[BLOCK_TYPE_MAX][BLOCK_TROUT_SIZE][BLOCK_TROUT_SIZE] = {
	{
	 {0,0,0,0},
	 {0,1,1,0},
	 {0,1,1,0},
	 {0,0,0,0}
	},
	{
	{0,0,0,0},
	{0,0,0,0},
	{2,2,2,2},
	{0,0,0,0}
    },
	{
	{0,0,0,0},
	{0,5,5,0},
	{0,0,5,5},
	{0,0,0,0}
    },
	{
	{0,0,0,0},
	{0,6,6,0},
	{6,6,0,0},
	{0,0,0,0}
    },
	{
	{0,0,0,0},
	{0,7,0,0},
	{7,7,7,0},
	{0,0,0,0}
    }
};

/*****************************************
*変数宣言
*****************************************/
int BlockImage[E_BLOCK_IMAGE_MAX];                     //ブロック画像
BLOCK_STATE Field[FIELD_HEIGHT][FIELD_WIDTH];          //フィールド配列
BLOCK_STATE Next[BLOCK_TROUT_SIZE][BLOCK_TROUT_SIZE];  //待機状態のブロック
BLOCK_STATE Stock[BLOCK_TROUT_SIZE][BLOCK_TROUT_SIZE]; //ストックのブロック
BLOCK_STATE DropBlock[BLOCK_TROUT_SIZE][BLOCK_TROUT_SIZE];//落ちるブロック
int DropBlock_x;                                       //落ちるブロックのx座標
int DropBlock_y;                                       //落ちるブロックy座標

int WaitTime;  //待機時間
int Stock_Flg; //ストックフラグ
int Generate_Flg;//生成フラグ
int DeleteLine;  //消したラインの数
int SoundEffect; //SE

/********************************************
*プロトタイプ宣言
*********************************************/
void create_field(void);             //フィールドの生成処理
void create_block(void);             //ブロックの生成syp炉
void moveblock(void);              //ブロックの移動処理
void change_block(void);           //ブロック交換処理
void turn_block(int clockwise);    //ブロック回転処理
int check_overlap(int x, int y);   //範囲外チェック処理
void lock_block(int x, int y);     //着地したブロックを固定済みに変更する処理
void check_line(void);             //ブロックの横一列確認処理

/********************************************
*ブロック機能:初期化処理
*引数:なし
*戻り値:エラー情報(-1:異常,それ以外:正常)
*********************************************/
int Block_Initialize(void)
{
	int ret = 0;  //戻り値
	int i = 0;

	//ブロック画像の読み込み
	ret = LoadDivGraph("images/block.pug", E_BLOCK_IMAGE_MAX, 10, 1, BLOCK_SIZE,
		BLOCK_SIZE, BlockImage);

	//SEの読み込み
	SoundEffect[0] = LoadSoundMem("sounds/SE3.mp3");
	SoundEffect[1] = LoadSoundMem("sounds/SE4.mp3");
	SoundEffect[2] = LoadSoundMem("sounds/SE5.wav");

	//音量の調整
	ChangeVolumeSoundMem(150, SoundEffect[0]);
	ChangeVolumeSoundMem(150, SoundEffect[1]);
	ChangeVolumeSoundMem(130, SoundEffect[2]);
	//フィールドの生成
	create_field();

	//ブロック生成
	create_block();
	create_block();

	//待機時間の初期化
	WaitTime = 0;
	//ストックグラフの初期化
	Stock_Flg = FALSE;
	//生成フラグの初期化
	Generate_Flg = TRUE;
	//消したラインの数の初期化
	DeleteLine = 0;

	//エラーチェック
	for (i = 0; i < 3; i++)
	{
		if (SoundEffect[i] == -1)
		{
			ret = -1;
			break;
		}
	}
	return ret;
}

/*****************************************
*ブロック機能:更新処理
*引数:なし
*戻り値:なし
*****************************************/
void Block_Update(void)
	{
	//ブロックの移動処理
	move_block();
	}