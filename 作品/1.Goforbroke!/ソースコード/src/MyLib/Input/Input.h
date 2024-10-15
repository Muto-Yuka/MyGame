#pragma once
#include <vector>
#include "PadInput/PadInput.h"

class CInput 
{
	static std::vector<int> m_vKeyButton;
	static std::vector<int> m_vController;

public:
	enum {
		INPUT_LEFT,		//���ړ�
		INPUT_RIGHT,	//�E�ړ�
		INPUT_UP,		//�O�ړ�
		INPUT_DOWN,		//���ړ�
		INPUT_DASH,		//����
		INPUT_TAKE,		//���̂��Ƃ�		
		INPUT_ZOOM,		//�Y�[��
		INPUT_SHOT,		//�e������
		INPUT_REPAIR,	//�C������

		INPUT_NEXT,		//Enter����{�^��
		INPUT_END,		//Esc�Q�[���I��
	};

	static void Init();		//������
	static void Update();	//�X�V

	static bool IsInputPush(int key);	//�������ꂽ 
	static bool IsInputKeep(int key);	//�����������Ă��邩�@
	static bool IsInputRelese(int key);	//�������������ꂽ���@
	static bool IsInputDown(int key);	//�P���ɉ�����Ă��邩

};



