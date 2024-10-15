#pragma once
#include "SceneBase.h"

class CDay2PlayScene : public CBaseScene
{
public:
	//�R���X�g���N�^�E�f�X�g���N�^b
	CDay2PlayScene();
	~CDay2PlayScene();

	//�J��Ԃ��s������
	void Loop();
	//�`�揈��(�e����)
	void ShadowDraw();
	//�`�揈��(�e�Ȃ�)
	void Draw();

	//������
	void Init(void);
	//�I������
	void Exit();
	//�f�[�^���[�h
	void Load();
	//���t���[���Ăԏ���
	void AmStep();
	void PmStep();
	void Next();

	//�N���A�������łȂ���
	bool GetClearFlg();
	//���U���g�ɂ������ǂ����@true : ���U���g��
	bool GetResultFlg() { return cItemManager.GetResultFrg(); }
	//����ڃN���A�ł��邩����́��@�t���O
	bool GetWaterClear();
	



};



