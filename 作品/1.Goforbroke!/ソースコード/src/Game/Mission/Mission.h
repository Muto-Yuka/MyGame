#pragma once
#include "DxLib.h"
#include "../Item/ItemManager.h"

class CMission
{
private:
	//**�摜�n���h��**
	int m_iHndl;			//�~�b�V�����Q���摜�n���h��
	int m_iPaperHndl;		//�~�b�V�����p���`��

	int count;				//�t���[�����J�E���g
	int m_iTransparency;	//�摜�����x 0=�����@255=�s����
	bool m_bDraw;			//�Q���摜��`�悵�Ă��邩�ǂ����@true:�`�撆�@false:�`�悵�Ă��Ȃ�
	int m_iMissionCnt;
	int DrawCount;			//�Qd�摜��`�悷��񐔃J�E���g
	int L_DrawX, L_DrawY;	//�摜�̍��������W�A���������W
	int R_DrawX, R_DrawY;	//�摜�̉E�������W�A�E�������W
	bool SceneId;			// true=����� false=�����
	bool MissionTitle;		//�~�b�V�������e�`�悷�邩���Ȃ��� true:����@false:���Ȃ�

//**�~�b�V�����A�C�e���ϐ�**
	int m_iStraw;			//�m�̌�
	int m_iBranch;			//�}�̌�
	int m_iIvy;				//�c�^�̌�

	//�A�C�e���̃N���A�t���O������\����
	struct ItemClearFrg
	{
		bool s_bStraw = false;
		bool s_bBranch = false;
		bool s_bIvy = false;
	};

	ItemClearFrg m_sItemClearFrg;

public:

	//�R���X�g���N�^.�f�X�g���N�^
	CMission();
	~CMission();

	//������
	void Init();
	//�f�[�^�֘A�̃��[�h
	void Load();
	//���t���[���Ăԏ���
	void Step(CItemManager& cItemManager);
	//��ɕ`��
	void Draw();
	//�I��
	void Exit();

	//�~�b�V�������ߏ���
	void StepMission();
	//�~�b�V�������̂ݕ`��
	void MissionDraw();
	//�~�b�V�������e���E��Ɉړ�����
	void MoveMIssion();
	//�~�b�V�������e���͂�\������
	void StringMission();

		//����ڃZ�b�g   true=����ځ@false=�����
	void SetDay1Scene() { SceneId = true; }
	void SetDay2Scene() { SceneId = false; }

	//�~�b�V�����N���A���ǂ����@true:�N���A�@false:�~�b�V�������s
	bool GetMissionClearFrg();


};


