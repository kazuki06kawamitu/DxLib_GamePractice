#include"InputControl.h"
#include"Dxlib.h"

/**************************************
*�}�N����`
**************************************/
#define XINPUT_BUTTON_MAX (16)           //�R���g���[���[�̃{�^����
/*************************************
*�^��`
**************************************/
enum KEY_STATE
{
	E_NONE,    //������
	E_CLICK,   //�������u��
	E_PRESS,   //���������Ă���
	E_RELEASED,//������
	E_KEY_STATE_MAX
};
/*****************************************
*�ϐ��錾
*****************************************/
KEY_STATE button_state[XINPUT_BUTTON_MAX];  //�e�{�^�����͏��