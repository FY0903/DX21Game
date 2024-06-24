#include "missile.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"

CMissile::CMissile()
{
	m_nAnimeNo = 0;			// 現在のUV配列の番号
	m_fAnimeU = 0.0f;		// 現在のU値
	m_fAnimeV = 0.0f;		// 現在のV値
	m_uv = {
		{0.33f, 1.0f, 0.0f, 0.0f},
		{0.33f, 1.0f, 0.33f, 0.0f},
		{0.33f, 1.0f, 0.66f, 0.0f},
	};

	// 頂点バッファの作成
	m_vtx = {
		{{-1280.0f, -720.0f, 0.0f}, {0.0f, 0.0f}},
		{{-1280.0f, 720.0 , 0.0f}, {0.0f, 1.0f}},
		{{1280.0f, -720.0f, 0.0f}, {1.0f, 0.0f}},
		{{1280.0f, 720.0f, 0.0f}, {1.0f, 1.0f}} };

	m_pVtxBuf = CreateVertexBuffer(m_vtx.data(), 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/missilemove.png", &m_pTex)))
	{
		MessageBox(nullptr, "テクスチャー読み込み失敗", "エラー", S_OK);
	}
}

CMissile::~CMissile()
{
	if (m_pVtxBuf) m_pVtxBuf->Release();
	if (m_pTex) m_pTex->Release();
}

void CMissile::Update()
{
	m_fAnimeU = m_uv[m_nAnimeNo][2];
	m_fAnimeV = m_uv[m_nAnimeNo][3];
	m_nAnimeNo++;
	if (m_nAnimeNo > m_uv.size() - 1)
	{
		m_nAnimeNo = 0;
	}
}

void CMissile::Draw()
{
	SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
	SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}

void CMissile::InitAnimeNo()
{
	m_nAnimeNo = 0;
}

int CMissile::GetAnimeNo()
{
	return m_nAnimeNo;
}

void CMissile::SetAnimeNo(int nAnimeNo)
{
	m_nAnimeNo = nAnimeNo;
}

int CMissile::GetAnime()
{
	return m_uv.size();
}
