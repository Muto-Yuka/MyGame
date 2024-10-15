#pragma once
#include "../../Character/Enemy/BaseEnemy.h"
#include "../../Game/Mission/Mission.h"
#include "../../Character/Player/Player.h"

#define AM_TIME_COUNT (800)		//�ߑO�����I��鎞�ԃJ�E���g
#define PM_TIME_COUNT (4000)	//�ߌオ�I��鎞�ԃJ�E���g

class CScreen {
private:
	int m_UpHndl;		 //��ʏ㕔�ɕ\������摜�n���h��
	int m_AmCount;		//�[���ɂȂ�܂ł̃J�E���g
	int m_PmCount;		//���ɂȂ�܂ł̃J�E���g
	int m_PlayerHp;		//Hp�i�����S�j
	float WaterHp;		//����̗̑�

public:
	CScreen();
	~CScreen();

	void Init();
	void Load();
	void Step(int SceneId, CPlayer& cPlayer);	//�����邩i���Ŏ󂯎��
	void Day1Draw(int SceneId);	//�����邩i���Ŏ󂯎��
	void Day2Draw(int SceneId);	//�����邩i���Ŏ󂯎��
	void Exit();


	//�Q�b�^�[�E�Z�b�^�[==========

	inline void SetPlayerHp(int Hp) { m_PlayerHp = Hp; }
	inline int GetAmTimeLimit() { return m_AmCount; }		//���̎��Ԃ��擾
	inline int GetPmTimeLimit() { return m_PmCount; }		//�ߌ�̎��Ԃ��擾
	inline void SetWaterHp(float hp) { WaterHp = hp; }		//����̗͎̑擾
};


