#include <DxLib.h>
#include "Gameover.h"
#include "../../MyLib/Fade/Fade.h"
#include "../../MyLib/Input/Input.h"
#include "../../MyLib/Sound/Sound.h"

static const char GAMEOVER_PATH[] = { "data/Scene/Gameover/Gameover.png" };

CGameover::CGameover()
{
	Init();
}
CGameover::~CGameover()
{
	Exit();
	CFade::DeleteInstance();
}

//���[�v
int CGameover::Loop()
{
	//�֐��|�C���^��錾���֐���z��ɓ����
	void (CGameover:: * Operation[])() = {
		&CGameover::Init,& CGameover::Load,& CGameover::Step,& CGameover::Exit, & CGameover::Next
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
void CGameover::Init()
{
	CSceneBase::Init();
}

//���[�h
void CGameover::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = LoadGraph(GAMEOVER_PATH);
	}
	CSound::Play(CSound::SOUND_GAMEOVER, DX_PLAYTYPE_BACK, true);

	CSceneBase::Load();
}

//�X�e�b�v
void CGameover::Step()
{
	//CSceneBase::Step();
}

//�`��
void CGameover::Draw()
{
	DrawGraph(0, 0, m_iHndl, true);
}

//�j��
void CGameover::Exit()
{
	CSceneBase::Exit();
}

//����
void CGameover::Next()
{
	CSceneBase::Next();
}


