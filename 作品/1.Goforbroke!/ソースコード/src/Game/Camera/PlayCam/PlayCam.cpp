#include <DxLib.h>
#include <crtdbg.h>
#include <math.h>
#include "PlayCam.h"
#include "../../../MyLib/Input/Input.h"
#include "../../../Character/Player/Player.h"

#define CAMERA_MAX_LENGTH		(70.0f)		//���������ɗ����ő�̋���
#define CAMERA_USUALLY_LENGTH	(50.0f)		//�ʏ�̃v���C���[�ƃJ�����̋���
#define CAMERA_MIN_LENGTH		(40.0f)		//�Y�[�����̃v���C���[�ƃJ�����̋���

#define CAMERA_OFFSET_Y (35.0f)
#define FORCUS_OFFSET_Y (30.0f)

//�R���X�g���N�^
CPlayCamera::CPlayCamera()
{
	//������
	memset(&m_vPos, 0, sizeof(VECTOR));
	memset(&m_vForcus, 0, sizeof(VECTOR));
	memset(&m_vUp, 0, sizeof(VECTOR));
	m_iCameraLen = CAMERA_USUALLY_LENGTH;
	Init();
}

//�f�X�g���N�^
CPlayCamera::~CPlayCamera()
{

}


void CPlayCamera::Init()
{
	m_vPos = VGet(0.0f, 0.0f, 1.0f);
	m_vForcus = VGet(0.0f, 0.0f, 0.0f);
	m_vUp = VGet(0.0f, 1.0f, 0.0f);
	SubVector = { 0.0f,0.0f,0.0f };

}

//���t���[���Ăԏ���
void CPlayCamera::Loop(VECTOR vForcus, float fRot)
{

	//�R���g���[���[�p
	CPlayer::Key = GetJoypadDirectInputState(DX_INPUT_PAD1, &CPlayer::input);		//�g�p����p�b�h���w��

	//�v���C���[�����_�ɂ��āA������]���O�ǂł��邱�Ƃ�O��ɍl����
	//�v���C���[�̉�]�p�x�ɍ��킹�ď�L�����x�N�g������]������
	VECTOR vDir;
	vDir.x = sinf(fRot) * m_iCameraLen;
	vDir.z = cosf(fRot) * m_iCameraLen;
	//���_�̍����͌Œ�
	vDir.y = CAMERA_OFFSET_Y;

	//�����X�i�v���C���[�j�̈��r�v�Z���ʂ̋������ړ��������
	//�J�����̎��_�ɂȂ�
	m_vPos = VAdd(vForcus, vDir);

	//�����_�̓^�[�Q�b�g�̈ʒu�𗘗p����
	m_vForcus = vForcus;
	m_vForcus.y = FORCUS_OFFSET_Y;

	//�V�t�g�����ƃY�[���@�\
	if (CInput::IsInputDown(CInput::INPUT_ZOOM) /*|| (&CPlayer::input.Z > 0)*/)
	{
		//�߂Â���
		if (m_iCameraLen > CAMERA_MIN_LENGTH)
			m_iCameraLen--;

	}
	else
	{
		//�ʏ틗���ɖ߂�
		if (m_iCameraLen < CAMERA_USUALLY_LENGTH)
			m_iCameraLen++;
	}

	//�v���C���[������ƃJ���������ꂽ��߂Â�����
	if (CInput::IsInputDown(CInput::INPUT_DASH) && CInput::IsInputDown(CInput::INPUT_UP))
	{
		//�J��������������
		if (m_iCameraLen < CAMERA_MAX_LENGTH)
			m_iCameraLen += 0.5f;

	}
	else
	{
		//�ʏ틗���ɖ߂�
		if (m_iCameraLen > CAMERA_USUALLY_LENGTH)
			m_iCameraLen -= 0.5f;

	}

}

//�X�V�����f�[�^�𔽉f������
void CPlayCamera::Update()
{
	//DxLib�̕��ɃJ�������X�V
	SetCameraPositionAndTargetAndUpVec(m_vPos, m_vForcus, m_vUp);
}


