#include "Block.h"
#include "DxLib.h"
#include "InputControl.h"

/***************************************
*マクロ定義
***************************************/
#define FIELD_HEIGT (21)       //フィールドのマスの高さ
#define FIELD_WIDTH (12)       //フィールドのマスの幅
#define BLOCK_TROUT_SIZE (4)   //ブロックのマスサイズ
#define BLOCK_SIZE  (36)       //１ブロックの当たりのサイズ
#define BLOCK_TYPE_MAX (7)     //落ちてくるブロックの種類
#define BLOCK_NEXT_POS_X (700) //次のブロックの座標(x座標)
#define BLOCK_NEXT_POS_Y (500) //次のブロックの座標(y座標)
#define BLOCK_STOCK_POS_X (500)//ストックされたブロックの座標(x座標)
