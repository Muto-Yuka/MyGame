#pragma once

//�X�e�[�W��{�N���X
//�p�������{��public�͑��₳�Ȃ�
class CGameBase {
public:
	virtual ~CGameBase() {}		//�f�X�g���N�^
	virtual void Init() = 0;	//������
	virtual void Load() = 0;	//���[�h
	virtual int Step() = 0;		//�߂�l:���̃V�[��(-1�Ȃ�ύX�Ȃ�)
	virtual void Draw() = 0;	//�`��
	virtual void Exit() = 0;	//�I��

	//���U���g����Ԃ� 0:�ҋ@�@1:�N���A�@2:�Q�[���I�[�o�[
	virtual int GetResult() = 0;	

};




