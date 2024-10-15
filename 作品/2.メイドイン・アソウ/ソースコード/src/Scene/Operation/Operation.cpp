#include <DxLib.h>
#include"Operation.h"
#include "../../MyLib/Fade/Fade.h"
#include "../../MyLib/Input/Input.h"
#include "../../MyLib/Sound/Sound.h"

static const char OPERATION_PATH[] = { "" };

COperation::COperation()
{
	Init();	
}
COperation::~COperation()
{
	Exit();
}

//���[�v
int COperation::Loop()
{
	//�֐��|�C���^��錾���֐���z��ɓ����
	void (COperation:: * Operation[])() = {
		&COperation::Init,& COperation::Load,& COperation::Step,& COperation::Exit, & COperation::Next
	};
	//id�ɍ��킹�ď��������s
	(this->*Operation[m_eSceneID])();

	if (m_eSceneID == SCENE_NEXT)
		return 1;

	return -1;
}

//������
void COperation::Init()
{
	CSceneBase::Init();

}

//���[�h
void COperation::Load()
{

	CSceneBase::Load();
}

//�X�e�b�v
void COperation::Step()
{
	//����Ŏ���
	CSceneBase::Step();

}

//�`��
void COperation::Draw()
{
	DrawGraph(0, 0, m_iHndl, true);
}

//�j��
void COperation::Exit()
{
	CSceneBase::Exit();
}

//����
void COperation::Next()
{
	CSceneBase::Next();
}


