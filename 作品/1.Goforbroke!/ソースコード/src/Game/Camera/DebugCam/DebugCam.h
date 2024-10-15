#pragma once
#include <dxlib.h>

class DebugCamera {
private:
	// �J�����Ɏg�p����ϐ�
	VECTOR m_vPos;	// ���_
	VECTOR m_vForcus;// �����_
	VECTOR m_vUp;	// �����
	VECTOR m_vRot;			//��]�p�x

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	DebugCamera();

	~DebugCamera();

	//������

	void Init();
	void Init(VECTOR vPos, VECTOR vForcus, VECTOR vUp);

	//���t���[���Ăԏ���
	void Step(VECTOR vForcus, float fRot);

	//�X�V�����f�[�^�𔽉f������
	void Update();
};
