#include "text.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"

CText::CText()
{
	m_nAnimeNo = 0;			// 現在のUV配列の番号
	m_fAnimeU = 0.0f;		// 現在のU値
	m_fAnimeV = 0.0f;		// 現在のV値
	m_uv = {
		{1.0f, 1.0f, 0.0f, 0.0f},
	};

	// 頂点バッファの作成
	m_vtx = {
		{{-680.0f, -260.0f, 0.0f}, {0.0f, 0.0f}},
		{{-680.0f, 480.0 , 0.0f}, {0.0f, 1.0f}},
		{{680.0f, -260.0f, 0.0f}, {1.0f, 0.0f}},
		{{680.0f, 480.0f, 0.0f}, {1.0f, 1.0f}} };

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
}

void CText::Draw()
{
	SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
	SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}
