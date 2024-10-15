#include "SceneBase.h"
#include "../../MyLib/Fade/Fade.h"
#include "../../MyLib/Sound/Sound.h"

//�����[�v
void CBaseScene::Loop()
{
	//�֐��|�C���^��錾���֐���scene�z��ɓ����
	void (CBaseScene:: * scene[])() = {
		 &CBaseScene::Init,& CBaseScene::Load,& CBaseScene::AmStep,& CBaseScene::PmStep,& CBaseScene::Exit,& CBaseScene::Next
	};
	//id�ɍ��킹�ď��������s
	(this->*scene[m_eSceneID])();
}


//�`�揈��
void CBaseScene::Draw()
{
	cFieldManager.Draw(m_eSceneID);
	cPlayer.CBaseAnim::Draw();
	cShotManager.Draw();
	cEnemyManager.Draw();
	cItemManager.Draw();


}

//������
void CBaseScene::Init()
{
	m_eSceneID = SCENE_INIT;

	cMission.Init();
	//�J����������
	cCameraManager.SetNearFar(1.0f, 5000.0f);

	//�v���C���[������
	cPlayer.Init();
	cFieldManager.Init();
	cShotManager.Init();
	cEnemyManager.Init(cItemManager.cApple);
	cScreen.Init();
	//cItemManager.Init();
	cItemManager.Init(cPlayer);

	m_eSceneID = SCENE_LOAD;


}

//�I������
void CBaseScene::Exit()
{
	if (!CFade::GetInstance()->IsEnd()) return;

	CSound::AllStop();
	cMission.Exit();
	cPlayer.CBaseAnim::Exit();
	cFieldManager.Exit();
	cShotManager.Exit();
	cEnemyManager.Exit();
	cScreen.Exit();
	//cItemManager.Exit();
	cItemManager.Exit();

	m_eSceneID = SCENE_NEXT;

}

void CBaseScene::Next()
{
	Exit();
	CFade::DeleteInstance();
	m_eSceneID = SCENE_INIT;

}

//�f�[�^���[�h
void CBaseScene::Load()
{

	cMission.Load();
	cPlayer.Load();
	cFieldManager.Load();
	cShotManager.Load();
	cEnemyManager.Load();
	cScreen.Load();
	//cItemManager.Load();
	cItemManager.Load();
	CSound::Play(CSound::SOUND_PLAY, DX_PLAYTYPE_LOOP);


	m_eSceneID = SCENE_AM_STEP;
	CFade::GetInstance()->Request(4.0f, true);

}


//���t���[���Ăԏ���
//�ߑO�̏����@�A�C�e���W�߁B�~�b�V�����B
void CBaseScene::AmStep()
{

	cMission.Step(cItemManager);
	cPlayer.Loop(cShotManager, cItemManager.cWater);
	cPlayer.CPlayer::Update();
	cShotManager.Step();
	cScreen.Step(m_eSceneID,cPlayer);
	cItemManager.Step();
	cScreen.SetPlayerHp(cPlayer.GetPlayerHP());
	//�����蔻��
	Collision();
	cFieldManager.Loop();

	//�J�����X�V����
	cCameraManager.Step(cPlayer.GetPosition(), cPlayer.GetRotateY());

	if (cScreen.GetAmTimeLimit() == 0 || cPlayer.GetPlayerHP() == 0)
	{
		m_eSceneID = SCENE_PM_STEP;

	}

	//water�N���X����Q�b�g����������screen�N���X�փZ�b�g
	cScreen.SetWaterHp(cItemManager.cWater.GetWaterHp());
}

//�ߌ�̏���
void CBaseScene::PmStep()
{

	cMission.Step(cItemManager);
	

	//�v���C���[�X�V����
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PLAY)
	{
		cPlayer.Loop(cShotManager, cItemManager.cWater);
		cPlayer.CPlayer::Update();

		cShotManager.Step();
		cEnemyManager.Step(cPlayer, cShotManager, cItemManager.cWater, cScreen);

		cItemManager.Step();

		cScreen.Step(m_eSceneID, cPlayer);

		cScreen.SetPlayerHp(cPlayer.GetPlayerHP());

		//�v���C�C���[�̂������Ȃ��Ȃ�Ύ��̃V�[����
		if (cEnemyManager.GetNextDayFrg())
		{
			cEnemyManager.SetNextDayFrg(false);
			m_eSceneID = SCENE_EXIT;
			CFade::GetInstance()->Request(4.0f, false);

		}
		//�����蔻��
		Collision();
	}
	//�J�����X�V����
	cCameraManager.Step(cPlayer.GetPosition(), cPlayer.GetRotateY());

	//water�N���X����Q�b�g����������screen�N���X�փZ�b�g
	cScreen.SetWaterHp(cItemManager.cWater.GetWaterHp());
}

//�����蔻�菈��=====================================================================================
void CBaseScene::Collision()
{
//�e�����G�̓����蔻��
	CHitManager::CheckHitShotToEnemy1(cEnemyManager, cShotManager, cItemManager.cApple);						//�e������(�G�P)�ƒe
	CHitManager::CheckHitPlayerToEnemy1(cEnemyManager, cPlayer, cItemManager.cApple);	//�G�P�ƃv���C���[
	CHitManager::CheckHitEShotToEnemy1(cPlayer, cShotManager, cItemManager.cApple);		//�G1�̒e�ƃv���C���[
//������󂷓G�̓����蔻��
	CHitManager::CheckHitShotToEnemy2(cEnemyManager, cShotManager, cItemManager.cApple);						//������󂷓G(2)�ƒe
	CHitManager::CheckHitPlayerToEnemy2(cEnemyManager, cPlayer, cItemManager.cApple);	//�G�Q�ƃv���C���[
	CHitManager::CheckHitWaterToEnemy2(cEnemyManager, cItemManager.cWater);				//�G�Q�Ɛ���		
//�v���C���[�ƃA�C�e���̓����蔻��
	CHitManager::CheckHitApple(cPlayer, cItemManager);									//�v���C���[�Ƃ��
	CHitManager::CheckHitBranch(cPlayer, cItemManager.cBranch);							//�v���C���[�Ɩ؂̎}
	CHitManager::CheckHitWater(cPlayer, cItemManager.cWater);							//�v���C���[�Ɛ����ݏ�
	CHitManager::CheckHitStraw(cPlayer, cItemManager);									//�v���C���[�Ƃ��
	CHitManager::CheckHitTree(cPlayer, cItemManager);									//�v���C���[�Ɩ�
	CHitManager::CheckHitDropWater(cPlayer, cEnemyManager, cItemManager.cWater);

//�A�C�e���ƃA�C�e���̓����蔻��
	CHitManager::CheckHitAppleToWater(cItemManager.cApple, cItemManager.cWater);		//�����S�Ɛ����ݏ�
	CHitManager::CheckHitBranchToWater(cItemManager.cBranch, cItemManager.cWater);		//�؂̎}�Ɛ����ݏ�

//�t�B�[���h�̓����蔻��
	cPlayer.ReflectCollision(cFieldManager.HitCheck(cPlayer.GetCenter(), cPlayer.GetRadius()));

}






