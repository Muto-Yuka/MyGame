#include "DropWater.h"

#define DROP_WATER_RADIUS	(3)

//������
void CDropWater::Init()
{
	m_iDropHndl = -1;
	m_vWaterPos = { 0.f, 0.f, 0.f };
	m_fRadius = DROP_WATER_RADIUS;
	m_bSurvival = false;
	m_bMove = false;
	m_bPlayerHit = false;
}

//�������[�h
void CDropWater::DuplicateLoad(int DropHndl)
{

	//�R���A�C�e�����f���`��
	if (m_iDropHndl == -1)
	{
		m_iDropHndl = MV1DuplicateModel(DropHndl);
		MV1SetScale(m_iDropHndl, VGet(0.1f, 0.1f, 0.1f));
	}
}

//���[�v
void CDropWater::Step()
{

	//���W���Z�b�g
	MV1SetPosition(m_iDropHndl, m_vWaterPos);

}

//�`��
void CDropWater::Draw()
{
	if (m_bSurvival)
	{
		//���������l����ړ����Ă���`��
		if (m_vWaterPos.x != 0.0f || m_vWaterPos.z != 0.0f)
		{
			//���f���`��
			MV1DrawModel(m_iDropHndl);

		}

	}
}

//�j��
void CDropWater::Exit()
{
	MV1DeleteModel(m_iDropHndl);
}

//�v���C���[��HIT�������̏���
void CDropWater::HitCalc(CPlayer& cPlayer)
{
	m_bPlayerHit = true;

	//�`�悵�Ȃ�
	m_bSurvival = false;
	//�Ăэ��W�Z�b�g
	m_bMove = false;

	//�v���C���[�ɐ����������� �ϐ��Ɂ{�{����
	cPlayer.SetWaterNum();

	//�����Ă��鐅�𐅏�ɕԂ�
	HitReturn();
}

//�����Ă��鐅�𐅏�ɕԂ�
void CDropWater::HitReturn()
{
	//�C���E�Ԃ��{�^���������ꂽ��
	if (CheckHitKey(KEY_INPUT_Q) || CPlayer::input.Buttons[2] > 0)
	{


	}

}


