#include "BaseItem.h"

//�R���X�g���N�^
CItemBase::CItemBase()
{

}

//�f�X�g���N�^
CItemBase::~CItemBase()
{
	Exit();
}

//������
void CItemBase::Init(float Radius)
{
	m_iHndl = -1;
	m_bSurvival = true;
	m_RespawnTime = 0;
	m_fRadius = Radius;

}

//�ʏ탋�[�v
void CItemBase::Step()
{
	VECTOR scale = { 0.1f,0.1f,0.1f };
	MV1SetScale(m_iHndl, scale);


	MV1SetPosition(m_iHndl, m_vPos);

}

//���X�|�[�����郋�[�v����
void CItemBase::RespawnStep(int x, int z, int ItemNum)
{
	//�q�b�g���Ă��玞�Ԃ�}��
	if (m_bSurvival == false)
		m_RespawnTime++;

	//�����S�ɂ������ĕ`�悳��Ȃ��Ȃ胊�X�|�[�����Ԃɓ��B������
	if (m_bSurvival == false && m_RespawnTime % 120 == 0)
	{
		//���X�|�[������
		RespawnItem(x, z, ItemNum);

	}
}



//���[�h �͈͂�ݒ�	���ʂ̃����_���l���[�h
void CItemBase::Load(int x, int y)
{


	m_vPos = VGet((float)GetRand(x), 0, (float)GetRand(y));

}

//���������_���l���[�h
void CItemBase::DuplicateLoad(int Hndl, int x, int z)
{
	if (m_iHndl == -1)
	{
		//��������
		m_iHndl = MV1DuplicateModel(Hndl);
		//�X�P�[�����Z�b�g
		MV1SetScale(m_iHndl, VGet(0.1f, 0.1f, 0.1f));
		//���W���Z�b�g
		m_vPos = VGet((float)GetRand(x) - (x / 2), 0, (float)GetRand(z) - (z / 2));
		//���W���X�V
		MV1SetPosition(m_iHndl, m_vPos);

	}

}

//�`��
void CItemBase::Draw()
{
	if (m_bSurvival)
		MV1DrawModel(m_iHndl);
}

//�I��
void CItemBase::Exit()
{
	if (m_iHndl != -1)
	{
		MV1DeleteModel(m_iHndl);
		m_iHndl = -1;
	}


}

//���N�G�X�g
bool CItemBase::RequestItem(const VECTOR& vPos)
{
	//���łɓG���o�Ă���  �G���[����Ԃ�
	if (m_bSurvival) return false;

	m_vPos = vPos;
	m_bSurvival = true;

	//��x���W���X�V
	MV1SetPosition(m_iHndl, m_vPos);
	return true;
}

//���X�|�[������
void CItemBase::RespawnItem(int x, int z, int ItemNum)
{
	//�ēx�����_���ŏo��������W���擾
	m_vPos = VGet((float)GetRand(x - (x / 2)), 0, (float)GetRand(z - (z / 2)));
	//�Ăѕ`��
	m_bSurvival = true;
	m_RespawnTime = 0;

	for (int i = 0; i < ItemNum; i++)
	{
		if (RequestItem(m_vPos))
		{
			break;
		}
	}

}


