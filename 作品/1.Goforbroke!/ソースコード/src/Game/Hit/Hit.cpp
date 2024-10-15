#include "Hit.h"
#include "../../MyLib/Collision/Collision.h"

//�v���C���[�ƒe�����G1�̓����蔻��=========================================================================================
//====================================================================================================================
//�v���C���[�̋��ƓG�i���j
void CHitManager::CheckHitShotToEnemy1(CEnemyManager& cEnemyManager, ShotManager& cShotManager, CApple& cApple)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		//�e�����擾���A���˂���Ă��Ȃ���Ύ���
		CShot& cPlayerShot = cShotManager.GetPLayerShot(i);
		if (!cPlayerShot.CBaseAnim::IsSurvival()) continue;

		for (int j = 0; j < GUN_ENEMY_NUM; j++)
		{
			//�G�����擾���A��������Ă��Ȃ���Ύ���
			CEnemyBase& cEnemy = cEnemyManager.GetGunEnemy(j);
			if (!cEnemy.CBaseAnim::IsSurvival()) continue;

			//���W�Ɣ��a���擾
			VECTOR vEnemyPos = cEnemy.GetPosition();
			float fEnemyRadius = cEnemy.GetRadius();
			VECTOR vPlayerShotPos = cPlayerShot.GetPosition();

			//�e�̓����蔻���������
			vPlayerShotPos.y -= 15;
			//�G�̕��͓����蔻��̒��S�𔼕���������
			vEnemyPos.y += fEnemyRadius;

			//���Ƌ��̓����蔻�� �i�G�Ƌ��j
			if (CCollision::CheckHitSphereToSphere
			(vPlayerShotPos, vEnemyPos, cPlayerShot.GetRadius(), fEnemyRadius))
			{
				//�����܂ł���Γ�������
				cPlayerShot.HitCalc();
				cEnemy.HitCalc(cApple);
			}
		}
	}
}
//�v���C���[���G�ɓ��������Ƃ�
void CHitManager::CheckHitPlayerToEnemy1(CEnemyManager& cEnemyManager, CPlayer& cPlayer, CApple& cApple)
{
	//�G�̐�����
	for (int j = 0; j < GUN_ENEMY_NUM; j++)
	{
		//�G�����擾���A��������Ă��Ȃ���Ύ���
		CEnemyBase& cEnemy = cEnemyManager.GetGunEnemy(j);
		if (!cEnemy.CBaseAnim::IsSurvival()) continue;

		VECTOR vEnemyPos = cEnemy.GetPosition();
		float fEnemyRadius = cEnemy.GetRadius();

		//�G�̕��͓����蔻��̒��S�𔼕���������
		vEnemyPos.y += fEnemyRadius;

		//���Ƌ��̓����蔻�� �i�G�ƃv���C���[�j
		if (CCollision::CheckHitSphereToSphere
		(cPlayer.GetPosition(), vEnemyPos, cPlayer.GetRadius(), fEnemyRadius))
		{
			//�����܂ł���Γ�������
			cPlayer.HitCalc();
			cEnemy.HitCalc(cApple);
			cApple.SetAppleGauge();
		}
	}
}
//�G�̒e���v���C���[�ɓ���������
void CHitManager::CheckHitEShotToEnemy1(CPlayer& cPlayer, ShotManager& cShotManager, CApple& cApple)
{
	for (int i = 0; i < EM_SHOT_NUM; i++)
	{
		//�e�����擾���A���˂���Ă��Ȃ���Ύ���
		CShot& cEnemyShot = cShotManager.GetEnemyShot(i);
		if (!cEnemyShot.CBaseAnim::IsSurvival()) continue;

		DrawSphere3D(cPlayer.GetPosition(), cPlayer.GetRadius(), 20, GetColor(255, 255, 255), GetColor(0, 0, 0), FALSE);


		//���Ƌ��̓����蔻�� �i�G�Ƌ��j
		if (CCollision::CheckHitSphereToSphere
		(cEnemyShot.GetPosition(), cPlayer.GetPosition(), cEnemyShot.GetRadius(), cPlayer.GetRadius()))
		{
			//�����܂ł���Γ�������
			cPlayer.HitCalc();
			cEnemyShot.HitCalc();
			cApple.SetAppleGauge();

		}
	}
}

