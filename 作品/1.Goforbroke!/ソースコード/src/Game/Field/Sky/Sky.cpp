#include "Sky.h"

const char AM_SKY_MODEL_PATH[] = { "data/Game/Field/Sky/AmSky.x" };
const char PM_SKY_MODEL_PATH[] = { "data/Game/Field/Sky/PmSky.x" };

CSky::CSky()
{
	Init();
}

CSky::~CSky()
{
	Exit();
}

//������
void CSky::Init()
{
	m_iAmHndl = -1;
	m_iPmHndl = -1;
}

//���[�h
void CSky::Load()
{
	if (m_iAmHndl == -1)
		m_iAmHndl = MV1LoadModel(AM_SKY_MODEL_PATH);

	if (m_iPmHndl == -1)
		m_iPmHndl = MV1LoadModel(PM_SKY_MODEL_PATH);
}

//���[�v
void CSky::Loop()
{
	MV1SetScale(m_iAmHndl, VGet(30.0f, 30.0f, 30.0f));
	MV1SetScale(m_iPmHndl, VGet(30.0f, 30.0f, 30.0f));
}

//�ߑO�`��
void CSky::AmDraw()
{
	MV1DrawModel(m_iAmHndl);
}

//�ߌ�`��
void CSky::PmDraw()
{
	MV1DrawModel(m_iPmHndl);
}

void CSky::Exit()
{
	MV1DeleteModel(m_iAmHndl);
	MV1DeleteModel(m_iPmHndl);
}








