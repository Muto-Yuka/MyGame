#pragma once
#include "../Player/Player.h"

class CFlag
{
	int FlagX = 0, FlagY = 0;//���W
	int FlagGraph = 0;     //�摜
	bool life = 0;
public:
	void Init();		//������
	void Load();		//���[�h
	void Step(CPlayer& cPlayer);	//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��
	void Hit();
};






