#pragma once

class CBackGround3
{
	int bgSkyHandle;
public:
	CBackGround3();
	~CBackGround3();

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��
	void Hit();
};