#pragma once
#include "../SceneBase.h"

class CGameover : public CSceneBase
{
public:
	CGameover();
	~CGameover();

	int Loop();		//���[�v 
	void Draw();		//�`��

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Exit();		//�j��
	void Next();		//����

};




