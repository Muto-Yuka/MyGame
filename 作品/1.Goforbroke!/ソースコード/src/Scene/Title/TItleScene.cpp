#include <DxLib.h>
#include "TitleScene.h"
#include "../../MyLib/Input/Input.h"
#include "../../MyLib/Fade/Fade.h"
#include "../../MyLib/Sound/Sound.h"

static const char TITLE_PATH[] = { "data/Scene/Title/Title.png" };

CTitleScene::CTitleScene()
{
	Init();
}
CTitleScene::~CTitleScene()
{
	Exit();
	CFade::DeleteInstance();
}

//���[�v
bool CTitleScene::Loop()
{
	//�֐��|�C���^��錾���֐���z��ɓ����
	void (CTitleScene:: * Title[])() = {
		&CTitleScene::Init,& CTitleScene::Load,& CTitleScene::Step,& CTitleScene::Exit,& CTitleScene::Next
	};
	//id�ɍ��킹�ď��������s
	(this->*Title[m_eTitleID])();

	if (m_eTitleID == SCENE_NEXT)
		return true;
	else
		return false;
}

//������
void CTitleScene::Init()
{
	m_iHndl = -1;		
	m_eTitleID = SCENE_LOAD;
}

//���[�h
void CTitleScene::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = LoadGraph(TITLE_PATH);
	}
	CSound::Play(CSound::SOUND_TITLE, DX_PLAYTYPE_LOOP);
	m_eTitleID = SCENE_STEP;
	CFade::GetInstance()->Request(4.0f, true);
}

//�X�e�b�v
void CTitleScene::Step()
{
	if (!CFade::GetInstance()->IsEnd()) return;

	//����{�^���Ŏ���
	if (CInput::IsInputPush(CInput::INPUT_NEXT) || (CPadInput::PadInput & PAD_INPUT_8))
	{
		m_eTitleID = SCENE_EXIT;
		CFade::GetInstance()->Request(4.0f, false);
	}
}

//�`��
void CTitleScene::Draw()
{
	DrawGraph(0, 0, m_iHndl, true);
}

//�j��
void CTitleScene::Exit()
{
	if (!CFade::GetInstance()->IsEnd()) return;
	
	DeleteGraph(m_iHndl);

	m_eTitleID = SCENE_NEXT;
}

//����
void CTitleScene::Next()
{
	m_eTitleID = SCENE_INIT;
}


