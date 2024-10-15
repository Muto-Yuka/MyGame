#include "Drop.h"
#include <DxLib.h>
#include "../../../MyLib/Collision/Collision.h"

const char WATER_PATH[] = { "data/Game/Stage3/Drop.png" };

CDrop::CDrop()
{
	Init();
}
CDrop::~CDrop()
{
	Exit();
}
//������
void CDrop::Init()
{
	life = false;
	DropY = 400;
	DropX = 0;
	time = 5.0f;
}
//���[�h
void CDrop::Load()
{
	// �O���t�B�b�N�̃��[�h
	DropGraph = LoadGraph(WATER_PATH);
}
//�X�e�b�v
void CDrop::Step(CPlayer3 &cPlayer)
{
	bool now = cPlayer.GetOffer();

	if (now)
	{
		life = true;
		for (int i = 0; i < 1; i++)
		{
			DropX = cPlayer.GetHandX() + 70;
		}
		now = false;
	}
	if (life == true)
	{
		time = time - 1.0f;
		if (time == 0.0f)
		{
			DropY += cPlayer.GetHandY() + 20;
			time = 5.0f;
		}
	}
}
//�P�F�N���A�@�Q�F�Q�[���I�[�o�[
int CDrop::Hit(CHitPoint& cHitPoint)
{
	//���ƃq�b�g�|�C���g�̓��������
	if (CCollision::IsHitRect(DropX, DropY, 90, 90, cHitPoint.HitX(), cHitPoint.HitY(), 125, 150) == true)
	{
		return 1;
	}
	else if (DropY == 1080)
		return 2;

	return 0;
}
//�`��
void CDrop::Draw()
{
	// �v���C���[��`�悷��
	if (life == true)
	{
		DrawGraph(DropX, DropY, DropGraph, true);
	}
}
//�j��
void CDrop::Exit()
{
	DeleteGraph(DropGraph);
}






