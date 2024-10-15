#include <DxLib.h>
#include "Play.h"
#include "../../Game/Stage1/Stage1.h"
#include "../../Game/Stage2/Stage2.h" 
#include "../../Game/Stage3/Stage3.h"
#include "../../Game/Stage4/Stage4.h"

CPlay::CPlay():m_base(nullptr),m_ePlayID(STATEID_INIT),m_next(STAGE_1)
{
	// �֐��|�C���^�ɓK�؂Ȋ֐���ݒ�
	m_step[STATEID_INIT] = &CPlay::Init;
	m_step[STATEID_LOAD] = &CPlay::Load;
	m_step[STATEID_STEP] = &CPlay::Step;
	m_step[STATEID_FIN] = &CPlay::Exit;
	CreateScene();	// �ŏ��̃V�[���쐬
}
CPlay::~CPlay()
{
	if (m_base != nullptr)
		delete m_base;
}

//���[�v 0:�ҋ@
int CPlay::Loop()
{
	// �e�폈���̌Ăяo��
	(this->*m_step[m_ePlayID])();

	//�N���A��
	if (m_base->GetResult() == 1)
	{
		if (m_eClearCount == STAGE_3)
			return 1;
	}
	if (m_base->GetResult() == 2)
		return 2;
	
	return -1;
}

//�`��
void CPlay::Draw()
{
	m_base->Draw();
	CFade::GetInstance()->Draw(); //�K���t�F�[�h�͍Ō�ɂ���
}

//������
void CPlay::Init()
{
	m_eClearCount = 0;
	m_base->Init();
	m_ePlayID = STATEID_LOAD;
}
//���[�h
void CPlay::Load()
{
	m_base->Load();
	m_ePlayID = STATEID_STEP;
	CFade::GetInstance()->Request(4.0f, true);
}

//���̑����[�v
void CPlay::Step()
{
	if (!CFade::GetInstance()->IsEnd()) return;

	int Fin = m_base->Step();

	if (Fin != -1)
	{
  		m_eClearCount = m_next;
       	m_ePlayID = STATEID_FIN;
    	CFade::GetInstance()->Request(4.0f, false);
	}
}
//�j��
void CPlay::Exit()
{
	if (!CFade::GetInstance()->IsEnd()) return;

	m_base->Exit();			//�j��
	//m_next = GetRand(3);	//�����_���Ŏ��̃X�e�[�W�擾
	CreateScene();			//�V�[����j���������쐬

	m_ePlayID = STATEID_INIT;
}

//�V�[���쐬
void CPlay::CreateScene()
{
	// �Â��V�[���폜
	if (m_base != nullptr)
	{
		if (m_base->GetResult() == 1)
		{
			delete m_base;
			m_next += 1;
		}
		else
			delete m_base;
	}

	// �V�����V�[���쐬
	switch (m_next)
	{
	case STAGE_1:
		m_base = new CStage1;
		break;

	case STAGE_2:
		m_base = new CStage2;
		break;

	case STAGE_3:
		m_base = new CStasge3;
		break;

	case STAGE_4:
		m_base = new CStasge4;
		break;

	default:

		break;
	}

}







