#include "BackGround.h"
#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"	

BackGround::BackGround() : m_pTex(nullptr), m_pVtx(nullptr), m_offsetU(0.0f)
{
	Vertex vtx[] = {
		{{-1280.0f, -720.0f, 0.0f}, {0.0f, 0.0f}},
		{{-1280.0f, 720.0 , 0.0f}, {0.0f, 1.0f}},
		{{1280.0f, -720.0f, 0.0f}, {1.0f, 0.0f}},
		{{1280.0f, 720.0f, 0.0f}, {1.0f, 1.0f}} };
	m_pVtx = CreateVertexBuffer(vtx, 4);
	HRESULT hr = LoadTextureFromFile(GetDevice(), "pipo-battlebg001b.jpg", &m_pTex);
	if (FAILED(hr)) 
	{
		MessageBox(nullptr, "テクスチャー読み込み失敗", "エラー", S_OK);
	}
}

BackGround::~BackGround()
{
	if (m_pVtx) m_pVtx->Release();
	if (m_pTex) m_pTex->Release();
}

void BackGround::Update()
{
	m_offsetU += 0.001f;
}

void BackGround::Draw()
{
	SetSpriteUVScale(1.0f, 1.0f);
	SetSpriteUVPos(m_offsetU, 0.0f);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtx, sizeof(Vertex));
}