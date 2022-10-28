#include "DxLib.h"
#include "Input.h"


//更新
//キー
int Input_Update_Key(void)
{
	//全てのキーの押下状態を取得
	//入力情報として格納
	int value;
	value = GetHitKeyStateAll( InputInfo.Key.StateBuf );

	//入力情報を正しく格納できたかを返却(0:成功 -1:失敗)
	return (value);
}
//マウス
int Input_Update_Mouse(void)
{
	//マウスのボタンの押下情報を取得
	//一時格納用
	int tmpButton;
	int tmpClickX,tmpClickY;
	int tmpLogType;
	int value;	//返却値
	value = GetMouseInputLog2( &tmpButton , &tmpClickX , &tmpClickY , &tmpLogType , InputInfo.Mouse.LogDelete );
	
	//ホイールの回転量
	int tmpWheelRot;
	tmpWheelRot = GetMouseWheelRotVol();
	InputInfo.Mouse.WheelRot += tmpWheelRot;

	//ボタンの押下情報を正しく格納できたかを返却(0:成功 -1:失敗)
	return (value);
}
//全部
int Input_Update_All(void)
{
	//返却用
	int value;
	value = Input_Update_Key();	//キー
	Input_Update_Mouse();	//マウス

	//返却(0:正しい , 0以外:正しくない)(キーのみ)(マウスは操作されたかされていないかで返り値が変化するため)
	return (value);
}

//ゲッタ
//キー入力
//全てのキーの押下状態を取得
int Input_Get_Key_State_All(void)
{
	int cnt = 0;
	for( int i = 0 ; i < KEY_MAX ; i++ )
	{
		if( InputInfo.Key.StateBuf[ i ] == 1 )
		{
			cnt++;
		}
	}

	return (cnt);
}

//特定のキーの押下状態を取得
int Input_Get_Key_State( int KeyCode )
{
	int value;
	if( InputInfo.Key.StateBuf[ KeyCode ] == 1 )
	{
		value = 1;
	}
	else
	{
		value = 0;
	}

	return (value);
}