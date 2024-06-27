#include "Block.h"
#include "SpriteDrawer.h"

Block::Block() : m_pVtxBuf(nullptr), m_pTex(nullptr), m_posX(0.0f), m_posY(0.0f), m_type(0), m_state(MOVE), m_moveFrame(0), m_moveY(0.0f)
{
	// 頂点バッファの生成
	Vertex vtx[] = {
		{{-411.0f, -299.0f, 0.0f}, {0.0f, 0.0f}},
		{{-411.0f, 299.0f, 0.0f}, {0.0f, 1.0f}},
		{{411.0f, -299.0f, 0.0f}, {1.0f, 0.0f}},
		{{411.0f, 299.0f, 0.0f}, {1.0f, 1.0f}},
	};
	m_pVtxBuf = CreateVertexBuffer(vtx, 4);

	// テクスチャの読み込み
	HRESULT hr = LoadTextureFromFile(GetDevice(), "T-mino.png", &m_pTex);
	if (FAILED(hr))
	{
		MessageBox(NULL, "テクスチャ読み込み失敗", "block.cpp", MB_OK);
	}
}

Block::~Block()
{
	// テクスチャの開放
	m_pVtxBuf->Release();

	// 頂点バッファの開放
	m_pTex->Release();
}

void Block::Update()
{
	// 状態に応じて処理を分ける
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
	// テクスチャの設定
	SetSpriteTexture(m_pTex);
	
	// UVの設定（分割しないよう設定）
	SetSpriteUVScale(1.0f, 1.0f);
	SetSpriteUVPos(0.0f, 0.0f);
	// スプライトの表示位置を設定
	SetSpritePos(m_posX, m_posY);
	//描画
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}

// IDLE状態のときの処理
void Block::UpdateIdle()
{
	// 動かないので現状は処理なし
}

// MOVE状態のときの処理
void Block::UpdateMove()
{
	// 時間経過の判定
	if (m_moveFrame >= 60)
	{
		// 一段下に下がる処理
		m_posY += BLOCK_SIZE;
		// 計測し直すために初期化
		m_moveFrame = 0;
	}

	// フレームのカウント
	m_moveFrame++;
}

// FALL状態のときの処理
void Block::UpdateFall()
{
	// 落下処理は『移動速度』が徐々に上がる
	m_moveY += 0.1f;
	// 上がった移動速度分、座標を移動させる
	m_posY += m_moveY;
}
