#include "Field.h"

Field::Field() : m_pBlocks{}, m_step(CREATE)
{
}

Field::~Field()
{
	for (int j = 0; j < FIELD_ROW; j++)
	{
		for (int i = 0; i < FIELD_COLUMN; i ++)
		{
			// �u���b�N��null(0)�Ȃ�detele���Ȃ�
			if (!m_pBlocks[j][i]) continue;
			// �u���b�N������̂ō폜
			delete m_pBlocks[j][i];
		}
	}
}

void Field::Update()
{
	// �t�B�[���h�̏����󋵂Ɋւ�炸�A
	// �u���b�N�͏�ɍX�V
	for (int j = 0; j < FIELD_ROW; j++)
	{
		for (int i = 0; i < FIELD_COLUMN; i++)
		{
			if (!m_pBlocks[j][i]) continue;
			m_pBlocks[j][i]->Update();
		}
	}

	// �u���b�N�̍X�V��A�t�B�[���h�̏������s��
	switch (m_step)
	{
	default:
	case END: UpdateEnd(); break;
	case CREATE: UpdateCreate(); break;
	case WAIT: UpdateWait(); break;
	case CHECK: UpdateCheck(); break;
	case ERASE: UpdateEnd(); break;
	}
}

void Field::Draw()
{
	// �t�B�[���h�̏����󋵂Ɋւ�炸�A
	// �u���b�N�͏�ɕ`��
	for (int j = 0; j < FIELD_ROW; j++)
	{
		for (int i = 0; i < FIELD_COLUMN; i++)
		{
			if (!m_pBlocks[j][i]) continue;
			m_pBlocks[j][i]->Draw();
		}
	}
}

// �������̏���
void Field::UpdateCreate()
{
	// �u���b�N�̐����ʒu
	int x = FIELD_COLUMN / 2;	// �^�񒆂��琶��
	int y = 0;	// ��ԏォ�琶��

	// �u���b�N�̐���
	m_pBlocks[y][x] = new Block();

	// �u���b�N����ʂ̂ǂ��ɏo����
	// �u���b�N�̏�Ԃ�ς���

	// ������A������҂�
	m_step = WAIT;
}

// �����҂��̂Ƃ��̏���
void Field::UpdateWait()
{
}

// �폜�m�F�̏���
void Field::UpdateCheck()
{
}

// �폜�̏���
void Field::UpdateErase()
{
}

// �Q�[���I���̏���
void Field::UpdateEnd()
{
}
