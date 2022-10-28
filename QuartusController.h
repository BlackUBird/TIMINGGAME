#ifndef QUARTUSCONTROLLER_H
#define QUARTUSCONTROLLER_H

#include "Quartus.h"
#include "Input.h"

#define WAITTIME_INPUT (6)	//入力があってから何フレーム待つか

//操作が有効か無効化を格納
typedef struct ts_Available
{
	int Key;	//0:無効 0以外:有効
	int Mouse;	//0:無効 0以外:有効
} s_Available;

//Quartusの操作を管理
typedef struct ts_QuartusController
{
	int WaitCount;	//待機時間をカウント
	s_Available Available;	//操作可能かどうか
	
	s_Quartus Quartus;	//Quartusの状態
} s_QuartusController;

static s_QuartusController InitQuartusController;	//Quartusの初期状態
static s_QuartusController QuartusController;	//Quartusの状態を格納(コントローラ)

//初期化
int QuartusController_Initialize( int WindowX , int WindowY );

//セッタ
//Quartus
//7セグ
int QuartusController_Set_SEVEN_SEGMENT_LED_Pattern( int Num , int NewPattern[] );
int QuartusController_Set_SEVEN_SEGMENT_LED_Pattern_All( int NewPattern[] );	//一括
//発光ダイオード
//赤
int QuartusController_Set_LEDRED_State( int Num , int NewState );
int QuartusController_Set_LEDRED_State_All( int NewState );	//一括
//緑
int QuartusController_Set_LEDGREEN_State( int Num , int NewState );
int QuartusController_Set_LEDGREEN_State_All( int NewState );	//一括
//プッシュボタン
int QuartusController_Set_PUSH_BUTTON_State( int Num , int NewState );
int QuartusController_Set_PUSH_BUTTON_State_All( int NewState );	//一括
//スライドスイッチ
int QuartusController_Set_SLIDER_State( int Num , int NewState );
int QuartusController_Set_SLIDER_State_All( int NewState );	//一括

//ゲッタ
//Quartus
//7セグ
int QuartusController_Get_SEVEN_SEGMENT_LED_Pattern( int Num , int PatternNum );
//発光ダイオード
//赤
int QuartusController_Get_LEDRED_State( int Num );
//緑
int QuartusController_Get_LEDGREEN_State( int Num );
//プッシュボタン
int QuartusController_Get_PUSH_BUTTON_State( int Num );
//スライドスイッチ
int QuartusController_Get_SLIDER_State( int Num );

//更新
int QuartusController_Update(void);

//描画
int QuartusController_Draw(void);

#endif