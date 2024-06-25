#include "robo.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "Game.h"

CRobo::CRobo()
{
	m_fAnimeU = 0.0f;		// 現在のU値
	m_fAnimeV = 0.0f;		// 現在のV値
	m_nAnimeNo = 0;			// 現在のUV配列の番号
	m_uv = {
		{1.0f, 1.0f, 0.0f, 0.0f},
	};

	// 頂点バッファの作成
	m_vtx = {
		{{-180.0f, -180.0f, 0.0f}, {0.0f, 0.0f}},
		{{-180.0f, 180.0f, 0.0f}, {0.0f, 1.0f}},
		{{180.0f, -180.0f, 0.0f}, {1.0f, 0.0f}},
		{{180.0f, 180.0f, 0.0f}, {1.0f, 1.0f}}
	};

	m_pVtxBuf = CreateVertexBuffer(m_vtx.data(), 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/roboks.png", &m_pTex)))
	{
		MessageBox(nullptr, "テクスチャー読み込み失敗", "エラー", S_OK);
	}
}

CRobo::~CRobo()
{
}

void CRobo::Update()
{
	m_fSize += 0.01f;
	if (m_fSize > 1.0f) m_fSize = 1.0f;
	m_nFrame++;
	m_fRad = m_nFrame * (360.0f / 100.0f) * PI / 180.0f;
	if (m_fRad >= PI * 2) m_fRad = PI * 2;
}

void CRobo::Draw()
{
	SetSpriteAngle(m_fRad);
	SetSpriteScale(m_fSize, m_fSize);
	SetSpritePos(1000.0f, 400.0f);
	SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
	SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}