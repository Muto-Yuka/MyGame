#pragma once
#include "../SceneBase.h"

class CTitle :public CSceneBase
{
	float m_fVolume;
public:
	CTitle();
	~CTitle();

	int  Loop();		//���[�v 
	void Draw();		//�`��

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Exit();		//�j��
	void Next();		//����

	//���ʒ���
	void Volume();

};




