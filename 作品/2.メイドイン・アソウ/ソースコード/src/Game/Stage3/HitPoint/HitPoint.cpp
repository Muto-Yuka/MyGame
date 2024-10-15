#include "HitPoint.h"
#include <DxLib.h>

const char EYE_PATH[] = { "data/Game/Stage3/Hitpoint.png" };

CHitPoint::CHitPoint()
{
	Init();
}
CHitPoint::~CHitPoint()
{
	Exit();
}
//������
void CHitPoint::Init()
{
	// �L�����N�^�[�̏����f�[�^���Z�b�g
	EyeX = 1050;
	EyeY = 900;
}
//���[�h
void CHitPoint::Load()
{
	// �O���t�B�b�N�̃��[�h
	EyeGraph = LoadGraph("Data/Hitpoint.png");
}
//�X�e�b�v
void CHitPoint::Step()
{

}
void CHitPoint::Hit()
{

}
//�`��
void CHitPoint::Draw()
{

}
//�j��
void CHitPoint::Exit()
{
	DeleteGraph(EyeGraph);

}
