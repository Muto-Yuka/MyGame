#include "SceneManager.h"
#include "../MyLib/Input/Input.h"
#include "../MyLib/Fade/Fade.h"
#include "../MyLib/Sound/Sound.h"

CSceneManager::CSceneManager()
{
	
	shadowHndl = -1;

	//�Q�[���I�[�o�[
	cGameOverScene.Init();

	CSound::Init();
	CSound::AllLoad();

	//������
	m_eAllSceneID = SCENE_TITLE;

}
CSceneManager::~CSceneManager()
{
	cDay1PlayScene.Exit();
	cDay2PlayScene.Exit();

	CSound::Exit();
}

void CSceneManager::Init()
{
	//�V���h�E�}�b�v���쐬����i�T�C�Y�͉𑜓x�Ɋ֌W����j
	//�T�C�Y�͕K���Q�ׂ����
	shadowHndl = MakeShadowMap(2048, 2048);

	//���̕�����ݒ肷��	  �V���h�E�}�b�v�n���h���A�΂߂̉e���ł���
	SetShadowMapLightDirection(shadowHndl, VGet(-1.5f, -3.0f, -2.8f));

	//�e��`�悷��͈͂��Z�b�g�i�G���A�����߂Ȃ��Ə������������d�����Ȃ�j
	//�V���h�E�}�b�v�n���h���A
	SetShadowMapDrawArea	//�ݒ肵�����W�̓����ɂ���Ƃ������e�����f
	(shadowHndl, VGet(-50.0f, -1.0f, -50.0f), VGet(250.0f, 10.0f, 200.0f));
	//(shadowHndl, VGet(-50.0f, -1.0f, -50.0f), VGet(150.0f, 10.0f, 100.0f));
	//				�͈͂̍ŏ��l�A			�͈͂̍ő�l

}

//���t���[���Ăԏ���
int CSceneManager::Loop()
{
	int iRet = 0;

	switch (m_eAllSceneID)
	{
	case SCENE_TITLE:
		if(cTitleScene.Loop())
			m_eAllSceneID = SCENE_OPERATION;

		break;

	case SCENE_OPERATION:
		if (cOperation.Loop())
			m_eAllSceneID = SCENE_PLAY_DAY1;

		break;

	case SCENE_PLAY_DAY1:
		cDay1PlayScene.Loop(); 

		////day1�N���A�����܂ł��ׂďI���@����ڂ�
		if (cDay1PlayScene.GetClearFlg())
		{
			//�t�F�[�h
			CFade::GetInstance()->Request(4.0f, true);

			m_eAllSceneID = SCENE_PLAY_DAY2;

		}
		//�������Ȃ��Ȃ�΃��U���g
		if (cDay1PlayScene.GetResultFlg())
		{
			//�t�F�[�h
			CFade::GetInstance()->Request(4.0f, true);

			m_eAllSceneID = GAMEOVER_LACK;

		}

		break;

	//�����
	case SCENE_PLAY_DAY2:
		cDay2PlayScene.Loop(); //Init~Exit�܂ŉ񂷊֐����Ă�
		if (cDay2PlayScene.GetClearFlg())	
		{
			if (!cDay2PlayScene.GetWaterClear())
			{
				//�t�F�[�h
				CFade::GetInstance()->Request(4.0f, true);
				m_eAllSceneID = GAMEOVER_PLACE;
			}
			else
			{
				//�t�F�[�h
				CFade::GetInstance()->Request(4.0f, true);
				m_eAllSceneID = SCENE_RESULT;
			}

		}
		//�H���������Ȃ��Ȃ�΃��U���g
		if (cDay2PlayScene.GetResultFlg())
		{
			//�t�F�[�h
			CFade::GetInstance()->Request(4.0f, true);

			m_eAllSceneID = GAMEOVER_LACK;

		}	
		break;

	//���U���g
	case SCENE_RESULT:
		if (cClearScene.Loop())
			m_eAllSceneID = SCENE_TITLE;
		
		break;
	//�Q�[���I�[�o�[
	case GAMEOVER:
		cGameOverScene.Step();
		if (CInput::IsInputPush(CInput::INPUT_NEXT) || (CPadInput::PadInput & PAD_INPUT_8))	//�G���^�[�������Ǝ���
		{
			CFade::GetInstance()->Request(4.0f, true);

			m_eAllSceneID = SCENE_TITLE;
		}
		break;

	//�����s���@�Q�[���I�[�o�[
	case GAMEOVER_LACK:
		cGameOverScene.Step();
		if (CInput::IsInputPush(CInput::INPUT_NEXT) || (CPadInput::PadInput & PAD_INPUT_8))	//�G���^�[�������Ǝ���
		{
			CFade::GetInstance()->Request(4.0f, true);

			m_eAllSceneID = SCENE_TITLE;
		}
		break;

	//���B���@�Q�[���I�[�o�[
	case GAMEOVER_PLACE:
		cGameOverScene.Step();
		if (CInput::IsInputPush(CInput::INPUT_NEXT) || (CPadInput::PadInput & PAD_INPUT_8))	//�G���^�[�������Ǝ���
		{
			CFade::GetInstance()->Request(4.0f, true);

			m_eAllSceneID = SCENE_TITLE;
		}
		break;


	}

	//�t�F�[�h�����̍X�V
	CFade::GetInstance()->UpDate();


	return iRet;
}


//�X�V�����E�`��
void CSceneManager::SceneDraw()
{
	switch (m_eAllSceneID)
	{
	//�^�C�g��
	case SCENE_TITLE:
		cTitleScene.Draw();
		break;

	//�������
	case SCENE_OPERATION:
		cOperation.Draw();

	//�����
	case SCENE_PLAY_DAY1:
		cDay1PlayScene.ShadowDraw();//�e����`��
		cDay1PlayScene.Draw();		//�e�Ȃ��`��
		break;

	//�����
	case SCENE_PLAY_DAY2:
		cDay2PlayScene.ShadowDraw();
		cDay2PlayScene.Draw();
		break;

	//���U���g
	case SCENE_RESULT:
		cClearScene.Draw();
		break;

	//�Q�[���I�[�o-
	case GAMEOVER:
		cGameOverScene.Draw();
		break;
	//�����s���@�Q�[���I�[�o�[
	case GAMEOVER_LACK:
		cGameOverScene.LackDraw();
		break;
	//���B���@�Q�[���I�[�o�[
	case GAMEOVER_PLACE:
		cGameOverScene.PlaceDraw();
		break;
	}

	//�t�F�[�h�֘A
	CFade::GetInstance()->Draw();


}

void CSceneManager::Draw()
{
	//�e�̕`�揈��
	ShadowMap_DrawSetup(shadowHndl);//�e�̕`��O�ɕK���s��
	cDay1PlayScene.ShadowDraw();
	cDay2PlayScene.ShadowDraw();
	ShadowMap_DrawEnd();			//�e�̕`���ɕK���s��
	//�ʏ�̕`�揈��
	SetUseShadowMap(0, shadowHndl);	//���f������e�̃n���h���ƂO�`�Q�̃X���b�g�ԍ��Z�b�g
	SceneDraw();
	SetUseShadowMap(0, -1);			//�I�������g�p�����X���b�g�ԍ����[�P�ŏI��点��
}


void CSceneManager::Exit()
{
	DeleteShadowMap(shadowHndl);

}
