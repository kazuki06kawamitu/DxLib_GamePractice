#include "Block.h"
#include "DxLib.h"
#include "InputControl.h"

/***************************************
*�}�N����`
***************************************/
#define FIELD_HEIGT (21)       //�t�B�[���h�̃}�X�̍���
#define FIELD_WIDTH (12)       //�t�B�[���h�̃}�X�̕�
#define BLOCK_TROUT_SIZE (4)   //�u���b�N�̃}�X�T�C�Y
#define BLOCK_SIZE  (36)       //�P�u���b�N�̓�����̃T�C�Y
#define BLOCK_TYPE_MAX (7)     //�����Ă���u���b�N�̎��
#define BLOCK_NEXT_POS_X (700) //���̃u���b�N�̍��W(x���W)
#define BLOCK_NEXT_POS_Y (500) //���̃u���b�N�̍��W(y���W)
#define BLOCK_STOCK_POS_X (500)//�X�g�b�N���ꂽ�u���b�N�̍��W(x���W)
