#pragma once
#include "DxLib.h"

class CNumber
{
public:
	//	������
	void InitNumber(void);
	//	�摜�̃��[�h
	void LoadNumber(void);
	//	�X�V
	void UpdateNumber(void);
	//	�Q���`��
	void Draw2dNumber(void);
	//  �R���`�� �����ŕ\��������W���󂯎��
	void Draw3dNumber(VECTOR DrawPos, float Size);
	//	�摜�j��
	void ExitNumber(void);

	//	���Z����
	void AddNumber(int score);
	//	�����I�ɃZ�b�g����
	void SetNumber(int score);
	//	�擾����
	int GetNumber(void);

};


