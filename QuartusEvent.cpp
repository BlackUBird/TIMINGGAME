#include "DxLib.h"
#include "QuartusEvent.h"

//ローカル関数
//引数で指定された7セグに指定された数字を表示
int localQuartusEvent_Set_SEVEN_SEG_Pattern_Decimal( int SevenSegNum , int Number )
{
	int NumPattern[ 10 ][ SEVEN_SEG_LED_NUM ] =
	{
		{ 1 , 1 , 1 , 1 , 1 , 1 , 0 },
		{ 0 , 1 , 1 , 0 , 0 , 0 , 0 },
		{ 1 , 1 , 0 , 1 , 1 , 0 , 1 },
		{ 1 , 0 , 0 , 1 , 1 , 1 , 1 },
		{ 0 , 1 , 1 , 0 , 0 , 1 , 1 },
		
		{ 1 , 0 , 1 , 1 , 0 , 1 , 1 },
		{ 1 , 0 , 1 , 1 , 1 , 1 , 1 },
		{ 1 , 1 , 1 , 0 , 0 , 1 , 0 },
		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 },
		{ 1 , 1 , 1 , 0 , 0 , 1 , 1 },
	};

	int value;
	if( Number < 0 || Number > 9 )
	{
		return (-1);
	}
	else
	{
		value = QuartusController_Set_SEVEN_SEGMENT_LED_Pattern( SevenSegNum , NumPattern[ Number ] );
	}

	return (value);
}
//スコアの1の位～1000の位のうち、指定された位置の数字を返す
//数値が 1234 の時は、右側から1番目(=4)、2番目(=3)　3番目(=2)、4番目(=1)とする
int localQuartusEvent_Get_ScoreNumPosition( int Position )
{
	int NowScore = NowEvent.SEVENSEG.Score;	//現在のスコア
	int PositionNumber;	//返却値

	for( int i = 0 ; i < Position ; i++ )
	{
		PositionNumber = NowScore % 10;
		NowScore /= 10;
	}

	return (PositionNumber);
}

//初期化
int QuartusEvent_Initialize( int WindowX , int WindowY )
{
	//QuartusContoroller起動
	int value;
	value = QuartusController_Initialize( WindowX , WindowY );
	//セッティング(全オフ)
	int sevenseg[ 7 ] = { 0 };
	int state = 0;
	//7セグ
	value += QuartusController_Set_SEVEN_SEGMENT_LED_Pattern_All( sevenseg );
	//LED赤
	value += QuartusController_Set_LEDRED_State_All( state );
	//LED緑
	value += QuartusController_Set_LEDGREEN_State_All( state );
	//プッシュボタン
	value += QuartusController_Set_PUSH_BUTTON_State_All( state );
	//スライドスイッチ
	value += QuartusController_Set_SLIDER_State_All( state );

	NowEvent.LEDRED.LightCnt = 0;
	NowEvent.LEDGREEN.LightCnt = 0;
	NowEvent.SEVENSEG.Score = 0;

	return (value);
}

