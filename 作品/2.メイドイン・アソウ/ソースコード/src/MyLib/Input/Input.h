#pragma once
#include <vector>

class CInput 
{
	static std::vector<int> m_vKeyButton;

public:
	enum {
		INPUT_LEFT,		//���ړ� A
		INPUT_RIGHT,	//�E�ړ� D
		INPUT_UP,		//��ړ� W
		INPUT_DOWN,		//���ړ� S
		INPUT_SPACE,	//�ړ��ȊO
		INPUT_RESPAWN,	//���X�|�[��

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



