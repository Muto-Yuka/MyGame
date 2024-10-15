#pragma once
#include "shot.h"

#define PL_SHOT_NUM (50)
#define EM_SHOT_NUM (100)

class ShotManager
{
private:
	//�v���C���[�̃V���b�g
	CShot cPlayerShot[PL_SHOT_NUM];
	//�G�̃V���b�g
	CShot cEnemyShot[EM_SHOT_NUM];

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	ShotManager();
	~ShotManager();

	//������
	void Init();

	void Load();
	void Exit();
	void Step();
	void Draw();

	//�V���b�g���N�G�X�g
	void RequestPlayerShot(const VECTOR& vPos, const VECTOR& vSpeed);	//�v���C���[
	void RequestEnemyShot(const VECTOR& vPos, const VECTOR& vSpeed);	//�G
	//�v���C���[�̃V���b�g���擾
	CShot& GetPLayerShot(int iID) { return cPlayerShot[iID]; }
	CShot& GetEnemyShot(int iID) { return cEnemyShot[iID]; }


};