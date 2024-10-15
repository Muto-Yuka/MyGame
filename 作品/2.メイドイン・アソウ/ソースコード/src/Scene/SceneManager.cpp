#include "SceneManager.h"
#include "../MyLib/Input/Input.h"
#include "../MyLib/Fade/Fade.h"
#include "../MyLib/Sound/Sound.h"

#include "Title/Title.h"
#include "Play/Play.h"
#include "Clear/Clear.h"
#include "GameOver/Gameover.h"

CSceneManager::CSceneManager()
{
	Init();
}
CSceneManager::~CSceneManager()
{
	//���������������
	delete cScene;

	Exit();
	CSound::Exit();
}

//������
void CSceneManager::Init()
{
	CSound::Init();
	CSound::AllLoad();

	cScene = new CTitle();
	m_eAllSceneID = SCENE_TITLE;
}

//���[�v
int CSceneManager::Loop()
{
	int iRet = 0;

	switch (m_eAllSceneID)
	{
	case SCENE_TITLE:
		if (cScene->Loop() == 1)
		{
			delete cScene;
			cScene = new CPlay();
			m_eAllSceneID = SCENE_PLAY;
		}
		break;
	case SCENE_OPERATION:
		//if (cOperation.Loop())
		//	m_eAllSceneID = SCENE_PLAY;
		break;

	case SCENE_PLAY:
		if (cScene->Loop() == 1)
		{	//�N���A
			delete cScene;
			cScene = new CClear();

			m_eAllSceneID = SCENE_CLEAR;
		}
		else if (cScene->Loop() == 2)
		{	//�Q�[���I�[�o�[
			delete cScene;
			cScene = new CGameover();
			m_eAllSceneID = SCENE_GAMEOVER;
		}
		break;

	case SCENE_CLEAR:
		cScene->Loop();
		break;

	case SCENE_GAMEOVER:
		cScene->Loop();
		break;
	}

	//�t�F�[�h�����̍X�V
	CFade::GetInstance()->UpDate();

	return iRet;
}

//�X�V�����E�`��
void CSceneManager::Draw()
{
	switch (m_eAllSceneID)
	{
	//�^�C�g��
	case SCENE_TITLE:
		cScene->Draw();
		break;

	//�������
	case SCENE_OPERATION:
		cScene->Draw();
		break;

	//�v���C
	case SCENE_PLAY:
		cScene->Draw();
		break;

	//�N���A
	case SCENE_CLEAR:
		cScene->Draw();
		break;

	//�Q�[���I�[�o-
	case SCENE_GAMEOVER:
		cScene->Draw();
		break;
	}

	//�t�F�[�h�֘A
	CFade::GetInstance()->Draw();

}

void CSceneManager::Exit()
{

}
