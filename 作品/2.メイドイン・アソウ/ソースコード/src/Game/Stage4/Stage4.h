#pragma once
#include "../GameBase.h"
#include "Player4/Player4.h"
#include "Pop/Pop.h"

//�|�b�v�R�[��
class CStasge4 : public CGameBase
{
	CPlayer4	cPlayer4;
	CPop		cPop;
public:
	CStasge4();
	~CStasge4();

	void Init();		//������
	void Load();		//���[�h
	int  Step();		//�X�e�b�v
	void Exit();		//�j��
	void Draw();		//�`��

	//���U���g����Ԃ� 0:�ҋ@�@1:�N���A�@2:�Q�[���I�[�o�[
	int GetResult();

};




