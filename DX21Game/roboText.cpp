#include "roboText.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"

CRoboText::CRoboText()
{
	m_fAnimeU = 0.0f;		// 現在のU値
	m_fAnimeV = 0.0f;		// 現在のV値
	m_nAnimeNo = 0;			// 現在のUV配列の番号
	m_uv = {
		{1.0f, 1.0f, 0.0f, 0.0f},
	};

	// 頂点バッファの作成
	m_vtx = {
		{{-240.0f, -111.0f, 0.0f}, {0.0f, 0.0f}},
		{{-240.0f, 111.0f, 0.0f}, {0.0f, 1.0f}},
		{{240.0f, -111.0f, 0.0f}, {1.0f, 0.0f}},
		{{240.0f, 111.0f, 0.0f}, {1.0f, 1.0f}}
	};

	m_pVtxBuf = CreateVertexBuffer(m_vtx.data(), 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/robokstext.png", &m_pTex)))
	{
		MessageBox(nullptr, "テクスチャー読み込み失敗", "エラー", S_OK);
	}
}

CRoboText::~CRoboText()
{
	if (m_pVtxBuf) m_pVtxBuf->Release();
	if (m_pTex) m_pTex->Release();
}

void CRoboText::Update()
{

}

void CRoboText::Draw()
{
	SetSpriteAngle(0.0f);
	SetSpritePos(400.0f, 300.0f);
	SetSpriteScale(1.0f, 1.0f);
	SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
	SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}