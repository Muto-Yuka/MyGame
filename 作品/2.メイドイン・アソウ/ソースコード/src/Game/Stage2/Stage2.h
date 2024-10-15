#pragma once
#include "../GameBase.h"

//�B�ł�
class CStage2 : public CGameBase
{
private:
	//�C���X�g�֘A
	enum tagIMAGE
	{
		tag_BG,			//�w�i
		tag_DESK,		//��
		tag_HAMMER,		//�n���}�[
		tag_NAIL,		//�B
		tag_SPACE,		//�X�y�[�X�L�[

		tag_NUM
	};
	int		m_iGraph[tag_NUM];	//�S�摜�i�[
	int		m_iKeyCount;		//�L�[�������J�E���g
	int		m_iTime;			//��������
	float	m_fRot;				//�n���}�[�̉�]�p�x

public:
	CStage2();
	~CStage2();

	void Init();		//������
	void Load();		//���[�h
	int  Step();		//�X�e�b�v
	void Exit();		//�j��
	void Draw();		//�`��

	//���U���g����Ԃ� 0:�ҋ@�@1:�N���A�@2:�Q�[���I�[�o�[
	int GetResult();	

};




