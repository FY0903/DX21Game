#include "Block.h"
#include "SpriteDrawer.h"

Block::Block() : m_pVtxBuf(nullptr), m_pTex(nullptr), m_posX(0.0f), m_posY(0.0f), m_type(0), m_state(MOVE), m_moveFrame(0), m_moveY(0.0f)
{
	// ���_�o�b�t�@�̐���
	Vertex vtx[] = {
		{{-50.0f, -50.0f, 0.0f}, {0.0f, 0.0f}},
		{{-50.0f, 50.0f, 0.0f}, {0.0f, 1.0f}},
		{{50.0f, -50.0f, 0.0f}, {1.0f, 0.0f}},
		{{50.0f, 50.0f, 0.0f}, {1.0f, 1.0f}},
	};
	m_pVtxBuf = CreateVertexBuffer(vtx, 4);

	// �e�N�X�`���̓ǂݍ���
	HRESULT hr = LoadTextureFromFile(GetDevice(), "p.png", &m_pTex);
	if (FAILED(hr))
	{
		MessageBox(NULL, "�e�N�X�`���ǂݍ��ݎ��s", "block.cpp", MB_OK);
	}
}

Block::~Block()
{
	// �e�N�X�`���̊J��
	m_pVtxBuf->Release();

	// ���_�o�b�t�@�̊J��
	m_pTex->Release();
}

void Block::Update()
{
	// ��Ԃɉ����ď����𕪂���
	switch (m_state)
	{
	default:
	case IDLE: UpdateIdle(); break;
	case MOVE: UpdateMove(); break;
	case FALL: UpdateFall(); break;
	}
}

void Block::Draw()
{
	// �e�N�X�`���̐ݒ�
	SetSpriteTexture(m_pTex);
	
	// UV�̐ݒ�i�������Ȃ��悤�ݒ�j
	SetSpriteUVScale(1.0f, 1.0f);
	SetSpriteUVPos(0.0f, 0.0f);
	// �X�v���C�g�̕\���ʒu��ݒ�
	SetSpritePos(m_posX, m_posY);
	//�`��
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}

// ��Ԃ̕ύX
void Block::ChangeState(State state)
{
	m_state = state;
}

// �\���ʒu�̐ݒ�
void Block::SetPos(float x, float y)
{
	m_posX = x;
	m_posY = y;
}

// ���W���擾
float Block::GetPosX()
{
	return m_posX;
}

// ���W���擾
float Block::GetPosY()
{
	return m_posY;
}

// IDLE��Ԃ̂Ƃ��̏���
void Block::UpdateIdle()
{
	// �����Ȃ��̂Ō���͏����Ȃ�
}

// MOVE��Ԃ̂Ƃ��̏���
void Block::UpdateMove()
{
	// ���Ԍo�߂̔���
	if (m_moveFrame >= 60)
	{
		// ��i���ɉ����鏈��
		m_posY += BLOCK_SIZE;
		// �v�����������߂ɏ�����
		m_moveFrame = 0;
	}

	// �t���[���̃J�E���g
	m_moveFrame++;
}

// FALL��Ԃ̂Ƃ��̏���
void Block::UpdateFall()
{
	// ���������́w�ړ����x�x�����X�ɏオ��
	m_moveY += 0.1f;
	// �オ�����ړ����x���A���W���ړ�������
	m_posY += m_moveY;
}
