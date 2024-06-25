#include "object.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "Game.h"
#include <math.h>

CObject::CObject(bool bAnime) : m_bAnime(bAnime)
{
	m_fAnimeU = 0.0f;		// 現在のU値
	m_fAnimeV = 0.0f;		// 現在のV値
	m_nAnimeNo = 0;			// 現在のUV配列の番号
	m_uv = {
		{1.0f, 1.0f, 0.0f, 0.0f},
	};

	// 頂点バッファの作成
	m_vtx = {
		{{-556.8f, -301.2f, 0.0f}, {0.0f, 0.0f}},
		{{-556.8f, 601.2f, 0.0f}, {0.0f, 1.0f}},
		{{556.8f, -301.2f, 0.0f}, {1.0f, 0.0f}},
		{{556.8f, 601.2f, 0.0f}, {1.0f, 1.0f}} 
	};

	m_pVtxBuf = CreateVertexBuffer(m_vtx.data(), 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/niconico.png", &m_pTex)))
	{
		MessageBox(nullptr, "テクスチャー読み込み失敗", "エラー", S_OK);
	}
}

CObject::~CObject()
{
	if (m_pVtxBuf) m_pVtxBuf->Release();
	if (m_pTex) m_pTex->Release();
}

void CObject::Update()
{

}

void CObject::Draw()
{
	if (!m_bAnimeStop)
	{
		if (m_bAnime)
		{
			m_fRad = GetFrame() * (360.0f / 270.0f) * PI / 180.0f;
			SetSpriteScale(1.0f, cosf(m_fRad) * 0.5f + 0.5f);
			SetSpritePos(0.0f, 348.0f);
			if (m_fRad >= PI) m_bAnimeStop = true;
		}
		SetSpriteAngle(0.0f);
		SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
		SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
		SetSpriteTexture(m_pTex);
		DrawSprite(m_pVtxBuf, sizeof(Vertex));
	}

}

void CObject::InitAnimeNo()
{
	m_nAnimeNo = 0;
}

int CObject::GetAnimeNo()
{
	return m_nAnimeNo;
}

void CObject::SetAnimeNo(int nAnimeNo)
{
	m_nAnimeNo = nAnimeNo;
}

int CObject::GetAnime()
{
	return m_uv.size();
}
