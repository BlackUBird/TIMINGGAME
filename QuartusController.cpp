#include "DxLib.h"
#include "QuartusController.h"


//������
int QuartusController_Initialize( int WindowX , int WindowY )
{
	//����
	int value;	//�Ԃ�l�Ƃ��ĕۑ�
	value = Input_Update_All();

	//Quartus
	//�ҋ@����
	InitQuartusController.WaitCount = 0;
	//����\���ǂ���(�S�đ���\)
	InitQuartusController.Available.Key = 1;
	InitQuartusController.Available.Mouse = 1;

	//QuartusLike�̏�����
	value += Quartus_Initialize( WindowX , WindowY , &(InitQuartusController.Quartus) );

	//������ԗp�̏����R���g���[���ɃR�s�[
	QuartusController = InitQuartusController;

	//�������������ł�����(0:������ 0�ȊO�F�ُ픭��)
	return (value);
}

//�X�V
//�v�b�V���{�^���̏�Ԃ𔽓]������
int local_QuartusController_Update_Inverse_PUSH_BUTTON( int Num )
{
	if( QuartusController_Get_PUSH_BUTTON_State( Num ) == 0 )
	{//���݂̏�Ԃ�0��������1�ɂ���
		QuartusController_Set_PUSH_BUTTON_State( Num , 1 );
	}
	else
	{//���݂̏�Ԃ�1��������0�ɂ���
		QuartusController_Set_PUSH_BUTTON_State( Num , 0 );
	}

	return (QuartusController.Quartus.PushButton[Num].State);
}
//�X���C�h�X�C�b�`�̏�Ԃ𔽓]������
int local_QuartusController_Update_Inverse_SLIDER( int Num )
{
	if( QuartusController_Get_SLIDER_State( Num ) == 0 )
	{//���݂̏�Ԃ�0��������1�ɂ���
		QuartusController_Set_SLIDER_State( Num , 1 );
	}
	else
	{//���݂̏�Ԃ�1��������0�ɂ���
		QuartusController_Set_SLIDER_State( Num , 0 );
	}
	
	return (QuartusController.Quartus.Slider[Num].State);
}
int local_QuartusController_Update_Effect_Key(void)
{
	int value = 0;	//�ԋp�l(�ύX����������)

	if( QuartusController.Available.Key == 1 )
	{
		//�v�b�V���{�^��
		if( Input_Get_Key_State( KEY_INPUT_1 ) == 1 )
		{//�����L�[1��������Ă�����0�Ԃ��X�V
			int num = 0;
			local_QuartusController_Update_Inverse_PUSH_BUTTON( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_2 ) == 1 )
		{//�����L�[2��������Ă�����1�Ԃ��X�V
			int num = 1;
			local_QuartusController_Update_Inverse_PUSH_BUTTON( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_3 ) == 1 )
		{//�����L�[3��������Ă�����2�Ԃ��X�V
			int num = 2;
			local_QuartusController_Update_Inverse_PUSH_BUTTON( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_4 ) == 1 )
		{//�����L�[4��������Ă�����3�Ԃ��X�V
			int num = 3;
			local_QuartusController_Update_Inverse_PUSH_BUTTON( num );
			value++;
		}

		//�X���C�h�X�C�b�`
		if( Input_Get_Key_State( KEY_INPUT_Q ) == 1 )
		{//�����L�[Q��������Ă�����0�Ԃ��X�V
			int num = 0;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_W ) == 1 )
		{//�����L�[W��������Ă�����1�Ԃ��X�V
			int num = 1;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_E ) == 1 )
		{//�����L�[E��������Ă�����2�Ԃ��X�V
			int num = 2;
			local_QuartusController_Update_Inverse_SLIDER( num );
		}
		if( Input_Get_Key_State( KEY_INPUT_R ) == 1 )
		{//�����L�[R��������Ă�����3�Ԃ��X�V
			int num = 3;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_T ) == 1 )
		{//�����L�[T��������Ă�����4�Ԃ��X�V
			int num = 4;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_Y ) == 1 )
		{//�����L�[Y��������Ă�����5�Ԃ��X�V
			int num = 5;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_U ) == 1 )
		{//�����L�[U��������Ă�����6�Ԃ��X�V
			int num = 6;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_I ) == 1 )
		{//�����L�[I��������Ă�����7�Ԃ��X�V
			int num = 7;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_O ) == 1 )
		{//�����L�[O��������Ă�����8�Ԃ��X�V
			int num = 8;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_A ) == 1 )
		{//�����L�[A��������Ă�����9�Ԃ��X�V
			int num = 9;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_S ) == 1 )
		{//�����L�[S��������Ă�����10�Ԃ��X�V
			int num = 10;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_D ) == 1 )
		{//�����L�[D��������Ă�����11�Ԃ��X�V
			int num = 11;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_F ) == 1 )
		{//�����L�[F��������Ă�����12�Ԃ��X�V
			int num = 12;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_G ) == 1 )
		{//�����L�[G��������Ă�����13�Ԃ��X�V
			int num = 13;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_H ) == 1 )
		{//�����L�[H��������Ă�����14�Ԃ��X�V
			int num = 14;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_J ) == 1 )
		{//�����L�[J��������Ă�����15�Ԃ��X�V
			int num = 15;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_K ) == 1 )
		{//�����L�[K��������Ă�����16�Ԃ��X�V
			int num = 16;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
		if( Input_Get_Key_State( KEY_INPUT_L ) == 1 )
		{//�����L�[L��������Ă�����17�Ԃ��X�V
			int num = 17;
			local_QuartusController_Update_Inverse_SLIDER( num );
			value++;
		}
	}

	//1��ȏ�ύX����������ҋ@����(WAITTIME_INPUT)���Z�b�g
	if( value > 0 )
	{
		QuartusController.WaitCount = WAITTIME_INPUT;
	}

	return (value);
}
int QuartusController_Update(void)
{
	//���͂��A�b�v�f�[�g
	//�L�[
	int value;	//�Ԃ�l�Ƃ��ĕۑ�
	value = Input_Update_Key();
	if( QuartusController.WaitCount == 0 )
	{//���͑҂����łȂ����
		//���͉\�ɂ���
		QuartusController.Available.Key = 1;
		//���͂ɉ�����Quartus�̑f�q��ω�
		local_QuartusController_Update_Effect_Key();
	}
	else
	{//���͑҂����ł����
		//���͕s�ɂ���
		QuartusController.Available.Key = 0;
		//�J�E���^����1����
		QuartusController.WaitCount -= 1;
	}

	//�}�E�X
	Input_Update_Mouse();

	return (value);	//0:������ 0�ȊO:�������Ȃ�
}

