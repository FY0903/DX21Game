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

	// �t�B�[���h���̔z��
	struct Index
	{
		int x;
		int y;
	};

	// �u���b�N�p�̔z��ʒu
	struct Corner
	{
		Index lt;	// ����
		Index rt;	// �E��
		Index lb;	// ����
		Index rb;	// �E��
	};
public:
	Field();
	~Field();
	void Update();
	void Draw();

private:
	// step�ʍX�V�֐�
	void UpdateCreate();
	void UpdateWait();
	void UpdateCheck();
	void UpdateErase();
	void UpdateEnd();

	// �z��ԍ������ʏ�̈ʒu���v�Z����֐�
	void SetGridPos(int x, int y, Block* pBlock);

	// ��ʏ�̍��W����z��̈ʒu���擾����֐�
	Corner GetGridIndex(Block* pBlock);
private:
	// �t�B�[���h���̃u���b�N�̏��
	Block* m_pBlocks[FIELD_ROW][FIELD_COLUMN];
	// �t�B�[���h�̏�����
	Step m_step;
};
