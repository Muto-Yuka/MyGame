#pragma once
#include "../Player/Player.h"

//26�u���b�N�����ɕ��ׂ�
const int GROUND_NUM = 26;

class CBackGround
{
	int bgSkyHandle[2] = { 0 };
	int bgSkyX[2] = { 0 };
	int bgSkyY[2] = { 0 };

public:
	CBackGround();
	~CBackGround();

	void Init();		//������
	void Load();		//���[�h
	void Step(CPlayer& cPlayer);//�X�e�b�v
	void Exit();		//�j��
	void Draw();		//�`��
};




