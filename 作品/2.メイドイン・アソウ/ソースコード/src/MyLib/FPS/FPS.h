#pragma once

class CFPS
{
	static int m_currentTime;		  //���݂̂o�b����
	static int m_lastTime;			  //�ЂƂO�̂o�b����
	static double m_frameRate;		  //���݂̃t���[�����[�g(�f�o�b�N�p)
	static int m_count;				  //�t���[�����J�E���g(�f�o�b�N�p)
	static int m_updateFrameRateTime; //�t���[�����[�g�X�V����(�f�o�b�N�p)

public:
	static void Init();			//������
	static bool CheckNext();	// true�F���̏����@false�F�ҋ@
	static void Step();			//�v�Z
	static void DrawFps();		//�\��(�f�o�b�N�p)

};


