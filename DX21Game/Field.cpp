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

	// 画面上の位置を設定
	SetGridPos(x, y, m_pBlocks[y][x]);

	// ブロックの状態の変更
	m_pBlocks[y][x]->ChangeState(Block::MOVE);

	// 生成後、落下を待つ
	m_step = WAIT;
}

// 落下待ちのときの処理
void Field::UpdateWait()
{
	// 移動後のブロックの配列位置を計算
	for (int j = 0; j < FIELD_ROW; j++)
	{
		for (int i = 0; i < FIELD_COLUMN; i++)
		{
			if (!m_pBlocks[j][i]) continue;


		}
	}
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

// 配列番号から画面上の位置を計算する関数
void Field::SetGridPos(int x, int y, Block* pBlock)
{
	// ステージ左上の配列位置を計算
	float halfsize = BLOCK_SIZE * 0.5f;
	float posX = -(FIELD_COLUMN - 1) * halfsize;
	float posY = -(FIELD_ROW - 1) * halfsize;

	// 配列番号に応じて左上から移動
	posX += x * BLOCK_SIZE;
	posY += y * BLOCK_SIZE;

	// ブロックの位置を更新
	pBlock->SetPos(posX, posY);
}

// 画面上の座標から配列の位置を取得する関数
Field::Corner Field::GetGridIndex(Block* pBlock)
{
	// 左上の座標が0,0となるように全体を移動
	float halfsize = BLOCK_SIZE * 0.5f;
	float posX = -(FIELD_COLUMN - 1) * halfsize;
	float posY = -(FIELD_ROW - 1) * halfsize;

	// ブロックの座標に、左上の座標がとなるような値を足す

}
