#pragma once

//�N���A�ɔ�ԉ�
#define POP_FULL (20)

class CPop
{
	int PopX, PopY;//���W
	int PopGraph[4];     //�|�b�v�R�[���摜
	bool nothing;
	bool little;
	bool half;
	bool full;
public:
	CPop();
	~CPop();

	void Init();		//������
	void Load();		//���[�h
	void Step(int num);		//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��
};



