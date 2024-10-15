#pragma once
#include <DxLib.h>
#include "../Player/Player.h"
#include "../../Game/shot/shotManager.h"
#include "../../MyLib/BaseAnim/BaseAnim.h"
#include "../../Game/Item/Apple/Apple.h"
#include "../../Game/Item/Water/Water.h"

#define PLAYER_ATTACK	(5) //�v���C���[�̈��̍U����


class CEnemyBase : public CBaseAnim
{
private:
	float m_fAngle;		//�p�x
	int m_iHp, spare;				//�G�̂���
	int m_DropItem;					//�h���b�v����A�C�e���n���h��
	float m_fTransparency;	//���f���̓����x
	bool m_bStopBEnemy;		//�󂷓G���ړ����邩�ǂ����@true:�~�܂�i�q�b�g�����jfalse:����

//�x�N�g��
	VECTOR m_vInitPos;		//�G�������A����W
	VECTOR SubVector;	//�G����v���C���[�Ɍ������x�N�g��

//bool�t���O
	bool Clear;

	//���ԃJ�E���g�ϐ�
	int m_enemy_count;
	int m_iWaitBulletCnt;	//�G�̒e�̏o�����ԊǗ�

//�摜�n���h���E���f���n���h��1
	int m_iHpGaugeHndl;		//hp�Q�[�W�n���h��

public:

	void Init(CApple& cApple);
	void Draw();
	void Exit();

	//�f�[�^�֘A�̒ʏ�摜���[�h
	void Load(int iMdlHndl);
	//�h���b�v�A�C�e���֘A�R�����f�����[�h
	//void DropItemLoad(int DropItem);
	//���t���[���Ăԏ���
	void GunEnemyStep(CPlayer& cPlayer, ShotManager& cEnemyShot);
	void BreakEnemyStep(CWater& cWater);


	//�e�֐�����������===================================================
	//===================================================================

	//�e���ˏ���
	void EnemyShot(ShotManager& cEnemyShot);
	//�����蔻�菈��
	void HitCalc(CApple& cApple);
	//��Ɏw�肳�ꂽ�����Ɍ���
	void EnemyLook(VECTOR TargetPos, VECTOR EnemyPos);
	//�����Ă�����ɐi�ފ֐�
	void EnemyMove();
	//������󂷏���
	void BreakWater(CWater& cwater);
	//�_���[�W���󂯂��Ƃ��ɓ_�ł����鏈�� 0~1�@�P�̂ق����͂�����@�O�͓���
	void Transparency(int Hndl, float Transparency);

	//�Q�b�^�[�E�Z�b�^�[==================================================
	//====================================================================

	//�G���t�B�[���h�ɂ��邩�@false��true��
	bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);
	//���a�擾
	float GetRadius(void) { return m_fRadius; }

	//�G�̍��W���擾
	VECTOR GetPos() { return m_vPos; }
	//�G�̂������Z�b�g�i�������j
	void SetEnemyHP(int HP) { m_iHp = HP; spare = HP; }
	//�����t���O���Q�b�g����
	inline bool GetSurvival() { return m_bSurvival; }



};