#pragma once
#include "DxLib.h"
#include "../../../../Character/Player/Player.h"

class CDropWater
{
private:
	int		m_iDropHndl;		//�摜�n���h��
	VECTOR	m_vWaterPos;		//���̍��W
	float	m_fRadius;			//���̔��a
	bool	m_bSurvival;		//�����t���O true:�`�悷��@false:���Ȃ�
	bool	m_bMove;			//���̍��W���X�V���邩 true:�X�V����@false:�ҋ@
	bool	m_bPlayerHit;		//�v���C���[��HIT����

public:
	void Init();						//������
	void DuplicateLoad(int DropHndl);	//�������[�h
	void Step();						//���[�v
	void Draw();						//�`��
	void Exit();						//�j��

	//�v���C���[��HIT�������̏���
	void HitCalc(CPlayer& cPlayer);
	//�v���C���[�ƐڐG�������v���C���[����������
	void HitDrink();
	//�v���C���[�ƐڐG����������ɐ���߂�
	void HitReturn();


	//**�Q�b�^�[�E�Z�b�^�[**

	//�G�̍��W���Z�b�g����
	inline void SetWaterPos(VECTOR EnemyPos) { m_vWaterPos = EnemyPos; }
	//���W���擾
	inline VECTOR GetPosition() { return m_vWaterPos; }
	//���a�擾
	inline float GetRadius(void) { return m_fRadius; }
	//�����t���O��true�ɃZ�b�g����@�ĕ`�悷��
	inline void SetSurvival() { m_bSurvival = true; }
	//�����t���O���Q�b�g����
	inline bool GetSurvival() { return m_bSurvival; }

	//���W�X�V�t���O���Z�b�g�E�Q�b�g����
	inline bool GetMove() { return m_bMove; } //move true:���W�X�V�@false:�X�V���Ȃ�
	inline void SetMove(bool frg) { m_bMove = frg; }

};



