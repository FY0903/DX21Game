#ifndef ___BLOCK_H___
#define ___BLOCK_H___

#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"

class Block
{
public:
	// ブロックの状態を表す列挙型
	enum State {
		IDOLE,	// 静止状態
		MOVE,	// 移動状態
		FALL,	// 落下状態
	};

public:
	Block();
	~Block();

	void Update();
	void Draw();

private:
	// 画面へ表示するのに必要なデータ
	ID3D11Buffer* m_pVtxBuf;	// 頂点バッファ
	ID3D11ShaderResourceView* m_pTex;	// テクスチャ
	
	// 画面の表示位置
	float m_posX;
	float m_posY;

	// ブロックの情報
	int m_type;	// ブロックの種類
	State m_state;	// ブロックの状態

	// ブロックの移動に必要な変数
	int m_moveFrame;	// テトリスの落下用
	float m_moveY;	// ぷよぷよの落下用
};

#endif