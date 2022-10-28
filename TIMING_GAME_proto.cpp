#include "DxLib.h"
#include "QuartusEvent.h"

//�E�B���h�E�֘A�̒�`
#define WINDOW_SIZE_X (640)	//����
#define WINDOW_SIZE_Y (480)	//�c��
#define WINDOW_COLOR_BIT_NUM (32)	//�J���[�r�b�g��


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
	//�ݒ�A�ύX-------------------------------------------
	// �E�C���h�E���[�h�ɕύX
	if( ChangeWindowMode( TRUE ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// ��ʃ��[�h�̐ݒ�
	if( SetGraphMode( WINDOW_SIZE_X , WINDOW_SIZE_Y , WINDOW_COLOR_BIT_NUM ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}

	//������
	QuartusEvent_Initialize( WINDOW_SIZE_X , WINDOW_SIZE_Y );

	//1�t���[�����Ƃɍs���������L�q
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && QuartusEvent_Update()==0 )
	{
		//ESC�������ꂽ��I��
		if( Input_Get_Key_State( KEY_INPUT_ESCAPE ) == 1 )
		{
			break;
		}

		//�\��
		QuartusEvent_Draw();
	}
	
	WaitKey() ;				// �L�[���͑҂�

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;				// �\�t�g�̏I�� 
}