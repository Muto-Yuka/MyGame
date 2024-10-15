#include "Straw.h"

//�p�X
static const char MODEL_PATH[] = { "data/Game/Item/Straw/Straw.x" };

//�o�������邘�͈̔�
#define DRAW_ITEM_X	(200)
//�o�������邚�͈̔�
#define DRAW_ITEM_Z (200)
//�A�C�e���̔��a
#define ITEM_RADIUS (3)
//�o��������A�C�e���̐�
#define ITEM_NUM (2)

//�R���X�g���N�^
CStraw::CStraw()
{

}

//�f�X�g���N�^
CStraw::~CStraw()
{
	Exit();

	for (int i = 0; i < STRAW_NUM; i++)
		m_cStraw[i].Exit();
}

//������
void CStraw::Init()
{
	for (int i = 0; i < STRAW_NUM; i++)
	{

		m_cStraw[i].Init(ITEM_RADIUS);
	}

	m_iItemNum = 0;
}

//���[�h
void CStraw::Load()
{
	//�I���W�i�����f����ǂݍ���
	int iHndl = MV1LoadModel(MODEL_PATH);

	//���f���̕���
	for (int i = 0; i < STRAW_NUM; i++)
	{
		//��������
		m_cStraw[i].DuplicateLoad(iHndl, DRAW_ITEM_X, DRAW_ITEM_Z);
	}

	//�I���W�i�����f���폜
	MV1DeleteModel(iHndl);

}

//���[�v
void CStraw::Step()
{

	for (int i = 0; i < STRAW_NUM; i++)
	{
		//�ʏ탋�[�v
		m_cStraw[i].Step();
		//���X�|�[�����郋�[�v����
		m_cStraw[i].RespawnStep(DRAW_ITEM_X, DRAW_ITEM_Z, STRAW_NUM);
	}
}

//�`��
void CStraw::Draw()
{
	//�R�����f���`��
	for (int i = 0; i < STRAW_NUM; i++)
		m_cStraw[i].Draw();

}

//�v���C���[���A�C�e������������̏���
void CStraw::HitItem()
{
	//�`�悵�Ȃ�
	m_bSurvival = false;
	//�擾�����A�C�e���ϐ���+1
	m_iItemNum++;


}

