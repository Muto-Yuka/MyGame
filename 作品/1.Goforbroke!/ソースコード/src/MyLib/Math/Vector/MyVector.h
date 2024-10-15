#pragma once
#include "DxLib.h"
#include <math.h>

class CMyVector 
{
public:
	//�x�N�g���쐬
	VECTOR VecCreate(VECTOR PosA, VECTOR PosB);
	//�x�N�g���̒���
	float VecLong(VECTOR PosA, VECTOR PosB);
	//�x�N�g���̑����Z
	VECTOR VecAdd(VECTOR vecA, VECTOR vecB);
	//�x�N�g���̈����Z
	VECTOR VecSubtract(VECTOR vecA, VECTOR vecB);
	//�x�N�g���̃X�J���[�{
	VECTOR VecScale(VECTOR vec, float scale);
	//�x�N�g���̓���
	float VecDot(VECTOR vecA, VECTOR vecB);
	//�x�N�g���̊O��
	VECTOR VecCross(VECTOR vecA, VECTOR vecB);
	//�x�N�g���̐��K��
	VECTOR VecNormalize(VECTOR vec);
	//�x�N�g���~�s��
	VECTOR Transform(MATRIX mat, VECTOR vec);

};


