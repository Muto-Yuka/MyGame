#include "GameOverScene.h"
#include <DxLib.h> 
#include "../../MyLib/Sound/Sound.h"
#include "../../MyLib/Fade/Fade.h"

static const char PATH[] = { "data/Scene/GameOver/GameOver.png" };
static const char LACK_PATH[] = { "data/Scene/GameOver/WaterGM2.png" };
static const char PLACE_PATH[] = { "data/Scene/GameOver/WaterGM1.png" };

//�R���X�g���N�^
CGameOverScene::CGameOverScene()
{
	Init();
}

//�f�X�g���N�^
CGameOverScene::~CGameOverScene()
{
	Exit();
	CFade::DeleteInstance();
}

//������
void CGameOverScene::Init(void)
{
	m_iHndl = -1;		//������
	m_iWaterlack = -1;
	m_iWaterplace = -1;
	Load();

}

//�f�[�^���[�h
void CGameOverScene::Load()
{
	//�ʏ�Q�[���I�[�o�[
	if (m_iHndl == -1)
	{
		m_iHndl = LoadGraph(PATH);
	}
	//�����s��
	if (m_iWaterlack == -1)
	{
		m_iWaterlack = LoadGraph(LACK_PATH);
	}
	//���ꖢ�B��
	if (m_iWaterplace == -1)
	{
		m_iWaterplace = LoadGraph(PLACE_PATH);
	}
	CFade::GetInstance()->Request(4.0f, true);

}

//���t���[���Ăԏ���
void CGameOverScene::Step()
{
	if (!CFade::GetInstance()->IsEnd())
		return;


}

//�`�揈��
void CGameOverScene::Draw()
{
	//�ʏ�
	DrawGraph(0, 0, m_iHndl, true);
}

//�����s���@�`��
void CGameOverScene::LackDraw()
{

	//�����s��
	DrawGraph(0, 0, m_iWaterlack, true);

}

//���ꖢ�B���@�`��
void CGameOverScene::PlaceDraw()
{

	//���B��
	DrawGraph(0, 0, m_iWaterplace, true);

}

//�I������
void CGameOverScene::Exit()
{
	CSound::AllStop();
	DeleteGraph(m_iHndl);
	DeleteGraph(m_iWaterplace);
	DeleteGraph(m_iWaterlack);

	CFade::DeleteInstance();

}
