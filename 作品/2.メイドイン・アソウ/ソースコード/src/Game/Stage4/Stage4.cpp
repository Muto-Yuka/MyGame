#include <DxLib.h>
#include "Stage4.h"
#include "../../MyLib/Sound/Sound.h"

//�w�i
static const char BG_PATH[] = { "data/" };

CStasge4::CStasge4()
{
	Init();
}
CStasge4::~CStasge4()
{
	Exit();
}

//������
void CStasge4::Init()
{
	cPlayer4.Init();
	cPop.Init();

	CSound::SetVolume(CSound::SOUND_STAGE4, 0.7);

}
//���[�h
void CStasge4::Load()
{
	cPlayer4.Load();
	cPop.Load();

	CSound::Play(CSound::SOUND_STAGE4, DX_PLAYTYPE_BACK, true);
}
//�X�e�b�v
int CStasge4::Step()
{
	int ret = -1;
	cPlayer4.Step();
	cPop.Step(cPlayer4.GetTime());

	if (cPlayer4.GetTime() >= POP_FULL)
	{
		ret = 1;
		CSound::AllStop();
	}

	return ret;

}
//�`��
void CStasge4::Draw()
{
	cPop.Draw();
	cPlayer4.Draw();
}
//�j��
void CStasge4::Exit()
{
	cPlayer4.Exit();
	cPop.Exit();
}

//���U���g����Ԃ�
int CStasge4::GetResult()
{
	//0:�ҋ@�@1:�N���A�@2:�Q�[���I�[�o�[
	if (cPlayer4.GetTime() >= POP_FULL)
		return 1;

	return 0;
}


