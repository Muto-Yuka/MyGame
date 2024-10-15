#include <DxLib.h>
#include "Ground.h"

const char GROUND_PATH[] = { "data/Game/Field/Ground/Stage.x" };

CGround::CGround()
{
	Init();
}

CGround::~CGround()
{
	Exit();
}

//������
void CGround::Init()
{
	m_isHitFlag = false;
	m_iHndl = -1;
	MV1SetPosition(m_iHndl, VGet(0.0f, 0.0f, 0.0f));
}

//���[�h
void CGround::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = MV1LoadModel(GROUND_PATH);
	}
	//���f���f�[�^�̃|���S�������\�z����
	MV1SetupCollInfo(m_iHndl);
}

//���[�v
void CGround::Loop()
{
	MV1SetPosition(m_iHndl, VGet(0.0f, -2.0f, 0.0f));
}

//�`��
void CGround::Draw()
{
	MV1DrawModel(m_iHndl);
}

//�j��
void CGround::Exit()
{
	//�|���S�����j��
	MV1TerminateCollInfo(m_iHndl);
}

//�t�B�[���h�S�̂̓����蔻��p
VECTOR CGround::HitCheck(VECTOR anotherPos, float anotherRadius)
{
	//�����߂�������ۑ�����ϐ�
	VECTOR vOut = { 0.0f, 0.0f, 0.0f };
	//�\����
	MV1_COLL_RESULT_POLY_DIM res;
	//�������Ƃɓ����蔻����擾���A�ϐ��̒��ɖ߂�l���󂯎��
	res = MV1CollCheck_Sphere(m_iHndl, -1, anotherPos, anotherRadius);

	if (res.HitNum == 0) m_isHitFlag = false;
	else if (res.HitNum > 0)
	{
		//�Ԃ������Ƃ��ɉ����߂��������v�Z����
		m_isHitFlag = true;
		//�����Ԃ���ꍇ
		for (int i = 0; i < res.HitNum; i++)
		{
			//�v���C���[�ƃt�B�[���h�̋����𒲂ׂ�
			//�Ԃ������|���S���Ƒ��葤�̍��W�������Z����
			VECTOR v = VSub(res.Dim[i].HitPosition, anotherPos);
			//�����Z�����x�N�g���̒��������߂�
			float length = VSize(v);
			//�߂荞�񂾋������v�Z���Ă���
			length = anotherRadius - length;
			//�@���������Ƃɉ����o��(�|���Z)
			v = VScale(res.Dim[i].Normal, length);

			vOut = VAdd(vOut, v);
		}
	}
	//�����蔻�����j��
	MV1CollResultPolyDimTerminate(res);

	return vOut; //�����߂��������ۑ����ꂽ�ϐ���Ԃ�

}



