#pragma once
#include "../SceneBase.h"

class CClear : public CSceneBase
{
public:
	CClear();
	~CClear();

	int  Loop();		//���[�v 
	void Draw();		//�`��

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Exit();		//�j��
	void Next();		//����

};




