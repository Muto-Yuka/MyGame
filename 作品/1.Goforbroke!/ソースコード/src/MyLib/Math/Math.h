#pragma once
#include <DxLib.h>
#include <math.h>

class CMath 
{
public:
	//�p�x���擾(Y��)
	float GetAngleY(VECTOR vec1, VECTOR vec2);
	//�p�x���擾(X��)
	float GetAngleX(VECTOR vec1, VECTOR vec2);
	//�p�x���擾(Z��)
	float GetAngleZ(VECTOR vec1, VECTOR vec2);
	//��Βl�̎擾
	float MyAbsf(float i_fNum);

};





