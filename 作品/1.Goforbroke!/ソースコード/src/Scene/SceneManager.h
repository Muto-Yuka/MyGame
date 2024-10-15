#pragma once

#include "PlayScene/Day1PlayScene.h"
#include "PlayScene/Day2PlayScene.h"
#include "Title/TitleScene.h"
#include "Clear/ClearScene.h"
#include "GameOver/GameOverScene.h"
#include "Operation/Operation.h"

class CSceneManager
{
	int shadowHndl;		//�V���h�E�n���h��

	enum tagSCENE {
		SCENE_TITLE,		//�^�C�g��
		SCENE_OPERATION,	//�������
		SCENE_PLAY_DAY1,	//����ځ@
		SCENE_PLAY_DAY2,	//�����
		SCENE_RESULT,		//���U���g
		GAMEOVER,			//�Q�[���I�[�o�[
		GAMEOVER_PLACE,		//���ꂪ�W�O�ȉ��̏ꍇ
		GAMEOVER_LACK,		//�����s��

		SCENE_NUM
	}m_eAllSceneID;			 // �V�[���ۑ�

	CTitleScene		cTitleScene;		//�^�C�g��
	COperationScene cOperation;		//�������
	CClearScene		cClearScene;		//���U���g
	CGameOverScene	cGameOverScene;	//�Q�[���I�[�o�[�V�[��
	CDay1PlayScene	cDay1PlayScene;	//�v���C���[����
	CDay2PlayScene	cDay2PlayScene;	//�v���C���[����

public:
	CSceneManager();
	~CSceneManager();

	void Init();
	//�J��Ԃ��s������
	int Loop();
	//�`�揈��
	void SceneDraw();
	//�e�܂߂�`��
	void Draw();
	void Exit();

};



