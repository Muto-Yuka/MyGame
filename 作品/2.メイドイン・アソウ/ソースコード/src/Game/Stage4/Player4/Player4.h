#pragma once

class CPlayer4
{
	enum tag_number
	{
		one,
		two,
		three,
		four,
	};

	int PlayerX, PlayerY;//���W
	int PlayerGraph;     //�v���C���[�摜
	bool fast;
	bool second;
	bool third;
	bool forth;
	bool turn;
	int num;
	int times;
public:
	CPlayer4();
	~CPlayer4();

	void Init();		//������
	void Load();		//���[�h
	void Update();
	void Step();		//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��

	//���Ԃ��擾
	inline int GetTime() { return  times;}

};




