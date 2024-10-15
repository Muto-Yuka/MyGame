#include "BackGround3.h"
#include <DxLib.h>

const char BG_PATH[] = { "data/Game/Stage3/bg.png" };

CBackGround3::CBackGround3()
{
	Init();
}
CBackGround3::~CBackGround3()
{
	Exit();
}

//������
void CBackGround3::Init()		
{
	bgSkyHandle = -1;
}
//���[�h
void CBackGround3::Load()		
{
	bgSkyHandle = LoadGraph(BG_PATH);
}
//�X�e�b�v
void CBackGround3::Step()		
{

}
//�`��
void CBackGround3::Draw()		
{
	DrawGraph(0, 0, bgSkyHandle, true);
}
//�j��
void CBackGround3::Exit()		
{
	DeleteGraph(bgSkyHandle);
}
void CBackGround3::Hit()
{

}