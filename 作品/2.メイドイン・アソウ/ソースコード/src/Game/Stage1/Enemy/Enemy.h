#pragma once
#include "../Player/Player.h"

//�G�̐�
const int ENEMY_NUM = 2;

class CEnemy
{
	int EnemyX[ENEMY_NUM] = { 0 }, EnemyY[ENEMY_NUM] = { 0 };//���W
	int EnemyGraph[ENEMY_NUM] = { 0 };     //�摜
	float time;							 //�C���^�[�o��
	bool life[ENEMY_NUM] = { 0 };
public:
	void Init();				//������
	void Load();				//���[�h
	void Step(CPlayer& cPlayer);//�X�e�b�v
	void Draw();				//�`��
	void Exit();				//�j��

};






