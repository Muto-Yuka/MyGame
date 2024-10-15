#pragma once

class CPlayer
{
	int PlayerX, PlayerY;//���W
	int PlayerGraph;     //�v���C���[�摜
	int Deadpath;		//���X�|�[���摜
	int Respawn;		 //�v���C���[���X�|�[��
	int RespawnTime;	//���X�|�[���ł���܂ł̎���
	float JumpPower;     //�W�����v��
	float time;          //�C���^�[�o��
	bool life;			//�����t���O
	bool BrockHit;		//�u���b�N��HIT������
	bool Clear,Gameover;

	const int MaxFrame = 10;
	int Ani_image[10];
	int Frame = 0;
	int Frame_adjust = 0;

public:	
	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��

	void Hit();
	void Jump();		//�W�����v����

//�Q�b�^�[
	inline int GetPlayerX() { return PlayerX; }		//X���W
	inline int GetPlayerY() { return PlayerY; }		//Y���W
	inline bool GetClear() { return Clear; }		//true:Clear�@false:�ҋ@
	inline bool GetGameover() { return Gameover; }	//true:Gameover�@false:�ҋ@
	inline bool GetLife() { return life; }			//���C�t�擾
	//�Z�b�^�[
	inline void SetJump(float power) { JumpPower = power; }	//�W�����v�p���[
	inline void SetPlayerLife(bool Frg) { life = Frg; }		//�v���C���[HP
	inline void SetPlayerHit(bool Frg) { BrockHit = Frg; }	//Hit������
	inline void SetClear() { Clear = true; }
};