//�v���C���[�Ɛ�����󂷓G2�̓����蔻��=========================================================================================
//====================================================================================================================
//�G�Q�ƒe(��)
void CHitManager::CheckHitShotToEnemy2(CEnemyManager& cEnemyManager, ShotManager& cShotManager, CApple& cApple)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		//�e�����擾���A���˂���Ă��Ȃ���Ύ���
		CShot& cPlayerShot = cShotManager.GetPLayerShot(i);
		if (!cPlayerShot.CBaseAnim::IsSurvival()) continue;

		for (int j = 0; j < BREAK_ENEMY_NUM; j++)
		{
			//�G�����擾���A��������Ă��Ȃ���Ύ���
			CEnemyBase& cEnemy = cEnemyManager.GetBreakEnemy(j);
			if (!cEnemy.CBaseAnim::IsSurvival()) continue;

			//���W�Ɣ��a���擾
			VECTOR vEnemyPos = cEnemy.GetPosition();
			VECTOR vPlayerShotPos = cPlayerShot.GetPosition();

			//�e�̓����蔻���������
			vPlayerShotPos.y -= 15;
			//�G�̕��͓����蔻��̒��S�𔼕���������
			vEnemyPos.y += cEnemy.GetRadius();

			//���Ƌ��̓����蔻�� �i�G�Ƌ��j
			if (CCollision::CheckHitSphereToSphere
			(vPlayerShotPos, vEnemyPos, cPlayerShot.GetRadius(), cEnemy.GetRadius()))
			{
				//�����܂ł���Γ�������
				cPlayerShot.HitCalc();
				cEnemy.HitCalc(cApple);
			}
		}
	}

}
//�G�Q�ƃv���C���[
void CHitManager::CheckHitPlayerToEnemy2(CEnemyManager& cEnemyManager, CPlayer& cPlayer, CApple& cApple)
{
	//�G�̐�����
	for (int j = 0; j < BREAK_ENEMY_NUM; j++)
	{
		//�G�����擾���A��������Ă��Ȃ���Ύ���
		CEnemyBase& cEnemy = cEnemyManager.GetBreakEnemy(j);
		if (!cEnemy.CBaseAnim::IsSurvival()) continue;

		VECTOR vEnemyPos = cEnemy.GetPosition();
		float fEnemyRadius = cEnemy.GetRadius();

		//�G�̕��͓����蔻��̒��S�𔼕���������
		vEnemyPos.y += fEnemyRadius;

		//���Ƌ��̓����蔻�� �i�G�ƃv���C���[�j
		if (CCollision::CheckHitSphereToSphere
		(cPlayer.GetPosition(), vEnemyPos, cPlayer.GetRadius(), fEnemyRadius))
		{
			//�����܂ł���Γ�������
			cPlayer.HitCalc();
			cEnemy.HitCalc(cApple);
			cApple.SetAppleGauge();

		}
	}

}
//�G�Q�Ɛ����ݏ�
void CHitManager::CheckHitWaterToEnemy2(CEnemyManager& cEnemyManager, CWater& cWater)
{
	for (int j = 0; j < BREAK_ENEMY_NUM; j++)
	{
		//�G�����擾���A��������Ă��Ȃ���Ύ���
		CEnemyBase& cEnemy = cEnemyManager.GetBreakEnemy(j);
		if (!cEnemy.CBaseAnim::IsSurvival()) continue;


		if (CCollision::CheckHitSphereToSphere
		(cEnemy.GetPosition(), cWater.GetPosition(), cEnemy.GetRadius(), cWater.GetRadius()))
		{
			//������󂷏���
			cEnemy.BreakWater(cWater);
			cWater.HitBreakWater();
		}
		else
		{
			//�G�Ɛ���̓q�b�g���ĂȂ�
			cWater.SetHitFrg(false);
		}
	}
}


