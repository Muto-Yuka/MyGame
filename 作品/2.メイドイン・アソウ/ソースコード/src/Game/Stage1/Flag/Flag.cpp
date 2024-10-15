#include "Flag.h"
#include <DxLib.h>
#include "../../../MyLib/Collision/Collision.h"

const char FLAG_PATH[] = { "data/Game/Stage1/flag2.png" };
//�v���C���[�����B������t���O���o��
const int FLAG_X = 400;

//������
void CFlag::Init()
{
	FlagX = -100;
	FlagY = 270;
	life = false;
}
//���[�h
void  CFlag::Load()
{
	FlagGraph = LoadGraph(FLAG_PATH);
}
//�X�e�b�v
void  CFlag::Step(CPlayer &cPlayer)
{
	if (cPlayer.GetPlayerX() < FLAG_X)
	{
		life = true;
	}
	if (life == true)
	{
		//�v���C���[�������Ă���Ƃ�
		if (cPlayer.GetLife() == true)
		{
			if (CheckHitKey(KEY_INPUT_A) == 1)
				FlagX = FlagX + 3;
			if (CheckHitKey(KEY_INPUT_D) == 1)
				FlagX = FlagX - 2;
		}
	}

	//�v���C���[�Ƃ̓����蔻��
	if (CCollision::IsHitRect(cPlayer.GetPlayerX(), cPlayer.GetPlayerY(),
		75, 75, FlagX, FlagY, 50, 208))
	{
		cPlayer.SetClear();
	}

}
//�`��
void  CFlag::Draw()
{
	if (life == true)
	{
		DrawGraph(FlagX, FlagY, FlagGraph, TRUE);
	}
}
//�j��
void  CFlag::Exit()
{
	DeleteGraph(FlagGraph);
}
void  CFlag::Hit()
{

}




