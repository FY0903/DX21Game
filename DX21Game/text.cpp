#include "text.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"

CText::CText()
{
	m_nAnimeNo = 0;			// 現在のUV配列の番号
	m_fAnimeU = 0.0f;		// 現在のU値
	m_fAnimeV = 0.0f;		// 現在のV値
	m_fPosX = 0.0f;
	m_fPosY = 2000.0f;
	m_uv = {
		{1.0f, 1.0f, 0.0f, 0.0f},
	};

	// 頂点バッファの作成
	m_vtx = {
		{{-680.0f, -1000.0f, 0.0f}, {0.0f, 0.0f}},
		{{-680.0f, -500.0f, 0.0f}, {0.0f, 1.0f}},
		{{680.0f, -1000.0f, 0.0f}, {1.0f, 0.0f}},
		{{680.0f, -500.0f, 0.0f}, {1.0f, 1.0f}} };

	m_pVtxBuf = CreateVertexBuffer(m_vtx.data(), 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/text.png", &m_pTex)))
	{
		MessageBox(nullptr, "テクスチャー読み込み失敗", "エラー", S_OK);
	}
}

CText::~CText()
{
	if (m_pVtxBuf) m_pVtxBuf->Release();
	if (m_pTex) m_pTex->Release();
}

void CText::Update()
{
	if (m_fPosY > 350.0f) m_fPosY -= 8.0f;
}

void CText::Draw()
{
	SetSpriteAngle(0.0f);
	SetSpritePos(m_fPosX, m_fPosY);
	SetSpriteScale(1.0f, 1.0f);
	SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
	SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}
