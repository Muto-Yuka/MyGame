#include"Sound.h"

int CSound::m_iHndl[SOUND_NUM];

#define BGM_TITLE ("data/Sound/Title/Title.mp3")
#define BGM_PLAY ("data/Sound/Play/Pm.mp3")
#define BGM_CLEAR  ("data/Sound/Clear/Clear.mp3")
#define BGM_GAMEOVER ("data/Sound/Gameover/Gameover.mp3")

CSound::CSound()
{
	Init();
}
CSound::~CSound()
{
	Exit();
}

//������
void CSound::Init()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		m_iHndl[i] = -1;
	}
}

//�S�f�[�^�ǂݍ���
bool CSound::AllLoad()
{
	bool isRet = true;

	const char pFileName[SOUND_NUM][128] =
	{
		BGM_TITLE, BGM_PLAY, BGM_CLEAR, BGM_GAMEOVER
	};

	for (int i = 0; i < SOUND_NUM; i++)
	{
		m_iHndl[i] = LoadSoundMem(pFileName[i]);

		if (m_iHndl[i] == -1) isRet = false;
	}
	return isRet;
}

//�j��
void CSound::Exit()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		if (m_iHndl[i] != -1)
		{
			DeleteSoundMem(m_iHndl[i]);
			m_iHndl[i] = -1;
		}
	}
}

//�Đ�
int CSound::Play(tag_Sound iID, int iType, bool isStart)
{
	return PlaySoundMem(m_iHndl[iID], iType, isStart);
}
//��~
int CSound::Stop(tag_Sound iID)
{
	return StopSoundMem(m_iHndl[iID]);
}
//�S��~
void CSound::AllStop()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		StopSoundMem(m_iHndl[i]);
	}
}

//�Đ����Ԏ擾
int CSound::GetSoundTime(tag_Sound iID)
{
	return (int)GetSoundCurrentTime(m_iHndl[iID]);
}
//�Đ������Ԏ擾
int CSound::GetSoundAllTime(tag_Sound iID)
{
	return (int)GetSoundTotalTime(m_iHndl[iID]);
}
//�Đ�����
bool CSound::IsPlay(tag_Sound iID)
{
	return CheckSoundMem(m_iHndl[iID]) == 1 ? true : false;
}

//���ʐݒ�
void CSound::SetVolume(tag_Sound iID, float fVol)
{
	if (fVol < 0.f || fVol > 1.f) return;
	ChangeVolumeSoundMem((int)(255.f * fVol), m_iHndl[iID]);
}


