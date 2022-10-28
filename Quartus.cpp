#include "DxLib.h"
#include "Quartus.h"

//初期化
int Quartus_Initialize( int WindowX , int WindowY , s_Quartus* QuartusStatus )
{
	//ウィンドウサイズ
	WindowSizeX = WindowX;
	WindowSizeY = WindowY;

	//名前
	strcpy( QuartusStatus->Name , "ALTERALike" );
	//フォントハンドル
	QuartusStatus->FontHandle = CreateFontToHandle( "Title" , BLOCK_32 * 3 , 7 , DX_FONTTYPE_NORMAL );
	//名前表示位置
	QuartusStatus->NameX = BLOCK_32 * 2;	QuartusStatus->NameY = BLOCK_32 * 2;
	//色
	QuartusStatus->NameColor = GetColor( 255 , 255 , 255 );

	//基準位置
	int X = BLOCK_32 * 3;	int Y = BLOCK_32 * 8;

	//7セグメントLED
	//大きさ
	int SizeX = 30;	int SizeY = 62;
	//間隔,縦占有度(実質的に占有してる縦の大きさ)
	int space = BLOCK_32;	int OccupatedY = 64;
	//開始点
	int OX = X + ( BLOCK_32 - SizeX ) / 2;
	int OY = Y + ( BLOCK_32*2 - SizeY ) / 2;
	//設定
	for( int i = 0 ; i < QUARTUS_SEVENSEG_NUM ; i++ )
	{
		//色
		//点灯時
		QuartusStatus->SevenSeg[i].OnColor = GetColor( 255 , 128 , 0 );
		//消灯時
		QuartusStatus->SevenSeg[i].OffColor = GetColor( 128 , 128 , 128 );
		//パターン
		//全部点灯
		for( int j = 0 ; j < SEVEN_SEG_LED_NUM ; j++ )
		{
			QuartusStatus->SevenSeg[i].Pattern[j] = 1;
		}
		//大きさ
		QuartusStatus->SevenSeg[i].Size.x = SizeX;
		QuartusStatus->SevenSeg[i].Size.y = SizeY;
		//位置
		if( i == 0 )	//初期位置
		{
			//一番左に来る7セグの位置
			QuartusStatus->SevenSeg[i].Position.x = OX;
			QuartusStatus->SevenSeg[i].Position.y = OY;
		}
		else	//初期位置以外
		{
			//間を大きく離す場合
			int ext;
			if( i == 2 || i == 4 )
			{
				ext = 2;
			}
			else
			{
				ext = 1;
			}
			QuartusStatus->SevenSeg[i].Position.x = QuartusStatus->SevenSeg[i-1].Position.x + space * ext;
			QuartusStatus->SevenSeg[i].Position.y = OY;
		}
	}

	//LED
	//大きさ
	SizeX = 10;	SizeY = 10;
	//間隔
	space = (BLOCK_32 - SizeX * 2) / 4; 
	//開始点
	OX = X + space;
	OY = Y + OccupatedY + (BLOCK_32 - SizeY) / 2;
	//縦占有度(実質的に占有してる縦の大きさ)
	OccupatedY += 32;
	//設定
	//赤
	for( int i = 0 ; i < QUARTUS_LEDRED_NUM ; i++ )
	{
		QuartusStatus->LEDRed[ i ].State = 1;	//状態:ON
		
		QuartusStatus->LEDRed[ i ].Color = GetColor( 255 , 0 , 0 );	//色
		QuartusStatus->LEDRed[ i ].OffColor = GetColor( 128 , 128 , 128 ); //OFF時
		//大きさ
		QuartusStatus->LEDRed[ i ].Size.x = SizeX;
		QuartusStatus->LEDRed[ i ].Size.y = SizeY;
		//位置
		if( i == 0 )
		{
			QuartusStatus->LEDRed[ i ].Position.x = OX;
			QuartusStatus->LEDRed[ i ].Position.y = OY;
		}
		else
		{
			QuartusStatus->LEDRed[ i ].Position.x = QuartusStatus->LEDRed[ i-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->LEDRed[ i ].Position.y = OY;
		}
	}
	//緑
	for( int i = 0 ; i < QUARTUS_LEDGREEN_NUM ; i++ )
	{
		QuartusStatus->LEDGreen[i].State = 1;	//状態:ON
		
		QuartusStatus->LEDGreen[i].Color = GetColor( 0 , 255 , 0 );	//色
		QuartusStatus->LEDGreen[i].OffColor = GetColor( 128 , 128 , 128 );	//OFF時
		//大きさ
		QuartusStatus->LEDGreen[ i ].Size.x = SizeX;
		QuartusStatus->LEDGreen[ i ].Size.y = SizeY;
		
		//位置
		if( i == 0 )
		{
			QuartusStatus->LEDGreen[ i ].Position.x = QuartusStatus->LEDRed[ QUARTUS_LEDRED_NUM-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->LEDGreen[ i ].Position.y = OY;
		}
		else
		{
			QuartusStatus->LEDGreen[ i ].Position.x = QuartusStatus->LEDGreen[ i-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->LEDGreen[ i ].Position.y = OY;
		}
	}

	//スライドスイッチ
	//大きさ
	SizeX = 12;	SizeY = 30;
	//間隔
	space = (BLOCK_32 - SizeX * 2) / 4;
	//開始点
	OX = X + space;
	OY = Y + OccupatedY + ( BLOCK_32 * 2 - SizeY ) / 2;
	//縦占有度(更新無し)
	//OccupatedY += 32;
	//設定
	for( int i = 0 ; i < QUARTUS_SLIDER_NUM ; i++ )
	{
		//状態(全部下側)
		QuartusStatus->Slider[ i ].State = 0;
		//大きさ
		QuartusStatus->Slider[ i ].Size.x = SizeX;
		QuartusStatus->Slider[ i ].Size.y = SizeY;
		//位置
		if( i == 0 )
		{
			QuartusStatus->Slider[ i ].Position.x = OX;
			QuartusStatus->Slider[ i ].Position.y = OY;
		}
		else
		{
			QuartusStatus->Slider[ i ].Position.x = QuartusStatus->Slider[ i-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->Slider[ i ].Position.y = OY;
		}
	}

	
	//プッシュボタン
	//大きさ
	SizeX = 30;	SizeY = 30;
	//間隔
	space = (BLOCK_32 - SizeX) / 2;
	//開始点
//	OX = X + QuartusStatus->LEDGreen[ 0 ].Position.x + space;
	OX = X + space;
	OY = Y + OccupatedY + ( BLOCK_32 * 2 - SizeY ) / 2;
	//設定
	for( int i = 0 ; i < QUARTUS_PUSHBUTTON_NUM ; i++ )
	{
		//状態(全部押されていない)
		QuartusStatus->PushButton[i].State = 0;
		//大きさ
		QuartusStatus->PushButton[ i ].Size.x = SizeX;
		QuartusStatus->PushButton[ i ].Size.y = SizeY;
		//位置
		if( i == 0 )
		{
			QuartusStatus->PushButton[ i ].Position.x = QuartusStatus->Slider[ QUARTUS_SLIDER_NUM-1 ].Position.x + BLOCK_32 / 2 + space;
			QuartusStatus->PushButton[ i ].Position.y = OY;
		}
		else
		{
			QuartusStatus->PushButton[ i ].Position.x = QuartusStatus->PushButton[ i-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->PushButton[ i ].Position.y = OY;
		}
	}

	return (0);
}

//描画
//素子のみを表示
//7セグメントLED
/*
	長方形に沿って7本線を引く
*/
int Quartus_Draw_SEVEN_SEGMENT_LED( int PosX , int PosY , int SizeX , int SizeY , int OnColor , int OffColor , int Pattern[] )
{
	//7セグの線の太さ
	//長辺/8 + 1
	int w;
	if( SizeX < SizeY )
	{
		w = SizeX/8;
	}
	else
	{
		w = SizeY/8;
	}
	w += 1;

	//表示する座標
	//左上
	int x1[] = 
	{ 
		PosX+w ,		//0
		PosX+SizeX-w ,	//1
		PosX+SizeX-w ,	//2
		PosX+w ,	//3
		PosX ,			//4
		PosX ,			//5
		PosX+w			//6
	};
	int y1[] =
	{
		PosY ,				//0
		PosY+w ,			//1
		PosY+SizeY/2+w/2 ,	//2
		PosY+SizeY-w ,	//3
		PosY+SizeY/2+w/2 ,			//4
		PosY+w ,	//5
		PosY+SizeY/2-w/2	//6
	};
	//右下
	int x2[] =
	{
		PosX+SizeX-w-1 ,	//0
		PosX+SizeX-1 ,		//1
		PosX+SizeX-1	,	//2
		PosX+SizeX-w-1 ,		//3
		PosX+w-1 ,			//4
		PosX+w-1 ,			//5
		PosX+SizeX-w-1		//6
	};
	int y2[] =
	{
		PosY+w-1 ,				//0
		PosY+SizeY/2-w/2-1 ,	//1
		PosY+SizeY-w-1 ,		//2
		PosY+SizeY-1 ,		//3
		PosY+SizeY-w-1 ,		//4
		PosY+SizeY/2-w/2-1 ,	//5
		PosY+SizeY/2+w/2-1		//6
	};

	//返却値
	int rtn = 0;

	//描画
	for( int i = 0 ; i < 7 ; i++ )
	{
		int cr;	//表示するときの色
		if( Pattern[i] == 0 )
		{
			cr = OffColor;
		}
		else
		{
			cr = OnColor;
		}

		//表示
		int tmp;
		tmp = DrawBox( x1[i] , y1[i] , x2[i] , y2[i] , cr , TRUE );

		rtn += tmp;
	}

	return (rtn);	//0:全て正しく描画できた 0以外:どこかおかしい
}
//発光ダイオード
/*
	四角を指定の色で表示
*/
int Quartus_Draw_LED( int PosX , int PosY , int SizeX , int SizeY , int Color )
{
	int rtn = DrawBox( PosX , PosY , PosX+SizeX-1 , PosY+SizeY-1 , Color , TRUE );

	return (rtn);
}
//プッシュボタン
/*
	四角の上に丸を表示
	押し込まれているときは時は中抜け
	押されていないときは塗りつぶす
*/
int Quartus_Draw_PUSH_BUTTON( int PosX , int PosY , int Size , int State )
{
	//返り値
	int rtn;
	//四角を表示
	//計算
	int x1 = PosX;
	int y1 = PosY;
	int x2 = PosX+Size-1;
	int y2 = PosY+Size-1;
	int cr = GetColor( 128 , 128 , 128 );
	//表示
	rtn = DrawBox( x1 , y1 , x2 , y2 , cr , TRUE );
	//丸を内接させる
	//計算
	x1 = PosX+(int)(Size/2)-1;
	y1 = PosY+(int)(Size/2)-1;
	x2 = (int)(Size/2)-1;	//半径
	y2 = State == 0 ? FALSE : TRUE ;	//塗りつぶすか否か
	cr = GetColor( 64 , 255 , 255 );
	//表示
	rtn += DrawCircle( x1 , y1 , x2 , cr , y2 );

	//返却
	return (rtn);
}
//スライドスイッチ
/*
	四角を縦に2つ並べる
	State == 0 ならば　上が塗りつぶし無し
*/
int Quartus_Draw_SLIDER( int PosX , int PosY , int SizeX , int SizeY , int State )
{
	//返却値
	int rtn;

	//上側の四角
	//計算
	int x1 = PosX;
	int y1 = PosY;
	int x2 = PosX+SizeX-1;
	int y2 = PosY+(int)(SizeY/2)-1;
	int cr = GetColor( 128 , 128 , 128 );
	int fl = State == 0 ? FALSE : TRUE ;	//塗りつぶすか否か
	//表示
	rtn = DrawBox( x1 , y1 , x2 , y2 , cr , fl );
	//下側の四角
	//計算
	//x1は変更なし
	y1 = y2+2;
	//x2は変更なし
	y2 = PosY + SizeY;
	//crは変更なし
	fl = State == 0 ? TRUE : FALSE ;	//条件を逆さまにする
	//表示
	rtn += DrawBox( x1 , y1 , x2 , y2 , cr , fl );

	//返却 
	return (rtn);
}

//Quatusな感じで表示
int Quartus_Draw( s_Quartus QuartusStatus )
{
	//背景を青(#000080)で塗りつぶす
	DrawBox( 0 , 0 , WindowSizeX-1 , WindowSizeY-1 , GetColor( 0 , 0 , 128 ) , TRUE );

	//名前(タイトル)を表示
	DrawFormatStringToHandle( QuartusStatus.NameX , QuartusStatus.NameY , QuartusStatus.NameColor , QuartusStatus.FontHandle , "%s" , QuartusStatus.Name );

	//各素子を描画
	//7セグ
	for( int i = 0 ; i < QUARTUS_SEVENSEG_NUM ; i++ )
	{
		Quartus_Draw_SEVEN_SEGMENT_LED( QuartusStatus.SevenSeg[i].Position.x , QuartusStatus.SevenSeg[i].Position.y , 
			QuartusStatus.SevenSeg[i].Size.x , QuartusStatus.SevenSeg[i].Size.y , 
			QuartusStatus.SevenSeg[i].OnColor , QuartusStatus.SevenSeg[i].OffColor , 
			QuartusStatus.SevenSeg[i].Pattern );
	}

	//LED
	//赤
	for( int i = 0 ; i < QUARTUS_LEDRED_NUM ; i++ )
	{
		int Color;
		if( QuartusStatus.LEDRed[i].State != 0 )
		{
			Color = QuartusStatus.LEDRed[i].Color;
		}
		else
		{
			Color = QuartusStatus.LEDRed[i].OffColor;
		}
		Quartus_Draw_LED( QuartusStatus.LEDRed[i].Position.x , QuartusStatus.LEDRed[i].Position.y , 
			QuartusStatus.LEDRed[i].Size.x , QuartusStatus.LEDRed[i].Size.y ,
			Color );
	}
	//緑
	for( int i = 0 ; i < QUARTUS_LEDGREEN_NUM ; i++ )
	{
		int Color;
		if( QuartusStatus.LEDGreen[i].State != 0 )
		{
			Color = QuartusStatus.LEDGreen[i].Color;
		}
		else
		{
			Color = QuartusStatus.LEDGreen[i].OffColor;
		}
		Quartus_Draw_LED( QuartusStatus.LEDGreen[i].Position.x , QuartusStatus.LEDGreen[i].Position.y , 
			QuartusStatus.LEDGreen[i].Size.x , QuartusStatus.LEDGreen[i].Size.y ,
			Color );
	}

	//スライドスイッチ	
	for( int i = 0 ; i < QUARTUS_SLIDER_NUM ; i++ )
	{
		Quartus_Draw_SLIDER( QuartusStatus.Slider[i].Position.x , QuartusStatus.Slider[i].Position.y , 
			QuartusStatus.Slider[i].Size.x , QuartusStatus.Slider[i].Size.y , 
			QuartusStatus.Slider[i].State );
	}

	//プッシュボタン	
	for( int i = 0 ; i < QUARTUS_PUSHBUTTON_NUM ; i++ )
	{
		Quartus_Draw_PUSH_BUTTON( QuartusStatus.PushButton[i].Position.x , QuartusStatus.PushButton[i].Position.y , 
			QuartusStatus.PushButton[i].Size.x , 
			QuartusStatus.PushButton[i].State );
	}

	return (0);
}

//セッタ
//7セグメントLED
//点灯パターン
int Quartus_Set_SEVEN_SEGMENT_LED_Pattern( int Num , int NewPattern[] , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_SEVENSEG_NUM )
	{
		return (-1);
	}
	int cnt = 0;
	for( int i = 0 ; i < SEVEN_SEG_LED_NUM ; i++ )
	{
		QuartusStatus->SevenSeg[ Num ].Pattern[ i ] = NewPattern[ i ];
		cnt += QuartusStatus->SevenSeg[ Num ].Pattern[ i ];
	}

	return (cnt);
}
//発光ダイオード
//ON/OFF
//緑
int Quartus_Set_LEDGREEN_State( int Num , int NewState , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_LEDGREEN_NUM )
	{
		return (-1);
	}
	int rtn;
	QuartusStatus->LEDGreen[Num].State = NewState;

	rtn = QuartusStatus->LEDGreen[Num].State;

	return (rtn);
}
//赤
int Quartus_Set_LEDRED_State( int Num , int NewState , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_LEDRED_NUM )
	{
		return (-1);
	}
	int rtn;
	QuartusStatus->LEDRed[Num].State = NewState;

	rtn = QuartusStatus->LEDRed[Num].State;

	return (rtn);
}
//プッシュボタン
//状態
int Quartus_Set_PUSH_BUTTON_State( int Num , int NewState , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_PUSHBUTTON_NUM )
	{
		return (-1);
	}
	int rtn;
	QuartusStatus->PushButton[Num].State = NewState;

	rtn = QuartusStatus->PushButton[Num].State;

	return (rtn);
}
//スライドスイッチ
//状態
int Quartus_Set_SLIDER_State( int Num , int NewState , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_SLIDER_NUM )
	{
		return (-1);
	}
	int rtn;
	QuartusStatus->Slider[Num].State = NewState;

	rtn = QuartusStatus->Slider[Num].State;

	return (rtn);
}

//ゲッタ
//define
int Quartus_Get_QUARTUS_NAME_MAX( void )
{
	return (QUARTUS_NAME_MAX);
}
int Quartus_Get_QUARTUS_SEVENSEG_NUM( void )
{
	return (QUARTUS_SEVENSEG_NUM);
}
int Quartus_Get_QUARTUS_LEDRED_NUM( void )
{
	return (QUARTUS_LEDRED_NUM);
}
int Quartus_Get_QUARTUS_LEDGREEN_NUM( void )
{
	return (QUARTUS_LEDGREEN_NUM);
}
int Quartus_Get_QUARTUS_PUSHBUTTON_NUM( void )
{
	return (QUARTUS_PUSHBUTTON_NUM);
}
int Quartus_Get_QUARTUS_SLIDER_NUM( void )
{
	return (QUARTUS_SLIDER_NUM);
}
int Quartus_Get_SEVEN_SEG_LED_NUM( void )
{
	return (SEVEN_SEG_LED_NUM);
}
int Quartus_Get_BLOCK_32( void )
{
	return (BLOCK_32);
}