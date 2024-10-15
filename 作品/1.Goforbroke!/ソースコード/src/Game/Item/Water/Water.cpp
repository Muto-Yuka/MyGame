#include "Water.h"
#include "../../../Character/Player/Player.h"

//3d���f��
static const char MODEL_PATH[] = { "data/Game/Item/Water/Water.mv1" };
//����̗͕̑`��
static const char HP_PATH[] = { "data/Game/Item/Water/2dWaterHp.png" };
//�����s���̎��ɕ`��
static const char FOGGYPATH[] = { "data/Game/Item/Water/NeedWater.png" };


//�Q���C���X�g�̃t�@�C���p�X
#define ON_WATER_PATH	("data/Game/Mission/Water/OnWater.png")
#define UNDER_WATER_PATH	("data/Game/Mission/Water/UnderWater.png")

//���������W
#define DRAW_ITEM_X	(50.0f)
//���������W
#define DRAW_ITEM_Z (50.0f)
//�A�C�e���̔��a
#define ITEM_RADIUS (22.0f)
//����̗̑�
#define WATER_HP	(50.f)
//�����Q�[�W�̂����W
#define WATER_2D_Y			(650)		
//���������鎞�� (���x)
#define WATER_TIME		(300)	

//�R���X�g���N�^
CWater::CWater()
{
	Init();
}

//�f�X�g���N�^
CWater::~CWater()
{
	Exit();

	//�摜�폜
	DeleteGraph(m_2dHpHndl);
	DeleteGraph(m_iFoggyHndl);
	//2d�摜���폜
	for (int i = 0; i < GAUGE_NUM; i++)
	{
		DeleteGraph(m_iOnHndl[i]);
		DeleteGraph(m_iUnderHndl[i]);
	}

	//�����p�摜�폜
	cNumber.ExitNumber();

}

//������
void CWater::Init()
{
	CItemBase::Init(ITEM_RADIUS);
	CItemBase::m_fRadius = ITEM_RADIUS;
	m_hp = WATER_HP;					//����̗̑�
	WaterGauge = GAUGE_NUM;				//�����Q�[�W�̕\����
	HitFrg = false;						//�G�ɓ������ĂȂ�
	m_bResult = false;
	m_iPlayerWater = 0;
	m_iFoggyHndl = -1;
	HitCount = 0;

	//�X�R�A�i�����̏������j
	cNumber.InitNumber();
}

//���[�h
void CWater::Load()
{
	//�X�R�A�������[�h
	cNumber.LoadNumber();

	//3d���f�������[�h
	if (m_iHndl == -1)
	{
		m_iHndl = MV1LoadModel(MODEL_PATH);
	}

	//2d�摜�����[�h
	for (int i = 0; i < GAUGE_NUM; i++)
	{
		m_iOnHndl[i] = LoadGraph(ON_WATER_PATH);
		m_iUnderHndl[i] = LoadGraph(UNDER_WATER_PATH);
	}
	//�����s���摜���[�h
	if (m_iFoggyHndl == -1)
	{
		m_iFoggyHndl = LoadGraph(FOGGYPATH);
	}

	//����̗͉̑摜���[�h
	m_2dHpHndl = LoadGraph(HP_PATH);

	//���̈ʒu�������ʒu��
	m_vPos = VGet(DRAW_ITEM_X, 0.0f, DRAW_ITEM_Z);
}

//���[�v
void CWater::Step()
{
	StartTime++;

	CItemBase::Step();

	//�G������ɓ������Ă��鎞
	if (HitFrg == true)
	{
		//����̗̑͂����炷
		m_hp -= 0.1f;

		//�̗͂��Ȃ��Ȃ�����
		if (m_hp <= 0)
		{
			//�t���O���I�t��
			m_bSurvival = false;
			HitFrg = false;
			//m_hp = WATER_HP;

		}
	}

	//��莞�Ԍo�Ăΐ��������炷
	if (StartTime % WATER_TIME == 0)
	{
		SetWaterGauge();
	}

	//�����Q�[�W���O�ɂȂ�ƃ��U���g
	if (GetWaterGauge() == 0)
		m_bResult = true;

	//����̐����X�V����
	cNumber.UpdateNumber();

}

//�`��
void CWater::Draw()
{

	MV1SetPosition(m_iHndl, m_vPos);

	//�R�����f���`��
	CItemBase::Draw();


	//����́��e�[�W��\������
	//����̐����`�� �`�悷����W �摜�T�C�Y
	VECTOR NumberPos = m_vPos;
	NumberPos.y += 40;
	cNumber.Draw3dNumber(NumberPos, 28.0f);

	VECTOR waterPos = m_vPos;
	waterPos.y += 10;

	float Hp = m_hp;

	//3d����̗̑̓Q�[�W�`��
	DrawModiBillboard3D(waterPos, -25.f, 0.f, Hp - 25, 0.f, Hp - 25, 20.f, -25.f, 20.f, m_2dHpHndl, TRUE);


	//�����s�����ɕ`��
	if (WaterGauge == 1)
	{
		DrawGraph(0, 0, m_iFoggyHndl, true);
	}

	//2d�����Q�[�W�`��
	for (int i = 0; i < GAUGE_NUM; i++)
		DrawGraph(i * SHIFT_ITEM_PICTURE, WATER_2D_Y, m_iUnderHndl[i], true);
	for (int k = 0; k < WaterGauge; k++)
		DrawGraph(k * SHIFT_ITEM_PICTURE, WATER_2D_Y, m_iOnHndl[k], true);

	//�v���C���[�����������`�悷��
	for (int k = 0; k < m_iPlayerWater; k++)
		DrawGraph(1100, WATER_2D_Y, m_iOnHndl[k], true);

}

//�������
void CWater::HitBreakWater()
{
	//�󂵎n�߂�t���O��on��
	HitFrg = true;

}

//����ɐ���߂� �����Ŏ����Ă��鐅�̐����󂯎��
void CWater::HitReturnWater(int WaterNum)
{
	//����ɓ������Ă���@���@�v���C���[�����������Ă�����
	if (WaterNum == 1)
	{
		//�C���{�^������������
		if (CheckHitKey(KEY_INPUT_Q) || CPlayer::input.Buttons[2] > 0)
		{
			if (HitCount == 0)
				//����́����A�b�v����@����
				cNumber.AddNumber(1);
			HitCount++;
		}
		else
			HitCount = 0;
	}
}

//������C������@�Q������
void CWater::HitRepairWater()
{
	interval++;

	//�������Ă����ԂŎ擾�{�^�������� ���@���ꂪ�����Ă���
	if (CheckHitKey(KEY_INPUT_E) && m_bSurvival == true)
	{
		//���Ƃ��Ƃ��鐅���̍ő�l��菭�Ȃ�������� 2d�摜
		if (WaterGauge < GAUGE_NUM)
		{
			WaterGauge++;

		}

	}
	else if ((CPlayer::input.Buttons[0] > 0) && (m_bSurvival == true))
	{
		//���Ƃ��Ƃ��鐅���̍ő�l��菭�Ȃ�������� 2d�摜
		if (WaterGauge < GAUGE_NUM)
		{
			WaterGauge++;

		}

	}

	//�C���{�^�����������
	if (CheckHitKey(KEY_INPUT_Q) || CPlayer::input.Buttons[2] > 0)
	{
		//�R���Q�[�W��
		if (m_hp < WATER_HP)
			m_hp += 0.1f;
	}
}





