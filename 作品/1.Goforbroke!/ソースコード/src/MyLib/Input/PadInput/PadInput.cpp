#include <DxLib.h>
#include "PadInput.h"

int CPadInput::PadInput = 0;

//������
void CPadInput::InitInput()
{
	//�R���g���[���[���w��
	CPadInput::PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}

//�X�e�b�v
void CPadInput::StepInput()
{

}

//������Ă��邩
bool CPadInput::IsPadDown(int code)
{
	if ((GetJoypadInputState(DX_INPUT_PAD1) & code) == 0)
	{
		return true;
	}

	return false;
}




