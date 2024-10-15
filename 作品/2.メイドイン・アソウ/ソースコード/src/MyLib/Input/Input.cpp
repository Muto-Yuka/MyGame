#include <DxLib.h>
#include "Input.h"
#include "KeyInput/KeyInput.h"

std::vector<int> CInput::m_vKeyButton;

//������
void CInput::Init()
{
	CKeyInput::InitInput();

	//�L�[���̓Z�b�g
	m_vKeyButton.push_back(KEY_INPUT_A);		//���ړ�
	m_vKeyButton.push_back(KEY_INPUT_D);		//�E�ړ�
	m_vKeyButton.push_back(KEY_INPUT_W);		//��ړ�
	m_vKeyButton.push_back(KEY_INPUT_S);		//���ړ�
	m_vKeyButton.push_back(KEY_INPUT_SPACE);	//�ړ��ȊO
	m_vKeyButton.push_back(KEY_INPUT_R);	//���X�|�[��

	m_vKeyButton.push_back(KEY_INPUT_RETURN);	//����{�^��
	m_vKeyButton.push_back(KEY_INPUT_ESCAPE);	//����{�^��

}

//�X�V
void CInput::Update()
{
	CKeyInput::StepInput();
}

//�������ꂽ�@
bool CInput::IsInputPush(int key)
{
	return CKeyInput::IsKeyPush(m_vKeyButton[key]);
}

//�����������Ă��邩
bool CInput::IsInputKeep(int key)
{
	return CKeyInput::IsKeyKeep(m_vKeyButton[key]);
}

//�������������ꂽ��
bool CInput::IsInputRelese(int key)
{
	return CKeyInput::IsKeyRelese(m_vKeyButton[key]);
}

//�P���ɉ�����Ă��邩
bool CInput::IsInputDown(int key)
{
	return CKeyInput::IsKeyDown(m_vKeyButton[key]);

}


