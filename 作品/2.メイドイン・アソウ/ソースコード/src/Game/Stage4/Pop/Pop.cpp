#include "Pop.h"
#include <DxLib.h>

//�������@��]��
#define POP_BEAN (5)
//�������傢�͂�����@��]��
#define POP_BEANBURST (10)
//���傢����S���͂�����
#define POP_BURST (15)

CPop::CPop()
{
	Init();
}
CPop::~CPop()
{
	Exit();
}

void CPop::Init()//������
{
	// �L�����N�^�[�̏����f�[�^���Z�b�g
	PopX = 0;
	PopY = 0;
	nothing = true;
	little = false;
	half = false;
	full = false;
}
void CPop::Load()//���[�h
{
	// �O���t�B�b�N�̃��[�h
	PopGraph[0] = LoadGraph("data/Game/Stage4/Bg.png");
	PopGraph[1] = LoadGraph("data/Game/Stage4/popstate1.png");
	PopGraph[2] = LoadGraph("data/Game/Stage4/popstate2.png");
	PopGraph[3] = LoadGraph("data/Game/Stage4/popstate3.png");

}
void CPop::Step(int num)//�X�e�b�v
{
	if (num > POP_BEAN)
	{
		nothing = false;
		little = true;
	}
	if (num > POP_BEANBURST)
	{
		little = false;
		half = true;
	}
	if (num > POP_BURST)
	{
		half = false;
		full = true;
	}
}
void CPop::Draw()//�`��
{
	DrawGraph(PopX, PopY, PopGraph[0], true);

	if (little == true)
		DrawGraph(PopX, PopY, PopGraph[1], true);
	else if (half == true)
		DrawGraph(PopX, PopY, PopGraph[2], true);
	else if (full == true)
		DrawGraph(PopX, PopY, PopGraph[3], true);

}
void CPop::Exit()//�j��
{
	for (int i = 0; i < 4; i++ )
		DeleteGraph(PopGraph[i]);
}





