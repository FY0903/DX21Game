#ifndef ___BLOCK_H___
#define ___BLOCK_H___

#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"

class Block
{
public:
	// �u���b�N�̏�Ԃ�\���񋓌^
	enum State {
		IDOLE,	// �Î~���
		MOVE,	// �ړ����
		FALL,	// �������
	};

public:
	Block();
	~Block();

	void Update();
	void Draw();

private:
	// ��ʂ֕\������̂ɕK�v�ȃf�[�^
	ID3D11Buffer* m_pVtxBuf;	// ���_�o�b�t�@
	ID3D11ShaderResourceView* m_pTex;	// �e�N�X�`��
	
	// ��ʂ̕\���ʒu
	float m_posX;
	float m_posY;

	// �u���b�N�̏��
	int m_type;	// �u���b�N�̎��
	State m_state;	// �u���b�N�̏��

	// �u���b�N�̈ړ��ɕK�v�ȕϐ�
	int m_moveFrame;	// �e�g���X�̗����p
	float m_moveY;	// �Ղ�Ղ�̗����p
};

#endif