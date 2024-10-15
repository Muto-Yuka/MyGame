#include "Mission.h"

static const char MODEL_PATH[] = { "data/Game/Mission/Mission.png" };
static const char M_PAPER_PATH[] = { "data/Game/Mission/Paper.png" };

//�~�b�V�����Q���摜������傫����ʂɕ\�����邩�@���̌�͏�ɕ`�悵�Ă���
#define MISSION_DRAW_NUM  (1)
//�Q���摜�����l�@��X
#define L_DRAW_X		(0)
//�Q���摜�����l�@��Y
#define L_DRAW_Y		(40)
//�Q���摜�����l�@�EX
#define R_DRAW_X		(1280)
//�Q���摜�����l�@�E1Y
#define R_DRAW_Y		(190)

//�~�b�V�����̈ړ����鑬��
#define MOVE_MISSION_SPEED	(2)

//�~�b�V�����A�C�e�����W�߂鐔
#define M_STRAW		(12)	//�m
#define M_BRANCH	(6)		//�}
#define M_IVY		(4)		//�c�^

CMission::CMission()
{

}

CMission::~CMission()
{
	Exit();
}

//������
void CMission::Init()
{
	m_iHndl = -1;
	m_iPaperHndl = -1;
	m_iTransparency = 0;
	count = 0;
	m_bDraw = false;
	m_iMissionCnt = 0;
	DrawCount = 0;
	L_DrawX = L_DRAW_X;
	L_DrawY = L_DRAW_Y;
	R_DrawX = R_DRAW_X;
	R_DrawY = R_DRAW_Y;

	//�~�b�V�����A�C�e��������
	m_iStraw = 0;
	m_iBranch = 0;
	m_iIvy = 0;

	MissionTitle = true;

}

//���[�h
void CMission::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = LoadGraph(MODEL_PATH);
	}

	if (m_iPaperHndl == -1)
	{
		m_iPaperHndl = LoadGraph(M_PAPER_PATH);
	}

}

//���t���[���Ăԏ���
void CMission::Step(CItemManager& cItemManager)
{
	count++;
	m_iMissionCnt++;

	//�~�b�V�������ߏ���
	StepMission();

	//���̐����擾���Ă���
	m_iStraw = cItemManager.GetStrawNum();

}

//�`��
void CMission::Draw()
{
	//�����
	if (SceneId == true)
	{
		if (MissionTitle == true)
		{
			DrawFormatString(445, 200, GetColor(165, 42, 42), "<�P���ځF��P���Ă���G�ɒ��ӂ���>");
		}
	}
	else 
	{
		if (MissionTitle == true)
		{
			DrawFormatString(445, 200, GetColor(165, 42, 42), "<�Q���ځF�����50���ȏ�ɂ���>");
		}
	}

	//�w��̉񐔕��~�b�V������`�悷��
	if (DrawCount == MISSION_DRAW_NUM)
	{
		//�w��񐔕`�悵����@��ɕ`�悵��������
		if (m_iTransparency >= 255)
		{
			//�~�b�V�������e���E��ɕ`�悷��
			StringMission();
		}
	}
	//�~�b�V������`�悷��
	MissionDraw();

}
//�I��
void CMission::Exit()
{
	DeleteGraph(m_iHndl);
	DeleteGraph(m_iPaperHndl);

}

//�~�b�V�������ߏ��� ���ߗp�ϐ��ɒl��������
void CMission::StepMission()
{

	//�w��̉񐔕��~�b�V������`�悷��
	if (DrawCount != MISSION_DRAW_NUM)
	{
		//�~�b�V�����̓��߂��J��Ԃ�����
		//�P�O�O�t���[�����Ƃɓ��߂��邵�Ȃ������݂ɌJ��Ԃ�
		if (count == 100)
		{

			if (m_bDraw == true)
			{
				m_bDraw = false;
				DrawCount++;
			}
			else
				m_bDraw = true;

			count = 0;
		}

		if (m_bDraw == true)	//true�i�`�撆�j�������瓧���� 0=����
			m_iTransparency -= 3;
		else
			m_iTransparency += 3; //false�i�����`�悵�ĂȂ��j�������瓧���x���グ��@255=�s����

	}
	else //��ɕ`�悳����
	{
		m_iTransparency += 3; //false�i�����`�悵�ĂȂ��j�������瓧���x���グ��@255=�s����

		//�w��񐔕`�悵����@��ɕ`�悵��������
		if (m_iTransparency >= 255)
		{
			//�摜�E��Ɉړ�
			MoveMIssion();
			MissionTitle = false;

		}

	}
}

//�~�b�V�����̂Q���摜�`��
void CMission::MissionDraw()
{
	//�~�b�V������ʂ̕`�揈��
	//�u�����h���[�h��ύX �O�������@�Q�T�T���s����
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_iTransparency);
	//				   0        40      1280     190
	DrawExtendGraph(L_DrawX, L_DrawY, R_DrawX, R_DrawY, m_iHndl, true);
	//�ݒ�����ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//�~�b�V�����摜���E��Ɉړ�����
void CMission::MoveMIssion()
{
	//DrawExtendGraph(900, 0, 1280, 50, m_iHndl, true)�ɐݒ肷��

	//����
	if (L_DrawX <= 900)
		L_DrawX += MOVE_MISSION_SPEED + 8;
	//����
	if (L_DrawY >= 0)
		L_DrawY -= MOVE_MISSION_SPEED;
	//�E��
	if (R_DrawY >= 50)
		R_DrawY -= MOVE_MISSION_SPEED;

}

//�~�b�V�������e�̕���\������
void CMission::StringMission()
{

	//�A�C�e�������ׂĎ��I������炸���ƂO�\��
	if (m_iStraw >= M_STRAW)
	{
		//�m�̃~�b�V�����N���A
		m_sItemClearFrg.s_bStraw = true;
		m_iStraw = M_STRAW;
	}

	if (SceneId == true)
	{
		DrawFormatString(900, 60, GetColor(165, 42, 42), "�s�P���Ă���G�ɒ��ӂ���t");
	}
	else
	{
		DrawFormatString(900, 60, GetColor(165, 42, 42), "�s�����50%�ȏ�ɂ���t");
	}
}


//**�Q�b�^�[�E�Z�b�^�[**
//�~�b�V�����������ǂ����@true:���� false:���s
bool CMission::GetMissionClearFrg()
{
	//���~�b�V���������s�Ȃ�
	if (m_sItemClearFrg.s_bStraw == false)
		return false;
	//�}�~�b�V���������s�Ȃ�
	if (m_sItemClearFrg.s_bBranch == false)
		return false;
	//���~�b�V���������s�Ȃ�
	if (m_sItemClearFrg.s_bIvy == false)
		return false;


	//���ׂĐ������Ă���true��Ԃ�
	return true;
}


