#include "shotManager.h"

static const char PLSHOT_MODEL_PATH[] = { "data/Game/Shot/Shot.x" };

//�R���X�g���N�^
ShotManager::ShotManager()
{
	Init();
}

//�f�X�g���N�^
ShotManager::~ShotManager()
{
	Exit();
}

//������
void ShotManager::Init()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Init();
	}

	for (int k = 0; k < EM_SHOT_NUM; k++)
	{
		cEnemyShot[k].Init();
	}
}

//���[�h
void ShotManager::Load()
{
	//�I���W�i�����f����ǂݍ���
	int iHndl = MV1LoadModel(PLSHOT_MODEL_PATH);

	//�v���C���[�̒e���f���̕���
	for (int i = 0; i < PL_SHOT_NUM; i++)
		cPlayerShot[i].Load(iHndl);
	//�G���f���̒e�̕���
	for (int k = 0; k < EM_SHOT_NUM; k++)
		cEnemyShot[k].Load(iHndl);

	MV1DeleteModel(iHndl);
}

//�I������
void ShotManager::Exit()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
		cPlayerShot[i].Exit();
	for (int k = 0; k < EM_SHOT_NUM; k++)
		cEnemyShot[k].Exit();
}

//���t���[���Ăԏ���
void ShotManager::Step()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
		cPlayerShot[i].Step();
	for (int k = 0; k < EM_SHOT_NUM; k++)
		cEnemyShot[k].Step();
}


//�X�V����
void ShotManager::Draw()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
		cPlayerShot[i].Draw();
	for (int k = 0; k < EM_SHOT_NUM; k++)
		cEnemyShot[k].Draw();
}

//�v���C���[�̃V���b�g���N�G�X�g
void ShotManager::RequestPlayerShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		if (cPlayerShot[i].RequestShot(vPos, vSpeed))
		{
			break;
		}
	}
}

//�G�̃��N�G�X�g�V���b�g
void ShotManager::RequestEnemyShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	for (int k = 0; k < EM_SHOT_NUM; k++)
	{
		if (cEnemyShot[k].RequestShot(vPos, vSpeed))
		{
			break;
		}
	}
}





