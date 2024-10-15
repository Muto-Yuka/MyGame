#pragma once

#include "Apple/Apple.h"
#include "Water/Water.h"
#include "Branch/Branch.h"
#include "Straw/Straw.h"
#include "Tree/Tree.h"

class CItemManager
{
public:

	CApple cApple;
	CBranch cBranch;
	//CLeaf cLear;
	//CTent cTent;
	CStraw cStraw;
	CTree cTree;
	CWater cWater;

	//�R���X�g���N�^�E�f�X�g���N�^
	CItemManager();
	~CItemManager();

	//������
	void Init(CPlayer& cPlayer);
	//���[�h
	void Load();
	//���[�v
	void Step();
	//�`��
	void Draw();
	//�I��
	void Exit();

	//**�e�֐�**==
		//�f�o�b�N�p�����蔻��\��
	void MyDbug();

	//**�Q�b�^�[�E�Z�b�^�[**==
		//���U���g�֍s���� true:���U���g�� false:���̂܂܃v���C
	bool GetResultFrg();
	//���̌���Ԃ�
	inline int GetStrawNum() { return cStraw.GetItemNum(); }

	//�A�C�e�����擾
	inline CItemBase& GetApple(int iID) { return cApple.m_cApple[iID]; }
	inline CItemBase& GetStraw(int iID) { return cStraw.m_cStraw[iID]; }
	inline CItemBase& GetTree(int iID) { return cTree.m_cTree[iID]; }

	//���ꂪ�B���ł��Ă��邩�ǂ���
	bool GetWaterClearFrg();

};




