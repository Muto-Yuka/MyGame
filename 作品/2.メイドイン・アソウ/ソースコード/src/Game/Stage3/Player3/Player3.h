#pragma once

class CPlayer3
{
	//��
	int HandX, HandY;	 //���W
	int HandGraph;		 //�v���C���[�摜
	bool offer;			 //����~�߂邩
	bool left;			
	bool right;
	//�v���C���[�i�ځj
	int HeadX, HeadY;//���W
	int headGraph;     //�v���C���[�摜

public:
	CPlayer3();
	~CPlayer3();

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��
	void Hit();

//�Q�b�^�[
	int GetHandX() { return HandX; }
	int GetHandY() { return HandY; }
	bool GetOffer() { return offer; }


};



