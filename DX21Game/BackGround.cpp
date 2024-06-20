#include "BackGround.h"
#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"

CBackGround::CBackGround() : m_pTex(nullptr), m_pVtx(nullptr), m_offsetU(0.0f)
{
	Vertex vtx[] = {
		{{-1280.0f, -720.0f, 0.0f}, {0.0f, 0.0f}},
		{{-1280.0f, 720.0 , 0.0f}, {0.0f, 1.0f}},
		{{1280.0f, -720.0f, 0.0f}, {1.0f, 0.0f}},
		{{1280.0f, 720.0f, 0.0f}, {1.0f, 1.0f}} };
	m_pVtx = CreateVertexBuffer(vtx, 4);
	HRESULT hr = LoadTextureFromFile(GetDevice(), "texture/Bg3.png", &m_pTex);
	if (FAILED(hr)) 
	{
		MessageBox(nullptr, "テクスチャー読み込み失敗", "エラー", S_OK);
	}
}

CBackGround::~CBackGround()
{
	if (m_pVtx) m_pVtx->Release();
	if (m_pTex) m_pTex->Release();
}

void CBackGround::Update()
{
	m_offsetU += 0.001f;
}

void CBackGround::Draw()
{
	SetSpriteUVScale(1.0f, 1.0f);
	SetSpriteUVPos(m_offsetU, 0.0f);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtx, sizeof(Vertex));
}