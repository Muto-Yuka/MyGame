#include "GunEnemy.h"

static const int WAIT_TIME = 300;		//�G�̏o������
static const int RESPAWN_TIME = 800;	//�G���|����Ă��畜������܂ł̎���

//<3d>���f���E�摜�p�X
static const char ENEMY_MODEL_PATH[] = { "data/Character/Enemy/TemporaryEnemy�P.mv1" };	//�G���f��
static const char ENEMY_DROP_PATH[] = { "data/Character/Enemy/DropWater.x" };				//�G�����Ƃ������f��

#define NEXT_TIME	(500)			//�ߌ㎞�Ԃ��I���΋����Ŏ��̃V�[����

//�R���X�g���N�^
CGunEnemy::CGunEnemy()
{
	m_iWaitCnt = 0;
}

//�f�X�g���N�^
CGunEnemy::~CGunEnemy()
{
	Exit();
}

//������
void CGunEnemy::Init(CApple& cApple)
{
	m_iWaitCnt = WAIT_TIME;

	//�G�̐���������
	for (int i = 0; i < GUN_ENEMY_NUM; i++)
	{
		//���f��������
		m_cGunEnemy[i].Init(cApple);
		//�h���b�v��������
		m_cDropWater[i].Init();

		//�G�̂������Z�b�g�i�������j
		m_cGunEnemy[i].SetEnemyHP(G_ENEMY_HP * PLAYER_ATTACK);
	}



	//���X�|�[�����Ԃ�ݒ�
	m_iWaitRespawn = RESPAWN_TIME;

	NextDayFrg = false;
	NextDayCount = NEXT_TIME;
}

//���[�h
void CGunEnemy::Load()
{
	//�I���W�i���G���f����ǂݍ���
	int iHndl = MV1LoadModel(ENEMY_MODEL_PATH);
	//�I���W�i�������f����ǂݍ���
	int iDropHndl = MV1LoadModel(ENEMY_DROP_PATH);

	//�G�̐������f���̕���
	for (int i = 0; i < GUN_ENEMY_NUM; i++)
	{
		//�G�𕡐����[�h
		m_cGunEnemy[i].Load(iHndl);

		//���𕡐����[�h
		m_cDropWater[i].DuplicateLoad(iDropHndl);
	}

	//�I���W�i�����f���j��
	MV1DeleteModel(iHndl);
	//�I���W�i�����f���j��
	MV1DeleteModel(iDropHndl);

}

//�I������
void CGunEnemy::Exit()
{
	for (int i = 0; i < GUN_ENEMY_NUM; i++)
	{
		m_cGunEnemy[i].Exit();
		m_cDropWater[i].Exit();
	}

}

//���t���[���Ăԏ���
void CGunEnemy::Step(CPlayer& cPlayer, ShotManager& cEnemyShot, CScreen& cScreen)
{

	int iEnemyCnt = 0;

	//�G�̐�����
	for (int i = 0; i < GUN_ENEMY_NUM; i++)
	{

		//�G�̈ړ�����
		m_cGunEnemy[i].GunEnemyStep(cPlayer, cEnemyShot);
		if (m_cGunEnemy[i].CBaseAnim::IsSurvival())
			iEnemyCnt++;

		if (m_cDropWater[i].GetSurvival())
		{
			//������~���łȂ���΍X�V
			if (!m_cDropWater[i].GetMove())
			{

				//�G�̍��W�𐅂̍��W�ɃZ�b�g
				m_cDropWater[i].SetWaterPos(m_cGunEnemy[i].GetPos());
				//���̍��W���X�V
				m_cDropWater[i].Step();
			}
		}
	}

	//�ߌ�̎��ԃJ�E���g���I����Ă�����G���o���Ȃ�
	if (cScreen.GetPmTimeLimit() >= 0)
	{
		//�G�̏o��
		m_iWaitCnt--;
		if (m_iWaitCnt < 0)
		{
			RequestEnemy();
			m_iWaitCnt = WAIT_TIME;
			m_iWaitRespawn = RESPAWN_TIME;


		}

	}
	//�ߌ㎞�Ԃ��I���Ύ���
	if (cScreen.GetPmTimeLimit() <= 0)
	{
		NextDayCount--;

		for (int i = 0; i < GUN_ENEMY_NUM; i++)
		{
			//�G���݂�ȓ|���ꂽ��
			if (!m_cDropWater[0].GetSurvival() && !m_cDropWater[1].GetSurvival())
			{
				NextDayFrg = true;
			}

		}


		//���Ԃ��߂���΋����I�Ɏ��̃V�[����
		if (NextDayCount < 0)
		{
			NextDayCount = NEXT_TIME;
			NextDayFrg = true;
		}
	}



}


//�`�揈��
void CGunEnemy::Draw()
{
	for (int i = 0; i < GUN_ENEMY_NUM; i++)
	{
		//�G�`��
		m_cGunEnemy[i].Draw();
		//���`��
		m_cDropWater[i].Draw();
	}
}

//�G�̃��N�G�X�g
void CGunEnemy::RequestEnemy()
{
	VECTOR vPos = VGet((float)GetRand(200) - 100.0f, 0, 200.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, -0.5f);


	for (int i = 0; i < GUN_ENEMY_NUM; i++)
	{


		if (m_cGunEnemy[i].RequestEnemy(vPos, vSpeed))
		{

			//�����`�悳��ĂȂ�������
			if (!m_cDropWater[i].GetSurvival())
				m_cDropWater[i].SetSurvival();

			break;
		}
	}
}

