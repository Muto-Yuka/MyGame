#pragma once
#include "../BaseItem.h"

//�`�悷��؂̐�
#define TREE_NUM (2)

class CTree : public CItemBase
{
private:
	float m_hp;				//�̗�
	bool HitFrg;			//�������Ă邩�ǂ����@true�������Ă�@false�������ĂȂ�

public:

	//�R���X�g���N�^
	CTree();
	//�f�X�g���N�^
	~CTree();

	//������
	void Init();
	//���[�h
	void Load();
	//���[�v
	void Step();
	//�`��
	void Draw();

	CItemBase m_cTree[TREE_NUM];

	//**�e�֐�**==
		////�v���C���[�Ɠ���������̏���
		//void HitItem();

	//**�Q�b�^�[�E�Z�b�^�[**==

};




