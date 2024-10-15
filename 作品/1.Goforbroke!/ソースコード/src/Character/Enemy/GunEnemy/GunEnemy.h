#pragma once
#include "../BaseEnemy.h"
#include "DropWater/DropWater.h"
#include "../../../Game/Screen/Screen.h"

#define GUN_ENEMY_NUM (2)	//�����ɏo������G�̐�
#define G_ENEMY_HP	(3)		//����e�ɓ�������������邩
#define DROP_WATER_MAXNUM	(3)


class CGunEnemy
{
private:
	int m_iWaitRespawn;		//���X�|�[������܂ł̎��Ԃ��J�E���g
	int m_iWaitCnt;			//���̓G���o�Ă���܂ł̎��ԊǗ�
	bool NextDayFrg;		//���̓��ɍs�����ǂ����@true:���̓��ց@false:�܂��҂� 
	int NextDayCount;		//�ߌ㎞�Ԃ��I����ċ����Ŏ��̃V�[���ւ������ԊǗ�

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CGunEnemy();
	~CGunEnemy();

	//������
	void Init(CApple& cApple);
	void Load();
	void Exit();
	void Step(CPlayer& cPlayer, ShotManager& cEnemyShot, CScreen& cScreen);
	void Draw();


	//�G�̐����p��
	CEnemyBase m_cGunEnemy[GUN_ENEMY_NUM];
	//�G�̐�������p��
	CDropWater m_cDropWater[GUN_ENEMY_NUM];

	//**�Q�b�^�[�E�Z�b�^�[**
		//���̓��ɂ����ނ��󂯎��
	inline bool GetNextDayFrg() { return NextDayFrg; }
	inline void SetNextDayFrg(bool Frg) { NextDayFrg = Frg; }

private:
	//���N�G�X�g
	void RequestEnemy();



};



