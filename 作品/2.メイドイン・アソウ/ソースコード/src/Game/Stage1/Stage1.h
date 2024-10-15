#pragma once
#include "../GameBase.h"
#include "BackGround/BackGround.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Brock/Brock.h"
#include "Flag/Flag.h"

//�W�����v�������Ă���L���������E�ɓ������X�e�[�W��i��
class CStage1 : public CGameBase
{
	CBackGround	cBackGround;	//�w�i
	CPlayer		cPlayer;		//�v���C���[
	CEnemy		cEnemy;			//�G
	CBrock		cBrock;			//�u���b�N
	CFlag		cFlag;			//�S�[���i���j

public:
	CStage1();
	~CStage1();

	void Init();		//������
	void Load();		//���[�h
	int  Step();		//�X�e�b�v
	void Exit();		//�j��
	void Draw();		//�`��

	//���U���g����Ԃ� 0:�ҋ@�@1:�N���A�@2:�Q�[���I�[�o�[
	int GetResult();

};




