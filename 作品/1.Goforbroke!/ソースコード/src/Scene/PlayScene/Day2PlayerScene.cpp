#include "Day2PlayScene.h"

//�R���X�g���N�^
CDay2PlayScene::CDay2PlayScene()
{
	//������
	CBaseScene::Init();

}

//�f�X�g���N�^
CDay2PlayScene::~CDay2PlayScene()
{
	Exit();
}


//���t���[���Ăԏ���
void CDay2PlayScene::Loop()
{

	cMission.SetDay2Scene();

	CBaseScene::Loop();


}



//�`�揈���i�e����j
void CDay2PlayScene::ShadowDraw()
{
	CBaseScene::Draw();

}
//�`�揈���i�e�Ȃ��j
void CDay2PlayScene::Draw()
{
	cMission.Draw();
	cScreen.Day2Draw(m_eSceneID);
	cItemManager.MyDbug();

}
//������
void CDay2PlayScene::Init()
{

	CBaseScene::Init();
}

//�I������
void CDay2PlayScene::Exit()
{
	CBaseScene::Exit();

}
void CDay2PlayScene::Next()
{
	CBaseScene::Next();
}


//�f�[�^���[�h
void CDay2PlayScene::Load()
{
	CBaseScene::Load();
}


//���t���[���Ăԏ���
//�ߑO�̏����@�A�C�e���W�߁B�~�b�V�����B
void CDay2PlayScene::AmStep()
{

	CBaseScene::AmStep();

}

//�ߌ�̏���
void CDay2PlayScene::PmStep()
{

	CBaseScene::PmStep();

}

bool CDay2PlayScene::GetClearFlg()
{
	//�I�������܂ł��ׂďI�������N���A�t���O
	if (m_eSceneID == SCENE_NEXT)
		return true;
	else if (m_eSceneID != SCENE_NEXT)
		return false;


	return false;

}

//���ꁓ���B���ł��Ă��邩�@true:�B���@false:���B��
bool CDay2PlayScene::GetWaterClear()
{
	if (cItemManager.GetWaterClearFrg())
		return true;
	

	return false;
}



