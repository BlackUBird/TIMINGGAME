#ifndef INPUT_H
#define INPUT_H

#define KEY_MAX (256)

//キー入力関連
typedef struct ts_Key
{
	char StateBuf[ KEY_MAX ];	//全てのキーの押下状態を格納するバッファ
} s_Key;
//マウス関連
typedef struct ts_Mouse
{
	int Button;	//クリックされたボタンの種類を格納
	int ClickX, ClickY;	//クリックされた場所を格納
	int LogType;	//ボタンが「押された」or「離された」の情報を格納
	int LogDelete;	//ログ情報(マウスの入力状態)を削除するか

	int WheelRot;	//ホイールの回転量
} s_Mouse;
//入力情報
typedef struct ts_InputInfo
{
	s_Key Key;	//キー入力
	s_Mouse Mouse;	//マウス入力
} s_InputInfo;

static s_InputInfo InputInfo;

//更新
int Input_Update_Key(void);		//キー
int Input_Update_Mouse(void);	//マウス
int Input_Update_All(void);	//全部


//ゲッタ
//キー入力
//全てのキーの押下状態を取得
int Input_Get_Key_State_All(void);
//特定のキーの押下状態を取得
int Input_Get_Key_State( int KeyCode );

#endif