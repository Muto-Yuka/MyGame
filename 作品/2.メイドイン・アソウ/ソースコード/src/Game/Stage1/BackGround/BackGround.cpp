#include "BackGround.h"
#include <DxLib.h>

//�w�i
const char BG_PATH[] = { "data/Game/Stage1/Bg.png" };

CBackGround::CBackGround()
{
	Init();
}
CBackGround::~CBackGround()
{
	Exit();
}

//������
void CBackGround::Init()
{
	bgSkyX[0] = 0;
	bgSkyX[1] = -1920;
}
//���[�h
void CBackGround::Load()		
{
	//�w�i
	for (int i = 0; i < 2; i++)
	{
		bgSkyHandle[i] = LoadGraph(BG_PATH);
	}
}
//�X�e�b�v
void CBackGround::Step(CPlayer& cPlayer)
{
	//�w�i�̈ړ�
	for (int i = 0; i < 2; i++)
	{
		if (bgSkyX[i] > 1920)
		{
			int Index = 0;
			if (i == 0)
				Index = 1;
			bgSkyX[i] = bgSkyX[Index] - 1920;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (bgSkyX[i] < -1920)
		{
			int Index = 0;
			if (i == 0)
				Index = 1;
			bgSkyX[i] = bgSkyX[Index] + 1920;
		}
	}
	if (cPlayer.GetLife())
	{
		if (CheckHitKey(KEY_INPUT_D) == 1)
		{
			for (int i = 0; i < 2; i++)
			{
				bgSkyX[i] -= 2;
			}
		}
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			for (int i = 0; i < 2; i++)
			{
				bgSkyX[i] += 3;
			}
		}
	}
	
}
//�`��
void CBackGround::Draw()
{
	//�w�i
	for (int i = 0; i < 2; i++)
		DrawGraph(bgSkyX[i], 0, bgSkyHandle[i], true);
}
//�j��
void CBackGround::Exit()	
{
	for (int i = 0; i < 2; i++)
		DeleteGraph(bgSkyHandle[i]);
}








