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

	// フィールド内の配列
	struct Index
	{
		int x;
		int y;
	};

	// ブロック角の配列位置
	struct Corner
	{
		Index lt;	// 左上
		Index rt;	// 右上
		Index lb;	// 左下
		Index rb;	// 右下
	};
public:
	Field();
	~Field();
	void Update();
	void Draw();

private:
	// step別更新関数
	void UpdateCreate();
	void UpdateWait();
	void UpdateCheck();
	void UpdateErase();
	void UpdateEnd();

	// 配列番号から画面上の位置を計算する関数
	void SetGridPos(int x, int y, Block* pBlock);

	// 画面上の座標から配列の位置を取得する関数
	Corner GetGridIndex(Block* pBlock);
private:
	// フィールド内のブロックの情報
	Block* m_pBlocks[FIELD_ROW][FIELD_COLUMN];
	// フィールドの処理状況
	Step m_step;
};
