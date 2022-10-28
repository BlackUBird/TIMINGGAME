#ifndef QUARTUS_H
#define QUARTUS_H

//32*32のマス
#define BLOCK_32 (32)

//ウィンドウの大きさ
static int WindowSizeX;
static int WindowSizeY;

//位置
typedef struct ts_Position
{
	int x;
	int y;
} s_Position;
//大きさ
typedef struct ts_Size
{
	int x;
	int y;
} s_Size;

//Quartus--------------------------------------------------------
//7セグメント
#define SEVEN_SEG_LED_NUM (7)
typedef struct
{
	int Pattern[ SEVEN_SEG_LED_NUM ];	//発光パターン
	int OnColor;	//点灯時の色
	int OffColor;	//消灯時の色
	s_Position Position;	//位置
	s_Size Size;	//大きさ
} s_SevenSeg;

//発光ダイオード
typedef struct ts_LED
{
	int Color;
	int OffColor;
	int State;	//状態
	s_Position Position;	//位置
	s_Size Size;	//大きさ
} s_LED;

//プッシュボタン
typedef struct ts_PushButton
{
	int State;	// 0:押されていない　0以外:押されている
	s_Position Position;	//位置
	s_Size Size;	//大きさ(xのみ有効)
} s_PushButton;

//スライドスイッチ
typedef struct ts_Slider
{
	int State;	//状態(0:下側 0以外:上側)
	s_Position Position;	//位置
	s_Size Size;	//大きさ
} s_Slider;

//Quartus用構造体
#define QUARTUS_NAME_MAX (30)
#define QUARTUS_SEVENSEG_NUM (8)
#define QUARTUS_LEDRED_NUM (18)
#define QUARTUS_LEDGREEN_NUM (8)
#define QUARTUS_PUSHBUTTON_NUM (4)
#define QUARTUS_SLIDER_NUM (18)
typedef struct ts_Quartus
{
	//基本情報
	char Name[ QUARTUS_NAME_MAX ];	//名前
	int FontHandle;	//名前用のフォントのハンドル
	int NameX,NameY;	//名前表示位置
	int NameColor;	//色

	//素子
	s_SevenSeg SevenSeg[ QUARTUS_SEVENSEG_NUM ];		// 7セグ
	s_LED LEDRed[ QUARTUS_LEDRED_NUM ];					// 赤LED
	s_LED LEDGreen[ QUARTUS_LEDGREEN_NUM ];				// 緑LED
	s_PushButton PushButton[ QUARTUS_PUSHBUTTON_NUM ];	// プッシュボタン
	s_Slider Slider[ QUARTUS_SLIDER_NUM ];				// スライドスイッチ
} s_Quartus;
//--------------------------------------------------------------------


//初期化
int Quartus_Initialize( int WindowX , int WindowY , s_Quartus* QuartusStatus );

//描画
//素子のみを表示
int Quartus_Draw_SEVEN_SEGMENT_LED( int PosX , int PosY , int SizeX , int SizeY , int OnColor , int OffColor , int Pattern[] );	//7セグメントLED
int Quartus_Draw_LED( int PosX , int PosY , int SizeX , int SizeY , int Color );	//発光ダイオード
int Quartus_Draw_PUSH_BUTTON( int PosX , int PosY , int Size , int State );	//プッシュボタン
int Quartus_Draw_SLIDER( int PosX , int PosY , int SizeX , int SizeY , int State );	//スライドスイッチ
//Quatusな感じで表示
int Quartus_Draw( s_Quartus QuartusStatus );

//セッタ
//7セグメントLED
int Quartus_Set_SEVEN_SEGMENT_LED_Pattern( int Num , int NewPattern[] , s_Quartus* QuartusStatus );	//点灯パターン
//発光ダイオード
int Quartus_Set_LEDRED_State( int Num , int NewState , s_Quartus* QuartusStatus );	//ON/OFF
int Quartus_Set_LEDGREEN_State( int Num , int NewState , s_Quartus* QuartusStatus );	//ON/OFF
//プッシュボタン
int Quartus_Set_PUSH_BUTTON_State( int Num , int NewState , s_Quartus* QuartusStatus );	//状態
//スライドスイッチ
int Quartus_Set_SLIDER_State( int Num , int NewState , s_Quartus* QuartusStatus );	//状態

//ゲッタ
//define
int Quartus_Get_QUARTUS_NAME_MAX( void );
int Quartus_Get_QUARTUS_SEVENSEG_NUM( void );
int Quartus_Get_QUARTUS_LEDRED_NUM( void );
int Quartus_Get_QUARTUS_LEDGREEN_NUM( void );
int Quartus_Get_QUARTUS_PUSHBUTTON_NUM( void );
int Quartus_Get_QUARTUS_SLIDER_NUM( void );
int Quartus_Get_SEVEN_SEG_LED_NUM( void );
int Quartus_Get_BLOCK_32( void );

#endif