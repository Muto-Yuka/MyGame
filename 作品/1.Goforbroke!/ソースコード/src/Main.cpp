#include <DxLib.h>
#include <crtdbg.h>
#include "Scene/SceneManager.h"
#include "MyLib/FPS/FPS.h"
#include "MyLib/Input/Input.h"

int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// �c�w���C�u���������������E�ݒ�
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// ���������[�N�`�F�b�N�p
	ChangeWindowMode(TRUE);											// �E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);									// �E�B���h�E�T�C�Y
	SetMainWindowText("Goforbroke!!");								// �N�����ɕ\������镶��
	if (DxLib_Init() == -1) return -1;								// Dxlib�������֐�
	SetDrawScreen(DX_SCREEN_BACK);									// �X�N���[���ݒ�
	SetTransColor(255, 0, 255);										// ���ߐF�ݒ�

	//�t�H���g�ǂݍ��� 
	AddFontResourceEx("data/font/Font.TTF", FR_PRIVATE, NULL);

	//�V�[��
	CSceneManager cSceneManager;
	CInput cInput;

	//���͏�����
	cInput.Init();
	cSceneManager.Init();
	CFPS::Init();
	
	// �Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		Sleep(1);
		
		// �G�X�P�[�v�L�[�������ꂽ��I��
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

		//FPS�`��
		//CMyFPS::DrawFps();


		ScreenFlip();			// �t���b�v�֐�
		
	}
	
	cSceneManager.Exit();
	RemoveFontResourceEx("data/font/Font.TTF", FR_PRIVATE, NULL);

	DxLib_End();			
	return 0;				
}


