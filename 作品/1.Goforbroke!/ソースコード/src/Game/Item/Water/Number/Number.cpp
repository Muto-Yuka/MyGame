#include "Number.h"

//��`�֘A---------------------------------------------------------------------------
#define  NUMBER (10)				//�ǂݍ��މ摜���u�O�v�`�u�X�v
#define NUMBER_SIZE_X (48)			//�����T�C�Y��(�摜�T�C�Y)
#define NUMBER_SIZE_Y (32)			//�����T�C�Y�c(�摜�T�C�Y)
#define DIGIT_NUMBER (1)			//�\���\�Ȍ���
#define ADD_SCORE_SPD (10)			//�P�t���[���ŉ��Z�����X�R�A��

#define START_POS_X (580)			//�X�R�A�\���J�n�ʒu�@���i�ǂ��ɕ\�����邩�j
#define START_POS_Y (32)			//�X�R�A�\���J�n�ʒu�@���i�ǂ��ɕ\�����邩�j

//�^�C�g����ʂ̍\����
typedef struct {
	int m_graphHndl[NUMBER];		//�摜�n���h��
	int m_score;					//���݂̃X�R�A
	int m_dispScore;				//�f�B�X�v���C�ɂ��\������Ă���X�R�A
}NUMBER_DATA;

//---------------------------------------------------------------------------------------

//���̕ϐ��Ɏ��ۂ̃X�R�A�Ȃǂ̃f�[�^���i�[����
NUMBER_DATA g_number = { 0 };

//----------------------------------------
//			������
//----------------------------------------
void CNumber::InitNumber(void)
{
	for (int i = 0; i < NUMBER; i++)
	{
		g_number.m_graphHndl[i] = -1;
	}
	g_number.m_score = 0;
	g_number.m_dispScore = 0;
}

//----------------------------------------
//			���[�h
//----------------------------------------
void CNumber::LoadNumber(void)
{
	LoadDivGraph("data/Game/Item/Water/Number/Number.png", NUMBER, 6, 2,
		NUMBER_SIZE_X, NUMBER_SIZE_Y, g_number.m_graphHndl);
}

//-----------------------------------------
//			�f�[�^�j��
//-----------------------------------------
void CNumber::ExitNumber(void)
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

//-----------------------------------------
//			2d�`�揈��
//-----------------------------------------
void CNumber::Draw2dNumber(void)
{
	//���j�^�[�ɕ\������X�R�A�����̕ϐ��ɃZ�b�g
	int TempScore = g_number.m_score;
	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		//���P�������o��
		int iNum = TempScore % 10;
		//1���ڂ������ʒuX=580�AY=32����X�R�A��\�����Ă���

		DrawRotaGraph(START_POS_X - i * NUMBER_SIZE_X, START_POS_Y,
			1.0, 0.0, g_number.m_graphHndl[iNum], TRUE);
		//���ꌅ���폜
		TempScore /= 10;
	}
}


//-----------------------------------------
//			3d�`�揈��
//-----------------------------------------
void CNumber::Draw3dNumber(VECTOR DrawPos, float Size)
{
	//���j�^�[�ɕ\������X�R�A�����̕ϐ��ɃZ�b�g
	int TempScore = g_number.m_score;
	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		//���P�������o��
		int iNum = TempScore % 10;
		//1���ڂ��X�R�A��\�����Ă���
		VECTOR Pos = DrawPos;
		Pos.x *= (float)i / 3;

		//���W�̔�����
		Pos.x += 50;

		//�R����Ԃɓ\��t�� ���W/���S���W/�摜�T�C�Y/��]�p�x/�n���h��/�����x��L���ɂ��邩/
		DrawBillboard3D(Pos, 0.5f, 0.5f, Size, 0.f, g_number.m_graphHndl[iNum], TRUE);

		//���ꌅ���폜
		TempScore /= 10;
	}
}


//----------------------------------------
//			���Z����
//----------------------------------------
void CNumber::AddNumber(int score)
{
	//�J��グ�Ȃ�
	if (g_number.m_score < NUMBER - 1)
		g_number.m_score += score;
}

//----------------------------------------
//			�����I�ɃZ�b�g����
//------------------------------------------
void CNumber::SetNumber(int score)
{
	g_number.m_score = score;
}

//-----------------------------------------
//			�擾����
//-----------------------------------------
int CNumber::GetNumber(void)
{
	return g_number.m_score;
}

//-----------------------------------------
//			���X�V
//------------------------------------------
void CNumber::UpdateNumber()
{

}