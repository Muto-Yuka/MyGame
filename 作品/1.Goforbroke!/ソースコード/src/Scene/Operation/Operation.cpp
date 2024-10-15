#include <DxLib.h>
#include"Operation.h"
#include "../../MyLib/Fade/Fade.h"
#include "../../MyLib/Input/Input.h"
#include "../../MyLib/Sound/Sound.h"

static const char OPERATION_PATH[] = { "data/Scene/Operation/Operation.png" };
static const int  OPERATION_TIME = 1200;

COperationScene::COperationScene()
{
	Init();	
}
COperationScene::~COperationScene()
{
	Exit();
	CFade::DeleteInstance();
}

//���[�v
bool COperationScene::Loop()
{
	//�֐��|�C���^��錾���֐���z��ɓ����
	void (COperationScene:: * Operation[])() = {
		&COperationScene::Init,&COperationScene::Load,& COperationScene::Step,& COperationScene::Exit, & COperationScene::Next
	};
	//id�ɍ��킹�ď��������s
	(this->*Operation[m_eOperationID])();

	if (m_eOperationID == SCENE_NEXT)
		return true;
	else
		return false;

}

//������
void COperationScene::Init()
{
	m_iHndl = -1;		
	m_iOperationTime = 0;
	m_eOperationID = SCENE_LOAD;
}

//���[�h
void COperationScene::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = LoadGraph(OPERATION_PATH);
	}
	m_eOperationID = SCENE_STEP;
	CFade::GetInstance()->Request(4.0f, true);
}

//�X�e�b�v
void COperationScene::Step()
{
	if (!CFade::GetInstance()->IsEnd()) return;

	//��������J�E���g
	m_iOperationTime++;
	//����������Ԍo�߂�����
	if (OPERATION_TIME <= m_iOperationTime)
	{
		CSound::AllStop();
		m_eOperationID = SCENE_EXIT;
		CFade::GetInstance()->Request(4.0f, false);
	}
	else if (CInput::IsInputPush(CInput::INPUT_NEXT) || (CPadInput::PadInput & PAD_INPUT_8))	//�G���^�[�������Ǝ���
	{
		CSound::AllStop();
		m_eOperationID = SCENE_EXIT;
		CFade::GetInstance()->Request(4.0f, false);
	}
}

//�`��
void COperationScene::Draw()
{
	DrawGraph(0, 0, m_iHndl, true);
}

//�j��
void COperationScene::Exit()
{
	if (!CFade::GetInstance()->IsEnd()) return;

	DeleteGraph(m_iHndl);

	m_eOperationID = SCENE_NEXT;
}

//����
void COperationScene::Next()
{
	m_eOperationID = SCENE_INIT;
}


