#include <dxlib.h>

class CPlayCamera {
private:
	VECTOR m_vPos;			//���_
	VECTOR m_vForcus;		//�����_
	VECTOR m_vUp;			//�����
	VECTOR SubVector;		//�J�������G�Ɍ������x�N�g��
	float m_iCameraLen;		//�J��������

public:
	CPlayCamera();
	~CPlayCamera();

	void Init();
	void Loop(VECTOR vForcus, float fRot);
	void Update();



};



