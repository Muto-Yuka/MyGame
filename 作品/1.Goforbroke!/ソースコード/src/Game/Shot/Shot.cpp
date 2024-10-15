#include "shot.h"
#include <Math.h>

#define SHOT_RADIUS (3)

//�R���X�g���N�^
CShot::CShot()
{
	//������
	memset(&m_vPos, 0, sizeof(VECTOR));
	m_iHndl = -1;
	m_bSurvival = false;
	m_fRadius = SHOT_RADIUS;
	m_vSpeed = VGet(0.0f, 0.0f, 0.0f);
}

//�f�X�g���N�^
CShot::~CShot()
{
	Exit();
}

//������
void CShot::Init()
{
	CBaseAnim::Init();
	m_bSurvival = false;
	m_fRadius = SHOT_RADIUS;
}

//�I������
void CShot::Exit()
{
	CBaseAnim::Exit();
}

//�f�[�^�֘A�̃��[�h
void CShot::Load(int iMdlHndl)
{
	if (m_iHndl == -1)
	{
		m_iHndl = MV1DuplicateModel(iMdlHndl);
	}
}

//�`�揈��
void CShot::Draw()
{
	CBaseAnim::Draw();
}

//���t���[���Ăԏ���
void CShot::Step()
{
	if (!m_bSurvival) return;

	//���W�ɑ��x�����Z
	m_vPos = VAdd(m_vPos, m_vSpeed);
	//���͈͂𒴂����狅������
	float fLength = 300.0f;
	if (m_vPos.x > fLength || m_vPos.x < -fLength
		|| m_vPos.z > fLength || m_vPos.z < -fLength)
	{
		m_bSurvival = false;
	}

	//�e�̑傫����ύX
	VECTOR scale = { 1.5f,1.5f,1.5f };
	MV1SetScale(m_iHndl, scale);


	//���W�X�V
	MV1SetPosition(m_iHndl, m_vPos);

}

//���N�G�X�g
bool CShot::RequestShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//���łɔ��˂���Ă���  �G���[����Ԃ�
	if (m_bSurvival) return false;

	m_vPos = vPos;
	m_vSpeed = vSpeed;
	m_bSurvival = true;

	return true;


}

//�����蔻��
void CShot::HitCalc()
{
	m_bSurvival = false;
}


