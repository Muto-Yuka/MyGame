#include "BreakEnemy.h"

static const char ENEMY_MODEL_PATH[] = { "data/Character/Enemy/TemporaryEnemy�P.mv1" };
static const int WAIT_TIME = 120;		//�G�̏o������
static const int RESPAWN_TIME = 600;	//�G���|����Ă��畜������܂ł̎���

#define B_ENEMY_HP	(3)			
#define NEXT_TIME	(500)			//�ߌ㎞�Ԃ��I���΋����Ŏ��̃V�[����

CBreakEnemy::CBreakEnemy()
{

}
CBreakEnemy::~CBreakEnemy()
{
	Exit();
}

//������
void CBreakEnemy::Init(CApple& cApple)
{
	for (int i = 0; i < BREAK_ENEMY_NUM; i++)
	{
		//������
		m_cBreakEnemy[i].Init(cApple);
		//�G�̂������Z�b�g
		m_cBreakEnemy[i].SetEnemyHP(B_ENEMY_HP * PLAYER_ATTACK);
	}
	//���X�|�[�����Ԃ�ݒ�
	m_iWaitRespawn = RESPAWN_TIME;

	NextDayFrg = false;
	NextDayCount = NEXT_TIME;
}

//���[�h
void CBreakEnemy::Load()
{
	//�I���W�i�����f����ǂݍ���
	int iHndl = MV1LoadModel(ENEMY_MODEL_PATH);

	//���f���̕���
	for (int i = 0; i < BREAK_ENEMY_NUM; i++)
		m_cBreakEnemy[i].Load(iHndl);

	MV1DeleteModel(iHndl);
}

//�I������
void CBreakEnemy::Exit()
{
	for (int i = 0; i < BREAK_ENEMY_NUM; i++)
		m_cBreakEnemy[i].Exit();
}

//���t���[���Ăԏ���
void CBreakEnemy::Step(CWater& cWater, CScreen& cScreen)
{

	int iEnemyCnt = 0;
	//�G�̈ړ�����
	for (int i = 0; i < BREAK_ENEMY_NUM; i++)
	{
		m_cBreakEnemy[i].BreakEnemyStep(cWater);
		if (m_cBreakEnemy[i].CBaseAnim::IsSurvival())
			iEnemyCnt++;
	}

	//���ꂪ�`�悳��Ă��ĕ`�悳��Ď��Ԃ��o���Ă���
	if (cWater.GetSurvivalFrg())
	{
		m_iWaitRespawn--;

		//�ߌ�̎��Ԃ��O�ɂȂ�܂ł͓G���o��
		if (cScreen.GetPmTimeLimit() >= 0)
		{
			//�|����Ă��玞�Ԃ��o����
			if (m_iWaitRespawn < 0)
			{

				RequestEnemy();

				m_iWaitRespawn = RESPAWN_TIME;
			}
		}
	}

	//�ߌ㎞�Ԃ��I���Ύ���
	if (cScreen.GetPmTimeLimit() <= 0)
	{
		NextDayCount--;

		//�G���݂�ȓ|���ꂽ��
		if (!m_cBreakEnemy[0].GetSurvival() && !m_cBreakEnemy[1].GetSurvival())
		{
			NextDayFrg = true;
		}

		//���Ԃ��o�Ă΋����Ŏ��̃V�[����
		if (NextDayCount < 0)
		{
			NextDayCount = NEXT_TIME;
			NextDayFrg = true;
		}
	}
}


//�`�揈��
void CBreakEnemy::Draw()
{
	for (int i = 0; i < BREAK_ENEMY_NUM; i++)
		m_cBreakEnemy[i].Draw();

}

//�G�̃��N�G�X�g
void CBreakEnemy::RequestEnemy()
{
	//�o������ʒu�������_���Ŏ擾
	VECTOR vPos = VGet((float)GetRand(200) - 100.0f, 0, 200.0f);
	//�G�̃X�s�[�h
	VECTOR vSpeed = VGet(0.0f, 0.0f, -0.5f);

	for (int i = 0; i < BREAK_ENEMY_NUM; i++)
	{
		if (m_cBreakEnemy[i].RequestEnemy(vPos, vSpeed))
		{
			break;
		}
	}
}



