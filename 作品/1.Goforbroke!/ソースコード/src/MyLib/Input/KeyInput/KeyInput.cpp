#include <Dxlib.h>
#include "KeyInput.h"

static const int  KEY_BUF_LEN = (256);

//���݂̃t���[���̃L�[���
char currentKeyBuf[KEY_BUF_LEN] = { 0 };
//�O�t���[���̃L�[���
char preKeyBuf[KEY_BUF_LEN] = { 0 };

//������
void CKeyInput::InitInput()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currentKeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}

//�X�e�b�v
void CKeyInput::StepInput()
{
	//�O�t���[���̃L�[���ϐ��ɋL�^���Ă���
	for (int index = 0; index < KEY_BUF_LEN; index++)
		preKeyBuf[index] = currentKeyBuf[index];

	//���݂̃L�[�����擾
	GetHitKeyStateAll(currentKeyBuf);
}

//�������ꂽ��
bool CKeyInput::IsKeyPush(int key_code)
{
	//�O�t���ŉ�����ĂȂ��@���@���t���ŉ�����Ă���
	if (preKeyBuf[key_code] == 0 && currentKeyBuf[key_code] == 1)
		return true;

	return false;
}

//�����������Ă��邩
bool CKeyInput::IsKeyKeep(int key_code)
{
	//�O�t���ŉ�����Ă���@���@���t���ŉ�����Ă���
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 1)
		return true;

	return false;
}

//�������������ꂽ��
bool CKeyInput::IsKeyRelese(int key_code)
{
	//�O�t���ŉ�����Ă���@���@���t���ŉ�����Ă��Ȃ�
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 0)
		return true;

	return false;
}

//�P���ɉ�����Ă��邩
bool CKeyInput::IsKeyDown(int key_code)
{
	//���t���ŉ�����Ă���i�O�t���̏�Ԃ͊֌W�Ȃ��j
	if (currentKeyBuf[key_code] == 1)
		return true;

	return false;
}

