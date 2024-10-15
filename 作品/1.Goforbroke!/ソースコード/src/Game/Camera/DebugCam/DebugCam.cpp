#include <DxLib.h>
#include <crtdbg.h>
#include <math.h>
#include "DebugCam.h"

static const float ROTATE_SPEED = 0.1f;		//�v���C���[�̉�]���x

#define CAMERA_LENGTH (50.0f)
#define CAMERA_OFFSET_Y (20.0f)
#define FORCUS_OFFSET_Y (10.0f)
static const float DEBUG_CAMERA_SPEED = 1.0f;		//�̈ړ����x


//�R���X�g���N�^
DebugCamera::DebugCamera()
{
	//������
	memset(&m_vPos, 0, sizeof(VECTOR));
	memset(&m_vForcus, 0, sizeof(VECTOR));
	memset(&m_vUp, 0, sizeof(VECTOR));
}

//�f�X�g���N�^
DebugCamera::~DebugCamera()
{

}


void DebugCamera::Init()
{
	m_vPos = VGet(0.0f, 0.0f, 1.0f);
	m_vForcus = VGet(0.0f, 0.0f, 0.0f);
	m_vUp = VGet(0.0f, 1.0f, 0.0f);
}

//������
void DebugCamera::Init(VECTOR vPos, VECTOR vForcus, VECTOR vUp)
{
	m_vPos = vPos;
	m_vForcus = vForcus;
	m_vUp = vUp;
}


//���t���[���Ăԏ���
void DebugCamera::Step(VECTOR vForcus, float fRot)
{

	//�����_�㉺
	if (CheckHitKey(KEY_INPUT_UP)) m_vForcus.y += DEBUG_CAMERA_SPEED;
	if (CheckHitKey(KEY_INPUT_DOWN)) m_vForcus.y -= DEBUG_CAMERA_SPEED;
	//�����_
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		//if (m_vForcus.x >= -DX_PI_F * 0.5f)
		m_vForcus.x += DEBUG_CAMERA_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		//if (m_vForcus.x >= DX_PI_F * 0.5f)
		m_vForcus.x -= DEBUG_CAMERA_SPEED;

	}

	//�J�����̑O�i���
	float speed = 0.0f;
	if (CheckHitKey(KEY_INPUT_W)) speed += DEBUG_CAMERA_SPEED;
	if (CheckHitKey(KEY_INPUT_S)) speed -= DEBUG_CAMERA_SPEED;
	m_vPos.x += sinf(m_vForcus.y) * speed;


	////�L�����N�^�[�̂����Ă�
	//if (CheckHitKey(KEY_INPUT_RIGHT)) m_vRot.y += ROTATE_SPEED;
	//else if (CheckHitKey(KEY_INPUT_LEFT)) m_vRot.y -= ROTATE_SPEED;

	////�L�����N�^�[�̈ړ�
	//float fSpd = 0.0f;
	//if (CheckHitKey(KEY_INPUT_UP)) fSpd = -MODEL_SPEED;
	//if (CheckHitKey(KEY_INPUT_DOWN)) fSpd = MODEL_SPEED;

	////���͂����L�[���ƃv���C���[�̊p�x����A�ړ����x�����߂�
	//m_vSpeed.x = sinf(m_vRot.y) * fSpd;
	//m_vSpeed.z = cosf(m_vRot.y) * fSpd;
	////�ړ����x�����݂̍��W�ɉ��Z����
	//m_vPos = VAdd(m_vPos, m_vSpeed);

}

//�X�V�����f�[�^�𔽉f������
void DebugCamera::Update()
{
	//DxLib�̕��ɃJ�������X�V
	SetCameraPositionAndTargetAndUpVec(m_vPos, m_vForcus, m_vUp);
}
