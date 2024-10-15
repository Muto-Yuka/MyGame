#pragma once
#include <DxLib.h>

class CSound 
{
public:
	enum tag_Sound
	{
		SOUND_TITLE,		
		SOUND_PLAY,
		SOUND_CLEAR,
		SOUND_GAMEOVER,

		SOUND_NUM
	};

	CSound();
	~CSound();

	static void Init();		//������
	static void Exit();		//�j��
	static bool AllLoad();	//true;�S���[�h�����@false:���s

	//�Đ�
	static int Play(tag_Sound iID, int iType = DX_PLAYTYPE_BACK, bool isStart = true);
	//��~
	static int Stop(tag_Sound iID);
	//�S��~
	static void AllStop();

	//�Đ����Ԏ擾
	static int GetSoundTime(tag_Sound iID);
	//�Đ������Ԏ擾
	static int GetSoundAllTime(tag_Sound iID);
	//�Đ����� true:�Đ����@false:��~��
	static bool IsPlay(tag_Sound iID);

	//�{�����[���ݒ�  (fVol 0.0�`1.0)
	static void SetVolume(tag_Sound iID, float fVol);

private:
	static int m_iHndl[SOUND_NUM];	//�T�E���h�n���h��

};









