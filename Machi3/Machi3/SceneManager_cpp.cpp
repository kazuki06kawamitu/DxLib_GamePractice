#include"SceneManager.h"
#include"TitleScene.h"
#include"gameMainScene.h"
#include"GameClearScene.h"
#include"GameOverScene.h"

/*****************************************
*マクロ定義
*****************************************/

/*****************************************
*型定義
*****************************************/

/****************************************
*プロトタイプ宣言
*****************************************/


/********************************************
*シーン管理機能：初期化処理
* 引数：ゲームモード情報
* 戻り値：なし
********************************************/

int SceneManager_Initialize(GAME_MODE mode)
{
	int Read_Error;

	//シーン読み込み処理
	//タイトル画面
	Read_Error = Titlescene_Initialize();
	if (Read_Error == D_ERROR)
	{
		returnD_ERROR;
	}
	//ゲームメイン画面
	Read_Error = GameClearScene_Initiailze();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR;
	}

	//ゲームオーバー画面
	Read_Error = GameOverScene_Initialize();
	if (Read_Error == D_ERROE)
	{
		return D_ERROR;
	}
	Game_Mode = mode;
	Next_Mode = Game_Mode;

	returnRead_Error;
}

/**********************************************
*シーン管理機能：更新処理
*引数：なし
*戻り値：なし
***********************************************/
void SceneManager_Updata(void)
{
	//前フレームとゲームモードが違っていたらシーンを切り替える
	if(Game_Mode!=Next_Mode)
	{
		SceneManager_Initizlize(Next_Mode);

	}

	//各画面の更新処理

	switch (Game = Mode)
	{
	case E_TITLE:
			TitleScene_Update();
			break;
		case E_GAMEMAIN:
			GameMainScene_Updata();
			break;
		case E_GAME_CLEAR:
				GameClearScene_Updata();
				break;
			case E_GAME_OVER:
					GameOverScene_Updata();
					break;
				default:
					break;
	}
}

/**********************************
*処理管理機能：描画処理
*引数：なし
*戻り値：なし
***********************************/
void SceneManager_Draw(void)
{
	//各画面の描画処理
	switch (Game_Mode)
	{
	case ETITLE:
		TitleScene_Draw();
		break;
	case E_GAMEMAIN:
		GameMainScene_Draw();
		break;
	case E_GAME_CLEAR:
		GameclearScene_Draw();
		break;
	case E_GAME_OVER:
		GameOverScene_Draw();
		berak;
	default:
		berak;
	}
}

/*************************************
*シーン管理機能：シーン切り替え処理
*引数：変更するゲームモード
*戻り値：なし
***************************************/
void Change_Scene(GAME_MODEmode)
{
	Next_Mode = mode;
}