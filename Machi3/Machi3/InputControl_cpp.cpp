#include"DxLib.h"
#include"InputControl.h"

/*******************************
*変数宣言
********************************/
int old_button;
int now_button;
int mouse_position_x;
int mouse_position_y;

/********************************
*プロトタイプ宣言
*********************************/


/*********************************
*入力制御機能：初期化処理
*引数：なし
*戻り値：なし
**********************************/
void Input_Initialize(void)
{
	old_button = NULL;
	now_button = NULL;
	mouse_position_x = NULL;
	mouse_position_y = NULL;
}


/*************************************
*入力制御機能：更新処理
*引数：なし
*
戻り値：なし
***************************************/

void Input_Update(void)
{
	//マウス入力情報の取得
	old_button = now_button;
	now_button = GetMouseInput();

	//マウスカーソル座標の取得
	GetMousePoint(&mouse_position_x, &mouse_position_y);
}

/**************************************
*入力制御機能：ESCキーチェック
*引数：なし
*戻り値：TRUE（入力された）、FALSE（未入力）
****************************************/
int Input_Escape(void)
{
	int ret = FALSE;

	//ESCキーが押されたらループから抜ける
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}
	return ret;
}

/*****************************************
*入力制御機能：入力情報取得処理（離した瞬間）
*引数：指定するマウスのボタン
*戻り値：TREU（入力された）、FALSE（未入力）
*****************************************/
int GetOldKey(int Key)
{
	int ret = FALSE;

	if ((Key & old_button) != FALSE)
	{
		ret = TRUE;
	}
	return ret;
}

/*******************************************
*入力制御機能：入力情報取得処理（押している）
*引数：指定するマウスのボタン
*戻り値：TRUE（入力された）、FALSE（未入力）
********************************************/
int GetNowKey(int Key)
{
	int ret = FALSE;

	if ((Key & now_button) != FALSE)
	{
		ret = TRUE;
	}
	return ret;
}

/*******************************************
*入力制御機能：入力情報取得処理（押している）
*引数：指定するマウスのボタン
*戻り値：TRUE（入力された）、FALSE（未入力）
*******************************************/
int GetKeyFlg(int Key)
{
	int ret = FALSE;
	int Keyflg = now_button & old_button;

	if ((Key & Keyflg) != FALSE)
	{
		ret = TRUE;
	}
	return ret;
}

/******************************************
*入力制御機能マウス座標取得処理
*引数：なし
*戻り値：マウスカーソルのY座標情報
******************************************/
int GetMousePositionY(void)
{
	return mouse_position_y;
}