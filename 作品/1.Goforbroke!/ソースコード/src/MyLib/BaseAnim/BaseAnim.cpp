#include "BaseAnim.h"

static const VECTOR VECTOR_ZERO = { 0.0f, 0.0f, 0.0f };

//������
void CBaseAnim::Init()
{
	//�A�j���֘A�f�[�^������
	ZeroMemory(&m_sAnimData, sizeof(m_sAnimData));
	m_sAnimData.m_iAnimHndl = -1;
	m_sAnimData.m_iID = -1;

	//���f���֘A�f�[�^������
	m_vPos = VECTOR_ZERO;
	m_vRot = VECTOR_ZERO;
	m_vScale = VECTOR_ZERO;
	m_vSpeed = VECTOR_ZERO;
	m_iHndl = -1;
	m_fRadius = 0;
	m_bSurvival = true;
	m_sAnimData.m_bPlay = true;
}

//�`��
void CBaseAnim::Draw()
{
	if (m_bSurvival)
		MV1DrawModel(m_iHndl);
}

//�j��
void CBaseAnim::Exit()
{
	if (m_iHndl != -1)
	{
		MV1DeleteModel(m_iHndl);
		m_iHndl = -1;
	}
}

//�X�V
void CBaseAnim::UpData()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
}

//**���[�h�֐�**
//�ʏ탍�[�h
bool CBaseAnim::LoadModel(const char* pFilePath)
{
	if (m_iHndl != -1) return false;	
	m_iHndl = MV1LoadModel(pFilePath);
	if (m_iHndl == -1) return false;	

	return true;
}

//���f���������[�h
bool CBaseAnim::DuplicateModel(int iModelHndl)
{
	if (m_iHndl != -1) return false;	
	m_iHndl = MV1DuplicateModel(iModelHndl);
	if (m_iHndl == -1) return false;	

	return true;
}

//���f���폜
void CBaseAnim::DeleteModel()
{
	if (m_iHndl == -1) return;

	MV1DeleteModel(m_iHndl);
	m_iHndl = -1;

}

//**�A�j���[�V�����֐�**
//�A�j���X�V
void CBaseAnim::UpdataAnim()
{
	//�A�j���[�V�������Đ�����ĂȂ��Ɣ�����
	if (m_sAnimData.m_iAnimHndl == -1) return;
	//���x�X�V
	m_sAnimData.m_fFrm += m_sAnimData.m_fSpd;
	//�Ō�܂ōĐ����ꂽ�瓮���ς���
	if (m_sAnimData.m_fFrm >= m_sAnimData.m_fEndFrm)
	{
		switch (m_sAnimData.m_iState)
		{
			//�ʏ�Đ�
		case ANIMSTATE_NORMAL:
			DetachAnim();
			m_sAnimData.m_fEndFrm = 0.f;
			m_sAnimData.m_fFrm = 0.0f;
			m_sAnimData.m_fSpd = 0.0f;
			m_sAnimData.m_bPlay = false;
			return;

			//���[�v�Đ��@�ŏ��ɂ��ǂ�
		case ANIMSTATE_LOOP:
			m_sAnimData.m_fFrm = 0.0f;
			m_sAnimData.m_bPlay = true;
			break;

			//�G���h���[�v�@�Ō�Ŏ~�߂�
		case ANIMSTATE_END:
			m_sAnimData.m_fFrm = m_sAnimData.m_fEndFrm;
			m_sAnimData.m_bPlay = false;	//�Đ��I��
			break;
		}
	}

	//�Đ����Ԑݒ�
	MV1SetAttachAnimTime(m_iHndl, m_sAnimData.m_iAnimHndl, m_sAnimData.m_fFrm);
}

//�A�j���h�c�A�Đ����x�A�A�j���̃��f���n���h���A�ʃ��f���̃A�j�����g���ꍇ�A�^�b�`���邩
void CBaseAnim::Request(int iAnimID, float iAnimSpd, int iAnimSrcHndl, bool NameCheck)
{
	//�A�j������
	DetachAnim();

	//�A�j���Đ��E�e��f�[�^�Z�b�g
	m_sAnimData.m_iAnimHndl = MV1AttachAnim(m_iHndl, iAnimID, iAnimSrcHndl, NameCheck);
	m_sAnimData.m_iID = iAnimID;
	m_sAnimData.m_fEndFrm = MV1GetAnimTotalTime(m_iHndl, iAnimID);
	m_sAnimData.m_fFrm = 0.0f;
	m_sAnimData.m_fSpd = iAnimSpd;
	//�ʏ�Đ�
	m_sAnimData.m_iState = ANIMSTATE_NORMAL;
}

//���[�v�A�j���@ �A�j�����Ō�܂ōĐ������ƍŏ��ɖ߂�
void CBaseAnim::RequestLoop(int iAnimID, float iAnimSpd, int iAnimSrcHndl, bool NameCheck)
{
	Request(iAnimID, iAnimSpd, iAnimSrcHndl, NameCheck);
	m_sAnimData.m_bPlay = true;
	//���[�v�Đ���
	m_sAnimData.m_iState = ANIMSTATE_LOOP;
}

//�G���h���[�v�@�@�A�j�����Ō�܂ōĐ�����Ă��߂������̂܂�
void CBaseAnim::RequestEndLoop(int iAnimID, float iAnimSpd, int iAnimSrcHndl, bool NameCheck)
{
	Request(iAnimID, iAnimSpd, iAnimSrcHndl, NameCheck);
	//���̂ݍĐ���
	m_sAnimData.m_iState = ANIMSTATE_END;
}

//�A�j�����f�^�b�`
void CBaseAnim::DetachAnim()
{
	if (m_sAnimData.m_iAnimHndl != -1)
	{
		MV1DetachAnim(m_iHndl, m_sAnimData.m_iAnimHndl);
		m_sAnimData.m_iAnimHndl = -1;
	}
}


