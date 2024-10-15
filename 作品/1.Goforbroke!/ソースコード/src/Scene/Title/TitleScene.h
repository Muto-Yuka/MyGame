#pragma once

class CTitleScene
{
	int	m_iHndl;	//�摜�n���h��

	enum tagTitle
	{
		SCENE_INIT,		//������
		SCENE_LOAD,		//���[�h
		SCENE_STEP,		//�e����
		SCENE_EXIT,		//�j��
		SCENE_NEXT,		//����
	}m_eTitleID;

public:
	CTitleScene();
	~CTitleScene();

	bool Loop();		//���[�v

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��
	void Next();		//����

};




