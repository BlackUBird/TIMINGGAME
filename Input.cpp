#include "DxLib.h"
#include "Input.h"


//�X�V
//�L�[
int Input_Update_Key(void)
{
	//�S�ẴL�[�̉�����Ԃ��擾
	//���͏��Ƃ��Ċi�[
	int value;
	value = GetHitKeyStateAll( InputInfo.Key.StateBuf );

	//���͏��𐳂����i�[�ł�������ԋp(0:���� -1:���s)
	return (value);
}
//�}�E�X
int Input_Update_Mouse(void)
{
	//�}�E�X�̃{�^���̉��������擾
	//�ꎞ�i�[�p
	int tmpButton;
	int tmpClickX,tmpClickY;
	int tmpLogType;
	int value;	//�ԋp�l
	value = GetMouseInputLog2( &tmpButton , &tmpClickX , &tmpClickY , &tmpLogType , InputInfo.Mouse.LogDelete );
	
	//�z�C�[���̉�]��
	int tmpWheelRot;
	tmpWheelRot = GetMouseWheelRotVol();
	InputInfo.Mouse.WheelRot += tmpWheelRot;

	//�{�^���̉������𐳂����i�[�ł�������ԋp(0:���� -1:���s)
	return (value);
}
//�S��
int Input_Update_All(void)
{
	//�ԋp�p
	int value;
	value = Input_Update_Key();	//�L�[
	Input_Update_Mouse();	//�}�E�X

	//�ԋp(0:������ , 0�ȊO:�������Ȃ�)(�L�[�̂�)(�}�E�X�͑��삳�ꂽ������Ă��Ȃ����ŕԂ�l���ω����邽��)
	return (value);
}

//�Q�b�^
//�L�[����
//�S�ẴL�[�̉�����Ԃ��擾
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

//����̃L�[�̉�����Ԃ��擾
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