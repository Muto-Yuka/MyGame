#include "Apple.h"

//�Q���C���X�g�̃t�@�C���p�X
#define ON_APPLES_PATH	("data/Game/Mission/Apple/OnApple.png")
#define UNDER_APPLES_PATH	("data/Game/Mission/Apple/UnderApple.png")
//���f���p�X
static const char MODEL_PATH[] = { "data/Game/Item/Apple/Apple.x" };

//�o�������邘�͈̔�
#define DRAW_ITEM_X	(400)
//�o�������邚�͈̔�
#define DRAW_ITEM_Z (400)
//�A�C�e���̔��a
#define ITEM_RADIUS (3)
//�H���Q�[�W�̂����W
#define APPLE_2D_Y		(600)		
//���Ȃ������鎞��
#define HUNGRY_TIME		(600)	
//�A�C�e���̏o������
#define WAIT_TIME		(120)

//�R���X�g���N�^
CApple::CApple()
{

}

//�f�X�g���N�^
CApple::~CApple()
{
	Exit();

	for (int i = 0; i < APPLE_NUM; i++)
		m_cApple[i].Exit();

}

//������
void CApple::Init(CPlayer& cPlayer)
{
	m_fRadius = ITEM_RADIUS;
	m_iHp = cPlayer.GetPlayerHP();	//�v���C���[��h�����󂯎��
	StartTime = 0;
	ResultFrg = false;
	MaxPlayerHp = cPlayer.GetPlayerHP();
	m_iWaitCnt = WAIT_TIME;


	for (int i = 0; i < APPLE_NUM; i++)
	{
		m_cApple[i].Init(ITEM_RADIUS);
	}

}

//���[�h
void CApple::Load()
{
	//�Q���摜���[�h ���������[�h����
	for (int i = 0; i < m_iHp; i++)
	{
		m_iOnHndl[i] = LoadGraph(ON_APPLES_PATH);
		m_iUnderHndl[i] = LoadGraph(UNDER_APPLES_PATH);

	}

	//�I���W�i�����f����ǂݍ���
	int iHndl = MV1LoadModel(MODEL_PATH);

	//���f���̕���
	for (int i = 0; i < APPLE_NUM; i++)
	{
		//�o���͈͂�ݒ�
		m_cApple[i].Load(DRAW_ITEM_X, DRAW_ITEM_Z);
		//��������
		m_cApple[i].DuplicateLoad(iHndl, DRAW_ITEM_X, DRAW_ITEM_Z);
	}

	//�I���W�i�����f���폜
	MV1DeleteModel(iHndl);

}

//���[�v
void CApple::Step()
{
	StartTime++;

	for (int i = 0; i < APPLE_NUM; i++)
	{

		//�ʏ탋�[�v
		m_cApple[i].Step();
		//���X�|�[�����郋�[�v����
		m_cApple[i].RespawnStep(DRAW_ITEM_X, DRAW_ITEM_Z, APPLE_NUM);


	}

	//��莞�Ԍo�ĂΐH�������炷
	if (StartTime % HUNGRY_TIME == 0)
	{
		SetAppleGauge();
	}

	////�H���Q�[�W���O�ɂȂ�ƃ��U���g
	//if (m_iHp == 0)
	//{
	//	ResultFrg = true;
	//}

}

//�`��
void CApple::Draw()
{
	//�R�����f���`��
	for (int i = 0; i < APPLE_NUM; i++)
	m_cApple[i].Draw();

	////�H���Q�[�W�`��(�ǂꂭ�炢���Ȃ����ւ��Ă��邩�킩��悤�ɈÂ��`��)
	//for (int i = 0; i < MaxPlayerHp; i++)
	//	DrawGraph(i * SHIFT_ITEM_PICTURE, APPLE_2D_Y, m_iUnderHndl[i], true);

	//for (int k = 0; k < m_iHp; k++)
	//	DrawGraph(k * SHIFT_ITEM_PICTURE, APPLE_2D_Y, m_iOnHndl[k], true);


}

//�v���C���[���A�C�e������������̏���
void CApple::HitItem()
{

	//���Ƃ��Ƃ���H���̍ő�l��菭�Ȃ��������
	if (m_iHp < PLAYER_HP)
		m_iHp++;

}

