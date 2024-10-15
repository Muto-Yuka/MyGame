#pragma once

class CClearScene
{
	int m_iHndl;	//�摜�n���h��

	enum tagClear
	{
		SCENE_INIT,		//������
		SCENE_LOAD,		//���[�h
		SCENE_STEP,		//�e����
		SCENE_EXIT,		//�j��
		SCENE_NEXT,		//����
	}m_eClearID;

public:
	CClearScene();
	~CClearScene();

	bool Loop();		//���[�v

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��
	void Next();		//����

};