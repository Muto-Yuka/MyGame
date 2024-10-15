#pragma once
#include "Ground/Ground.h"
#include "Sky/Sky.h"

//�t�B�[���h���܂Ƃ߂�}�l�[�W���[�N���X
class CFieldManager
{
	enum tagSceneID
	{
		SCENE_AM = 2,	//�ߑO
		SCENE_PM,		//�ߌ�

	}m_eSceneID;

	CGround cGround;
	CSky	cSky;

public:
	void Init();		//������
	void Load();		//���[�h
	void Loop();		//���[�v
	void Draw(int m_eSceneID);		//�`�� �����FSceneID�����邩�󂯎��
	void Exit();		//�j��

	//�����蔻��p�i����̍��W�Ɣ��a�jreturn:�����߂������ƕ���
	VECTOR	HitCheck(VECTOR anotherPos, float anotherRadius)
	{ return cGround.HitCheck(anotherPos, anotherRadius);};

};



