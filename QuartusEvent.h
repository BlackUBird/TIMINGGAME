#ifndef QUARTUSEVENT_H
#define QUARTUSEVENT_H

#include "QuartusController.h"

#define QUARTUSEVENT_WAITTIME (6)

//LED��
typedef struct ts_QuartusEvent_LEDRED
{
	int LightCnt;
} s_QuartusEvent_LEDRED;
//LED��
typedef struct ts_QuartusEvent_LEDGREEN
{
	int LightCnt;
} s_QuartusEvent_LEDGREEN;
//�v�b�V���{�^��
typedef struct ts_QuartusEvent_PUSHBUTTON
{
	int State;
} s_QuartusEvent_PUSHBUTTON;
//7�Z�O
typedef struct ts_QuartusEvent_SEVENSEG
{
	int Score;	//�_��
} s_QuartusEvent_SEVENSEG;
//�C�x���g���
typedef struct ts_QuartusEvent_Event
{
	s_QuartusEvent_LEDRED LEDRED;
	s_QuartusEvent_LEDGREEN LEDGREEN;
	s_QuartusEvent_SEVENSEG SEVENSEG;
	int WaitCnt;
} s_QuartusEvent_Event;

static s_QuartusEvent_Event NowEvent;

//������
int QuartusEvent_Initialize( int WindowX , int WindowY );

//7�Z�O�ALED�ԁALED�΂̓_���p�^�[�����Z�b�g
int QuartusEvent_Set_SEVEN_SEGMENT_LED_Lights( int Num , int PatternLight[] );
int QuartusEvent_Set_LEDRED_Light( int PatternLen , int PatternLight[] );
int QuartusEvent_Set_LEDGREEN_Light( int PatternLen , int PatternLight[] );

//7�Z�O�ALED�ԁALED�΂̓_���p�^�[�����`�E�Ăяo��
int QuartusEvent_Define_SEVEN_SEGMENT_LED_Lights( int Num , int PatternLight[] );
int QuartusEvent_Define_LEDRED_Light( int PatternLen , int PatternLight[] );
int QuartusEvent_Define_LEDGREEN_Light( int PatternLen , int PatternLight[] );

//�X�V
int QuartusEvent_Update( void );

//�`��
int QuartusEvent_Draw( void );

#endif