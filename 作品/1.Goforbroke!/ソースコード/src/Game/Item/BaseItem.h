#pragma once
#include "DxLib.h"

//�H��/�����Q�[�W�C���X�g�����炷
#define SHIFT_ITEM_PICTURE	(28)

class CItemBase
{
protected:
	int m_iHndl;		//�摜�n���h��
	bool m_bSurvival;	//�����t���O
	float m_fRadius;	//���a
	VECTOR m_vPos;		//���W
	int m_RespawnTime;	//�V���ɃX�|�[������܂ł̎���
	float m_fHp;

public:
	//�R���X�g���N�^
	CItemBase();
	//�f�X�g���N�^
	~CItemBase();
	//������ ���a���Z�b�g
	void Init(float Radius);
	//���[�v
	void Step();
	//���X�|�[�����郋�[�v���� �`��͈�xz, �A�C�e���̐�
	void RespawnStep(int x, int z, int ItemNum);
	//�ʏ탍�[�h �o���͈͂��Z�b�g
	void Load(int x, int y);
	//�f�[�^�𕡐����[�h
	void DuplicateLoad(int iMdlHndl, int x, int z);
	//�`��
	void Draw();
	//�I��
	void Exit();


	//�A�C�e�����X�|�[���̏��� �`�悷��͈́A�o�ߎ���
	void RespawnItem(int x, int z, int ItemNum);
	//�A�C�e�����q�b�g��,�t���O��off��
	void HitItem() { m_bSurvival = false; }
	//�����̕������[�h
	void DuplicateLoad(int Hndl) { m_iHndl = MV1DuplicateModel(Hndl); }


	//**�Q�b�^�[�E�Z�b�^�[**==

		//�A�C�e�����t�B�[���h�ɂ��邩�@false��true��
	inline 	bool RequestItem(const VECTOR& vPos);
	//�����蔻��p�i���a�擾�j
	inline 	float GetRadius() { return m_fRadius; }
	//���W�擾
	inline 	VECTOR GetPosition() { return m_vPos; }
	//�����t���O�擾�@true:�����@false:���S
	inline 	bool GetSurvivalFrg() { return m_bSurvival; }
	//�������W���Z�b�g
	inline 	void SetInitPos(VECTOR pos) { m_vPos = pos; }
	//hp���Z�b�g
	inline  void SetHp(float hp) { m_fHp = hp; }
	//hp���Q�b�g
	inline float GetHp() { return m_fHp; }

};






