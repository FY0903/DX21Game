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
			// ブロックがnull(0)ならdeteleしない
			if (!m_pBlocks[j][i]) continue;
			// ブロックがあるので削除
			delete m_pBlocks[j][i];
		}
	}
}

void Field::Update()
{
	// フィールドの処理状況に関わらず、
	// ブロックは常に更新
	for (int j = 0; j < FIELD_ROW; j++)
	{
		for (int i = 0; i < FIELD_COLUMN; i++)
		{
			if (!m_pBlocks[j][i]) continue;
			m_pBlocks[j][i]->Update();
		}
	}

	// ブロックの更新後、フィールドの処理を行う
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
	// フィールドの処理状況に関わらず、
	// ブロックは常に描画
	for (int j = 0; j < FIELD_ROW; j++)
	{
		for (int i = 0; i < FIELD_COLUMN; i++)
		{
			if (!m_pBlocks[j][i]) continue;
			m_pBlocks[j][i]->Draw();
		}
	}
}

// 生成時の処理
void Field::UpdateCreate()
{
	// ブロックの生成位置
	int x = FIELD_COLUMN / 2;	// 真ん中から生成
	int y = 0;	// 一番上から生成

	// ブロックの生成
	m_pBlocks[y][x] = new Block();

	// ブロックを画面のどこに出すか
	// ブロックの状態を変えて

	// 生成後、落下を待つ
	m_step = WAIT;
}

// 落下待ちのときの処理
void Field::UpdateWait()
{
}

// 削除確認の処理
void Field::UpdateCheck()
{
}

// 削除の処理
void Field::UpdateErase()
{
}

// ゲーム終了の処理
void Field::UpdateEnd()
{
}
