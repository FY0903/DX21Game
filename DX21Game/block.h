#ifndef ___BLOCK_H___
#define ___BLOCK_H___

#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"

// �萔
#define BLOCK_SIZE (40.0f)	// �u���b�N�̃T�C�Y

class Block
{
public:
	// �u���b�N�̏�Ԃ�\���񋓌^
	enum State {
		IDLE,	// �Î~���
		MOVE,	// �ړ����
		FALL,	// �������
	};

public:
	Block();
	~Block();

	void Update();
	void Draw();

private:
	// �N���X���ł������p���Ȃ��֐�
	void UpdateIdle();
	void UpdateMove();
	void UpdateFall();

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