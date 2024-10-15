#pragma once
#include "../Player3/Player3.h"
#include "../HitPoint/HitPoint.h"

class CDrop
{
	int DropX, DropY, DropY2;//���W
	int DropGraph;     //�v���C���[�摜
	bool life;
	float time;

public:
	CDrop();
	~CDrop();

	void Init();		//������
	void Load();		//���[�h
	void Step(CPlayer3& cPlayer);//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��

	//�P�F�N���A�@�Q�F�Q�[���I�[�o�[
	int Hit(CHitPoint &cHitPoint);
};





