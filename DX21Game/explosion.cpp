#include "explosion.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"

CExplosion::CExplosion(bool bExplosion) : m_bExpolosionBig(bExplosion)
{
	m_nAnimeNo = 0;			// 現在のUV配列の番号
	m_fAnimeU = 0.0f;		// 現在のU値
	m_fAnimeV = 0.0f;		// 現在のV値
	m_uv = {
		{0.05f, 1.0f, 0.0f, 0.0f},
		{0.05f, 1.0f, 0.05f, 0.0f},
		{0.05f, 1.0f, 0.1f, 0.0f},
		{0.05f, 1.0f, 0.15f, 0.0f},
		{0.05f, 1.0f, 0.2f, 0.0f},
		{0.05f, 1.0f, 0.25f, 0.0f},
		{0.05f, 1.0f, 0.3f, 0.0f},
		{0.05f, 1.0f, 0.35f, 0.0f},
		{0.05f, 1.0f, 0.4f, 0.0f},
		{0.05f, 1.0f, 0.45f, 0.0f},
		{0.05f, 1.0f, 0.5f, 0.0f},
		{0.05f, 1.0f, 0.55f, 0.0f},
		{0.05f, 1.0f, 0.6f, 0.0f},
		{0.05f, 1.0f, 0.65f, 0.0f},
		{0.05f, 1.0f, 0.7f, 0.0f},
		{0.05f, 1.0f, 0.75f, 0.0f},
		{0.05f, 1.0f, 0.8f, 0.0f},
		{0.05f, 1.0f, 0.85f, 0.0f},
		{0.05f, 1.0f, 0.9f, 0.0f},
		{0.05f, 1.0f, 0.95f, 0.0f},
	};

	// 頂点バッファの作成
	m_vtx = {
		{{-680.0f, -260.0f, 0.0f}, {0.0f, 0.0f}},
		{{-680.0f, 480.0 , 0.0f}, {0.0f, 1.0f}},
		{{680.0f, -260.0f, 0.0f}, {1.0f, 0.0f}},
		{{680.0f, 480.0f, 0.0f}, {1.0f, 1.0f}} };

	m_pVtxBuf = CreateVertexBuffer(m_vtx.data(), 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/explosion.png", &m_pTex)))
	{
		MessageBox(nullptr, "テクスチャー読み込み失敗", "エラー", S_OK);
	}
}

CExplosion::~CExplosion()
{
	if (m_pVtxBuf) m_pVtxBuf->Release();
	if (m_pTex) m_pTex->Release();
}

void CExplosion::Update()
{
	m_fAnimeU = m_uv[m_nAnimeNo][2];
	m_fAnimeV = m_uv[m_nAnimeNo][3];
	m_nAnimeNo++;
	if (m_nAnimeNo > m_uv.size() - 1)
	{
		m_nAnimeNo = 0;
	}
}

void CExplosion::Draw()
{
	m_bExpolosionBig ? SetSpritePos(1000.0f, 400.0f) : SetSpritePos(0.0f, 0.0f);
	SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
	SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}