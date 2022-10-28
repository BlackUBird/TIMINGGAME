#include "DxLib.h"
#include "QuartusEvent.h"

//���[�J���֐�
//�����Ŏw�肳�ꂽ7�Z�O�Ɏw�肳�ꂽ������\��
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
//�X�R�A��1�̈ʁ`1000�̈ʂ̂����A�w�肳�ꂽ�ʒu�̐�����Ԃ�
//���l�� 1234 �̎��́A�E������1�Ԗ�(=4)�A2�Ԗ�(=3)�@3�Ԗ�(=2)�A4�Ԗ�(=1)�Ƃ���
int localQuartusEvent_Get_ScoreNumPosition( int Position )
{
	int NowScore = NowEvent.SEVENSEG.Score;	//���݂̃X�R�A
	int PositionNumber;	//�ԋp�l

	for( int i = 0 ; i < Position ; i++ )
	{
		PositionNumber = NowScore % 10;
		NowScore /= 10;
	}

	return (PositionNumber);
}

//������
int QuartusEvent_Initialize( int WindowX , int WindowY )
{
	//QuartusContoroller�N��
	int value;
	value = QuartusController_Initialize( WindowX , WindowY );
	//�Z�b�e�B���O(�S�I�t)
	int sevenseg[ 7 ] = { 0 };
	int state = 0;
	//7�Z�O
	value += QuartusController_Set_SEVEN_SEGMENT_LED_Pattern_All( sevenseg );
	//LED��
	value += QuartusController_Set_LEDRED_State_All( state );
	//LED��
	value += QuartusController_Set_LEDGREEN_State_All( state );
	//�v�b�V���{�^��
	value += QuartusController_Set_PUSH_BUTTON_State_All( state );
	//�X���C�h�X�C�b�`
	value += QuartusController_Set_SLIDER_State_All( state );

	NowEvent.LEDRED.LightCnt = 0;
	NowEvent.LEDGREEN.LightCnt = 0;
	NowEvent.SEVENSEG.Score = 0;

	return (value);
}

//�X�V
int QuartusEvent_Update( void )
{
	int value;
	//QuartusController�̍X�V����
	value = QuartusController_Update();

	//LED�_��
	if( NowEvent.WaitCnt == 0 )	//�҂����ԂłȂ����
	{
		//LED��
		//��U�S����
		QuartusController_Set_LEDRED_State_All( 0 );
		//��2��_��
		QuartusController_Set_LEDRED_State( 0 , 1 );
		QuartusController_Set_LEDRED_State( 1 , 1 );
		//LightCnt�̏ꏊ��_��
		QuartusController_Set_LEDRED_State( NowEvent.LEDRED.LightCnt , 1 );
		//LED�Ԃ̐��𒴂��Ă��Ȃ���Γ_���ʒu���E�ɂ��炷
		if( NowEvent.LEDRED.LightCnt < Quartus_Get_QUARTUS_LEDRED_NUM() - 1 )
		{
			NowEvent.LEDRED.LightCnt++;
		}
		else
		{
			NowEvent.LEDRED.LightCnt = 0;
		}

		//LED��
		//��U�S����
		QuartusController_Set_LEDGREEN_State_All( 0 );
		//��2��_��
		QuartusController_Set_LEDGREEN_State( 0 , 1 );
		QuartusController_Set_LEDGREEN_State( 1 , 1 );
		//LightCnt�̏ꏊ��_��
//		QuartusController_Set_LEDGREEN_State( Quartus_Get_QUARTUS_LEDGREEN_NUM() -1 - NowEvent.LEDGREEN.LightCnt , 1 );
		QuartusController_Set_LEDGREEN_State( NowEvent.LEDGREEN.LightCnt , 1 );
		//LED�΂̐��𒴂��Ă��Ȃ���Γ_���ʒu���E�ɂ��炷
		if( NowEvent.LEDGREEN.LightCnt < Quartus_Get_QUARTUS_LEDGREEN_NUM() - 1 )
		{
			NowEvent.LEDGREEN.LightCnt++;
		}
		else
		{
			NowEvent.LEDGREEN.LightCnt = 0;
		}

		//�v�b�V���X�C�b�`
		//��ԍ��̂�������Ă�����
		if( QuartusController_Get_PUSH_BUTTON_State( 0 ) == 1 )
		{
			//LED�Ԃ������Ă�����
			if( QuartusController_Get_LEDRED_State( QUARTUS_LEDRED_NUM - 1 ) == 1 )
			{
				NowEvent.SEVENSEG.Score += 1;
			}
			else
			{
				NowEvent.SEVENSEG.Score -= 1;
			}
		}
		//������2�Ԗڂ̂�������Ă�����
		if( QuartusController_Get_PUSH_BUTTON_State( 1 ) == 1 )
		{
			//LED�΂������Ă�����
			if( QuartusController_Get_LEDGREEN_State( QUARTUS_LEDGREEN_NUM ) == 1 )
			{
				NowEvent.SEVENSEG.Score += 1;
			}
			else
			{
				NowEvent.SEVENSEG.Score -= 1;
			}
		}

		//�҂����ԂɈڍs
		NowEvent.WaitCnt = QUARTUSEVENT_WAITTIME;
	}
	else	//�҂����Ԓ��ł����
	{
		NowEvent.WaitCnt -= 1;	//�҂�����-1
	}

	//�v�b�V���X�C�b�`
	//��ԍ��̂�������Ă�����
	if( QuartusController_Get_PUSH_BUTTON_State( 0 ) == 1 )
	{
		//LED�Ԃ������Ă�����
		if( QuartusController_Get_LEDRED_State( QUARTUS_LEDRED_NUM - 1 ) == 1 )
		{
			NowEvent.SEVENSEG.Score += 1;
		}
		else
		{
			NowEvent.SEVENSEG.Score -= 1;
		}
	}
	//������2�Ԗڂ̂�������Ă�����
	if( QuartusController_Get_PUSH_BUTTON_State( 1 ) == 1 )
	{
		//LED�΂������Ă�����
		if( NowEvent.LEDGREEN.LightCnt == (QUARTUS_LEDRED_NUM-1) )
		{
			NowEvent.SEVENSEG.Score += 1;
		}
		else
		{
			NowEvent.SEVENSEG.Score -= 1;
		}
	}

	//7�Z�O
	//�X�R�A��\��
	//1�̈�
	localQuartusEvent_Set_SEVEN_SEG_Pattern_Decimal( 7 ,  localQuartusEvent_Get_ScoreNumPosition( 1 ) );
	//10�̈�
	localQuartusEvent_Set_SEVEN_SEG_Pattern_Decimal( 6 ,  localQuartusEvent_Get_ScoreNumPosition( 2 ) );
	//100�̈�
	localQuartusEvent_Set_SEVEN_SEG_Pattern_Decimal( 5 ,  localQuartusEvent_Get_ScoreNumPosition( 3 ) );
	//1000�̈�
	localQuartusEvent_Set_SEVEN_SEG_Pattern_Decimal( 4 ,  localQuartusEvent_Get_ScoreNumPosition( 4 ) );

	return (value);
}

//�`��
int QuartusEvent_Draw( void )
{
	int value;
	value = QuartusController_Draw();

	return (value);
}