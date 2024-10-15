#pragma once
#include <DxLib.h>

class CCollision
{
public:
//�R�c
	// �{�b�N�X�ǂ���
	static bool CheckHitBoxToBox(VECTOR pos1, VECTOR pos2, VECTOR size1, VECTOR size2);
	// ���ǂ���
	static bool CheckHitSphereToSphere(VECTOR pos1, VECTOR pos2, float r1, float r2);

//�Q�c
	//��`�ǂ���
	static bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);
	//�~�ǂ���
	static bool IsHitCircle(int Xa, int Xb, int Ya, int Yb, int Ra, int Rb);

};



