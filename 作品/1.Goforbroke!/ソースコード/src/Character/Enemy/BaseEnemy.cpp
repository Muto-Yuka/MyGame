#include "BaseEnemy.h"
#include <math.h>

const float ENEMY_SPEED = 1.0f;				//�e�̑��x
static const int WAIT_BULLET_TIME = 180;     //�G�̎��̒e�̔��ˎ���
static const float ENEMY_SLOW_DOWN = 0.3f;	//�ǂꂾ���G�̃X�s�[�h�𗎂Ƃ���

//2d�@�G�̂����摜
#define ENEMY_HP_PATH ("data/Character/Enemy/EnemyHP.Png")

#define ENEMY_RADIUS (5)
#define MY_DEBUG	(1)

//������
void CEnemyBase::Init(CApple& cApple)
{
	CBaseAnim::Init();
	m_fRadius = ENEMY_RADIUS;
	m_bSurvival = false;
	m_enemy_count = 0;
	Clear = false;
	m_vRot = { 0.0f,0.0f,0.0f };
	m_iWaitBulletCnt = WAIT_BULLET_TIME;
	m_vInitPos = (VGet((float)GetRand(200) - 100.0f, 0, 200.0f));
	m_fTransparency = 1.0f;
	m_iHpGaugeHndl = -1;
	m_bStopBEnemy = false;
	m_DropItem = -1;
}

//�I������
void CEnemyBase::Exit()
{
	CBaseAnim::Exit();
}

//�f�[�^���[�h
void CEnemyBase::Load(int iMdlHndl)
{


	//�R���G���f���`��
	if (m_iHndl == -1)
	{
		m_iHndl = MV1DuplicateModel(iMdlHndl);
		MV1SetScale(m_iHndl, VGet(0.05f, 0.05f, 0.05f));
	}

	//�Q���@�����摜���[�h
	m_iHpGaugeHndl = LoadGraph(ENEMY_HP_PATH);

}


//�`�揈��
void CEnemyBase::Draw()
{
	if (m_bSurvival)
	{
		//���f���`��
		MV1DrawModel(m_iHndl);
		//�̗͂�`�悷��
		VECTOR m_pos = m_vPos;
		m_pos.y += 25;
		DrawModiBillboard3D(m_pos, -15.f, 0.f, (float)m_iHp - 15, 0.f, (float)m_iHp - 15, 5.f, -15.f, 5.f, m_iHpGaugeHndl, TRUE);

	}

}

//�G�P�̃��[�v�����i�e�����G�j
void CEnemyBase::GunEnemyStep(CPlayer& cPlayer, ShotManager& cEnemyShot)
{


	if (!m_bSurvival) return;
	m_iWaitBulletCnt--;

	//�����x��ݒ�
	Transparency(m_iHndl, m_fTransparency);


	//���f���̑傫��
	VECTOR scale = { 0.1f,0.1f,0.1f };
	MV1SetScale(m_iHndl, scale);

	//==�G����Ƀv���C���[�̕��Ɍ�������==
	EnemyLook(cPlayer.GetPosition(), m_vPos);

	//�e���ˏ����֐�
	EnemyShot(cEnemyShot);

	//==�G�̈ړ�����==
	EnemyMove();
}

//�G�Q�̃��[�v�����i������󂷓G�j
void CEnemyBase::BreakEnemyStep(CWater& cWater)
{

	//�����x��ݒ�
	Transparency(m_iHndl, m_fTransparency);

	m_iWaitBulletCnt--;

	//�G�����񂾂玟�̓G�͐���Ɍ������Ĉړ�����悤��
	if (m_bSurvival == false)
		m_bStopBEnemy = false;

	//���ꂪ�����Ă���
	if (cWater.GetSurvivalFrg())
	{
		//�G�������Ă���
		if (m_bSurvival)
		{
			//�G����ɐ���̕��Ɍ�������==
			EnemyLook(cWater.GetPosition(), m_vPos);

			if (m_bStopBEnemy == false)
			{
				//����Ɍ������Ĉړ�����
				EnemyMove();

			}

		}
	}
	//���ꂪ���Ă���
	else
	{
		m_bStopBEnemy = false;
		//���ꂩ�瓦���� ��ɐ���Ɣ��Ε��������� �X�^�[�g�n�_������
		EnemyLook(m_vInitPos, m_vPos);

		//�ڕW�Ɍ������Ĉړ�����
		EnemyMove();

		//����̈ʒu�𒴂�����G������
		if (m_vPos.z > 190.0f)
		{
			m_bSurvival = false;
		}

	}
}

