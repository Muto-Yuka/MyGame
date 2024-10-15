#include "EnemyManager.h"
#include "../../Scene/PlayScene/SceneBase.h"

void CEnemyManager::Init(CApple& cApple)
{
	cGunEnemy.Init(cApple);
	cBreakEnemy.Init(cApple);
}

void CEnemyManager::Load()
{
	cGunEnemy.Load();
	cBreakEnemy.Load();
}

void CEnemyManager::Step(CPlayer& cPlayer, ShotManager& cEnemyShot, CWater& cWater, CScreen& cScreen)
{
	cGunEnemy.Step(cPlayer, cEnemyShot, cScreen);
	cBreakEnemy.Step(cWater, cScreen);
}

void CEnemyManager::Draw()
{
	cGunEnemy.Draw();
	cBreakEnemy.Draw();
}

void CEnemyManager::Exit()
{
	cGunEnemy.Exit();
	cBreakEnemy.Exit();
}

//�Q�b�^�[�@���̓��ɍs�����ǂ����t���O�擾  true:���̃V�[���ց@false:�ҋ@
bool CEnemyManager::GetNextDayFrg()
{
	if (cGunEnemy.GetNextDayFrg() && cBreakEnemy.GetNextDayFrg())
	{
		return true;
	}

	return false;
}

void CEnemyManager::SetNextDayFrg(bool frg)
{
	cBreakEnemy.SetNextDayFrg(frg);
	cGunEnemy.SetNextDayFrg(frg);


}

