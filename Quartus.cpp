#include "DxLib.h"
#include "Quartus.h"

//������
int Quartus_Initialize( int WindowX , int WindowY , s_Quartus* QuartusStatus )
{
	//�E�B���h�E�T�C�Y
	WindowSizeX = WindowX;
	WindowSizeY = WindowY;

	//���O
	strcpy( QuartusStatus->Name , "ALTERALike" );
	//�t�H���g�n���h��
	QuartusStatus->FontHandle = CreateFontToHandle( "Title" , BLOCK_32 * 3 , 7 , DX_FONTTYPE_NORMAL );
	//���O�\���ʒu
	QuartusStatus->NameX = BLOCK_32 * 2;	QuartusStatus->NameY = BLOCK_32 * 2;
	//�F
	QuartusStatus->NameColor = GetColor( 255 , 255 , 255 );

	//��ʒu
	int X = BLOCK_32 * 3;	int Y = BLOCK_32 * 8;

	//7�Z�O�����gLED
	//�傫��
	int SizeX = 30;	int SizeY = 62;
	//�Ԋu,�c��L�x(�����I�ɐ�L���Ă�c�̑傫��)
	int space = BLOCK_32;	int OccupatedY = 64;
	//�J�n�_
	int OX = X + ( BLOCK_32 - SizeX ) / 2;
	int OY = Y + ( BLOCK_32*2 - SizeY ) / 2;
	//�ݒ�
	for( int i = 0 ; i < QUARTUS_SEVENSEG_NUM ; i++ )
	{
		//�F
		//�_����
		QuartusStatus->SevenSeg[i].OnColor = GetColor( 255 , 128 , 0 );
		//������
		QuartusStatus->SevenSeg[i].OffColor = GetColor( 128 , 128 , 128 );
		//�p�^�[��
		//�S���_��
		for( int j = 0 ; j < SEVEN_SEG_LED_NUM ; j++ )
		{
			QuartusStatus->SevenSeg[i].Pattern[j] = 1;
		}
		//�傫��
		QuartusStatus->SevenSeg[i].Size.x = SizeX;
		QuartusStatus->SevenSeg[i].Size.y = SizeY;
		//�ʒu
		if( i == 0 )	//�����ʒu
		{
			//��ԍ��ɗ���7�Z�O�̈ʒu
			QuartusStatus->SevenSeg[i].Position.x = OX;
			QuartusStatus->SevenSeg[i].Position.y = OY;
		}
		else	//�����ʒu�ȊO
		{
			//�Ԃ�傫�������ꍇ
			int ext;
			if( i == 2 || i == 4 )
			{
				ext = 2;
			}
			else
			{
				ext = 1;
			}
			QuartusStatus->SevenSeg[i].Position.x = QuartusStatus->SevenSeg[i-1].Position.x + space * ext;
			QuartusStatus->SevenSeg[i].Position.y = OY;
		}
	}

	//LED
	//�傫��
	SizeX = 10;	SizeY = 10;
	//�Ԋu
	space = (BLOCK_32 - SizeX * 2) / 4; 
	//�J�n�_
	OX = X + space;
	OY = Y + OccupatedY + (BLOCK_32 - SizeY) / 2;
	//�c��L�x(�����I�ɐ�L���Ă�c�̑傫��)
	OccupatedY += 32;
	//�ݒ�
	//��
	for( int i = 0 ; i < QUARTUS_LEDRED_NUM ; i++ )
	{
		QuartusStatus->LEDRed[ i ].State = 1;	//���:ON
		
		QuartusStatus->LEDRed[ i ].Color = GetColor( 255 , 0 , 0 );	//�F
		QuartusStatus->LEDRed[ i ].OffColor = GetColor( 128 , 128 , 128 ); //OFF��
		//�傫��
		QuartusStatus->LEDRed[ i ].Size.x = SizeX;
		QuartusStatus->LEDRed[ i ].Size.y = SizeY;
		//�ʒu
		if( i == 0 )
		{
			QuartusStatus->LEDRed[ i ].Position.x = OX;
			QuartusStatus->LEDRed[ i ].Position.y = OY;
		}
		else
		{
			QuartusStatus->LEDRed[ i ].Position.x = QuartusStatus->LEDRed[ i-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->LEDRed[ i ].Position.y = OY;
		}
	}
	//��
	for( int i = 0 ; i < QUARTUS_LEDGREEN_NUM ; i++ )
	{
		QuartusStatus->LEDGreen[i].State = 1;	//���:ON
		
		QuartusStatus->LEDGreen[i].Color = GetColor( 0 , 255 , 0 );	//�F
		QuartusStatus->LEDGreen[i].OffColor = GetColor( 128 , 128 , 128 );	//OFF��
		//�傫��
		QuartusStatus->LEDGreen[ i ].Size.x = SizeX;
		QuartusStatus->LEDGreen[ i ].Size.y = SizeY;
		
		//�ʒu
		if( i == 0 )
		{
			QuartusStatus->LEDGreen[ i ].Position.x = QuartusStatus->LEDRed[ QUARTUS_LEDRED_NUM-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->LEDGreen[ i ].Position.y = OY;
		}
		else
		{
			QuartusStatus->LEDGreen[ i ].Position.x = QuartusStatus->LEDGreen[ i-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->LEDGreen[ i ].Position.y = OY;
		}
	}

	//�X���C�h�X�C�b�`
	//�傫��
	SizeX = 12;	SizeY = 30;
	//�Ԋu
	space = (BLOCK_32 - SizeX * 2) / 4;
	//�J�n�_
	OX = X + space;
	OY = Y + OccupatedY + ( BLOCK_32 * 2 - SizeY ) / 2;
	//�c��L�x(�X�V����)
	//OccupatedY += 32;
	//�ݒ�
	for( int i = 0 ; i < QUARTUS_SLIDER_NUM ; i++ )
	{
		//���(�S������)
		QuartusStatus->Slider[ i ].State = 0;
		//�傫��
		QuartusStatus->Slider[ i ].Size.x = SizeX;
		QuartusStatus->Slider[ i ].Size.y = SizeY;
		//�ʒu
		if( i == 0 )
		{
			QuartusStatus->Slider[ i ].Position.x = OX;
			QuartusStatus->Slider[ i ].Position.y = OY;
		}
		else
		{
			QuartusStatus->Slider[ i ].Position.x = QuartusStatus->Slider[ i-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->Slider[ i ].Position.y = OY;
		}
	}

	
	//�v�b�V���{�^��
	//�傫��
	SizeX = 30;	SizeY = 30;
	//�Ԋu
	space = (BLOCK_32 - SizeX) / 2;
	//�J�n�_
//	OX = X + QuartusStatus->LEDGreen[ 0 ].Position.x + space;
	OX = X + space;
	OY = Y + OccupatedY + ( BLOCK_32 * 2 - SizeY ) / 2;
	//�ݒ�
	for( int i = 0 ; i < QUARTUS_PUSHBUTTON_NUM ; i++ )
	{
		//���(�S��������Ă��Ȃ�)
		QuartusStatus->PushButton[i].State = 0;
		//�傫��
		QuartusStatus->PushButton[ i ].Size.x = SizeX;
		QuartusStatus->PushButton[ i ].Size.y = SizeY;
		//�ʒu
		if( i == 0 )
		{
			QuartusStatus->PushButton[ i ].Position.x = QuartusStatus->Slider[ QUARTUS_SLIDER_NUM-1 ].Position.x + BLOCK_32 / 2 + space;
			QuartusStatus->PushButton[ i ].Position.y = OY;
		}
		else
		{
			QuartusStatus->PushButton[ i ].Position.x = QuartusStatus->PushButton[ i-1 ].Position.x + SizeX + space * 2;
			QuartusStatus->PushButton[ i ].Position.y = OY;
		}
	}

	return (0);
}

//�`��
//�f�q�݂̂�\��
//7�Z�O�����gLED
/*
	�����`�ɉ�����7�{��������
*/
int Quartus_Draw_SEVEN_SEGMENT_LED( int PosX , int PosY , int SizeX , int SizeY , int OnColor , int OffColor , int Pattern[] )
{
	//7�Z�O�̐��̑���
	//����/8 + 1
	int w;
	if( SizeX < SizeY )
	{
		w = SizeX/8;
	}
	else
	{
		w = SizeY/8;
	}
	w += 1;

	//�\��������W
	//����
	int x1[] = 
	{ 
		PosX+w ,		//0
		PosX+SizeX-w ,	//1
		PosX+SizeX-w ,	//2
		PosX+w ,	//3
		PosX ,			//4
		PosX ,			//5
		PosX+w			//6
	};
	int y1[] =
	{
		PosY ,				//0
		PosY+w ,			//1
		PosY+SizeY/2+w/2 ,	//2
		PosY+SizeY-w ,	//3
		PosY+SizeY/2+w/2 ,			//4
		PosY+w ,	//5
		PosY+SizeY/2-w/2	//6
	};
	//�E��
	int x2[] =
	{
		PosX+SizeX-w-1 ,	//0
		PosX+SizeX-1 ,		//1
		PosX+SizeX-1	,	//2
		PosX+SizeX-w-1 ,		//3
		PosX+w-1 ,			//4
		PosX+w-1 ,			//5
		PosX+SizeX-w-1		//6
	};
	int y2[] =
	{
		PosY+w-1 ,				//0
		PosY+SizeY/2-w/2-1 ,	//1
		PosY+SizeY-w-1 ,		//2
		PosY+SizeY-1 ,		//3
		PosY+SizeY-w-1 ,		//4
		PosY+SizeY/2-w/2-1 ,	//5
		PosY+SizeY/2+w/2-1		//6
	};

	//�ԋp�l
	int rtn = 0;

	//�`��
	for( int i = 0 ; i < 7 ; i++ )
	{
		int cr;	//�\������Ƃ��̐F
		if( Pattern[i] == 0 )
		{
			cr = OffColor;
		}
		else
		{
			cr = OnColor;
		}

		//�\��
		int tmp;
		tmp = DrawBox( x1[i] , y1[i] , x2[i] , y2[i] , cr , TRUE );

		rtn += tmp;
	}

	return (rtn);	//0:�S�Đ������`��ł��� 0�ȊO:�ǂ�����������
}
//�����_�C�I�[�h
/*
	�l�p���w��̐F�ŕ\��
*/
int Quartus_Draw_LED( int PosX , int PosY , int SizeX , int SizeY , int Color )
{
	int rtn = DrawBox( PosX , PosY , PosX+SizeX-1 , PosY+SizeY-1 , Color , TRUE );

	return (rtn);
}
//�v�b�V���{�^��
/*
	�l�p�̏�Ɋۂ�\��
	�������܂�Ă���Ƃ��͎��͒�����
	������Ă��Ȃ��Ƃ��͓h��Ԃ�
*/
int Quartus_Draw_PUSH_BUTTON( int PosX , int PosY , int Size , int State )
{
	//�Ԃ�l
	int rtn;
	//�l�p��\��
	//�v�Z
	int x1 = PosX;
	int y1 = PosY;
	int x2 = PosX+Size-1;
	int y2 = PosY+Size-1;
	int cr = GetColor( 128 , 128 , 128 );
	//�\��
	rtn = DrawBox( x1 , y1 , x2 , y2 , cr , TRUE );
	//�ۂ���ڂ�����
	//�v�Z
	x1 = PosX+(int)(Size/2)-1;
	y1 = PosY+(int)(Size/2)-1;
	x2 = (int)(Size/2)-1;	//���a
	y2 = State == 0 ? FALSE : TRUE ;	//�h��Ԃ����ۂ�
	cr = GetColor( 64 , 255 , 255 );
	//�\��
	rtn += DrawCircle( x1 , y1 , x2 , cr , y2 );

	//�ԋp
	return (rtn);
}
//�X���C�h�X�C�b�`
/*
	�l�p���c��2���ׂ�
	State == 0 �Ȃ�΁@�オ�h��Ԃ�����
*/
int Quartus_Draw_SLIDER( int PosX , int PosY , int SizeX , int SizeY , int State )
{
	//�ԋp�l
	int rtn;

	//�㑤�̎l�p
	//�v�Z
	int x1 = PosX;
	int y1 = PosY;
	int x2 = PosX+SizeX-1;
	int y2 = PosY+(int)(SizeY/2)-1;
	int cr = GetColor( 128 , 128 , 128 );
	int fl = State == 0 ? FALSE : TRUE ;	//�h��Ԃ����ۂ�
	//�\��
	rtn = DrawBox( x1 , y1 , x2 , y2 , cr , fl );
	//�����̎l�p
	//�v�Z
	//x1�͕ύX�Ȃ�
	y1 = y2+2;
	//x2�͕ύX�Ȃ�
	y2 = PosY + SizeY;
	//cr�͕ύX�Ȃ�
	fl = State == 0 ? TRUE : FALSE ;	//�������t���܂ɂ���
	//�\��
	rtn += DrawBox( x1 , y1 , x2 , y2 , cr , fl );

	//�ԋp 
	return (rtn);
}

//Quatus�Ȋ����ŕ\��
int Quartus_Draw( s_Quartus QuartusStatus )
{
	//�w�i���(#000080)�œh��Ԃ�
	DrawBox( 0 , 0 , WindowSizeX-1 , WindowSizeY-1 , GetColor( 0 , 0 , 128 ) , TRUE );

	//���O(�^�C�g��)��\��
	DrawFormatStringToHandle( QuartusStatus.NameX , QuartusStatus.NameY , QuartusStatus.NameColor , QuartusStatus.FontHandle , "%s" , QuartusStatus.Name );

	//�e�f�q��`��
	//7�Z�O
	for( int i = 0 ; i < QUARTUS_SEVENSEG_NUM ; i++ )
	{
		Quartus_Draw_SEVEN_SEGMENT_LED( QuartusStatus.SevenSeg[i].Position.x , QuartusStatus.SevenSeg[i].Position.y , 
			QuartusStatus.SevenSeg[i].Size.x , QuartusStatus.SevenSeg[i].Size.y , 
			QuartusStatus.SevenSeg[i].OnColor , QuartusStatus.SevenSeg[i].OffColor , 
			QuartusStatus.SevenSeg[i].Pattern );
	}

	//LED
	//��
	for( int i = 0 ; i < QUARTUS_LEDRED_NUM ; i++ )
	{
		int Color;
		if( QuartusStatus.LEDRed[i].State != 0 )
		{
			Color = QuartusStatus.LEDRed[i].Color;
		}
		else
		{
			Color = QuartusStatus.LEDRed[i].OffColor;
		}
		Quartus_Draw_LED( QuartusStatus.LEDRed[i].Position.x , QuartusStatus.LEDRed[i].Position.y , 
			QuartusStatus.LEDRed[i].Size.x , QuartusStatus.LEDRed[i].Size.y ,
			Color );
	}
	//��
	for( int i = 0 ; i < QUARTUS_LEDGREEN_NUM ; i++ )
	{
		int Color;
		if( QuartusStatus.LEDGreen[i].State != 0 )
		{
			Color = QuartusStatus.LEDGreen[i].Color;
		}
		else
		{
			Color = QuartusStatus.LEDGreen[i].OffColor;
		}
		Quartus_Draw_LED( QuartusStatus.LEDGreen[i].Position.x , QuartusStatus.LEDGreen[i].Position.y , 
			QuartusStatus.LEDGreen[i].Size.x , QuartusStatus.LEDGreen[i].Size.y ,
			Color );
	}

	//�X���C�h�X�C�b�`	
	for( int i = 0 ; i < QUARTUS_SLIDER_NUM ; i++ )
	{
		Quartus_Draw_SLIDER( QuartusStatus.Slider[i].Position.x , QuartusStatus.Slider[i].Position.y , 
			QuartusStatus.Slider[i].Size.x , QuartusStatus.Slider[i].Size.y , 
			QuartusStatus.Slider[i].State );
	}

	//�v�b�V���{�^��	
	for( int i = 0 ; i < QUARTUS_PUSHBUTTON_NUM ; i++ )
	{
		Quartus_Draw_PUSH_BUTTON( QuartusStatus.PushButton[i].Position.x , QuartusStatus.PushButton[i].Position.y , 
			QuartusStatus.PushButton[i].Size.x , 
			QuartusStatus.PushButton[i].State );
	}

	return (0);
}

//�Z�b�^
//7�Z�O�����gLED
//�_���p�^�[��
int Quartus_Set_SEVEN_SEGMENT_LED_Pattern( int Num , int NewPattern[] , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_SEVENSEG_NUM )
	{
		return (-1);
	}
	int cnt = 0;
	for( int i = 0 ; i < SEVEN_SEG_LED_NUM ; i++ )
	{
		QuartusStatus->SevenSeg[ Num ].Pattern[ i ] = NewPattern[ i ];
		cnt += QuartusStatus->SevenSeg[ Num ].Pattern[ i ];
	}

	return (cnt);
}
//�����_�C�I�[�h
//ON/OFF
//��
int Quartus_Set_LEDGREEN_State( int Num , int NewState , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_LEDGREEN_NUM )
	{
		return (-1);
	}
	int rtn;
	QuartusStatus->LEDGreen[Num].State = NewState;

	rtn = QuartusStatus->LEDGreen[Num].State;

	return (rtn);
}
//��
int Quartus_Set_LEDRED_State( int Num , int NewState , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_LEDRED_NUM )
	{
		return (-1);
	}
	int rtn;
	QuartusStatus->LEDRed[Num].State = NewState;

	rtn = QuartusStatus->LEDRed[Num].State;

	return (rtn);
}
//�v�b�V���{�^��
//���
int Quartus_Set_PUSH_BUTTON_State( int Num , int NewState , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_PUSHBUTTON_NUM )
	{
		return (-1);
	}
	int rtn;
	QuartusStatus->PushButton[Num].State = NewState;

	rtn = QuartusStatus->PushButton[Num].State;

	return (rtn);
}
//�X���C�h�X�C�b�`
//���
int Quartus_Set_SLIDER_State( int Num , int NewState , s_Quartus* QuartusStatus )
{
	if( Num < 0 || Num > QUARTUS_SLIDER_NUM )
	{
		return (-1);
	}
	int rtn;
	QuartusStatus->Slider[Num].State = NewState;

	rtn = QuartusStatus->Slider[Num].State;

	return (rtn);
}

//�Q�b�^
//define
int Quartus_Get_QUARTUS_NAME_MAX( void )
{
	return (QUARTUS_NAME_MAX);
}
int Quartus_Get_QUARTUS_SEVENSEG_NUM( void )
{
	return (QUARTUS_SEVENSEG_NUM);
}
int Quartus_Get_QUARTUS_LEDRED_NUM( void )
{
	return (QUARTUS_LEDRED_NUM);
}
int Quartus_Get_QUARTUS_LEDGREEN_NUM( void )
{
	return (QUARTUS_LEDGREEN_NUM);
}
int Quartus_Get_QUARTUS_PUSHBUTTON_NUM( void )
{
	return (QUARTUS_PUSHBUTTON_NUM);
}
int Quartus_Get_QUARTUS_SLIDER_NUM( void )
{
	return (QUARTUS_SLIDER_NUM);
}
int Quartus_Get_SEVEN_SEG_LED_NUM( void )
{
	return (SEVEN_SEG_LED_NUM);
}
int Quartus_Get_BLOCK_32( void )
{
	return (BLOCK_32);
}