//更新
int QuartusEvent_Update( void )
{
	int value;
	//QuartusControllerの更新処理
	value = QuartusController_Update();

	//LED点灯
	if( NowEvent.WaitCnt == 0 )	//待ち時間でなければ
	{
		//LED赤
		//一旦全消し
		QuartusController_Set_LEDRED_State_All( 0 );
		//左2つを点灯
		QuartusController_Set_LEDRED_State( 0 , 1 );
		QuartusController_Set_LEDRED_State( 1 , 1 );
		//LightCntの場所を点灯
		QuartusController_Set_LEDRED_State( NowEvent.LEDRED.LightCnt , 1 );
		//LED赤の数を超えていなければ点灯位置を右にずらす
		if( NowEvent.LEDRED.LightCnt < Quartus_Get_QUARTUS_LEDRED_NUM() - 1 )
		{
			NowEvent.LEDRED.LightCnt++;
		}
		else
		{
			NowEvent.LEDRED.LightCnt = 0;
		}

		//LED緑
		//一旦全消し
		QuartusController_Set_LEDGREEN_State_All( 0 );
		//左2つを点灯
		QuartusController_Set_LEDGREEN_State( 0 , 1 );
		QuartusController_Set_LEDGREEN_State( 1 , 1 );
		//LightCntの場所を点灯
//		QuartusController_Set_LEDGREEN_State( Quartus_Get_QUARTUS_LEDGREEN_NUM() -1 - NowEvent.LEDGREEN.LightCnt , 1 );
		QuartusController_Set_LEDGREEN_State( NowEvent.LEDGREEN.LightCnt , 1 );
		//LED緑の数を超えていなければ点灯位置を右にずらす
		if( NowEvent.LEDGREEN.LightCnt < Quartus_Get_QUARTUS_LEDGREEN_NUM() - 1 )
		{
			NowEvent.LEDGREEN.LightCnt++;
		}
		else
		{
			NowEvent.LEDGREEN.LightCnt = 0;
		}

		//プッシュスイッチ
		//一番左のが押されていた時
		if( QuartusController_Get_PUSH_BUTTON_State( 0 ) == 1 )
		{
			//LED赤が光っていたら
			if( QuartusController_Get_LEDRED_State( QUARTUS_LEDRED_NUM - 1 ) == 1 )
			{
				NowEvent.SEVENSEG.Score += 1;
			}
			else
			{
				NowEvent.SEVENSEG.Score -= 1;
			}
		}
		//左から2番目のが押されていた時
		if( QuartusController_Get_PUSH_BUTTON_State( 1 ) == 1 )
		{
			//LED緑が光っていたら
			if( QuartusController_Get_LEDGREEN_State( QUARTUS_LEDGREEN_NUM ) == 1 )
			{
				NowEvent.SEVENSEG.Score += 1;
			}
			else
			{
				NowEvent.SEVENSEG.Score -= 1;
			}
		}

		//待ち時間に移行
		NowEvent.WaitCnt = QUARTUSEVENT_WAITTIME;
	}
	else	//待ち時間中であれば
	{
		NowEvent.WaitCnt -= 1;	//待ち時間-1
	}

	//プッシュスイッチ
	//一番左のが押されていた時
	if( QuartusController_Get_PUSH_BUTTON_State( 0 ) == 1 )
	{
		//LED赤が光っていたら
		if( QuartusController_Get_LEDRED_State( QUARTUS_LEDRED_NUM - 1 ) == 1 )
		{
			NowEvent.SEVENSEG.Score += 1;
		}
		else
		{
			NowEvent.SEVENSEG.Score -= 1;
		}
	}
	//左から2番目のが押されていた時
	if( QuartusController_Get_PUSH_BUTTON_State( 1 ) == 1 )
	{
		//LED緑が光っていたら
		if( NowEvent.LEDGREEN.LightCnt == (QUARTUS_LEDRED_NUM-1) )
		{
			NowEvent.SEVENSEG.Score += 1;
		}
		else
		{
			NowEvent.SEVENSEG.Score -= 1;
		}
	}

	//7セグ
	//スコアを表示
	//1の位
	localQuartusEvent_Set_SEVEN_SEG_Pattern_Decimal( 7 ,  localQuartusEvent_Get_ScoreNumPosition( 1 ) );
	//10の位
	localQuartusEvent_Set_SEVEN_SEG_Pattern_Decimal( 6 ,  localQuartusEvent_Get_ScoreNumPosition( 2 ) );
	//100の位
	localQuartusEvent_Set_SEVEN_SEG_Pattern_Decimal( 5 ,  localQuartusEvent_Get_ScoreNumPosition( 3 ) );
	//1000の位
	localQuartusEvent_Set_SEVEN_SEG_Pattern_Decimal( 4 ,  localQuartusEvent_Get_ScoreNumPosition( 4 ) );

	return (value);
}

//描画
int QuartusEvent_Draw( void )
{
	int value;
	value = QuartusController_Draw();

	return (value);
}