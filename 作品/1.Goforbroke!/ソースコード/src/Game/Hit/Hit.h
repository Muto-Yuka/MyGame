#pragma once

#include "../../Character/Enemy/EnemyManager.h"
#include "../../Game/shot/shotManager.h"
#include "../../Character/Player/Player.h"
#include "../../Game/Item/ItemManager.h"


#define DRAW_COLLISION (1)

class CHitManager
{
public:

	//�v���C���[�ƒe�����G(�G�P)�̓����蔻��==========
	//==================================================

		//�G�P�ƃv���C���[�̒e
	static void CheckHitShotToEnemy1(CEnemyManager& cEnemyManager, ShotManager& cShotManager, CApple& cApple);
	//�G�P�ƃv���C���[
	static void CheckHitPlayerToEnemy1(CEnemyManager& cEnemyManager, CPlayer& cPlayer, CApple& cApple);
	//�G�P�̒e�ƃv���C���[
	static void CheckHitEShotToEnemy1(CPlayer& cPlayer, ShotManager& cShotManager, CApple& cApple);

	//�v���C���[�Ɛ�����󂷓G(�G�Q)�̓����蔻��==========
	//====================================================

		//�G�Q�ƃv���C���[�̒e
	static void CheckHitShotToEnemy2(CEnemyManager& cEnemyManager, ShotManager& cShotManager, CApple& cApple);
	//�G�Q�ƃv���C���[
	static void CheckHitPlayerToEnemy2(CEnemyManager& cEemyManager, CPlayer& cPlayer, CApple& cApple);
	//�G�Q�Ɛ����ݏ�
	static void CheckHitWaterToEnemy2(CEnemyManager& cEnemyManager, CWater& cWater);

	//�v���C���[�ƃA�C�e��================
	//====================================

		//�����S�ƃv���C���[
	static void CheckHitApple(CPlayer& cPlayer, CItemManager& cItemManager);
	//�����ݏ�ƃv���C���[
	static void CheckHitWater(CPlayer& cPlayer, CWater& cWater);
	//�؂̎}�ƃv���C���[
	static void CheckHitBranch(CPlayer& cPlayer, CBranch& cBranch);
	//���ƃv���C���[
	static void CheckHitStraw(CPlayer& cPlayer, CItemManager& cItemManager);
	//�v���C���[�Ɩ؂̓����蔻��
	static void CheckHitTree(CPlayer& cPlayer, CItemManager& cItemManager);
	//�v���C���[�ƓG�����Ƃ������̓����蔻��
	static void CheckHitDropWater(CPlayer& cPlayer, CEnemyManager& cEnemyManager, CWater& cWater);

	//�A�C�e���ƃA�C�e��==================
	//====================================

		//�����S�Ɛ����ݏ�
	static void CheckHitAppleToWater(CApple& cApple, CWater& cWater);
	//�؂̎}�Ɛ����ݏ�
	static void CheckHitBranchToWater(CBranch& cBranch, CWater& cWater);


};

