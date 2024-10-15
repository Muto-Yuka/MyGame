#pragma once

class CFade {
public:
	enum FadeState{
		FADE_NON,	//�����Ȃ�
		FADE_IN,	//���X�ɕ\��
		FADE_OUT,	//���X�ɏ�����
	};

private:
	static CFade* m_instance;		//�V���O���g���ɕK�v�ȃC���X�^���X

	int		m_windowX, m_windowY;	//�E�B���h�E�̃T�C�Y
	float	m_cnt;					//�t�F�[�h���ɕK�v�ȃA���t�@�l
	float	m_speed;				//�t�F�[�h�̎���
	FadeState m_state;				//���݂̃t�F�[�h�̏��

public:
	static CFade* GetInstance();		//�C���X�^���X�擾
	static void Alloc();				//�N���X�𐶐����ă������m��
	static void DeleteInstance();		//�s�v�ɂȂ�����j��

private:
	CFade(){}
	~CFade(){}

	//�R�s�[�R���X�g���N�^�E����𕕈�(�O������A�N�Z�X�ł��Ȃ��悤)
	CFade(const CFade& other) {}
	CFade& operator=(const CFade& other){}

public:
	//�t�F�[�h�������I�ɏ���
	void Reset() { m_state = FADE_NON; }
	//(�t�F�[�h�̑���(1�`255)�Atrue�t�F�[�h�C��false�t�F�[�h�A�E�g)
	void Request(float speed, bool isFadeIn);
	//�X�V����
	void UpDate();
	//�`�揈��
	void Draw();
	//�I������
	bool IsEnd();
	//���݂̃t�F�[�h��Ԃ��擾
	FadeState GetState() { return m_state; }
	//�E�B���h�E�T�C�Y�ύX
	void SetWindowSize(int x, int y) { m_windowX = x; m_windowY = y; }

};



