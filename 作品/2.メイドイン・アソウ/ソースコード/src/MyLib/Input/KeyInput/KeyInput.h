#pragma once

class CKeyInput
{
public:
	static void InitInput();				//���͐��䏉����
	static void StepInput();				//���͐���X�e�b�v

	static bool IsKeyPush(int key_code);	//�������ꂽ
	static bool IsKeyKeep(int key_code);	//�����������Ă��邩
	static bool IsKeyRelese(int key_code);	//�������������ꂽ��
	static bool IsKeyDown(int key_code);	//�P���ɉ�����Ă��邩

};



