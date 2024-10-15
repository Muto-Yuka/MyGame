#include "Screen.h"
#include <DxLib.h>

unsigned int color = GetColor(255, 30, 30);

#define HP_SHIFT	(28)		//�ǂꂭ�炢���炵�ĕ`�悷�邩
#define HP_X		(1000)		//�����̂����W
#define HP_Y		(600)

CScreen::CScreen()
{
	Init();
}

CScreen::~CScreen()
{
	Exit();
}

void CScreen::Init()
{
	m_UpHndl = -1;
	m_AmCount = AM_TIME_COUNT;
	m_PmCount = PM_TIME_COUNT;
	m_PlayerHp = 0;

	WaterHp = 0;

	//�S�̂̃t�H���g�T�C�Y�ύX
	SetFontSize(30);
}

void CScreen::Load()
{
	m_UpHndl = LoadGraph("data/Game/Screen/screen.png");		//��ʏ㕔�\���i�X�R�A��HPS�����₷������E�����^�[�Q�b�g�|�C���^�j
	//�t�H���g���[�h
	ChangeFont("���z�� �l�N�X�g UP B");


}

//��Ƀ��[�v���鏈��
void CScreen::Step(int SceneId, CPlayer& cPlayer)
{
	//�v���C���[�̂������擾
	m_PlayerHp = cPlayer.GetPlayerHP();


	//���ꂼ��ߑO�ƌߌ�̎��ԃJ�E���g����
	if (SceneId == 2)
	{
		//�ߑO
		m_AmCount--;

		if (m_PmCount < 0)
			m_PmCount = PM_TIME_COUNT;

	}
	else if (SceneId == 3)
	{
		//�ߌ�
		m_PmCount--;

		if (m_AmCount < 0)
			m_AmCount = AM_TIME_COUNT;

	}
}

//����ڂ̕`�揈��
void CScreen::Day1Draw(int SceneId)
{

	//�ߑO�̏���
	if (SceneId == 2)
	{
		DrawGraph(0, 0, m_UpHndl, TRUE);

		//�^�C�����O�ɂȂ�Ε`�悵�Ȃ�
		if (m_AmCount > 0)
			DrawFormatString(400, 10, GetColor(255, 69, 0), "Time %d", m_AmCount);


	}
	//�ߌ�̏���
	else if (SceneId == 3)
	{

		DrawGraph(0, 0, m_UpHndl, TRUE);

		//DrawFormatString(200, 10, color, "�c���HP[%d]", m_PlayerHp);


		if (m_PmCount > 0)
			DrawFormatString(400, 10, GetColor(255, 69, 0), "Time %d", m_PmCount);


	}



	DrawFormatString(600, 10, GetColor(255, 0, 0), "Day1");





}

//����ڂ̕`�揈��
void CScreen::Day2Draw(int SceneId)
{
	//�ߑO
	if (SceneId == 2)
	{
		DrawGraph(0, 0, m_UpHndl, TRUE);

		DrawFormatString(400, 10, GetColor(255, 69, 0), "Time %d", m_AmCount);

	}
	//�ߌ�
	else if (SceneId == 3)
	{

		DrawGraph(0, 0, m_UpHndl, TRUE);


		if (m_PmCount > 0)
			DrawFormatString(400, 10, GetColor(255, 69, 0), "Time %d", m_PmCount);

	}


	DrawFormatString(600, 10, GetColor(255, 0, 0), "Day2");

}

void CScreen::Exit()
{
	DeleteGraph(m_UpHndl);
}

