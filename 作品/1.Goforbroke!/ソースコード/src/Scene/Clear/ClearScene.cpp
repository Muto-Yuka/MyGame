#include <DxLib.h>
#include "ClearScene.h"
#include "../../MyLib/Fade/Fade.h"
#include "../../MyLib/Input/Input.h"
#include "../../MyLib/Sound/Sound.h"

static const char TITLE_PATH[] = { "data/Scene/result/result.png" };

CClearScene::CClearScene()
{
	Init();
}
CClearScene::~CClearScene()
{
	Exit();
	CFade::DeleteInstance();

}

//���[�v
bool CClearScene::Loop()
{
	//�֐��|�C���^��錾���֐���z��ɓ����
	void (CClearScene:: * Clear[])() = {
		&CClearScene::Init,& CClearScene::Load,& CClearScene::Step,& CClearScene::Exit,& CClearScene::Next
	};
	//id�ɍ��킹�ď��������s
	(this->*Clear[m_eClearID])();

	if (m_eClearID == SCENE_NEXT)
		return true;
	else
		return false;

}

//������
void CClearScene::Init()
{
	m_iHndl = -1;	
	m_eClearID = SCENE_LOAD;
}

//���[�h
void CClearScene::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = LoadGraph(TITLE_PATH);
	}
	m_eClearID = SCENE_STEP;
	CFade::GetInstance()->Request(4.0f, true);

}

//�X�e�b�v
void CClearScene::Step()
{
	if (!CFade::GetInstance()->IsEnd()) 
		return;

	CSound::Play(CSound::SOUND_CLEAR, DX_PLAYTYPE_NORMAL);

	if (!CSound::IsPlay(CSound::SOUND_CLEAR))
	{
		m_eClearID = SCENE_EXIT;
		CFade::GetInstance()->Request(4.0f, false);

	}
}

//�`��
void CClearScene::Draw()
{
	DrawGraph(0, 0, m_iHndl, true);
}

//�j��
void CClearScene::Exit()
{
	CFade::DeleteInstance();

	DeleteGraph(m_iHndl);
	CSound::AllStop();

	m_eClearID = SCENE_NEXT;
}

//����
void CClearScene::Next()
{
	m_eClearID = SCENE_INIT;
}




