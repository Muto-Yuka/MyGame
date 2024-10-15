#pragma once

class COperationScene
{
	int	m_iHndl;			//�摜�n���h��
	int	m_iOperationTime;	//��������\������

	enum tagOperation
	{
		SCENE_INIT,		//������
		SCENE_LOAD,		//���[�h
		SCENE_STEP,		//�e����
		SCENE_EXIT,		//�j��
		SCENE_NEXT,		//����
	}m_eOperationID;

public:
	COperationScene();
	~COperationScene();

	bool Loop();		//���[�v

	void Init();		//������
	void Load();		//���[�h
	void Step();		//�X�e�b�v
	void Draw();		//�`��
	void Exit();		//�j��
	void Next();		//����

};




