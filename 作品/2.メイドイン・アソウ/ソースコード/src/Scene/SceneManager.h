#pragma once
#include "SceneBase.h"

class CSceneManager
{
	enum tagSCENE {
		SCENE_TITLE,		//�^�C�g��
		SCENE_OPERATION,	//�������
		SCENE_PLAY,			//�v���C
		SCENE_CLEAR,		//�N���A
		SCENE_GAMEOVER,		//�Q�[���I�[�o�[

		SCENE_NUM
	}m_eAllSceneID;			 // �V�[���ۑ�

	CSceneBase* cScene;

public:
	CSceneManager();
	~CSceneManager();

	void Init();	//������
	int Loop();		//�V�[���Ǘ�

	void Draw();	//�`��
	void Exit();	//�j��

};




