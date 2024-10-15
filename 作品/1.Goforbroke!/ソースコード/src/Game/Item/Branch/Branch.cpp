#include "Branch.h"

static const char MODEL_PATH[] = { "data/Game/Item/Branch/Branch.x" };
//�o�������邘�͈̔�
#define DRAW_ITEM_X	(200)
//�o�������邚�͈̔�
#define DRAW_ITEM_Z (200)
//�A�C�e���̔��a
#define ITEM_RADIUS (3)
//�o��������A�C�e���̐�
#define ITEM_NUM (2)

//�R���X�g���N�^
CBranch::CBranch()
{
	Init();
}

//�f�X�g���N�^
CBranch::~CBranch()
{
	Exit();
}

//������
void CBranch::Init()
{
	CItemBase::Init(ITEM_RADIUS);
	CItemBase::m_fRadius = ITEM_RADIUS;
}

//���[�h
void CBranch::Load()
{

	if (m_iHndl == -1)
	{
		m_iHndl = MV1LoadModel(MODEL_PATH);
	}

	CItemBase::Load(DRAW_ITEM_X, DRAW_ITEM_Z);

}

//���[�v
void CBranch::Step()
{
	CItemBase::Step();

	//�q�b�g���Ă��玞�Ԃ�}��
	if (m_bSurvival == false)
		m_RespawnTime++;

	//�����S�ɂ������ĕ`�悳��Ȃ��Ȃ胊�X�|�[�����Ԃɓ��B������
	if (m_bSurvival == false && m_RespawnTime % 240 == 0)
	{
		//���X�|�[������
		RespawnApple();
	}
}

//�v���C���[���A�C�e������������̏���
void CBranch::HitItem()
{
	//�`�悵�Ȃ�
	m_bSurvival = false;


}

//���X�|�[���֐�
void CBranch::RespawnApple()
{
	//�ēx�����_���ŏo��������W���擾
	m_vPos = VGet((float)GetRand(DRAW_ITEM_X), 0, (float)GetRand(DRAW_ITEM_Z));
	//�Ăѕ`��
	m_bSurvival = true;
	m_RespawnTime = 0;



}

