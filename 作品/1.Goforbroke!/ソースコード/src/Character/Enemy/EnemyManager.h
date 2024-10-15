#pragma once
#include "GunEnemy/GunEnemy.h"
#include "BreakEnemy/BreakEnemy.h"

class CEnemyManager {
private:
	CGunEnemy cGunEnemy;		//�v���C���[�Ɍ������Ēe�����G
	CBreakEnemy cBreakEnemy;	//������󂵂Ɍ������G

public:
	void Init(CApple& cApple);
	void Load();
	void Exit();
	void Step(CPlayer& cPlayer, ShotManager& cEnemyShot, CWater& cWater, CScreen& cScreen);
	void Draw();


	//**�Q�b�^�[�E�Z�b�^�[**
		//�G���擾
	inline CEnemyBase& GetGunEnemy(int iID) { return cGunEnemy.m_cGunEnemy[iID]; }
	inline CEnemyBase& GetBreakEnemy(int iID) { return cBreakEnemy.m_cBreakEnemy[iID]; }
	//�G�����Ƃ������擾
	inline CDropWater& GetDropWater(int iID) { return cGunEnemy.m_cDropWater[iID]; }

	//�G�̈ʒu���擾
	VECTOR GetGunEnemyPos() { return cGunEnemy.m_cGunEnemy->GetPos(); }
	VECTOR GetBreakEnemyPos() { return cBreakEnemy.m_cBreakEnemy->GetPos(); }


	//���̓��ɍs�����ǂ����@true:���̓��ց@false:�ҋ@
	bool GetNextDayFrg();
	void SetNextDayFrg(bool frg);


};
