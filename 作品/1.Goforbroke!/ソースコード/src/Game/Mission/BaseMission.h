#pragma once
#include <DxLib.h>

//�H���Q�[�W�̐�
#define GAUGE_NUM	(8)		

//�~�b�V�������e�����̏������W
#define MISSION_WORD_X		(350)	
#define MISSION_WORD_Y		(200)	

class CBaseMission
{
protected:
	int m_iOnHndl[GAUGE_NUM];		//2D�H���Q�[�W�摜�n���h��(�����ɕ`��)
	int m_iUnderHndl[GAUGE_NUM];	//2D�H���Q�[�W�摜�n���h���i���ɉe�Ƃ��ĕ`��j
	int m_iDrawNum;					//2D�\������H���E���̐�
	int m_iMissionCnt;				//�~�b�V�������̎��ԃJ�E���g
	int m_iWordX, m_iWordY;			//�������ړ������邽�߂̍��W������ϐ�
	int FontHandle;					//�ꎞ�I�ɕ�����ς��邽�߂̃t�H���g�n���h��
	int m_iDrawPictureY;			//�~�b�V����������Y���W

	bool m_bClear;					//���U���g�֍s�����ǂ���
	bool HitFlg;					//�A�C�e���Ƀq�b�g������

public:
	//�R���X�g���N�^
	CBaseMission();

	//������
	void Init();
	//���[�v
	void Step();
	//��ɕ`��
	void AlwaysDraw();
	//�I��
	void Exit();

	//�A�C�e���ɓ���������
	bool GetHitFlg() { return HitFlg; }
};






