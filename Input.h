#ifndef INPUT_H
#define INPUT_H

#define KEY_MAX (256)

//�L�[���͊֘A
typedef struct ts_Key
{
	char StateBuf[ KEY_MAX ];	//�S�ẴL�[�̉�����Ԃ��i�[����o�b�t�@
} s_Key;
//�}�E�X�֘A
typedef struct ts_Mouse
{
	int Button;	//�N���b�N���ꂽ�{�^���̎�ނ��i�[
	int ClickX, ClickY;	//�N���b�N���ꂽ�ꏊ���i�[
	int LogType;	//�{�^�����u�����ꂽ�vor�u�����ꂽ�v�̏����i�[
	int LogDelete;	//���O���(�}�E�X�̓��͏��)���폜���邩

	int WheelRot;	//�z�C�[���̉�]��
} s_Mouse;
//���͏��
typedef struct ts_InputInfo
{
	s_Key Key;	//�L�[����
	s_Mouse Mouse;	//�}�E�X����
} s_InputInfo;

static s_InputInfo InputInfo;

//�X�V
int Input_Update_Key(void);		//�L�[
int Input_Update_Mouse(void);	//�}�E�X
int Input_Update_All(void);	//�S��


//�Q�b�^
//�L�[����
//�S�ẴL�[�̉�����Ԃ��擾
int Input_Get_Key_State_All(void);
//����̃L�[�̉�����Ԃ��擾
int Input_Get_Key_State( int KeyCode );

#endif