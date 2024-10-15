#include "Math.h"

//�p�x���擾�iX���j
float CMath::GetAngleX(VECTOR vec1, VECTOR vec2)
{
	return -(atan2f(vec1.y - vec2.y, vec1.z - vec2.z));
}

//�p�x���擾�iY���j
float CMath::GetAngleY(VECTOR vec1, VECTOR vec2)
{
	return atan2f(vec1.x - vec2.x, vec1.z - vec2.z);
}

//�p�x���擾�iZ���j
float CMath::GetAngleZ(VECTOR vec1, VECTOR vec2)
{
	return -(atan2f(vec1.y - vec2.y, vec1.x - vec2.x));
}

//��Βl�̎擾
float CMath::MyAbsf(float i_fNum)
{
	if (i_fNum < 0.0f)
	{
		i_fNum = -i_fNum;
	}
	return i_fNum;
}




