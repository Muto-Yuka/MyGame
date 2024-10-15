#include "ItemManager.h"

//�R���X�g���N�^
CItemManager::CItemManager()
{

}

//�f�X�g���N�^
CItemManager::~CItemManager()
{
	Exit();
}

//������
void CItemManager::Init(CPlayer& cPlayer)
{
	cApple.Init(cPlayer);
	cBranch.Init();
	cStraw.Init();
	cTree.Init();
	cWater.Init();
	//cLear.Init();
	//cTent.Init();

}

//���[�h
void CItemManager::Load()
{
	cApple.Load();
	cBranch.Load();
	cStraw.Load();
	cTree.Load();
	cWater.Load();
	//cLear.Load();
	//cTent.Load();

}

//���[�v
void CItemManager::Step()
{
	cApple.Step();
	cBranch.Step();
	cStraw.Step();
	cTree.Step();
	cWater.Step();
	//cLear.Step();
	//cTent.Step();

	//�����蔻��

}

//�`��
void CItemManager::Draw()
{
	cApple.Draw();
	cBranch.Draw();
	cStraw.Draw();
	cTree.Draw();
	cWater.Draw();
	//cLear.Draw();
	//cTent.Draw();

}

//�I��
void CItemManager::Exit()
{
	cApple.Exit();
	cBranch.Exit();
	cStraw.Exit();
	cTree.Exit();
	cWater.Exit();
	//cLear.Exit();
	//cTent.Exit();

}

//�e�����蔻�苅�`��
void CItemManager::MyDbug()
{
	////�����S�̓����蔻��`��
	//for (int i = 0; i < APPLE_NUM; i++)
	//DrawSphere3D(cApple.m_cApple[i].GetPosition(), cApple.m_cApple[i].GetRadius(), 16, GetColor(255, 0, 0), GetColor(255, 255, 255), false);
	//���ꂪ��ꂽ��`��
	if (!cWater.GetSurvivalFrg())
	{
		//�����ݏ�̓����蔻��`��
		DrawSphere3D(cWater.GetPosition(), cWater.GetRadius(), 16, GetColor(0, 0, 255), GetColor(255, 255, 255), false);

	}
	////�؂̎}�̓����蔻��
	//DrawSphere3D(cBranch.GetPosition(), cBranch.GetRadius(), 16, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	////���̓����蔻��
	//DrawSphere3D(cStraw.GetPosition(), cStraw.GetRadius(), 16, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
}

//���U���g�֍s�������f true:���U���g�� false:���U���g�ɍs���Ȃ�
bool CItemManager::GetResultFrg()
{
	////�H���Q�[�W���Ȃ��Ȃ���
	//if (cApple.GetResultFrg())
	//	return true;

	//�����Q�[�W���Ȃ��Ȃ���
	if (cWater.GetResultFrg())
		return true;


	return false;
}


//���ꂪ�B���ł��Ă��邩�ǂ��� true:�B���@false:���B��
bool CItemManager::GetWaterClearFrg()
{
	//�W�O���ȏ�Ȃ�
	if (cWater.GetWaterClearFrg() > 4)
		return true;


	return false;
}