//�����Ă�����ɐi�ޏ���
void CEnemyBase::EnemyMove()
{
	//���W�ɑ��x�����Z
	VECTOR vSpeed;
	vSpeed.x = sinf(m_fAngle) * ENEMY_SLOW_DOWN;
	vSpeed.z = cosf(m_fAngle) * ENEMY_SLOW_DOWN;
	vSpeed.y = 0.0f;

	m_vPos = VAdd(m_vPos, vSpeed);

	//���W�X�V
	MV1SetPosition(m_iHndl, m_vPos);
}

//��Ɏw�肳�ꂽ�����������֐�
void CEnemyBase::EnemyLook(VECTOR TargetPos, VECTOR EnemyPos)
{
	// EnemyPos����TargetPos�Ɍ������x�N�g�����Z�o
	//�^�[�Q�b�g���W����G�̍��W���Ђ�
	SubVector = VSub(TargetPos, EnemyPos);

	// atan2�i���������Ԃł̊Ԃ̊p�x�j ���g�p���Ċp�x���擾
	m_fAngle = static_cast<float> (atan2(SubVector.x, SubVector.z));

	// atan2 �Ŏ擾�����p�x�ɂR�c���f���𐳖ʂɌ������邽�߂̕␳�l( DX_PI_F �i�΁j)��
	// �������l���R�c���f���� Y����]�l�Ƃ��Đݒ�
	MV1SetRotationXYZ(m_iHndl, VGet(0.0f, m_fAngle + DX_PI_F, 0.0f));

}

//�e���ˊ֐�
void CEnemyBase::EnemyShot(ShotManager& cEnemyShot)
{
	//==�e�̏���==
	//�G�̑̂���o��悤�ɍ��W���グ��
	VECTOR vPos = CBaseAnim::m_vPos;
	vPos.y += 5.0f;

	////���x�̓v���C���[�Ɠ������@�ňړ����������߂�
	//�v���C���[�Ɍ������Ēe���΂�
	VECTOR vSpd;
	vSpd.x = sinf(m_fAngle) * ENEMY_SPEED;
	vSpd.z = cosf(m_fAngle) * ENEMY_SPEED;
	vSpd.y = 0.0f;
	//���ˑҋ@���Ԃ��O�ɂȂ�����
	if (m_iWaitBulletCnt == 0)
	{
		//���ˊ֐����Ăԁ@RequestEnemtShot�̒��ɔ��ˏ���
		cEnemyShot.RequestEnemyShot(vPos, vSpd);
		m_iWaitBulletCnt = WAIT_BULLET_TIME;
	}
}

//���N�G�X�g
bool CEnemyBase::RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//���łɓG���o�Ă���  �G���[����Ԃ�
	if (m_bSurvival) return false;

	m_vPos = vPos;
	m_vSpeed = vSpeed;
	m_bSurvival = true;

	//��x���W���X�V
	MV1SetPosition(m_iHndl, m_vPos);
	return true;
}

//�����������̏���
void CEnemyBase::HitCalc(CApple& cApple)
{
	if (m_bSurvival == true)
	{
		//�����S�̐��ɍ��킹�Ă��������炷
		//m_iHp-= (int)cApple.GetHp();
		m_iHp -= PLAYER_ATTACK;

	}
	//�������Ȃ��Ȃ�����
	if (m_iHp <= 0)
	{
		//�G�t���O������
		m_bSurvival = false;
		//hp�����ʂ��
		m_iHp = spare;

	}
}

//����ɓ����������̏����E�������
void CEnemyBase::BreakWater(CWater& cwater)
{
	m_bStopBEnemy = true;

}

//�_���[�W�󂯂��Ƃ��_�ł����鏈�� �摜�n���h���Afloat�����x�i�O�͓����P�͕s�����j
void CEnemyBase::Transparency(int Hndl, float Transparency)
{

	//�����x��ݒ�
	MV1SetOpacityRate(m_iHndl, Transparency);


}




