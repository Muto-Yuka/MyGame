#pragma once
#include <DxLib.h>
#include "../../MyLib/BaseAnim/BaseAnim.h"

class CShot : public CBaseAnim
{
private:
	float m_fRadius; //���a�i���Ȃ̂�float�j

public:
	//�R���X�g���N�^.�f�X�g���N�^
	CShot();
	~CShot();

	void Init();
	void Exit();
	void Draw();

	//�f�[�^�֘A�̃��[�h
	void Load(int iMdlHndl);

	//���t���[���Ăԏ���
	void Step();

	//�e�����˂���Ă��邩�ǂ����@true�@���ˍς� false�@���˂���ĂȂ�
	bool RequestShot(const VECTOR& vPos, const VECTOR& Speed);

	//���W�擾
	VECTOR GetPosition() { return m_vPos; }
	//���a�擾
	float GetRadius(void) { return m_fRadius; }

	//�����蔻��
	void HitCalc();
};

