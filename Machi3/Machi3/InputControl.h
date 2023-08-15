#pragma once

/*******************************
*マクロ定義
********************************/


/********************************
*型定義
********************************/

/********************************
*プロトタイプ宣言
********************************/
void Input_Initialize(void);
void Input_Update(void);
int Input_Escape(void);

int GetOldKey(int Key);
int GetNowKey(int Key);
int GetKeyFlg(int Key);
int GetMousePositionX(void);
int GetMousePositionY(void);