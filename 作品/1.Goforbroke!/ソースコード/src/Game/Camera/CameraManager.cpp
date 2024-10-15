#include "CameraManager.h"
#include <DxLib.h>

//��`�֘A
//��{�ƂȂ鎋�_�E�����_�E�A�b�v�x�N�g��
VECTOR DEFAULT_EYE_POS = { 0.0f, 10.0f, -20.0f };
VECTOR DEFAULT_FORCUS_POS = { 0.0f, 0.0f, 0.0f };
VECTOR DEFAULT_UP_VEC = { 0.0f, 1.0f, 0.0f };


//�R���X�g���N�^
CCameraManager::CCameraManager()
{
	m_eCurrentCameraID = CAMERA_ID_PLAY;
}

//�f�X�g���N�^
CCameraManager::~CCameraManager()
{

}

//������
void CCameraManager::Init()
{
	//m_cPlayCam.Init(DEFAULT_EYE_POS, DEFAULT_FORCUS_POS, DEFAULT_UP_VEC);
	//m_DebugCam.Init(DEFAULT_EYE_POS, DEFAULT_FORCUS_POS, DEFAULT_UP_VEC);
}

//���t���[���Ăԏ���
void CCameraManager::Step(VECTOR vForcus, float fRot)
{
	//�J�����̃^�C�v�ɍ��킹�āA�X�V������ύX����
	switch (m_eCurrentCameraID)
	{
	case CAMERA_ID_PLAY:
	{
		m_cPlayCam.Loop(vForcus, fRot);
		m_cPlayCam.Update();

		break;
	}
	case CAMERA_ID_DEBUG:
	{
		m_DebugCam.Step(vForcus, fRot);
		m_DebugCam.Update();

		break;
	}
	}




}

//�J�����̃j�A�E�t�@�[�̐ݒ�
void CCameraManager::SetNearFar(float fNear, float fFar)
{
	SetCameraNearFar(fNear, fFar);

}

