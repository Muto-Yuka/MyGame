#pragma once
#include "../../Game/shot/shotManager.h"
#include "../../Game/Item/Water/Water.h"
#include "PlayAnim.h"

//�v���C���[HP
static const int PLAYER_HP = (5);

class CPlayer : public CPlayAnim
{
	int		m_iRepairHndl;			//�C������ۂɕ`�悷��
	int		m_iWaitBulletCnt;		//�O�ȉ��Œe�Ĕ���
	int		m_iRepair_time;			//����̏C�����ԁ@�O�ȉ��ŏC������
	int		m_iWaterNum;			//��������̐�

public:

	CPlayer();
	~CPlayer();

	void Init();	//������
	void Load();	//���[�h
	void Loop(ShotManager& cShotManager, CWater& cWater);	//���[�v

	//�s������
	void PlayerMove();
	//�V���b�g�֐�
	void PlayerShot(ShotManager& cShotManager);
	//�����蔻��
	void HitCalc();
	//���݈ʒu�ɍ��W�X�V
	void ReflectCollision(VECTOR vAddVec);
	//������C������
	void WatrRepair(CWater& cWater);

	//�t�B�[���h�p�����蔻��
	VECTOR GetCenter();

//�Q�b�^�[
	inline int GetPlayerHP() { return m_HP; }		//HP
	inline float GetRadius() { return m_fRadius; }	//���a
	inline float GetRotateY() { return m_vRot.y; }	//�����p�x
	inline int GetWaterNum() { return m_iWaterNum; }//�����Ă��鐅�̐����擾

//�Z�b�^�[
	inline void SetWaterNum() { m_iWaterNum++; }	//������������

};




