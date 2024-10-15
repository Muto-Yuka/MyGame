#include "Shadow.h"

void CShadow::Init()
{
	//�e��������������������������������������������������������������������������
	//�V���h�E�}�b�v���쐬����i�T�C�Y�͉𑜓x�Ɋ֌W����j
	//�T�C�Y�͕K���Q�ׂ����
	shadowHndl = MakeShadowMap(2048, 2048);

	//���̕�����ݒ肷��	  �V���h�E�}�b�v�n���h���A�΂߂̉e���ł���
	SetShadowMapLightDirection(shadowHndl, VGet(-1.5f, -3.0f, -2.8f));

	//�e��`�悷��͈͂��Z�b�g�i�G���A�����߂Ȃ��Ə������������d�����Ȃ�j
	//�V���h�E�}�b�v�n���h���A
	SetShadowMapDrawArea	//�ݒ肵�����W�̓����ɂ���Ƃ������e�����f
	(shadowHndl, VGet(-50.0f, -1.0f, -50.0f), VGet(250.0f, 10.0f, 200.0f));
	//(shadowHndl, VGet(-50.0f, -1.0f, -50.0f), VGet(150.0f, 10.0f, 100.0f));
	//				�͈͂̍ŏ��l�A			�͈͂̍ő�l


}

void CShadow::Draw()
{
	//�e�̕`�揈��
	ShadowMap_DrawSetup(shadowHndl);//�e�̕`��O�ɕK���s��
	cSceneManager.Draw();
	ShadowMap_DrawEnd();			//�e�̕`���ɕK���s��
	//�ʏ�̕`�揈��
	SetUseShadowMap(0, shadowHndl);	//���f������e�̃n���h���ƂO�`�Q�̃X���b�g�ԍ��Z�b�g
	cSceneManager.Draw();
	SetUseShadowMap(0, -1);			//�I�������g�p�����X���b�g�ԍ����[�P�ŏI��点��

}

void CShadow::Exit()
{
	//�V���h�E�}�b�v�j��
	DeleteShadowMap(shadowHndl);

}

void CShadow::Loop()
{
	//�v�Z����
	cSceneManager.Loop();

}


