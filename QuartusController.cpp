#include "DxLib.h"
#include "QuartusController.h"


//初期化
int QuartusController_Initialize( int WindowX , int WindowY )
{
	//入力
	int value;	//返り値として保存
	value = Input_Update_All();

	//Quartus
	//待機時間
	InitQuartusController.WaitCount = 0;
	//操作可能かどうか(全て操作可能)
	InitQuartusController.Available.Key = 1;
	InitQuartusController.Available.Mouse = 1;

	//QuartusLikeの初期化
	value += Quartus_Initialize( WindowX , WindowY , &(InitQuartusController.Quartus) );

	//初期状態用の情報をコントローラにコピー
	QuartusController = InitQuartusController;

	//正しく初期化できたか(0:正しい 0以外：異常発生)
	return (value);
}

//更新
//プッシュボタンの状態を反転させる
int local_QuartusController_Update_Inverse_PUSH_BUTTON( int Num )
{
	if( QuartusController_Get_PUSH_BUTTON_State( Num ) == 0 )
	{//現在の状態が0だったら1にする
		QuartusController_Set_PUSH_BUTTON_State( Num , 1 );
	}
	else
	{//現在の状態が1だったら0にする
		QuartusController_Set_PUSH_BUTTON_State( Num , 0 );
	}

	return (QuartusController.Quartus.PushButton[Num].State);
}
//スライドスイッチの状態を反転させる
int local_QuartusController_Update_Inverse_SLIDER( int Num )
{
	if( QuartusController_Get_SLIDER_State( Num ) == 0 )
	{//現在の状態が0だったら1にする
		QuartusController_Set_SLIDER_State( Num , 1 );
	}
	else
	{//現在の状態が1だったら0にする
		QuartusController_Set_SLIDER_State( Num , 0 );
	}
	
	return (QuartusController.Quartus.Slider[Num].State);
}
int local_QuartusController_Update_Effect_Key(void)
{
	int value = 0;	//返却値(変更があった回数)

	if( QuartusController.Available.Key == 1 )
	{
		//プッシュボタン
		if( Input_Get_Key_State( KEY_INPUT_1 ) == 1 )
		{//数字キー1が押されていたら0番を更新
			int num = 0;
			local_QuartusController_Update_Inverse_PUSH_BUTTON( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_2 ) == 1 )
		{//数字キー2が押されていたら1番を更新
			int num = 1;
			local_QuartusController_Update_Inverse_PUSH_BUTTON( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_3 ) == 1 )
		{//数字キー3が押されていたら2番を更新
			int num = 2;
			local_QuartusController_Update_Inverse_PUSH_BUTTON( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_4 ) == 1 )
		{//数字キー4が押されていたら3番を更新
			int num = 3;
			local_QuartusController_Update_Inverse_PUSH_BUTTON( num );
			value++;
		}

		//スライドスイッチ
		if( Input_Get_Key_State( KEY_INPUT_Q ) == 1 )
		{//文字キーQが押されていたら0番を更新
			int num = 0;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_W ) == 1 )
		{//文字キーWが押されていたら1番を更新
			int num = 1;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_E ) == 1 )
		{//文字キーEが押されていたら2番を更新
			int num = 2;
			local_QuartusController_Update_Inverse_SLIDER( num );
		}
		if( Input_Get_Key_State( KEY_INPUT_R ) == 1 )
		{//文字キーRが押されていたら3番を更新
			int num = 3;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_T ) == 1 )
		{//文字キーTが押されていたら4番を更新
			int num = 4;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_Y ) == 1 )
		{//文字キーYが押されていたら5番を更新
			int num = 5;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_U ) == 1 )
		{//文字キーUが押されていたら6番を更新
			int num = 6;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_I ) == 1 )
		{//文字キーIが押されていたら7番を更新
			int num = 7;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_O ) == 1 )
		{//文字キーOが押されていたら8番を更新
			int num = 8;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_A ) == 1 )
		{//文字キーAが押されていたら9番を更新
			int num = 9;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_S ) == 1 )
		{//文字キーSが押されていたら10番を更新
			int num = 10;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_D ) == 1 )
		{//文字キーDが押されていたら11番を更新
			int num = 11;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_F ) == 1 )
		{//文字キーFが押されていたら12番を更新
			int num = 12;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_G ) == 1 )
		{//文字キーGが押されていたら13番を更新
			int num = 13;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_H ) == 1 )
		{//文字キーHが押されていたら14番を更新
			int num = 14;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_J ) == 1 )
		{//文字キーJが押されていたら15番を更新
			int num = 15;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_K ) == 1 )
		{//文字キーKが押されていたら16番を更新
			int num = 16;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_L ) == 1 )
		{//文字キーLが押されていたら17番を更新
			int num = 17;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
	}

	//1回以上変更があったら待機時間(WAITTIME_INPUT)をセット
	if( value > 0 )
	{
		QuartusController.WaitCount = WAITTIME_INPUT;
	}

	return (value);
}
int QuartusController_Update(void)
{
	//入力をアップデート
	//キー
	int value;	//返り値として保存
	value = Input_Update_Key();
	if( QuartusController.WaitCount == 0 )
	{//入力待ち中でなければ
		//入力可能にする
		QuartusController.Available.Key = 1;
		//入力に応じてQuartusの素子を変化
		local_QuartusController_Update_Effect_Key();
	}
	else
	{//入力待ち中であれば
		//入力不可にする
		QuartusController.Available.Key = 0;
		//カウンタから1引く
		QuartusController.WaitCount -= 1;
	}

	//マウス
	Input_Update_Mouse();

	return (value);	//0:正しい 0以外:正しくない
}

