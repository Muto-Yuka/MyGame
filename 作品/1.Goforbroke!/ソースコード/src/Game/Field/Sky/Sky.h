#pragma once
#include <dxlib.h>

class CSky
{
	int	m_iAmHndl;		//�ߑO
	int	m_iPmHndl;		//�ߌ�

public:
	CSky();
	~CSky();

	void Init();		//������
	void Load();		//���[�h
	void Loop();		//���[�v
	void AmDraw();		//�ߑO�`��
	void PmDraw();		//�ߌ�`��
	void Exit();		//�j��	
};




