#pragma once
#include "../BaseItem.h"
#include "../../../Character/Player/Player.h"

//�����ɏo������A�C�e���̐�
#define STRAW_NUM		(5)

class CStraw : public CItemBase
{
private:
	int m_iItemNum;		//�擾�����A�C�e���̐�

public:

	//�R���X�g���N�^
	CStraw();
	//�f�X�g���N�^
	~CStraw();

	//������
	void Init();
	//���[�h
	void Load();
	//���[�v
	void Step();
	//�`��
	void Draw();

	CItemBase m_cStraw[STRAW_NUM];

	//**�e�֐�**==
		//�v���C���[�Ɠ���������̏���
	void HitItem();
	////���̃��X�|�[������
	//void Respawn();

//**�Q�b�^�[�E�Z�b�^�[**==
	//�擾�����A�C�e���̐���Ԃ�
	inline int GetItemNum() { return m_iItemNum; }
};




