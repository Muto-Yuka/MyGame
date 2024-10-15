#pragma once
#include <DxLib.h>

//�p���p��ꃂ�f���A�j���[�V�����N���X
class CBaseAnim
{
protected:
	enum ANIM_STATE				//�A�j���̏��
	{
		ANIMSTATE_NORMAL,		//�ʏ�Đ�
		ANIMSTATE_LOOP,			//���[�v�Đ�
		ANIMSTATE_END,			//���̂ݍĐ�
		ANIMSTATE_NUM			//��Ԃ̐�
	};

	typedef struct {
		int		m_iAnimHndl;	//�A�j���n���h��
		int		m_iID;			//�Đ����̃A�j��ID
		int		m_iState;		//�A�j���̏��
		float	m_fEndFrm;		//�A�j���S�Đ�����
		float	m_fFrm;			//�A�j���Đ�����
		float	m_fSpd;			//�A�j���Đ����x
		bool	m_bPlay;		//�Đ������ǂ����@true:�Đ���
	}ANIM_DATA;

	ANIM_DATA m_sAnimData;		//�\���̃A�j���֘A�f�[�^

	VECTOR m_vPos;				//���f�����W
	VECTOR m_vRot;				//��]�p�x
	VECTOR m_vScale;			//�g��k����
	VECTOR m_vSpeed;			//���f�����x
	int m_iHndl;				//���f���n���h��
	float m_fRadius;			//���a
	bool m_bSurvival;			//�����t���O
	int m_HP;					//�����Ǘ�

public:
	virtual void Init();		//������
	virtual void Draw();		//�`�揈��
	virtual void Exit();		//�I������
	virtual void UpData();		//�X�V����

//���[�h�֐�
	bool LoadModel(const char* pFilePath);		//���f���ʏ탍�[�h
	bool DuplicateModel(int iModelHndl);		//���f���������[�h
	void DeleteModel();							//���f���폜

//�Q�b�^�[�E�Z�b�^�[
	inline VECTOR GetPosition() { return m_vPos; }	//���W�擾
	bool IsSurvival() { return m_bSurvival; }		//�����t���O

//�A�j���[�V�����֘A
	void UpdataAnim();
	//�A�j���h�c�A�Đ����x�A�A�j���̃��f���n���h���A�ʃ��f���̃A�j�����g���ꍇ�A�^�b�`���邩
	void Request(int iAnimID, float iAnimSpd, int iAnimSrcHndl = -1, bool NameCheck = false);
	//���[�v�A�j���@ �A�j�����Ō�܂ōĐ������ƍŏ��ɖ߂�
	void RequestLoop(int iAnimID, float iAnimSpd, int iAnimSrcHndl = -1, bool NameCheck = false);
	//�G���h���[�v�@�@�A�j�����Ō�܂ōĐ�����Ă��߂������̂܂�
	void RequestEndLoop(int iAnimID, float iAnimSpd, int iAnimSrcHndl = -1, bool NameCheck = false);

private:
	void DetachAnim();		//�A�j�����f�^�b�`
};



