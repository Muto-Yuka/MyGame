#pragma once
#include "../Player/Player.h"

//���ɕ����u���b�N�̐�
const int BROCK_NUM = 3;

class CBrock
{
	int BrockX[BROCK_NUM] = { 0 };			//���W
	int BrockY[BROCK_NUM] = { 0 };			
	int BrockGraph[BROCK_NUM] = { 0 };		//�摜
	float time;								//�C���^�[�o��
public:
	CBrock();
	~CBrock();

	void Init();		//������
	void Load();		//���[�h
	void Step(CPlayer &cPlayer);//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��
};





