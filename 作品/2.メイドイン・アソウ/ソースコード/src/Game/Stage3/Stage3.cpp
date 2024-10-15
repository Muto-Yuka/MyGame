#include <DxLib.h>
#include "Stage3.h"
#include "../../MyLib/Sound/Sound.h"

CStasge3::CStasge3()
{
	Init();
}
CStasge3::~CStasge3()
{
	Exit();
}

//������
void CStasge3::Init()
{
	cBackGround.Init();
	cPlayer3.Init();
	cHitPoint.Init();
	cDrop.Init();
}
//���[�h
void CStasge3::Load()
{
	cBackGround.Load();
	cPlayer3.Load();
	cHitPoint.Load();
	cDrop.Load();

	CSound::Play(CSound::SOUND_STAGE3, DX_PLAYTYPE_BACK, true);
}
//�X�e�b�v
int CStasge3::Step()
{
	int ret = -1;

	cBackGround.Step();
	cPlayer3.Step();
	cHitPoint.Step();
	cDrop.Step(cPlayer3);

	//�j����
	if (cDrop.Hit(cHitPoint) != 0)
	{
		CSound::AllStop();
		return 1;
	}

	return ret;
}
//�`��
void CStasge3::Draw()
{
	cBackGround.Draw();
	cPlayer3.Draw();
	cHitPoint.Draw();
	cDrop.Draw();
}
//�j��
void CStasge3::Exit()
{
	cBackGround.Exit();
	cPlayer3.Exit();
	cHitPoint.Exit();
	cDrop.Exit();
}

//���U���g����Ԃ�
int CStasge3::GetResult()
{
	//0:�ҋ@�@1:�N���A�@2:�Q�[���I�[�o�[
	return cDrop.Hit(cHitPoint);
}



