#pragma once

#include "Block.h"

// �萔
#define FIELD_COLUMN (7)	// ���̐��i�񐔁j
#define FIELD_ROW (11)		// �c�̐��i�s���j

class Field
{
public:
	// ���s���鏈���̎��
	enum Step
	{
		CREATE,	// �u���b�N�̐���
		WAIT,	// �u���b�N�̗����҂�
		CHECK,	// �u���b�N�̏����邩����
		ERASE,	// �u���b�N�̏���
		END,	// �Q�[���I�[�o�[
	};

public:
	Field();
	~Field();
	void Update();
	void Draw();

private:
	void UpdateCreate();
	void UpdateWait();
	void UpdateCheck();
	void UpdateErase();
	void UpdateEnd();

private:
	// �t�B�[���h���̃u���b�N�̏��
	Block* m_pBlocks[FIELD_ROW][FIELD_COLUMN];
	// �t�B�[���h�̏�����
	Step m_step;
};
