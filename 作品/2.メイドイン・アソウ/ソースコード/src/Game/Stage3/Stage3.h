#pragma once
#include "../GameBase.h"
#include "BackGround3/BackGround3.h"
#include "Player3/Player3.h"
#include "HitPoint/HitPoint.h"
#include "Drop/Drop.h"

//�ږ������
class CStasge3 : public CGameBase
{
	CBackGround3	cBackGround;	//�w�i
	CPlayer3		cPlayer3;		//�v���C���[
	CHitPoint		cHitPoint;		//�q�b�g�|�C���g
	CDrop			cDrop;			//���Ƃ���

public:
	CStasge3();
	~CStasge3();

	void Init();		//������
	void Load();		//���[�h
	int  Step();		//�X�e�b�v
	void Exit();		//�j��
	void Draw();		//�`��

	//���U���g����Ԃ� 0:�ҋ@�@1:�N���A�@2:�Q�[���I�[�o�[
	int GetResult();

};




