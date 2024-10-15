#pragma once
#include "../BaseItem.h"
#include "Number/Number.h"

//�����Q�[�W�̐�
#define GAUGE_NUM	(8)		

class CWater : public CItemBase
{
private:
	float	m_hp;						//����̗̑�
	bool	HitFrg;						//����ɓ������Ă邩�ǂ����@true�������Ă�@false�������ĂȂ�
	int		interval;					//�����񕜂��鑬�x�i�Ԋu�j
	int		m_iOnHndl[GAUGE_NUM];		//2D�H���Q�[�W�摜�n���h��(�����ɕ`��)
	int		m_iUnderHndl[GAUGE_NUM];	//2D�H���Q�[�W�摜�n���h���i���ɉe�Ƃ��ĕ`��j
	int		WaterGauge;					//2d�����Q�[�W�\��
	int		StartTime;					//�~�b�V�������Ă΂�Ă���̎���
	bool	m_bResult;					//���U���g�ɍs�����ǂ���
	int		m_iPlayerWater;				//�v���C���[�������Ă鐅�̐�
	int		HitCount;					//�A���Ő���́����A�b�v���Ȃ��悤���䂷��

	//�摜�n���h���E���f���n���h��
	int m_2dHpHndl;
	int m_iFoggyHndl;					//���������Ă��ɂ����̎��ɐ��`��

	CNumber cNumber;

public:

	//�R���X�g���N�^
	CWater();
	//�f�X�g���N�^
	~CWater();

	//������
	void Init();
	//���[�h
	void Load();
	//���[�v
	void Step();
	//�`��
	void Draw();

	//�e�֐�����============================
		//�G�Q�Ɠ����������̏����i������󂷁j
	void HitBreakWater();
	//�v���C���[�Ɠ����������̏���(������C��)
	void HitRepairWater();
	//����ɐ���߂����� �����Ŏ����Ă��鐅�̐�������Ă���
	void HitReturnWater(int WaterNum);

	//�Q�b�^�[�E�Z�b�^�[==================
		//���ꐶ���t���O���擾 true ���݁@false ���Ă��� 
	inline 	bool GetSurvivalFrg() { return m_bSurvival; }
	//�������擾
	inline float GetWaterHp() { return m_hp; }
	//�������Z�b�g
	inline void SetWaterHP(float HP) { m_hp += HP; }
	//����̐�����Ԃ��Z�b�g����
	inline void SetSurvivalFrg(bool Frg) { m_bSurvival = Frg; }
	//�G������Ƀq�b�g���ĂȂ��@false ����
	inline void SetHitFrg(bool Frg) { HitFrg = Frg; }
	//�����Q�[�W�����炷�B�ϐ��ɃZ�b�g����
	inline void SetWaterGauge() { WaterGauge--; }
	//�����Q�[�W�̐����擾����
	inline int GetWaterGauge() { return WaterGauge; }

	//�v���C���[����������̐����Z�b�g���� 
	inline void SetWaterNum(int WaterNum) { m_iPlayerWater = WaterNum; }

	//�~�b�V�������������s��
	//true:���U���g�ց@	false:�~�b�V�����������̂܂�
	inline bool GetResultFrg() { return m_bResult; }
	//����́����B���ł��Ă邩�ǂ���
	inline int  GetWaterClearFrg() { return cNumber.GetNumber(); };

};




