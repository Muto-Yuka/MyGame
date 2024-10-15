#pragma once

#include "../../Game/Camera/CameraManager.h"
#include "../../Game/shot/shotManager.h"
#include "../../Character/Enemy/EnemyManager.h"
#include "../../Game/Hit/Hit.h"
#include "../../Game/Screen/Screen.h"
#include "../../Game/Item/ItemManager.h"
#include "../../Game/Item/Apple/Apple.h"
#include "../../Game/Mission/Mission.h"
#include "../../Game/Field/FieldManager.h"

class CBaseScene 
{
protected:
	enum tagPLAY_SCENE {
		SCENE_INIT,		//������
		SCENE_LOAD,		//���[�h
		SCENE_AM_STEP,	//�ߑO�̏���
		SCENE_PM_STEP,	//�ߌ�̏���
		SCENE_EXIT,		//�j������
		SCENE_NEXT,		//����

	}m_eSceneID;

	CCameraManager	cCameraManager;	
	CPlayer			cPlayer;		
	ShotManager		cShotManager;
	CEnemyManager	cEnemyManager;
	CScreen			cScreen;
	CMission		cMission;
	CFieldManager	cFieldManager;
	CItemManager	cItemManager;

public:

	//�J��Ԃ��s������
	void Loop();
	//�`�揈��
	void Draw();


	//������
	void Init();
	//�I������
	void Exit();
	//�f�[�^���[�h
	void Load();
	//���t���[���Ăԏ���
	void AmStep();
	void PmStep();
	void Next();


	//�����蔻����܂Ƃ߂��֐�
	void Collision();


};



