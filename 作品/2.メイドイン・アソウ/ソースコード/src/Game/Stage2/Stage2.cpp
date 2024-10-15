#include <DxLib.h>
#include "Stage2.h"
#include "../../MyLib/Input/Input.h"
#include "../../MyLib/Sound/Sound.h"
#define PI 3.141592654

//�w�i
static const char BG_PATH[] = { "data/Game/Stage2/bg.png" };
//��������
static const int TIME_LIMIT = 1800;
//���Ԃ����鑬�x�@
static const int TIME_SPEED = 3;
//���񂽂����΃N���A��
static const int NAIL_HIT = 30;

CStage2::CStage2()
{
	Init();
}
CStage2::~CStage2()
{
	Exit();
}

//������
void CStage2::Init()
{
	for (int i = 0; i < tag_NUM; i++)
	{
		m_iGraph[i] = -1;
	}
	m_fRot = 0.f;
	m_iKeyCount = 0;
	m_iTime = TIME_LIMIT;
	//�����̑傫���ύX
	SetFontSize(150);
	CSound::SetVolume(CSound::SOUND_STAGE2, 0.5);

}
//���[�h
void CStage2::Load()
{
	m_iGraph[tag_BG] = LoadGraph(BG_PATH, true);
	m_iGraph[tag_DESK] = LoadGraph("data/Game/Stage2/desk.png", true);
	m_iGraph[tag_HAMMER] = LoadGraph("data/Game/Stage2/hammer.png", true);
	m_iGraph[tag_NAIL] = LoadGraph("data/Game/Stage2/nail.png", true);
	m_iGraph[tag_SPACE] = LoadGraph("data/Game/Stage2/Space.png", true);

	CSound::Play(CSound::SOUND_STAGE2, DX_PLAYTYPE_BACK, true);
}
//�X�e�b�v 
int  CStage2::Step()
{
	int ret = -1;

	//�X�y�[�X�L�[�Ńn���}�[�̊p�x�ύX
	if (CInput::IsInputPush(CInput::INPUT_SPACE))
	{
		m_fRot = (float)-(PI / 4);
		m_iKeyCount += 1;
	}
	if (CInput::IsInputRelese(CInput::INPUT_SPACE))
	{
		m_fRot = 0;
	}

	//���Ԃ����炷
	m_iTime -= TIME_SPEED;

	//�j���֐i��
	if (m_iKeyCount / 2 > NAIL_HIT || m_iTime < 20)
	{
		ret = 1;
		CSound::AllStop();
	}
	return ret;

}
//�`��
void CStage2::Draw()
{
	DrawGraph(0, 0, m_iGraph[tag_BG], true);		//�w�i
	DrawGraph(945, 540, m_iGraph[tag_NAIL], true);	//�B
	DrawGraph(0, 0, m_iGraph[tag_DESK], true);		//��
	DrawRotaGraph(1400, 600, 1.0, m_fRot, m_iGraph[tag_HAMMER], true);//�n���}�[
	DrawRotaGraph(700, 550, 0.3, 0.f, m_iGraph[tag_SPACE], true);//�X�y�[�X�L�[

	//�c�莞�Ԃ��l�p�`�ŕ`��
	DrawBox(20, 10, m_iTime, 40, GetColor(255, 190, 70), TRUE);
	//����@�������\��
	DrawFormatString(670, 700, GetColor(255, 51, 51), "%d", m_iKeyCount / 2);
	//�Z��@���I
	DrawFormatString(300, 50, GetColor(255, 255, 255), "%d��@���I", NAIL_HIT);

}
//�j��
void CStage2::Exit()
{
	for (int i = 0; i < tag_NUM; i++)
		DeleteGraph(m_iGraph[i]);
}
//���U���g����Ԃ� 0:�ҋ@�@1:�N���A�@2:�Q�[���I�[�o�[
int CStage2::GetResult()
{
	int ret = 0;

	if (m_iKeyCount / 2 > NAIL_HIT)
		ret = 1;
	if (m_iTime < 20)
		ret = 2;

	return ret;
}