//セッタ
//Quartus
//7セグ
int QuartusController_Set_SEVEN_SEGMENT_LED_Pattern( int Num , int NewPattern[] )
{
	int value;	//返り値
	value = Quartus_Set_SEVEN_SEGMENT_LED_Pattern( Num , NewPattern , &(QuartusController.Quartus) );

	return (value);	//0:正しい 0以外:異常発生
}
//一括
int QuartusController_Set_SEVEN_SEGMENT_LED_Pattern_All( int NewPattern[] )
{
	int value = 0;
	for( int i = 0 ; i < Quartus_Get_QUARTUS_SEVENSEG_NUM() ; i++ )
	{
		value += QuartusController_Set_SEVEN_SEGMENT_LED_Pattern( i , NewPattern );
	}

	return (value);
}
//発光ダイオード
//赤
int QuartusController_Set_LEDRED_State( int Num , int NewState )
{
	int value;	//返り値
	value = Quartus_Set_LEDRED_State( Num , NewState , &(QuartusController.Quartus) );

	return (value);	//0:正しい 0以外:異常発生
}
//一括
int QuartusController_Set_LEDRED_State_All( int NewState )
{
	int value = 0;
	for( int i = 0 ; i < Quartus_Get_QUARTUS_LEDRED_NUM() ; i++ )
	{
		value += QuartusController_Set_LEDRED_State( i , NewState );
	}

	return (value);
}
//緑
int QuartusController_Set_LEDGREEN_State( int Num , int NewState )
{
	int value;	//返り値
	value = Quartus_Set_LEDGREEN_State( Num , NewState , &(QuartusController.Quartus) );

	return (value);	//0:正しい 0以外:異常発生
}
//一括
int QuartusController_Set_LEDGREEN_State_All( int NewState )
{
	int value = 0;	//返り値
	for( int i = 0 ; i < Quartus_Get_QUARTUS_LEDGREEN_NUM() ; i++ )
	{
		value = QuartusController_Set_LEDGREEN_State( i , NewState );
	}

	return (value);	//0:正しい 0以外:異常発生
}
//プッシュボタン
int QuartusController_Set_PUSH_BUTTON_State( int Num , int NewState )
{
	int value;	//返り値
	value = Quartus_Set_PUSH_BUTTON_State( Num , NewState , &(QuartusController.Quartus) );

	return (value);	//0:正しい 0以外:異常発生
}
//一括
int QuartusController_Set_PUSH_BUTTON_State_All( int NewState )
{
	int value = 0;	//返り値
	for( int i = 0 ; i < Quartus_Get_QUARTUS_PUSHBUTTON_NUM() ; i++ )
	{
		value = QuartusController_Set_PUSH_BUTTON_State( i , NewState );
	}

	return (value);	//0:正しい 0以外:異常発生
}
//スライドスイッチ
int QuartusController_Set_SLIDER_State( int Num , int NewState )
{
	int value;	//返り値
	value = Quartus_Set_SLIDER_State( Num , NewState , &(QuartusController.Quartus) );

	return (value);	//0:正しい 0以外:異常発生
}
//一括
int QuartusController_Set_SLIDER_State_All( int NewState )
{
	int value = 0;	//返り値
	for( int i = 0 ; i < Quartus_Get_QUARTUS_SLIDER_NUM() ; i++ )
	{
		value = QuartusController_Set_SLIDER_State( i , NewState );
	}

	return (value);	//0:正しい 0以外:異常発生
}

//ゲッタ
//Quartus
//7セグ
int QuartusController_Get_SEVEN_SEGMENT_LED_Pattern( int Num , int PatternNum )
{
	int value;
	value = QuartusController.Quartus.SevenSeg[Num].Pattern[PatternNum];

	return (value);
}
//発光ダイオード
//赤
int QuartusController_Get_LEDRED_State( int Num )
{
	int value;
	value = QuartusController.Quartus.LEDRed[Num].State;

	return (value);
}
//緑
int QuartusController_Get_LEDGREEN_State( int Num )
{
	int value;
	value = QuartusController.Quartus.LEDGreen[Num].State;

	return (value);
}
//プッシュボタン
int QuartusController_Get_PUSH_BUTTON_State( int Num )
{
	int value;
	value = QuartusController.Quartus.PushButton[Num].State;

	return (value);
}
//スライドスイッチ
int QuartusController_Get_SLIDER_State( int Num )
{
	int value;
	value = QuartusController.Quartus.Slider[Num].State;

	return (value);
}

//描画
int QuartusController_Draw(void)
{
	int value;
	value = Quartus_Draw( QuartusController.Quartus );

	return (value);
}