//�v���C���[�ƃA�C�e��================================================================================================
//====================================================================================================================
//�v���C���[�ƃ����S�̓����蔻��
void CHitManager::CheckHitApple(CPlayer& cPlayer, CItemManager& cItemManager)
{

	//�����S�̐�����
	for (int j = 0; j < APPLE_NUM; j++)
	{

		//��񂲏����擾���A��������Ă��Ȃ���Ύ���
		CItemBase& cAppleBase = cItemManager.GetApple(j);
		if (!cAppleBase.GetSurvivalFrg()) continue;

		//�A�C�e�����`�悳��Ă��Ȃ��Ɣ�����Ƃ�Ȃ�
		if (!cAppleBase.GetSurvivalFrg())
			return;

		//�v���C���[�ƃ����S�i���Ƌ��j
		if (CCollision::CheckHitSphereToSphere
		(cPlayer.GetPosition(), cAppleBase.GetPosition(), cPlayer.GetRadius(), cAppleBase.GetRadius()))
		{
			//�`�悵�Ȃ�
			cAppleBase.HitItem();
			//���̂ق��̃q�b�g����
			cItemManager.cApple.HitItem();
		}
	}
}
//�v���C���[�Ɛ����ݏ�̓����蔻��
void CHitManager::CheckHitWater(CPlayer& cPlayer, CWater& cWater)
{
	////�A�C�e�����`�悳��Ă��Ȃ��Ɣ�����Ƃ�Ȃ�
	//if (!cWater.GetSurvivalFrg())
	//	return;

	//�v���C���[�Ɛ��i���Ƌ��j
	if (CCollision::CheckHitSphereToSphere
	(cPlayer.GetPosition(), cWater.GetPosition(), cPlayer.GetRadius(), cWater.GetRadius()))
	{

		cWater.HitRepairWater();
		//�v���C���[�������Ă��鐅�𐅃N���X�̕ϐ��ɃZ�b�g
		cWater.SetWaterNum(cPlayer.GetWaterNum());
		if (cWater.GetSurvivalFrg())
		{
			//����ɐ���߂��֐�
			cWater.HitReturnWater(cPlayer.GetWaterNum());

		}

		//���ꂪ��ꂽ��C������֐�
		cPlayer.WatrRepair(cWater);

	}
}
//�v���C���[�Ɩ؂̎}�̓����蔻��
void CHitManager::CheckHitBranch(CPlayer& cPlayer, CBranch& cBranch)
{

	//�A�C�e�����`�悳��Ă��Ȃ��Ɣ�����Ƃ�Ȃ�
	if (!cBranch.GetSurvivalFrg())
		return;


	//�v���C���[�Ɛ��i���Ƌ��j
	if (CCollision::CheckHitSphereToSphere
	(cPlayer.GetPosition(), cBranch.GetPosition(), cPlayer.GetRadius(), cBranch.GetRadius()))
	{
		cBranch.HitItem();
	}

}
//�v���C���[�Ƙm�̓����蔻��
void CHitManager::CheckHitStraw(CPlayer& cPlayer, CItemManager& cItemManager)
{
	//�A�C�e���̐���
	for (int j = 0; j < STRAW_NUM; j++)
	{
		//�m�����擾���A��������Ă��Ȃ���Ύ���
		CItemBase& cStrawBase = cItemManager.GetStraw(j);
		if (!cStrawBase.GetSurvivalFrg()) continue;

		//�A�C�e�����`�悳��Ă��Ȃ��Ɣ�����Ƃ�Ȃ�
		if (!cStrawBase.GetSurvivalFrg())
			return;

		//�v���C���[�ƃ����S�i���Ƌ��j
		if (CCollision::CheckHitSphereToSphere
		(cPlayer.GetPosition(), cStrawBase.GetPosition(), cPlayer.GetRadius(), cStrawBase.GetRadius()))
		{
			//�`�悵�Ȃ�
			cStrawBase.HitItem();
			//���̂ق��̃q�b�g����
			cItemManager.cStraw.HitItem();
		}
	}
}
//�v���C���[�Ɩ؂̓����蔻��
void CHitManager::CheckHitTree(CPlayer& cPlayer, CItemManager& cItemManager)
{
	//�؂̐�����
	for (int j = 0; j < TREE_NUM; j++)
	{

		//��񂲏����擾���A��������Ă��Ȃ���Ύ���
		CItemBase& cTreeBase = cItemManager.GetTree(j);
		if (!cTreeBase.GetSurvivalFrg()) continue;

		//�A�C�e�����`�悳��Ă��Ȃ��Ɣ�����Ƃ�Ȃ�
		if (!cTreeBase.GetSurvivalFrg())
			return;

		//�v���C���[�Ɩ؁i���Ƌ��j
		if (CCollision::CheckHitSphereToSphere
		(cPlayer.GetPosition(), cTreeBase.GetPosition(), cPlayer.GetRadius(), cTreeBase.GetRadius()))
		{
			////�`�悵�Ȃ�
			//cTreeBase.HitItem();
			//���̂ق��̃q�b�g����
			cItemManager.cApple.HitItem();
		}
	}

}
//�v���C���[�ƓG�����Ƃ������̓����蔻��
void CHitManager::CheckHitDropWater(CPlayer& cPlayer, CEnemyManager& cEnemyManager, CWater& cWater)
{
	//���̐�����
	for (int j = 0; j < DROP_WATER_MAXNUM; j++)
	{
		//�������擾
		CDropWater& cDropWater = cEnemyManager.GetDropWater(j);

		//���W�E���a���擾
		VECTOR vWaterPos = cDropWater.GetPosition();
		float fWaterRadius = cDropWater.GetRadius();

		//���̕��͓����蔻��̒��S�𔼕���������
		vWaterPos.y += fWaterRadius;

		//�A�C�e�����`�悳��Ă��Ȃ��Ɣ�����Ƃ�Ȃ�
		if (!cDropWater.GetSurvival())
			return;


		//���Ƌ��̓����蔻�� �i�G�ƃv���C���[�j
		if (CCollision::CheckHitSphereToSphere
		(cPlayer.GetPosition(), vWaterPos, cPlayer.GetRadius(), fWaterRadius))
		{
			//��������
			cDropWater.HitCalc(cPlayer);
			//�v���C���[�������Ă��鐅�𐅃N���X�̕ϐ��ɃZ�b�g
			cWater.SetWaterNum(cPlayer.GetWaterNum());
		}
	}

}


//�A�C�e���ƃA�C�e��==================================================================================================
//====================================================================================================================
//�����S�Ɛ����ݏ�
void CHitManager::CheckHitAppleToWater(CApple& cApple, CWater& cWater)
{
	//�����S�Ɛ��i���Ƌ��j
	if (CCollision::CheckHitSphereToSphere
	(cApple.GetPosition(), cWater.GetPosition(), cApple.GetRadius(), cWater.GetRadius()))
	{
		//�������X�|�[��
	}
}
//�؂̎}�Ɛ����ݏ�
void CHitManager::CheckHitBranchToWater(CBranch& cBranch, CWater& cWater)
{
	//�؂̎}�Ɛ��i���Ƌ��j
	if (CCollision::CheckHitSphereToSphere
	(cBranch.GetPosition(), cWater.GetPosition(), cBranch.GetRadius(), cWater.GetRadius()))
	{
		//�������X�|�[��
		cBranch.RespawnApple();
	}
}





