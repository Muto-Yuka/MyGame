#pragma once
#include <DxLib.h>

class CGround
{
	int m_iHndl;		//���f���n���h��
	bool m_isHitFlag;	//�n�ʂɃq�b�g�@true:���Ă���  false:���Ă��Ȃ�

public:
	CGround();
	~CGround();

	void Init();		//������
	void Load();		//���[�h
	void Loop();		//���[�v
	void Draw();		//�`��
	void Exit();		//�j��

	//�����蔻��p�i����̍��W�Ɣ��a�jreturn:�����߂������ƕ���
	VECTOR	HitCheck(VECTOR anotherPos, float anotherRadius);

};



