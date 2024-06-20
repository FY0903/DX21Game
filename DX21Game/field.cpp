#include "field.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"

CField::CField()
{
	m_nAnimeNo = 0;	// 現在のUV配列の番号
	m_fAnimeU = 0.0f;		// 現在のU値
	m_fAnimeV = 0.0f;		// 現在のV値
	m_uv = {
		{0.5f, 1.0f, 0.0f, 0.0f},
		{0.5f, 1.0f, 0.5f, 0.0f},
	};

	// 頂点バッファの作成
	m_vtx = {
		{{-1280.0f, -720.0f, 0.0f}, {0.0f, 0.0f}},
		{{-1280.0f, 720.0 , 0.0f}, {0.0f, 1.0f}},
		{{1280.0f, -720.0f, 0.0f}, {1.0f, 0.0f}},
		{{1280.0f, 720.0f, 0.0f}, {1.0f, 1.0f}} };

	m_pVtxBuf = CreateVertexBuffer(m_vtx.data(), 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/Bg4.bmp", &m_pTex)))
	{
		MessageBox(nullptr, "テクスチャー読み込み失敗", "エラー", S_OK);
	}
}

CField::~CField()
{
	if(m_pVtxBuf) m_pVtxBuf->Release();
	if(m_pTex) m_pTex->Release();
}

void CField::Update()
{
	m_nAnimeNo++;
	if (m_nAnimeNo > m_uv.size() - 1)
	{
		m_nAnimeNo = 0;
	}
	m_fAnimeU = m_uv[m_nAnimeNo][2];
	m_fAnimeV = m_uv[m_nAnimeNo][3];
}

void CField::Draw()
{
	SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
	SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}
