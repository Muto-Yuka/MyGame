#pragma once
#include "../BaseEnemy.h"
#include "../../../Game/Screen/Screen.h"

#define BREAK_ENEMY_NUM (2)	//�����ɏo������G�̐�

class CBreakEnemy
{
private:
	int m_iWaitRespawn;		//���X�|�[������܂ł̎��Ԃ��J�E���g
	int m_iWaitCnt;			//���̓G���o�Ă���܂ł̎��ԊǗ�
	bool NextDayFrg;		//���̓��ɍs�����ǂ����@true:���̓��ց@false:�܂��҂� 
	int NextDayCount;		//�ߌ㎞�Ԃ��I����ċ����Ŏ��̃V�[���ւ������ԊǗ�

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBreakEnemy();
	~CBreakEnemy();

	//������
	void Init(CApple& cApple);
	void Load();
	void Exit();
	void Step(CWater& cWater, CScreen& cScreen);
	void Draw();


	CEnemyBase m_cBreakEnemy[BREAK_ENEMY_NUM];

	//���̓��ɂ����ނ��󂯎��
	inline bool GetNextDayFrg() { return NextDayFrg; }
	inline void SetNextDayFrg(bool Frg) { NextDayFrg = Frg; }

private:
	//�G�̃��N�G�X�g
	void RequestEnemy();

};



