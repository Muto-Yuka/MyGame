#pragma once

class CScore 
{
public:
	//������
	void InitScore();							
	//���[�h
	void LoadScore();						
	//�Q���`��
	void Draw2dScore();							
	//�R���`��
	void Draw3dScore(VECTOR DrawPos, float Size);	
	//�摜�j��
	void ExitScore();							
	//���Z����
	void AddScore(int score);						
	//�����I�ɃZ�b�g����
	void SetScore(int score);						
	//�擾����
	int GetScore();								

};


