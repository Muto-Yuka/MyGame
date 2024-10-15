#include "BaseMission.h"
#include "DxLib.h"

//�H���Q�[�W�C���X�g�����炷
#define SHIFT_ITEM_PICTURE	(28)



//�R���X�g���N�^
CBaseMission::CBaseMission()
{
	//�n���h���ɕۑ�				�t�H���g�̎�ށ@�T�C�Y�@�����@�^�C�v
	FontHandle = CreateFontToHandle("HGP�s����", 40, 10, DX_FONTTYPE_NORMAL);
	Init();
}

//������
void CBaseMission::Init()
{
	//�摜�n���h��������
	for (int i = 0; i < 5; i++)
	{
		m_iOnHndl[i] = -1;
		m_iUnderHndl[i] = -1;

	}

	m_iMissionCnt = 0;
	m_bClear = false;
	m_iDrawNum = GAUGE_NUM;
	HitFlg = false;
	m_iDrawPictureY = 0;
	m_iWordX = MISSION_WORD_X;
	m_iWordY = MISSION_WORD_Y;

}

//���[�v
void CBaseMission::Step()
{
	m_iMissionCnt++;

	//�~�b�V�����J�n����ܕb�o�����當�����E��ֈړ�
	if (m_iMissionCnt > 300)
	{
		if (m_iWordX < 680)
			m_iWordX += 2;		//�����𑫂�
		if (m_iWordY > 0)
			m_iWordY -= 2;
	}

}

//��ɕ`��
void CBaseMission::AlwaysDraw()
{
	//�H���Q�[�W�`��(�ǂꂭ�炢���Ȃ����ւ��Ă��邩�킩��悤�ɈÂ��`��)
	for (int i = 0; i < GAUGE_NUM; i++)
		DrawGraph(i * SHIFT_ITEM_PICTURE, m_iDrawPictureY, m_iUnderHndl[i], true);

	for (int k = 0; k < m_iDrawNum; k++)
		DrawGraph(k * SHIFT_ITEM_PICTURE, m_iDrawPictureY, m_iOnHndl[k], true);


}


//�I��
void CBaseMission::Exit()
{
	for (int i = 0; i < GAUGE_NUM; i++)
	{
		DeleteGraph(m_iOnHndl[i]);
		DeleteGraph(m_iUnderHndl[i]);

	}

	DeleteFontToHandle(FontHandle);
}






