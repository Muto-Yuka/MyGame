#include <DxLib.h>
#include "SceneBase.h"
#include "../MyLib/Fade/Fade.h"
#include "../MyLib/Input/Input.h"
#include "../MyLib/Sound/Sound.h"

//������
void CSceneBase::Init()
{
	m_iHndl = -1;
	m_eSceneID = SCENE_LOAD;
}

//���[�h
void CSceneBase::Load()
{
	m_eSceneID = SCENE_STEP;
	CFade::GetInstance()->Request(4.0f, true);
}

//�X�e�b�v
void CSceneBase::Step()
{
	if (!CFade::GetInstance()->IsEnd()) return;

	//����{�^���Ŏ���
	if (CInput::IsInputPush(CInput::INPUT_NEXT))
	{
		CSound::AllStop();								//�T�E���h��~
		m_eSceneID = SCENE_EXIT;						//���̃V�[��
		CFade::GetInstance()->Request(4.0f, false);		//�t�F�[�h���N�G�X�g
	}
}

//�j��
void CSceneBase::Exit()
{
	if (!CFade::GetInstance()->IsEnd()) return;

	DeleteGraph(m_iHndl);
	CFade::DeleteInstance();

	m_eSceneID = SCENE_NEXT;
}

//����
void CSceneBase::Next()
{
	m_eSceneID = SCENE_INIT;
}


