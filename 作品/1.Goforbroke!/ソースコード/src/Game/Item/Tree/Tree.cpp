#include "Tree.h"
//3d���f��
static const char MODEL_PATH[] = { "data/Game/Item/Tree/Tree.x" };

//�o�������邘�͈̔�
#define DRAW_ITEM_X	(400)
//�o�������邚�͈̔�
#define DRAW_ITEM_Z (400)
//�A�C�e���̔��a
#define ITEM_RADIUS (5.0f)
//�؂̗̑�
#define TREE_HP	(50.f)

//�R���X�g���N�^
CTree::CTree()
{


}

//�f�X�g���N�^
CTree::~CTree()
{
	Exit();
}

//������
void CTree::Init()
{
	for (int i = 0; i < TREE_NUM; i++)
	{
		//���a������
		m_cTree[i].Init(ITEM_RADIUS);
		//�؂̗̑͏�����
		m_cTree[i].SetHp(TREE_HP);
		//HitFrg = false;	//�G���������ĂȂ�

	}

}

//���[�h
void CTree::Load()
{



	//�I���W�i�����f����ǂݍ���
	int iHndl = MV1LoadModel(MODEL_PATH);

	//���f���̕���
	for (int i = 0; i < TREE_NUM; i++)
	{
		//��������
		m_cTree[i].DuplicateLoad(iHndl);


	}

	//���W���Z�b�g
	m_cTree[0].SetInitPos(VGet(200.f, 0.f, 30.f));
	m_cTree[1].SetInitPos(VGet(-200.f, 0.f, 30.f));

	//�I���W�i�����f���폜
	MV1DeleteModel(iHndl);


}

//���[�v
void CTree::Step()
{
	for (int i = 0; i < TREE_NUM; i++)
	{
		//�ʏ탋�[�v
		m_cTree[i].Step();
	}

}

//�`��
void CTree::Draw()
{


	//�R�����f���`��
	for (int i = 0; i < TREE_NUM; i++)
		m_cTree[i].Draw();

}
//
////�������
//void CTree::HitBreakWater()
//{
//
//
//}
//
////������C������
//void CTree::HitRepairWater()
//{
//
//
//}
//


