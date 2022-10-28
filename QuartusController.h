#ifndef QUARTUSCONTROLLER_H
#define QUARTUSCONTROLLER_H

#include "Quartus.h"
#include "Input.h"

#define WAITTIME_INPUT (6)	//���͂������Ă��牽�t���[���҂�

//���삪�L�������������i�[
typedef struct ts_Available
{
	int Key;	//0:���� 0�ȊO:�L��
	int Mouse;	//0:���� 0�ȊO:�L��
} s_Available;

//Quartus�̑�����Ǘ�
typedef struct ts_QuartusController
{
	int WaitCount;	//�ҋ@���Ԃ��J�E���g
	s_Available Available;	//����\���ǂ���
	
	s_Quartus Quartus;	//Quartus�̏��
} s_QuartusController;

static s_QuartusController InitQuartusController;	//Quartus�̏������
static s_QuartusController QuartusController;	//Quartus�̏�Ԃ��i�[(�R���g���[��)

//������
int QuartusController_Initialize( int WindowX , int WindowY );

//�Z�b�^
//Quartus
//7�Z�O
int QuartusController_Set_SEVEN_SEGMENT_LED_Pattern( int Num , int NewPattern[] );
int QuartusController_Set_SEVEN_SEGMENT_LED_Pattern_All( int NewPattern[] );	//�ꊇ
//�����_�C�I�[�h
//��
int QuartusController_Set_LEDRED_State( int Num , int NewState );
int QuartusController_Set_LEDRED_State_All( int NewState );	//�ꊇ
//��
int QuartusController_Set_LEDGREEN_State( int Num , int NewState );
int QuartusController_Set_LEDGREEN_State_All( int NewState );	//�ꊇ
//�v�b�V���{�^��
int QuartusController_Set_PUSH_BUTTON_State( int Num , int NewState );
int QuartusController_Set_PUSH_BUTTON_State_All( int NewState );	//�ꊇ
//�X���C�h�X�C�b�`
int QuartusController_Set_SLIDER_State( int Num , int NewState );
int QuartusController_Set_SLIDER_State_All( int NewState );	//�ꊇ

//�Q�b�^
//Quartus
//7�Z�O
int QuartusController_Get_SEVEN_SEGMENT_LED_Pattern( int Num , int PatternNum );
//�����_�C�I�[�h
//��
int QuartusController_Get_LEDRED_State( int Num );
//��
int QuartusController_Get_LEDGREEN_State( int Num );
//�v�b�V���{�^��
int QuartusController_Get_PUSH_BUTTON_State( int Num );
//�X���C�h�X�C�b�`
int QuartusController_Get_SLIDER_State( int Num );

//�X�V
int QuartusController_Update(void);

//�`��
int QuartusController_Draw(void);

#endif