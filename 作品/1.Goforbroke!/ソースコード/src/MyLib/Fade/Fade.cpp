#include "Fade.h"
#include <DxLib.h>

CFade* CFade::m_instance = nullptr;

//�C���X�^���X�擾
CFade* CFade::GetInstance()
{
	Alloc();
	return m_instance;
}

//�N���X�𐶐����ă������m��
void CFade::Alloc()
{
	if (m_instance == nullptr)
	{
		m_instance = new CFade;
	}
}

//�j��
void CFade::DeleteInstance()
{
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

//�t�F�[�h�̃��N�G�X�g
//(�t�F�[�h�̑���(1�`255)�Atrue�t�F�[�h�C��false�t�F�[�h�A�E�g)
void CFade::Request(float speed, bool isFadeIn)
{
	m_speed = speed;
	m_state = isFadeIn == true ? FADE_IN : FADE_OUT;
	m_cnt = isFadeIn == true ? 255.0f : 0.0f;
	m_windowX = 1280;
	m_windowY = 720;
}

//�X�V
void CFade::UpDate()
{
	switch (m_state)
	{
	case FADE_IN:
		m_cnt -= m_speed;
		if (m_cnt <= 0.0f) m_cnt = 0.0f;
		break;

	case FADE_OUT:
		m_cnt += m_speed;
		if (m_cnt >= 255.0f) m_cnt = 255;
		break;
	}
}

//�`��
void CFade::Draw()
{
	if (m_state == FADE_NON) return;

	//�A���t�@�l��ύX���Ďl�p���摜��`��\��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_cnt));
	//�w�肵�����W�Ŏl�p�����
	DrawBox(0, 0, m_windowX, m_windowY, GetColor(0, 0, 0), TRUE);
	//�u�����h���[�h�����Ƃɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

//�I��
bool CFade::IsEnd()
{
	bool isRed = true;

	switch (m_state)
	{
	case FADE_IN:
		//�t�F�[�h�C�����͒l���O�ɂȂ�����I��
		if (m_cnt > 0.0f) isRed = false;
		break;

	case FADE_OUT:
		//�t�F�[�h�A�E�g���͒l��255�ɂȂ�����I��
		if (m_cnt < 255.0f) isRed = false;
		break;
	}

	return isRed;
}










