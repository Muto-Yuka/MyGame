#include "Player3.h"
#include <DxLib.h>

//������
const char HAND_PATH[] = { "data/Game/Stage3/Image.png" };
//�v���C���[�i�ځj
const char HEAD_PATH[] = { "data/Game/Stage3/haed.png" };
//���E�ɓ�����̑���
const int HAND_SPEED = 10;

CPlayer3::CPlayer3()
{
	Init();
}
CPlayer3::~CPlayer3()
{
	Exit();
}
//������
void CPlayer3::Init()
{
	//��
	HandX = 0;
	HandY = 0;
	right = true;
	left = false;
	offer = false;

	// �L�����N�^�[�̏����f�[�^���Z�b�g
	HeadX = 0;
	HeadY = 400;

	SetFontSize(80);

}
//���[�h
void CPlayer3::Load()
{
	HandGraph = LoadGraph(HAND_PATH);
	headGraph = LoadGraph(HEAD_PATH);
}
//�X�e�b�v
void CPlayer3::Step()
{
	//��ʊO�ɂ����Ȃ��悤�ɂ��鏈��
	if (HandX < 0)
	{
		HandX = 0;
	}
	if (HandX > 1720)
	{
		HandX = 1720;
	}
	//�E�Ɉړ�
	if (right == true)//�E�t���O���I���Ȃ�
	{
		if (offer == false)
		{
			HandX += HAND_SPEED;//�E�ɐi��
			if (HandX == 1720)//��ʒ[�Ȃ�
			{
				right = false;//�E�t���O�I�t
				left = true;//���t���O�I��
			}
		}
	}
	//���Ɉړ�
	if (left == true)//���t���O���I���Ȃ�
	{
		if (offer == false)
		{
			HandX -= HAND_SPEED;//���ɐi��
			if (HandX == 0)//��ʒ[�Ȃ�
			{
				left = false;//���t���O�I�t
				right = true;//�E�t���O�I��
			}
		}
	}
	//����X�g�b�v
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		offer = true;
	}
}
void CPlayer3::Hit()
{

}
//�`��
void CPlayer3::Draw()
{
	// ���`�悷��
	DrawGraph(HandX, HandY, HandGraph, true);
	// �v���C���[�i�ځj
	DrawGraph(HeadX, HeadY, headGraph, true);

	DrawFormatString(0, 0, GetColor(175, 238, 238), "Space�L�[�Ŗږ������");
}
//�j��
void CPlayer3::Exit()
{
	DeleteGraph(HandGraph);
	DeleteGraph(headGraph);
}




