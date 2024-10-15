#pragma once
#include "../../MyLib/BaseAnim/BaseAnim.h"

class CPlayAnim : public CBaseAnim
{
	//�A�j���[�V�����̎��
	enum PLAY_ANIM {
		ANIMID_WAIT,		//�ҋ@
		ANIMID_WALK,		//����
		ANIMID_RUN,			//����
		ANIMID_SIDEWALK,	//���E�ړ�
		ANIMID_TAKE,		//���̂��Ƃ铮��

		ANIMID_NUM			//�A�j������
	};

public:
	static int Key;
	static DINPUT_JOYSTATE input;		//�R���g���[���[���

	CPlayAnim();

	void Init();	//������
	void Load();	//���[�h
	void Loop();	//���[�v
	void Update();	//�X�V

	void AnimLoop();		//�A�j���[�V�������[�v
	void ExecWait();		//�ҋ@�A�j���֐����s
	void ExecWalk();		//�����A�j���֐����s
	void ExecRun();			//����A�j���֐����s
	void ExecSideWalk();	//���E�ړ��A�j���֐����s
	void ExecTake();		//�擾�A�j���[�V�������s

};




