#pragma once
#include "../BaseItem.h"

class CBranch : public CItemBase
{
public:

	//�R���X�g���N�^
	CBranch();
	//�f�X�g���N�^
	~CBranch();

	//������
	void Init();
	//���[�h
	void Load();
	//���[�v
	void Step();

	//�v���C���[�Ɠ���������̏���
	void HitItem();
	//���X�|�[������
	void RespawnApple();


};




