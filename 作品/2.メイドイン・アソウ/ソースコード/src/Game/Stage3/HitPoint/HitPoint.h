#pragma once

class CHitPoint
{
	int EyeX, EyeY;	//���W
	int EyeGraph;		//�v���C���[�摜
public:
	CHitPoint();
	~CHitPoint();

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��
	void Hit();

//�Q�b�^�[
	int HitX() { return EyeX; }
	int HitY() { return EyeY; }

};




