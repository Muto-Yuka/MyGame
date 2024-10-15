#pragma once
#include "PlayCam/PlayCam.h"
#include "DebugCam/DebugCam.h"

class CCameraManager
{
public:

	//�J�����̃^�C�v
	enum tagCAMERA_ID
	{
		CAMERA_ID_PLAY,			//�Q�[�����̃J����
		CAMERA_ID_DEBUG,		//�f�o�b�N�p�J����

		CAMERA_ID_NUM
	};

private:
	CPlayCamera m_cPlayCam;				//�v���C���[�J����
	DebugCamera m_DebugCam;				//�v���C���[�J����
	tagCAMERA_ID m_eCurrentCameraID;	//���݂̃J����b


public:

	//�R���X�g���N�^.�f�X�g���N�^
	CCameraManager();
	~CCameraManager();

	//������
	void Init();
	//�X�V����
	void Step(VECTOR vForcus, float fRot);

	//�J�����̃j�A�E�t�@�[�ݒ�
	void SetNearFar(float fNear, float fFar);
	//���݂̃J�����^�C�v�擾
	tagCAMERA_ID GetCameraID() { return m_eCurrentCameraID; }


};


