#include"SceneManager.h"
#include"TitleScene.h"
#include"gameMainScene.h"
#include"GameClearScene.h"
#include"GameOverScene.h"

/*****************************************
*�}�N����`
*****************************************/

/*****************************************
*�^��`
*****************************************/

/****************************************
*�v���g�^�C�v�錾
*****************************************/


/********************************************
*�V�[���Ǘ��@�\�F����������
* �����F�Q�[�����[�h���
* �߂�l�F�Ȃ�
********************************************/

int SceneManager_Initialize(GAME_MODE mode)
{
	int Read_Error;

	//�V�[���ǂݍ��ݏ���
	//�^�C�g�����
	Read_Error = Titlescene_Initialize();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR;
	}
	//�Q�[�����C�����
	Read_Error = GameClearScene_Initiailze();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR;
	}

	//�Q�[���I�[�o�[���
	Read_Error = GameOverScene_Initialize();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR;
	}
	Game_Mode = mode;
	Next_Mode = Game_Mode;

	returnRead_Error;
}

/**********************************************
*�V�[���Ǘ��@�\�F�X�V����
*�����F�Ȃ�
*�߂�l�F�Ȃ�
***********************************************/
void SceneManager_Updata(void)
{
	//�O�t���[���ƃQ�[�����[�h������Ă�����V�[����؂�ւ���
	if(Game_Mode!=Next_Mode)
	{
		SceneManager_Initizlize(Next_Mode);

	}

	//�e��ʂ̍X�V����

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
*�����Ǘ��@�\�F�`�揈��
*�����F�Ȃ�
*�߂�l�F�Ȃ�
***********************************/
void SceneManager_Draw(void)
{
	//�e��ʂ̕`�揈��
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
*�V�[���Ǘ��@�\�F�V�[���؂�ւ�����
*�����F�ύX����Q�[�����[�h
*�߂�l�F�Ȃ�
***************************************/
void Change_Scene(GAME_MODEmode)
{
	Next_Mode = mode;
}