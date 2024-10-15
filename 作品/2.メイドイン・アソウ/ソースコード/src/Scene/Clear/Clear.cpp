#include <DxLib.h>
#include "Clear.h"
#include "../../MyLib/Fade/Fade.h"
#include "../../MyLib/Input/Input.h"
#include "../../MyLib/Sound/Sound.h"

static const char CLEAR_PATH[] = { "data/Scene/Clear/Clear.png" };

CClear::CClear()
{
	Init();
}
CClear::~CClear()
{
	Exit();
	CFade::DeleteInstance();
}

//���[�v
int CClear::Loop()
{
	//�֐��|�C���^��錾���֐���z��ɓ����
	void (CClear:: * Operation[])() = {
		&CClear::Init,& CClear::Load,& CClear::Step,& CClear::Exit, & CClear::Next
	};
	//id�ɍ��킹�ď��������s
	(this->*Operation[m_eSceneID])();

	if (m_eSceneID == SCENE_NEXT)
	{
		CSound::AllStop();
		return 1;
	}

	return -1;
}

//������
void CClear::Init()
{
	CSceneBase::Init();
}

//���[�h
void CClear::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = LoadGraph(CLEAR_PATH);
	}
	CSound::Play(CSound::SOUND_CLEAR, DX_PLAYTYPE_BACK, true);

	CSceneBase::Load();
}

//�X�e�b�v
void CClear::Step()
{
	//CSceneBase::Step();
}

//�`��
void CClear::Draw()
{
	DrawGraph(0, 0, m_iHndl, true);
}

//�j��
void CClear::Exit()
{
	CSceneBase::Exit();
}

//����
void CClear::Next()
{
	CSceneBase::Next();
}


