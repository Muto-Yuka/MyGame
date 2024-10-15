#include <DxLib.h>
#include "FPS.h"

//��b�ԂɂU�O
static const int FRAME_RATE = 60;		
//1�t���[�������~���b���H
static const int FRAME_RATE_MILL_SECOND = 1000 / 60;	

int CFPS::m_currentTime;
int CFPS::m_lastTime;
int CFPS::m_count;
int CFPS::m_updateFrameRateTime;
double CFPS::m_frameRate;

//������
void CFPS::Init()
{
	m_currentTime = GetNowCount();	
	m_lastTime = m_currentTime;		
	m_frameRate = 0.0;
	m_count = 0;
	m_updateFrameRateTime = m_currentTime;
}

//true:���̏����ց@false:�ҋ@
bool CFPS::CheckNext()
{
	//�ŐV���Ԏ擾
	m_currentTime = GetNowCount();	
	//�O��̎��ԂƍŐV�̎��Ԃ̍����i�ǂꂭ�炢�o�߂������j
	int difTime = m_currentTime - m_lastTime;
	
	//�O�񂩂獡��܂łŎw�肳�ꂽ���Ԃ��o�߂������@�Z�o�ߎ��Ԃ��傫���@�~������
	if (difTime >= FRAME_RATE_MILL_SECOND)
		return true;
	else 
		return false;

}

//�t���[�����[�g�̌v�Z
void CFPS::Step()
{
	m_lastTime = m_currentTime;
}

//�t���[�����[�g�\��(�f�o�b�N�p)
void CFPS::DrawFps()
{
	m_count++;	
	//�O��̎��ԂƍŐV�̎��Ԃ̍����i�ǂꂭ�炢�o�߂������j
	int difTime = m_currentTime - m_updateFrameRateTime;

	//�O��̎��Ԃ���P�b�o�܂ł͂��̏����͎��s���Ȃ�
	if (difTime > 1000)
	{
		float frameCnt = (float)(m_count * 1000);
		m_frameRate = frameCnt / difTime;
		m_count = 0;
		m_updateFrameRateTime = m_currentTime;
	}

	DrawFormatString(16, 16, GetColor(255, 255, 255), "FPS : %.02lf", m_frameRate);	//%.02lf 02�͏����_�񌅂܂Ł@lf��double�^

}





