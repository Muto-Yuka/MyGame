#include <DxLib.h>
#include "Stage1.h"
#include "../../MyLib/Sound/Sound.h"

CStage1::CStage1()
{
	Init();
}
CStage1::~CStage1()
{
	Exit();
}

//������
void CStage1::Init()
{
	cBackGround.Init();
	cPlayer.Init();
	cEnemy.Init();
	cBrock.Init();
	cFlag.Init();

	CSound::SetVolume(CSound::SOUND_STAGE1, 1);
}
//���[�h
void CStage1::Load()
{
	cBackGround.Load();
	cPlayer.Load();
	cEnemy.Load();
	cBrock.Load();
	cFlag.Load();

	CSound::Play(CSound::SOUND_STAGE1, DX_PLAYTYPE_BACK, true);
}
//�X�e�b�v�@-1�F�ҋ@
int  CStage1::Step()
{
	int ret = -1;

	cBackGround.Step(cPlayer);
	cPlayer.Step();
	cEnemy.Step(cPlayer);
	cBrock.Step(cPlayer);
	cFlag.Step(cPlayer);

	//�j���ւ�����
	if (cPlayer.GetClear() || cPlayer.GetGameover())
	{
		ret = 0;
		CSound::AllStop();
	}

	return ret;
}
//�`��
void CStage1::Draw()
{
	cBackGround.Draw();
	cPlayer.Draw();
	cEnemy.Draw();
	cBrock.Draw();
	cFlag.Draw();
}
//�j��
void CStage1::Exit()
{
	cBackGround.Exit();
	cPlayer.Exit();
	cEnemy.Exit();
	cBrock.Exit();
	cFlag.Exit();
}
//���U���g����Ԃ�
int CStage1::GetResult()
{
	//0:�ҋ@�@1:�N���A�@2:�Q�[���I�[�o�[

	if (cPlayer.GetClear())
		return 1;
	if (cPlayer.GetGameover())
		return 2;

	return 0;
}




