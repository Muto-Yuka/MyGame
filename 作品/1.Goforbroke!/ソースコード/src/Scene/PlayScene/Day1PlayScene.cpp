#include "Day1PlayScene.h"


//�R���X�g���N�^
CDay1PlayScene::CDay1PlayScene()
{
	//������
	CBaseScene::Init();
}

//�f�X�g���N�^
CDay1PlayScene::~CDay1PlayScene()
{
	Exit();
}

//���t���[���Ăԏ���
void CDay1PlayScene::Loop()
{
	cMission.SetDay1Scene();
	CBaseScene::Loop();

}

//�`�揈���i�e����j
void CDay1PlayScene::ShadowDraw()
{
	CBaseScene::Draw();

}

//�`�揈���i�e�Ȃ��j
void CDay1PlayScene::Draw()
{
	cMission.Draw();
	cScreen.Day1Draw(m_eSceneID);

//���ꂼ��̓����蔻��i���j�\��
	cItemManager.MyDbug();

}

//������
void CDay1PlayScene::Init()
{
	CBaseScene::Init();
}

//�I������
void CDay1PlayScene::Exit()
{
	CBaseScene::Exit();
}

void CDay1PlayScene::Next()
{
	Exit();
	m_eSceneID = SCENE_INIT;

}

//�f�[�^���[�h
void CDay1PlayScene::Load()
{
	CBaseScene::Load();
}


//���t���[���Ăԏ���
//�ߑO�̏����@�A�C�e���W�߁B�~�b�V�����B
void CDay1PlayScene::AmStep()
{

	CBaseScene::AmStep();

}

//�ߌ�̏���
void CDay1PlayScene::PmStep()
{


	CBaseScene::PmStep();

}

bool CDay1PlayScene::GetClearFlg()
{
	//�I�������܂ł��ׂďI�������N���A�t���O
	if (m_eSceneID == SCENE_NEXT)
		return true;
	else if (m_eSceneID != SCENE_NEXT)
		return false;


	return false;
}








