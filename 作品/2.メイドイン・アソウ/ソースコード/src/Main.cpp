#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "MyLib/Input/Input.h"
#include "MyLib/Fps/Fps.h"
#include "WindowsSize.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// ���������[�N�`�F�b�N�p
	ChangeWindowMode(FALSE);											// �E�B���h�E���[�h�ŋN��
	SetGraphMode(WINDOWS_X, WINDOWS_Y, 32);
	if (DxLib_Init() == -1) return -1;								// Dxlib�������֐�
	SetDrawScreen(DX_SCREEN_BACK);									// �X�N���[���ݒ�
	SetTransColor(255, 0, 255);										// ���ߐF�ݒ�

	//�V�[��
	CSceneManager cSceneManager;
	CInput cInput;

	//������
	cInput.Init();
	cSceneManager.Init();
	CFPS::Init();

	// �Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		Sleep(1);

		// �G�X�P�[�v�L�[�ŏI��
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
		//�e�o�r���K��̎��ԂɒB���ĂȂ�
		if (!CFPS::CheckNext()) continue;

		ClearDrawScreen();		// �摜�N���A

		//fps�v�Z����
		CFPS::Step();
		//���[�v����
		cSceneManager.Loop();
		//���̓X�e�b�v
		cInput.Update();
		//�`��
		cSceneManager.Draw();

		////FPS�`��
		//CFPS::DrawFps();

		ScreenFlip();			
	}
	cSceneManager.Exit();

	DxLib_End();			
	return 0;				
}




