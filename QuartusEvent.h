#ifndef QUARTUSEVENT_H
#define QUARTUSEVENT_H

#include "QuartusController.h"

#define QUARTUSEVENT_WAITTIME (6)

//LED赤
typedef struct ts_QuartusEvent_LEDRED
{
	int LightCnt;
} s_QuartusEvent_LEDRED;
//LED緑
typedef struct ts_QuartusEvent_LEDGREEN
{
	int LightCnt;
} s_QuartusEvent_LEDGREEN;
//プッシュボタン
typedef struct ts_QuartusEvent_PUSHBUTTON
{
	int State;
} s_QuartusEvent_PUSHBUTTON;
//7セグ
typedef struct ts_QuartusEvent_SEVENSEG
{
	int Score;	//点数
} s_QuartusEvent_SEVENSEG;
//イベント情報
typedef struct ts_QuartusEvent_Event
{
	s_QuartusEvent_LEDRED LEDRED;
	s_QuartusEvent_LEDGREEN LEDGREEN;
	s_QuartusEvent_SEVENSEG SEVENSEG;
	int WaitCnt;
} s_QuartusEvent_Event;

static s_QuartusEvent_Event NowEvent;

//初期化
int QuartusEvent_Initialize( int WindowX , int WindowY );

//7セグ、LED赤、LED緑の点灯パターンをセット
int QuartusEvent_Set_SEVEN_SEGMENT_LED_Lights( int Num , int PatternLight[] );
int QuartusEvent_Set_LEDRED_Light( int PatternLen , int PatternLight[] );
int QuartusEvent_Set_LEDGREEN_Light( int PatternLen , int PatternLight[] );

//7セグ、LED赤、LED緑の点灯パターンを定義・呼び出し
int QuartusEvent_Define_SEVEN_SEGMENT_LED_Lights( int Num , int PatternLight[] );
int QuartusEvent_Define_LEDRED_Light( int PatternLen , int PatternLight[] );
int QuartusEvent_Define_LEDGREEN_Light( int PatternLen , int PatternLight[] );

//更新
int QuartusEvent_Update( void );

//描画
int QuartusEvent_Draw( void );

#endif