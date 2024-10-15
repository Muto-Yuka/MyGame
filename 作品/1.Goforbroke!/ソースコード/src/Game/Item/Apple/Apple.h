#pragma once
#include "../BaseItem.h"
#include "../../../Character/Player/Player.h"

//�����ɏo������A�C�e���̐�
#define APPLE_NUM		(5)


class CApple : public CItemBase
{
private:
	int m_iHp;						//�H���E�̗�
	int m_iOnHndl[PLAYER_HP];		//2D�H���Q�[�W�摜�n���h��(�����ɕ`��)
	int m_iUnderHndl[PLAYER_HP];	//2D�H���Q�[�W�摜�n���h���i���ɉe�Ƃ��ĕ`��j
	int StartTime;					//�X�^�[�g����
	int MaxPlayerHp;				//�v���C���[�̃}�b�N�X����
	bool ResultFrg;					//���U���g�ɍs�����ǂ����@true:���U���g, false �������Ȃ�
	int m_iWaitCnt;					//�A�C�e���̏o�����ԊǗ�


public:

	//�R���X�g���N�^
	CApple();
	//�f�X�g���N�^
	~CApple();

	//������
	void Init(CPlayer &cPlayer);
	//���[�h
	void Load();
	//���[�v
	void Step();
	//�`��
	void Draw();

	CItemBase m_cApple[APPLE_NUM];

//**�e�֐�**==

	//�v���C���[�Ɠ���������̏���
	void HitItem();

//**�Q�b�^�[�E�Z�b�^�[**==

	//�H���Q�[�W�����炷�B�ϐ��ɃZ�b�g����
	inline void SetAppleGauge() { m_iHp--; }

	//�~�b�V�������������s��
	//true:���U���g�ց@	false:�~�b�V�����������̂܂�
	inline bool GetResultFrg() { return ResultFrg; }

};




