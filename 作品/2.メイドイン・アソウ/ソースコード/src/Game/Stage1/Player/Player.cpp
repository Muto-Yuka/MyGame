#include "Player.h"
#include <DxLib.h>
#include "../../../MyLib/Input/Input.h"
#include "../../../MyLib/Sound/Sound.h"

const char HAND_PATH[] = { "data/Game/Stage1/anim1.png" };
const char RESPAWN_PATH[] = { "data/Game/Stage1/Dead.png" };
//�W�����v����
const float JUMP_TIME = 12.f;
//�W�����v���� 
const int JUMP_HIGH = 15;
//�v���C���[�X�s�[�h
const int PLAYER_SPEED = 5;
//�v���C���[������ɔ�ԑ��x
const int PLAYER_PUSH = 2;
//�v���C���[������
const int PLAYER_RESPAWN = 3;

//������
void CPlayer::Init()
{
	// �L�����N�^�[�̏����f�[�^���Z�b�g
	PlayerX = 1820;
	PlayerY = 800;

	JumpPower = 0.f;
	time = JUMP_TIME;
	life = true;
	BrockHit = false;
	Respawn = PLAYER_RESPAWN;
	Clear = false;
	Gameover = false;
	Deadpath = -1;
	RespawnTime = 0;

	//�����̑傫���ύX
	SetFontSize(80);
}
//���[�h
void CPlayer::Load()
{
	// �O���t�B�b�N�̃��[�h
	LoadDivGraph(HAND_PATH, MaxFrame, MaxFrame, 1, 128, 128, Ani_image);
	//LoadDivGraph("�摜�t�@�C���̃p�X", MaxFrame, MaxFrame, 1, 196, 245, Ani_image)
	Deadpath = LoadGraph(RESPAWN_PATH, true);
}
//�X�e�b�v
void CPlayer::Step()
{
	//�W�����v����
	if (life == true)
		Jump();
	else
		RespawnTime++;
	
	//������΂���Ă���Ƃ��͈ړ��ł��Ȃ�
	if (BrockHit == false )
	{
		if (life == true)
		{
			if (CheckHitKey(KEY_INPUT_D) == 1)
				PlayerX += PLAYER_SPEED;	// �E�������Ă�����E�ɐi��
			if (CheckHitKey(KEY_INPUT_A) == 1)
				PlayerX -= PLAYER_SPEED;	// ���������Ă����獶�ɐi��
		}
	}
	if (CInput::IsInputPush(CInput::INPUT_RESPAWN) && !life)
	{
		if (RespawnTime > 120)
		{
			Respawn -= 1;
			life = true;	//���X�|�[��
			RespawnTime = 0;
		}
	}
	
	//��ʊO�ɂ����Ȃ��悤�ɂ��鏈��
	if (PlayerX < 0)
		PlayerX = 0;
	if (PlayerX >= 1792)
		PlayerX = 1792;

}
//�`��
void CPlayer::Draw()
{
	// �v���C���[��`�悷��
	if (life == true)
	{  //�摜�̕\��
		if (Frame_adjust == 5) {
			Frame++;
			Frame_adjust = 0;
		}
		if (Frame == MaxFrame - 1) {
			Frame = 0;
		}
		Frame_adjust++;
		DrawGraph(PlayerX, PlayerY, Ani_image[Frame], true);
	}	
	else
	{
		DrawFormatString(500, 40, GetColor(255, 99, 71), "[R]�Ń��X�|�[��");
		//���񂾈ʒu�`��
		DrawRotaGraph(PlayerX, PlayerY, 1.f, 1.f,Deadpath,true, false);
	}
	//�c�@�\��
	DrawFormatString(20, 40, GetColor(51, 156, 255), "�c�@�F%d", Respawn);
}
//�j��
void CPlayer::Exit()
{
	DeleteGraph(PlayerGraph);
}

//HIT����
void CPlayer::Hit()
{
	if(life == true)
	life = false;

	//�Q�[���I�[�o�[��
	if (Respawn == 0)
		Gameover = true;
}
//�W�����v
void CPlayer::Jump()
{
	// �����ŏ�ɐi��
	if (time == 0.0f)
	{
		PlayerY -= JUMP_HIGH;
	}

	time = JUMP_TIME;		

	// ��������
	PlayerY -= (int)JumpPower;
	// ���������x��������
	JumpPower -= 0.3f;

	// �����n�ʂɂ��Ă����烊�Z�b�g
	if (PlayerY > 720)
	{
		PlayerY = 720;
		JumpPower = 0;
		BrockHit = false;
	}
	for (int i = 0; i < 5; i++)
		time = time - 5.f;

	if (time < 0.0f)
		time = 0.0f;

	//�󒆃u���b�N�ɓ�����Ό���ɐ������
	if (BrockHit == true)
		PlayerX += PLAYER_PUSH;
	else
		PlayerX += 1;

}



