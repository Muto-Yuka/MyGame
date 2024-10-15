#include <DxLib.h>
#include "Input.h"
#include "KeyInput/KeyInput.h"

std::vector<int> CInput::m_vKeyButton;
std::vector<int> CInput::m_vController;

//������
void CInput::Init()
{
	CKeyInput::InitInput();
	CPadInput::InitInput();

	//�L�[���̓Z�b�g
	m_vKeyButton.push_back(KEY_INPUT_A);		//���ړ�
	m_vKeyButton.push_back(KEY_INPUT_D);		//�E�ړ�
	m_vKeyButton.push_back(KEY_INPUT_W);		//�O�ړ�
	m_vKeyButton.push_back(KEY_INPUT_S);		//���ړ�
	m_vKeyButton.push_back(KEY_INPUT_LSHIFT);	//����
	m_vKeyButton.push_back(KEY_INPUT_E);		//���̂��Ƃ�
	m_vKeyButton.push_back(KEY_INPUT_RSHIFT);	//�Y�[��
	m_vKeyButton.push_back(KEY_INPUT_SPACE);	//�e������
	m_vKeyButton.push_back(KEY_INPUT_Q);		//�C������
	m_vKeyButton.push_back(KEY_INPUT_RETURN);	//����{�^��

	//�R���g���[���[�p
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_LEFT);		//���ړ�
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_RIGHT);		//�E�ړ�
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_UP);		//�O�ړ�
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_DOWN);		//���ړ�
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_9);		//����
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_9);		//���̂��Ƃ�
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_9);		//�Y�[��
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_9);		//�e������
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_9);		//�C������
	m_vController.push_back(CPadInput::PadInput & PAD_INPUT_9);		//����{�^��

}

//�X�V
void CInput::Update()
{
	CKeyInput::StepInput();
	CPadInput::StepInput();
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

	return CPadInput::IsPadDown(m_vController[key]);
}


