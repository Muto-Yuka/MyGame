#pragma once
#include "DxLib.h"
#include <math.h>

class CMyMatrix
{
public:
	//�P�ʍs����擾
	static MATRIX GetIdentityMatrix();
	//���s�ړ��s����擾
	static MATRIX GetTranslateMatrix(VECTOR a);
	//�g�k�s����擾
	static MATRIX GetScalMatrix(VECTOR a);
	//X����]�s����擾�i��]�l���W�A���j
	static MATRIX GetPitchMatrix(float rot);	
	//Y����]�s����擾�i��]�l���W�A���j
	static MATRIX GetYawMatrix(float rot);	
	//Z����]�s����擾�i��]�l���W�A���j
	static MATRIX GetRollMatrix(float rot);	
	//�����Z����s��
	static MATRIX MatAdd(MATRIX a, MATRIX b);
	//�����œn���ꂽ�s����X�J���[�{����i�����s��ƃX�J���[�l�j
	static MATRIX MatScale(MATRIX a, float s);	
	//�|���Z������
	static MATRIX MatMult(MATRIX a, MATRIX b);
	//�s��X�x�N�g�����s��(�ϊ��v�Z)
	static VECTOR MatTransform(MATRIX a, VECTOR b);
	//�s��]�l���s��
	static MATRIX MatTranspose(MATRIX a);

};


