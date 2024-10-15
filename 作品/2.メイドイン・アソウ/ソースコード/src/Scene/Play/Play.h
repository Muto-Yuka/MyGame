#pragma once
#include "../tagStage.h"
#include "../../Game/GameBase.h"
#include "../SceneBase.h"
#include "../../MyLib/Fade/Fade.h"

class CGameBase;

class CPlay : public CSceneBase
{
	enum tagPlay
	{
		STATEID_INIT,
		STATEID_LOAD,
		STATEID_STEP,
		STATEID_FIN,

		STATEID_NUM
	};

	CGameBase* m_base;			//�e�V�[���i�[
	int m_ePlayID;				//���݂̏�� init~Exit
	int m_next;					//�V�[�����֐��|�C���^�ŊǗ�(�X�e�[�W�Ǘ�)
	int m_eClearCount;			//����N���A������
	void (CPlay::* m_step[STAGE_NUM])();	// �V�[�����֐��|�C���^�ŊǗ����邽�߂̂���


public:
	CPlay();
	~CPlay();

	int  Loop();		//���[�v 
	void Draw();		//�`��

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Exit();		//�j��

	//���̃V�[�����쐬
	void CreateScene();
};
