#include "PlayAnim.h"
#include "../../MyLib/Input/Input.h"

int CPlayAnim::Key;
DINPUT_JOYSTATE CPlayAnim::input;		//�R���g���[���[���

CPlayAnim::CPlayAnim()
{
	Init();
}

//������
void CPlayAnim::Init()
{
	CBaseAnim::Init();
}

//���[�h
void CPlayAnim::Load()
{
	RequestLoop(ANIMID_WAIT, 0.5f);
}

//���[�v
void CPlayAnim::Loop()
{
	//�p�b�h�w��
	Key = GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

	//�A�j���[�V�����X�V
	UpdataAnim();
	//�A�j���[�V�����؂�ւ�
	AnimLoop();
	//�v���C���[�X�V
	Update();
}

//�X�V
void CPlayAnim::Update()
{
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetPosition(m_iHndl, m_vPos);

	//�v���C���[�̑傫����1/10��
	VECTOR scale = { 0.1f,0.1f,0.1f };
	MV1SetScale(m_iHndl, scale);
}

//���[�v�A�j������
void CPlayAnim::AnimLoop()
{
	//�e�������֐��|�C���^�ɓ����
	//�֐��|�C���^��錾���֐���PlayerAnim�z��ɓ����
	void (CPlayAnim:: * PlayerAnim[])() =
	{ &CPlayAnim::ExecWait,&CPlayAnim::ExecWalk,&CPlayAnim::ExecRun,&CPlayAnim::ExecSideWalk, &CPlayAnim::ExecTake };
	//id�ɍ��킹�ď��������s
	(this->*PlayerAnim[m_sAnimData.m_iID])();
}

//�ҋ@
void CPlayAnim::ExecWait()
{
	//���̂��Ƃ�
	if (CInput::IsInputDown(CInput::INPUT_TAKE) || (input.Buttons[0] > 0))
		Request(ANIMID_TAKE, 1.0f);

	//�O��ړ��L�[�������ꂽ��
	if (CInput::IsInputDown(CInput::INPUT_UP) || CInput::IsInputDown(CInput::INPUT_DOWN))
	{
		//�O�i+�V�t�g�L�[�ő���
		if (CInput::IsInputDown(CInput::INPUT_DASH) || (input.Buttons[4] > 0))
			RequestLoop(ANIMID_RUN, 0.5f);
		else
			RequestLoop(ANIMID_WALK, 0.5f);
	}
	else if ((input.Y < 0) || (input.Y > 0))
	{
		//�O�i+�V�t�g�L�[�ő���
		if (CInput::IsInputDown(CInput::INPUT_DASH) || (input.Buttons[4] > 0))
			RequestLoop(ANIMID_RUN, 0.5f);
		//�O�i�̂�
		else
			RequestLoop(ANIMID_WALK, 0.5f);
	}

	//�E�����܂��͍��������������
	if (CInput::IsInputDown(CInput::INPUT_LEFT) || CInput::IsInputDown(CInput::INPUT_RIGHT))
	{
		RequestLoop(ANIMID_SIDEWALK, 0.5f);
	}
	else if ((input.X < 0) || (input.X > 0))
	{
		RequestLoop(ANIMID_SIDEWALK, 0.5f);
	}
}

//����
void CPlayAnim::ExecWalk()
{
	//���̂����A�j���[�V����
	if (CInput::IsInputDown(CInput::INPUT_TAKE) || (input.Buttons[0] > 0))
		Request(ANIMID_TAKE, 1.0f);

	//�O��ړ��L�[
	if (CInput::IsInputDown(CInput::INPUT_UP) || CInput::IsInputDown(CInput::INPUT_DOWN))
	{
		//+�V�t�g�L�[�ő���
		if (CInput::IsInputDown(CInput::INPUT_DASH))
			RequestLoop(ANIMID_RUN, 0.5f);
	}
	if ((input.Y < 0) || (input.Y > 0))
	{
		//+�V�t�g�L�[�ő���
		if (input.Buttons[4] > 0)
			RequestLoop(ANIMID_RUN, 0.5f);
	}

	if (CInput::IsInputRelese(CInput::INPUT_UP) || CInput::IsInputRelese(CInput::INPUT_DOWN))
		RequestLoop(ANIMID_WAIT, 0.5f);

}

//����
void CPlayAnim::ExecRun()
{
	//���̂��Ƃ�
	if (CInput::IsInputDown(CInput::INPUT_TAKE) || (input.Buttons[0] > 0))
		Request(ANIMID_TAKE, 1.0f);

	//����̂���߂�
	if (CInput::IsInputRelese(CInput::INPUT_DASH))
		RequestLoop(ANIMID_WALK, 0.5f);

	//�ړ��L�[�𗣂���
	if (CInput::IsInputRelese(CInput::INPUT_UP) || CInput::IsInputRelese(CInput::INPUT_DOWN))
		RequestLoop(ANIMID_WAIT, 0.5f);

}

//���E�ړ�
void CPlayAnim::ExecSideWalk()
{
	//���̂��Ƃ�
	if (CInput::IsInputDown(CInput::INPUT_TAKE) || (input.Buttons[0] > 0))
		Request(ANIMID_TAKE, 1.0f);

	//���E�L�[�𗣂�
	if (CInput::IsInputRelese(CInput::INPUT_LEFT) || CInput::IsInputRelese(CInput::INPUT_RIGHT))
		RequestLoop(ANIMID_WAIT, 0.5f);

}

//�擾
void CPlayAnim::ExecTake()
{
	//�A�j���Đ����I�������
	if (m_sAnimData.m_bPlay == false)
		RequestLoop(ANIMID_WAIT, 0.5f);
}











