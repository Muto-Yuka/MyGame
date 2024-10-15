#include "MyMatrix.h"

//�P�ʍs����擾
MATRIX CMyMatrix::GetIdentityMatrix()
{
	MATRIX matrix;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (i == k)
				matrix.m[i][k] = 1;
			else
				matrix.m[i][k] = 0;
		}
	}
	return matrix;
}

//���s�ړ��s����擾
MATRIX CMyMatrix::GetTranslateMatrix(VECTOR a)
{
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][3] = a.x;
	matrix.m[1][3] = a.y;
	matrix.m[2][3] = a.z;

	return matrix;
}

//�g�k�s����擾
MATRIX CMyMatrix::GetScalMatrix(VECTOR a)
{
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][0] = a.x;
	matrix.m[1][1] = a.y;
	matrix.m[2][2] = a.z;

	return matrix;
}

//X����]�s����擾 //��]�l���W�A��
MATRIX CMyMatrix::GetPitchMatrix(float rot)
{
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[1][1] = cosf(rot);
	matrix.m[1][2] = -sinf(rot);
	matrix.m[2][1] = sinf(rot);
	matrix.m[2][2] = cosf(rot);

	return matrix;
}

//Y����]�s����擾 //��]�l���W�A��
MATRIX CMyMatrix::GetYawMatrix(float rot)
{
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][0] = cosf(rot);
	matrix.m[2][0] = -sinf(rot);
	matrix.m[0][2] = sinf(rot);
	matrix.m[2][2] = cosf(rot);

	return matrix;
}
//Z����]�s����擾		//��]�l���W�A��
MATRIX CMyMatrix::GetRollMatrix(float rot)
{
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][0] = cosf(rot);
	matrix.m[0][1] = -sinf(rot);
	matrix.m[1][0] = sinf(rot);
	matrix.m[2][2] = cosf(rot);

	return matrix;
}

//�����Z����s��
MATRIX CMyMatrix::MatAdd(MATRIX a, MATRIX b)
{
	MATRIX matrix;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			matrix.m[i][k] = a.m[i][k] + b.m[i][k];
		}
	}
	return matrix;
}

//�����œn���ꂽ�s����X�J���[�{����//�����s��ƃX�J���[�l
MATRIX CMyMatrix::MatScale(MATRIX a, float scale)
{
	MATRIX matrix;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			matrix.m[i][k] = a.m[i][k] * scale;
		}
	}
	return matrix;
}

//�|���Z������
MATRIX CMyMatrix::MatMult(MATRIX a, MATRIX b)
{
	MATRIX matrix;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				matrix.m[i][j] += (a.m[i][k] * b.m[k][j]);
			}
		}
	}
	return matrix;
}

//�s��X�x�N�g�����s��(�ϊ��v�Z)
VECTOR CMyMatrix::MatTransform(MATRIX a, VECTOR b)
{
	float work[4] = { 0 };
	float result_buf[4] = { 0 };
	VECTOR result_vec;
	work[0] = b.x;
	work[1] = b.y;
	work[2] = b.z;
	work[3] = 1;

	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			result_buf[i] += (a.m[i][k] * work[k]);
		}
	}
	result_vec.x = result_buf[0];
	result_vec.y = result_buf[1];
	result_vec.z = result_buf[2];

	return result_vec;
}

//�s��]�l���s��
MATRIX CMyMatrix::MatTranspose(MATRIX a)
{
	MATRIX matrix = { 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix.m[j][i] = a.m[i][j];
		}
	}

	return matrix;
}





