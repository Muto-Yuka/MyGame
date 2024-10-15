#pragma once

class CGameOverScene
{
private:
	int m_iHndl;		//�ʏ�Q�[���I�[�o�[
	int m_iWaterlack;	//�����s���n���h��
	int m_iWaterplace;	//����̏������B��

public:

	//�R���X�g���N�^�E�f�X�g���N�^
	CGameOverScene();
	~CGameOverScene();

	//�ʏ�`�揈��
	void Draw();
	//�����s��
	void LackDraw();
	//���B��
	void PlaceDraw();
	//������
	void Init(void);
	//�I������
	void Exit();
	//�f�[�^���[�h
	void Load();
	//���t���[���Ăԏ���
	void Step();

};