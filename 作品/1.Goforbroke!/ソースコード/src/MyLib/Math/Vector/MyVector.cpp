#include "MyVector.h"

//�x�N�g������
VECTOR CMyVector::VecCreate(VECTOR vPosA, VECTOR vPosB)
{
	VECTOR result;
	result.x = vPosB.x - vPosA.x;
	result.y = vPosB.y - vPosA.y;
	result.z = vPosB.z - vPosA.z;
	return result;
}

//�x�N�g���̒�����Ԃ�
float CMyVector::VecLong(VECTOR PosA, VECTOR PosB)
{
	float result;
	result = sqrtf((PosA.x - PosB.x) * (PosA.x - PosB.x) + (PosA.y - PosB.y) * (PosA.y - PosB.y) + (PosA.z - PosB.z) * (PosA.z - PosB.z));
	return result;
}

//�x�N�g���̑����Z
VECTOR CMyVector::VecAdd(VECTOR vecA, VECTOR vecB)
{
	VECTOR result;
	result.x = vecA.x + vecB.x;
	result.y = vecA.y + vecB.y;
	result.z = vecA.z + vecB.z;

	return result;
}

//�x�N�g���̈����Z
VECTOR CMyVector::VecSubtract(VECTOR vecA, VECTOR vecB)
{
	VECTOR result;
	result.x = vecA.x - vecB.x;
	result.y = vecA.y - vecB.y;
	result.z = vecA.z - vecB.z;

	return result;

}

//�x�N�g���̃X�J���[�{
VECTOR CMyVector::VecScale(VECTOR vec, float scale)
{
	VECTOR result;
	result.x = vec.x * scale;
	result.y = vec.y * scale;
	result.z = vec.z * scale;

	return result;
}

//�x�N�g���̓���
float CMyVector::VecDot(VECTOR vecA, VECTOR vecB)
{
	float result;
	result = vecA.x * vecB.x + vecA.y * vecB.y + vecA.z * vecB.z;
	return result;
}

//�x�N�g���̊O��
VECTOR CMyVector::VecCross(VECTOR vecA, VECTOR vecB)
{
	VECTOR result;
	result.x = vecA.y * vecB.z - vecA.z * vecB.y;
	result.y = vecA.z * vecB.x - vecA.x * vecB.z;
	result.z = vecA.x * vecB.y - vecA.y * vecB.x;
	return result;
}

//�x�N�g���̐��K��
VECTOR CMyVector::VecNormalize(VECTOR vec)
{
	float size;
	VECTOR result;
	size = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	size = sqrtf(size);
	result.x = vec.x / size;
	result.y = vec.y / size;
	result.z = vec.z / size;

	return result;
}

//�x�N�g���~�s��
VECTOR CMyVector::Transform(MATRIX mat, VECTOR vec)
{
	float tVec[4];
	float rVec[4] = {0.0f, 0.0f, 0.0f, 0.0f};
	VECTOR result;
	tVec[0] = vec.x;
	tVec[1] = vec.y;
	tVec[2] = vec.z;
	tVec[3] = 1;
	for(int i = 0; i < 4; i++)
	{
		for(int k = 0; k < 4; k++)
		{
			rVec[i] += (mat.m[i][k] * tVec[k]);
		}
	}

	result.x = rVec[0];
	result.y = rVec[1];
	result.z = rVec[2];

	return result;
}