//�Z�b�^
//Quartus
//7�Z�O
int QuartusController_Set_SEVEN_SEGMENT_LED_Pattern( int Num , int NewPattern[] )
{
	int value;	//�Ԃ�l
	value = Quartus_Set_SEVEN_SEGMENT_LED_Pattern( Num , NewPattern , &(QuartusController.Quartus) );

	return (value);	//0:������ 0�ȊO:�ُ픭��
}
//�ꊇ
int QuartusController_Set_SEVEN_SEGMENT_LED_Pattern_All( int NewPattern[] )
{
	int value = 0;
	for( int i = 0 ; i < Quartus_Get_QUARTUS_SEVENSEG_NUM() ; i++ )
	{
		value += QuartusController_Set_SEVEN_SEGMENT_LED_Pattern( i , NewPattern );
	}

	return (value);
}
//�����_�C�I�[�h
//��
int QuartusController_Set_LEDRED_State( int Num , int NewState )
{
	int value;	//�Ԃ�l
	value = Quartus_Set_LEDRED_State( Num , NewState , &(QuartusController.Quartus) );

	return (value);	//0:������ 0�ȊO:�ُ픭��
}
//�ꊇ
int QuartusController_Set_LEDRED_State_All( int NewState )
{
	int value = 0;
	for( int i = 0 ; i < Quartus_Get_QUARTUS_LEDRED_NUM() ; i++ )
	{
		value += QuartusController_Set_LEDRED_State( i , NewState );
	}

	return (value);
}
//��
int QuartusController_Set_LEDGREEN_State( int Num , int NewState )
{
	int value;	//�Ԃ�l
	value = Quartus_Set_LEDGREEN_State( Num , NewState , &(QuartusController.Quartus) );

	return (value);	//0:������ 0�ȊO:�ُ픭��
}
//�ꊇ
int QuartusController_Set_LEDGREEN_State_All( int NewState )
{
	int value = 0;	//�Ԃ�l
	for( int i = 0 ; i < Quartus_Get_QUARTUS_LEDGREEN_NUM() ; i++ )
	{
		value = QuartusController_Set_LEDGREEN_State( i , NewState );
	}

	return (value);	//0:������ 0�ȊO:�ُ픭��
}
//�v�b�V���{�^��
int QuartusController_Set_PUSH_BUTTON_State( int Num , int NewState )
{
	int value;	//�Ԃ�l
	value = Quartus_Set_PUSH_BUTTON_State( Num , NewState , &(QuartusController.Quartus) );

	return (value);	//0:������ 0�ȊO:�ُ픭��
}
//�ꊇ
int QuartusController_Set_PUSH_BUTTON_State_All( int NewState )
{
	int value = 0;	//�Ԃ�l
	for( int i = 0 ; i < Quartus_Get_QUARTUS_PUSHBUTTON_NUM() ; i++ )
	{
		value = QuartusController_Set_PUSH_BUTTON_State( i , NewState );
	}

	return (value);	//0:������ 0�ȊO:�ُ픭��
}
//�X���C�h�X�C�b�`
int QuartusController_Set_SLIDER_State( int Num , int NewState )
{
	int value;	//�Ԃ�l
	value = Quartus_Set_SLIDER_State( Num , NewState , &(QuartusController.Quartus) );

	return (value);	//0:������ 0�ȊO:�ُ픭��
}
//�ꊇ
int QuartusController_Set_SLIDER_State_All( int NewState )
{
	int value = 0;	//�Ԃ�l
	for( int i = 0 ; i < Quartus_Get_QUARTUS_SLIDER_NUM() ; i++ )
	{
		value = QuartusController_Set_SLIDER_State( i , NewState );
	}

	return (value);	//0:������ 0�ȊO:�ُ픭��
}

//�Q�b�^
//Quartus
//7�Z�O
int QuartusController_Get_SEVEN_SEGMENT_LED_Pattern( int Num , int PatternNum )
{
	int value;
	value = QuartusController.Quartus.SevenSeg[Num].Pattern[PatternNum];

	return (value);
}
//�����_�C�I�[�h
//��
int QuartusController_Get_LEDRED_State( int Num )
{
	int value;
	value = QuartusController.Quartus.LEDRed[Num].State;

	return (value);
}
//��
int QuartusController_Get_LEDGREEN_State( int Num )
{
	int value;
	value = QuartusController.Quartus.LEDGreen[Num].State;

	return (value);
}
//�v�b�V���{�^��
int QuartusController_Get_PUSH_BUTTON_State( int Num )
{
	int value;
	value = QuartusController.Quartus.PushButton[Num].State;

	return (value);
}
//�X���C�h�X�C�b�`
int QuartusController_Get_SLIDER_State( int Num )
{
	int value;
	value = QuartusController.Quartus.Slider[Num].State;

	return (value);
}

//�`��
int QuartusController_Draw(void)
{
	int value;
	value = Quartus_Draw( QuartusController.Quartus );

	return (value);
}