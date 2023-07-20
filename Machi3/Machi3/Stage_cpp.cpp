#include"Stage.h"
#include"DxLib.h"
#include"InputControl.h"
/****************************************
*�}�N����`
****************************************/
#define HEIGHT           (12)  //�u���b�N�z�u�T�C�Y�i�����j
#define WIDTH�@�@�@�@�@�@(12)  //�u���b�N�z�u�T�C�Y�i���j
#define BLOCKSIZE        (48)  //�u���b�N�T�C�Y
#define BLOCK_IMAGE_MAX�@(10)  //�u���b�N�摜��

#define ITEM_MAX          (8)  //�A�C�e���ő吔

#define SELECT_CURSOR     (0)
#define NEXT_CURSOR       (1)
#define TMP_CURSOR        (2)
/******************************************
*�^��`
******************************************/
typedef struct
{
	int flg;
	int x, y;
	int width, height;
	int image;
	int backup;
}T_Object;

typedef struct
{
	int x;
	int y;
}T_CURSOR;

enum
{
	E_NONE,
	E_ONCE,
	E_SECOND
};

/************************************
*�ϐ��錾
*************************************/
T_Object Block[HEIGHT][WIDTH];//�u���b�N�I�u�W�F�N�g�f�[�^
T_CURSOR Select[3]; //�Z���N�g�J�[�\�����W
int ClickStatus;
int Stage_Stage;
int Stage_Mission;
int ClearFlag;

int BlockImage[BLOCK_IMAGE_MAX];   //�u���b�N�摜
int StageImage;                   //�w�i�p�摜
int ClickSE;                      //�N���b�NSE
int FadeOutSE;                    //�t�F�[�h�A�E�gSE
int MoveBlockSE;                  //�u���b�N�ړ�SE

/********************************************
*�v���g�^�C�v�錾
********************************************/
int combo_check(int x, int y);
void combo_check_h(int y, int x, int* cut, int* col);
void combo_check_w(int y, int x, int* cnt, int* col);
void save_block(void);
void restore_block(void);

/***********************************************
*�X�e�[�W����@�\�F����������
*�����F�Ȃ�
*�߂�l�F�G���[���
************************************************/
int StageInitialize(void)
{
	int ret = 0;
	int i;

	//�摜�ǂݍ���
	LoadDivGraph("image/block.png", BLOCK_IMAGE_MAX, BLOCK_IMAGE_MAX, 1,
		BLOCKSIZE, BlockImage);
	stageImage = LoadGraph("images/stage.png");
	
	//�����ǂݍ���
ClickSE = LoadSoundMem("sounds/click_semp3");
FadeOutSE = LoadSoundMem("sounds/fadeout_se.mp3");
MoveBlockSE = LoadSoundMem("sounds/moveblock_se.mp3");

//�u���b�N��������
CreateBlock();

ClickStateus = E_NONE;
Stage_Stage = 0;
Stage_Score = 0;
ClearFlag = FALSE;

for (i = 0; i < 3; I++)
{
	Select[i].x = 0;
	Select[i].y = 0;
}

//�G���[�`�F�b�N
for (i = 0; i < BLOCK_IMAGE_MAX; i++)
{
	if (BlockImage[i] == -1)
	{
		ret = -1;
		break;
	}
}

if (StageImage == -1)
{
	ret = -1;
}
if (ClickSE == -1)
{
	ret = -1;
}
if (FadeOutSE == -1)
{
	ret = -1;
}
if (MoveBlockSE == -1)
{
	ret = -1;
}

return ret;

}