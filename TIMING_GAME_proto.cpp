#include "DxLib.h"
#include "QuartusEvent.h"

//ウィンドウ関連の定義
#define WINDOW_SIZE_X (640)	//横幅
#define WINDOW_SIZE_Y (480)	//縦幅
#define WINDOW_COLOR_BIT_NUM (32)	//カラービット数


// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
	//設定、変更-------------------------------------------
	// ウインドウモードに変更
	if( ChangeWindowMode( TRUE ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// 画面モードの設定
	if( SetGraphMode( WINDOW_SIZE_X , WINDOW_SIZE_Y , WINDOW_COLOR_BIT_NUM ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 )
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}

	//初期化
	QuartusEvent_Initialize( WINDOW_SIZE_X , WINDOW_SIZE_Y );

	//1フレームごとに行う処理を記述
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && QuartusEvent_Update()==0 )
	{
		//ESCが押されたら終了
		if( Input_Get_Key_State( KEY_INPUT_ESCAPE ) == 1 )
		{
			break;
		}

		//表示
		QuartusEvent_Draw();
	}
	
	WaitKey() ;				// キー入力待ち

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;				// ソフトの終了 
}