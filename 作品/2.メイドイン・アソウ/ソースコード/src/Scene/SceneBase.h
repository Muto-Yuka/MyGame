#pragma once

class CSceneBase
{
protected:
	int	m_iHndl;			//�摜�n���h��

	enum tagScene
	{
		SCENE_INIT,		//������
		SCENE_LOAD,		//���[�h
		SCENE_STEP,		//�e����
		SCENE_EXIT,		//�j��
		SCENE_NEXT,		//����
	}m_eSceneID;

public:
	virtual int Loop() = 0;
	virtual void Draw() = 0;

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Exit();		//�j��
	void Next();		//����

};




