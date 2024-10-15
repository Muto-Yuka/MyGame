#include "FieldManager.h"

//������
void CFieldManager::Init()
{
	cGround.Init();
	cSky.Init();
}

//���[�h
void CFieldManager::Load()
{
	m_eSceneID = SCENE_AM;

	cGround.Load();
	cSky.Load();
}

//���[�v
void CFieldManager::Loop()
{
	cGround.Loop();
	cSky.Loop();
}

//�`��
void CFieldManager::Draw(int m_eSceneID)
{
	cGround.Draw();

	switch (m_eSceneID)
	{
	case SCENE_AM:
		cSky.AmDraw();
		break;

	case SCENE_PM:
		cSky.PmDraw();
		break;
	}
}

//�j��
void CFieldManager::Exit()
{
	cGround.Exit();
	cSky.Exit();
}





