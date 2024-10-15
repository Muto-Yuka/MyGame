#include "player.h"
#include "../../MyLib/Input/Input.h"

//�v���C���[���
static const float RADIUS = 5.0f;				//���a
static const int REPAIR_TIME = 150;				//����̏C������
static const float ROTATE_SPEED = 0.02f;		//�v���C���[�̉�]���x  DX_PI_F�̓�
static const float MODEL_SPEED = 1.0f;			//�v���C���[�̈ړ����x
static const float MODEL_RUN_SPEED = 2.0f;		//�v���C���[�̑��������̈ړ����x
static const float SHOT_SPEED = 5.0f;			//�e�̑��x
static const int WAIT_BULLET_TIME = 20;			//�e�̔��ˎ���
//�p�X
static const char PLAYER_MODEL_PATH[] = { "data/Character/Player/Playerblend.mv1" };
static const char REPAIR_PATH[] = { "data/Character/Player/Repair.png" };


CPlayer::CPlayer()
{
	Init();
}

CPlayer::~CPlayer()
{
	CBaseAnim::Exit();
	CPlayAnim::Exit();
	DeleteGraph(m_iRepairHndl);
}

//������
void CPlayer::Init()
{
	CBaseAnim::Init();
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_vRot.y = 3.1f;						
	m_fRadius = RADIUS;
	m_iWaitBulletCnt = WAIT_BULLET_TIME;
	m_iRepair_time = REPAIR_TIME;
	m_iWaterNum = 0;
	m_iRepairHndl = -1;

}

//���[�h
void CPlayer::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = MV1LoadModel(PLAYER_MODEL_PATH);
	}

	m_iRepairHndl = LoadGraph(REPAIR_PATH);

	CPlayAnim::Load();
}

//���[�v
void CPlayer::Loop(ShotManager& cShotManager, CWater& cWater)
{

	//�v���C���[�e�ݒ菈��
	PlayerShot(cShotManager);

	//�v���C���[�s������
	PlayerMove();

	//�A�j���X�V
	CPlayAnim::Loop();

}

//�v���C���[�s��
void CPlayer::PlayerMove()
{
	//���x�Ȃǂ𔽉f
	Update();
	float Rotate = ROTATE_SPEED;
	float Speed = MODEL_SPEED;

	//�Y�[��
	if (CheckHitKey(KEY_INPUT_RSHIFT) || (input.Z != 0))
	{
		Rotate = 0.01f;
	}

	//����
	if (CInput::IsInputDown(CInput::INPUT_DASH) || (input.Buttons[4] > 0))
		Speed = MODEL_RUN_SPEED;
	else
		Speed = MODEL_SPEED;

	//���E��]
	if (CheckHitKey(KEY_INPUT_RIGHT) || (input.Rx > 0)) m_vRot.y += Rotate;
	if (CheckHitKey(KEY_INPUT_LEFT) || (input.Rx < 0)) m_vRot.y -= Rotate;

	//�L�����N�^�[�̈ړ�
	VECTOR fSpd = { 0.0f,0.0f,0.0f };
	//�O��
	if (CInput::IsInputDown(CInput::INPUT_UP) || (input.Y < 0))
	{
		fSpd.x = sinf(m_vRot.y) * -Speed;
		fSpd.z = cosf(m_vRot.y) * -Speed;
	}
	if (CInput::IsInputDown(CInput::INPUT_DOWN) || (input.Y > 0))
	{
		fSpd.x = sinf(m_vRot.y) * Speed;
		fSpd.z = cosf(m_vRot.y) * Speed;
	}
	//���E
	if (CInput::IsInputDown(CInput::INPUT_LEFT) || (input.X < 0))
	{
		fSpd.x = sinf(m_vRot.y - DX_PI_F / 2) * -Speed;
		fSpd.z = cosf(m_vRot.y - DX_PI_F / 2) * -Speed;

	}
	if (CInput::IsInputDown(CInput::INPUT_RIGHT) || (input.X > 0))
	{
		fSpd.x = sinf(m_vRot.y - DX_PI_F / 2) * Speed;
		fSpd.z = cosf(m_vRot.y - DX_PI_F / 2) * Speed;
	}

	m_vSpeed = fSpd;

	//�n�ʂɍ��킹��
	m_vPos.y = 3.5f;
	//�ړ����x�����݂̍��W�ɉ��Z����
	m_vPos = VAdd(m_vPos, m_vSpeed);

}

//�v���C���[�ɓ����������̏���
void CPlayer::HitCalc()
{
	//�����l�Ƀ��X�|�[��
	memset(&m_vPos, 0, sizeof(VECTOR));
	m_vRot.y = 3.1f;

	m_HP--;
}

//�v���C���[�e���ˏ���
void CPlayer::PlayerShot(ShotManager& cShotManager)
{
	m_iWaitBulletCnt--;

	//��������
	VECTOR vPos = m_vPos;
	vPos.y += 15.0f;
	//�ړ�����
	VECTOR vSpd = { 0.0f, 0.0f, 0.0f };

	vSpd.x = sinf(m_vRot.y) * -SHOT_SPEED;
	vSpd.z = cosf(m_vRot.y) * -SHOT_SPEED;

	//����
	if (CInput::IsInputDown(CInput::INPUT_SHOT) || (input.Buttons[5] > 0))
	{
		if (m_iWaitBulletCnt < 0)
		{
			cShotManager.RequestPlayerShot(vPos, vSpd);

			m_iWaitBulletCnt = WAIT_BULLET_TIME;
		}
	}
}

//���݈ʒu�ɍ��W�����Z
void CPlayer::ReflectCollision(VECTOR vAddVec)
{
	//�ړ����Ă��Ȃ����return
	if (vAddVec.x == 0.0f && vAddVec.y == 0.0f && vAddVec.z == 0.0f) return;

	m_vPos = VAdd(m_vPos, vAddVec);
}

//������C�����鏈���֐��@����Ɠ������Ă��鎞�ɌĂ΂��
void CPlayer::WatrRepair(CWater& cWater)
{
	//����Ƀq�b�g���Ă��� �� �C���{�^���������ꑱ���Ă���
	if (CInput::IsInputKeep(CInput::INPUT_REPAIR) || (input.Buttons[2] > 0))
	{
		//���Ԃ̃J�E���g�����炷
		m_iRepair_time--;

		cWater.SetHp(10.f);

		//�J�E���g���O�܂��͂O�ȉ��ɂȂ�ΏC������
		if (m_iRepair_time < 0 || m_iRepair_time == 0)
		{
			cWater.SetSurvivalFrg(true);
			m_iRepair_time = REPAIR_TIME;
		}
	}
	//�C���L�[���������ƃJ�E���g�����Ƃɖ߂�
	else
	{
		m_iRepair_time = REPAIR_TIME;
	}

	//���������Ă����ԂŏC���L�[������
	if (CInput::IsInputPush(CInput::INPUT_REPAIR) || (input.Buttons[2] > 0))
	{
		if (m_iWaterNum > 0)
			m_iWaterNum--;
	}
}

//�t�B�[���h�p�v���C���[�̒��S�����蔻����擾����
VECTOR CPlayer::GetCenter()
{
	VECTOR	vCenter = MV1GetPosition(m_iHndl);
	return vCenter;
}








