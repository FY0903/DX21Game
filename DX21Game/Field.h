#pragma once

#include "Block.h"

// 定数
#define FIELD_COLUMN (7)	// 横の数（列数）
#define FIELD_ROW (11)		// 縦の数（行数）

class Field
{
public:
	// 実行する処理の種類
	enum Step
	{
		CREATE,	// ブロックの生成
		WAIT,	// ブロックの落下待ち
		CHECK,	// ブロックの消えるか判定
		ERASE,	// ブロックの消去
		END,	// ゲームオーバー
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
	// フィールド内のブロックの情報
	Block* m_pBlocks[FIELD_ROW][FIELD_COLUMN];
	// フィールドの処理状況
	Step m_step;
};
