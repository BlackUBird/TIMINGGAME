#ifndef QUARTUS_H
#define QUARTUS_H

//32*32�̃}�X
#define BLOCK_32 (32)

//�E�B���h�E�̑傫��
static int WindowSizeX;
static int WindowSizeY;

//�ʒu
typedef struct ts_Position
{
	int x;
	int y;
} s_Position;
//�傫��
typedef struct ts_Size
{
	int x;
	int y;
} s_Size;

//Quartus--------------------------------------------------------
//7�Z�O�����g
#define SEVEN_SEG_LED_NUM (7)
typedef struct
{
	int Pattern[ SEVEN_SEG_LED_NUM ];	//�����p�^�[��
	int OnColor;	//�_�����̐F
	int OffColor;	//�������̐F
	s_Position Position;	//�ʒu
	s_Size Size;	//�傫��
} s_SevenSeg;

//�����_�C�I�[�h
typedef struct ts_LED
{
	int Color;
	int OffColor;
	int State;	//���
	s_Position Position;	//�ʒu
	s_Size Size;	//�傫��
} s_LED;

//�v�b�V���{�^��
typedef struct ts_PushButton
{
	int State;	// 0:������Ă��Ȃ��@0�ȊO:������Ă���
	s_Position Position;	//�ʒu
	s_Size Size;	//�傫��(x�̂ݗL��)
} s_PushButton;

//�X���C�h�X�C�b�`
typedef struct ts_Slider
{
	int State;	//���(0:���� 0�ȊO:�㑤)
	s_Position Position;	//�ʒu
	s_Size Size;	//�傫��
} s_Slider;

//Quartus�p�\����
#define QUARTUS_NAME_MAX (30)
#define QUARTUS_SEVENSEG_NUM (8)
#define QUARTUS_LEDRED_NUM (18)
#define QUARTUS_LEDGREEN_NUM (8)
#define QUARTUS_PUSHBUTTON_NUM (4)
#define QUARTUS_SLIDER_NUM (18)
typedef struct ts_Quartus
{
	//��{���
	char Name[ QUARTUS_NAME_MAX ];	//���O
	int FontHandle;	//���O�p�̃t�H���g�̃n���h��
	int NameX,NameY;	//���O�\���ʒu
	int NameColor;	//�F

	//�f�q
	s_SevenSeg SevenSeg[ QUARTUS_SEVENSEG_NUM ];		// 7�Z�O
	s_LED LEDRed[ QUARTUS_LEDRED_NUM ];					// ��LED
	s_LED LEDGreen[ QUARTUS_LEDGREEN_NUM ];				// ��LED
	s_PushButton PushButton[ QUARTUS_PUSHBUTTON_NUM ];	// �v�b�V���{�^��
	s_Slider Slider[ QUARTUS_SLIDER_NUM ];				// �X���C�h�X�C�b�`
} s_Quartus;
//--------------------------------------------------------------------


//������
int Quartus_Initialize( int WindowX , int WindowY , s_Quartus* QuartusStatus );

//�`��
//�f�q�݂̂�\��
int Quartus_Draw_SEVEN_SEGMENT_LED( int PosX , int PosY , int SizeX , int SizeY , int OnColor , int OffColor , int Pattern[] );	//7�Z�O�����gLED
int Quartus_Draw_LED( int PosX , int PosY , int SizeX , int SizeY , int Color );	//�����_�C�I�[�h
int Quartus_Draw_PUSH_BUTTON( int PosX , int PosY , int Size , int State );	//�v�b�V���{�^��
int Quartus_Draw_SLIDER( int PosX , int PosY , int SizeX , int SizeY , int State );	//�X���C�h�X�C�b�`
//Quatus�Ȋ����ŕ\��
int Quartus_Draw( s_Quartus QuartusStatus );

//�Z�b�^
//7�Z�O�����gLED
int Quartus_Set_SEVEN_SEGMENT_LED_Pattern( int Num , int NewPattern[] , s_Quartus* QuartusStatus );	//�_���p�^�[��
//�����_�C�I�[�h
int Quartus_Set_LEDRED_State( int Num , int NewState , s_Quartus* QuartusStatus );	//ON/OFF
int Quartus_Set_LEDGREEN_State( int Num , int NewState , s_Quartus* QuartusStatus );	//ON/OFF
//�v�b�V���{�^��
int Quartus_Set_PUSH_BUTTON_State( int Num , int NewState , s_Quartus* QuartusStatus );	//���
//�X���C�h�X�C�b�`
int Quartus_Set_SLIDER_State( int Num , int NewState , s_Quartus* QuartusStatus );	//���

//�Q�b�^
//define
int Quartus_Get_QUARTUS_NAME_MAX( void );
int Quartus_Get_QUARTUS_SEVENSEG_NUM( void );
int Quartus_Get_QUARTUS_LEDRED_NUM( void );
int Quartus_Get_QUARTUS_LEDGREEN_NUM( void );
int Quartus_Get_QUARTUS_PUSHBUTTON_NUM( void );
int Quartus_Get_QUARTUS_SLIDER_NUM( void );
int Quartus_Get_SEVEN_SEG_LED_NUM( void );
int Quartus_Get_BLOCK_32( void );

#endif