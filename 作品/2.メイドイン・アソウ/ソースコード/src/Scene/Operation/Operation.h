#pragma once
#include "../SceneBase.h"

static const int OPERATION_NUM = 2;	//�\����������摜�̐� �c�̖���

class COperation : public CSceneBase
{
public:
	COperation();
	~COperation();

	int Loop();		//���[�v 
	void Draw();		//�`��

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Exit();		//�j��
	void Next();		//����

};




