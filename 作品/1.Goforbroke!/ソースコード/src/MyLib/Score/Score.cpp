#include<DxLib.h>
#include "Score.h"

static const int NUMBER = 10;			//�ǂݍ��މ摜���u�O�v�`�u�X�v
static const int NUMBER_SIZE_X = 16;	//�����T�C�Y��(�摜�T�C�Y)
static const int NUMBER_SIZE_Y = 32;	//�����T�C�Y�c(�摜�T�C�Y)
static const int DIGIT_NUMBER = 3;		//�\���\�Ȍ���
static const int START_POS_X = 580;		//�X�R�A�\���J�n�ʒu�@���i�ǂ��ɕ\�����邩�j
static const int START_POS_Y = 32;		//�X�R�A�\���J�n�ʒu�@���i�ǂ��ɕ\�����邩�j

static const char SCORE_PATH[] = "";

//�^�C�g����ʂ̍\����
typedef struct {
	int m_graphHndl[NUMBER];	//�摜�n���h��
	int m_soundHndl;			//���ʉ��n���h��
	int m_score;				//���݂̃X�R�A
	int m_dispScore;			//�f�B�X�v���C�ɂ��\������Ă���X�R�A
}SCORE_DATA;

SCORE_DATA g_number = { 0 };

//������
void CScore::InitScore(void)
{
	for (int i = 0; i < NUMBER; i++)
	{
		g_number.m_graphHndl[i] = -1;
	}
	g_number.m_soundHndl = -1;
	g_number.m_score = 0;
	g_number.m_dispScore = 0;
}

//���[�h
void CScore::LoadScore(void)
{
	LoadDivGraph(SCORE_PATH, NUMBER, 10, 1,
		NUMBER_SIZE_X, NUMBER_SIZE_Y, g_number.m_graphHndl);
}

//�f�[�^�j��
void CScore::ExitScore(void)
{
	for (int i = 0; i < NUMBER; i++)
	{
		if (g_number.m_graphHndl[i] != -1)
		{
			DeleteGraph(g_number.m_graphHndl[i]);
			g_number.m_graphHndl[i] = -1;
		}
	}

}

//2d�`�揈��
void CScore::Draw2dScore(void)
{
	//���j�^�[�ɕ\������X�R�A�����̕ϐ��ɃZ�b�g
	int TempScore = g_number.m_score;
	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		//���P�������o��
		int iNum = TempScore % 10;
		//1���ڂ������ʒu����\��

		DrawRotaGraph(START_POS_X - i * NUMBER_SIZE_X, START_POS_Y,
			1.0, 0.0, g_number.m_graphHndl[iNum], TRUE);
		//���ꌅ���폜
		TempScore /= 10;
	}
}


//3d�`�揈��
void CScore::Draw3dScore(VECTOR DrawPos, float Size)
{
	//���j�^�[�ɕ\������X�R�A�����̕ϐ��ɃZ�b�g
	int TempScore = g_number.m_score;
	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		//���P�������o��
		int iNum = TempScore % 10;
		//1���ڂ��X�R�A��\��
		VECTOR Pos = DrawPos;
		Pos.x *= (float)i/3;

		//���W�̔�����
		Pos.x += 45;

		//�`��
		DrawBillboard3D(Pos,  0.5f, 0.5f, Size, 0.f, g_number.m_graphHndl[iNum], TRUE);

		//���ꌅ���폜
		TempScore /= 10;
	}
}


//�X�R�A�����Z����
void CScore::AddScore(int score)
{
	g_number.m_score += score;
}

//�X�R�A�������I�ɃZ�b�g����
void CScore::SetScore(int score)
{
	g_number.m_score = score;
}

//�擾����
int CScore::GetScore(void)
{
	return g_number.m_score;
}



