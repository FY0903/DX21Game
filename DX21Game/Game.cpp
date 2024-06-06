/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "BackGround.h"

//=== グローバル宣言 ===
ID3D11Buffer* g_pVtxBuf;
ID3D11ShaderResourceView* g_pTex;

int g_animeFrame = 0;	// アニメーション切り替えフレーム
int g_animeNo = 0;		// 現在のUV配列の番号
float g_animeU = 0.0f;	// 現在のU値
float g_animeV = 0.0f;	// 現在のV値
float g_uv[][4] = {
	{0.3333f, 0.1f, 0.33f, 0.0f},
	{0.3333f, 0.1f, 0.67f, 0.0f},
	{0.3333f, 0.1f, 1.0f, 0.0f},
	{0.3333f, 0.1f, 0.33f, 0.1f},
	{0.3333f, 0.1f, 0.67f, 0.1f},
	{0.3333f, 0.1f, 1.0f, 0.1f},
	{0.3333f, 0.1f, 0.33f,0.2f},
	{0.3333f, 0.1f, 0.67f,0.2f},
	{0.3333f, 0.1f, 1.0f, 0.2f},
	{0.3333f, 0.1f, 0.33f,0.3f},
	{0.3333f, 0.1f, 0.67f,0.3f},
	{0.3333f, 0.1f, 1.0f, 0.3f},
	{0.3333f, 0.1f, 0.33f,0.4f},
	{0.3333f, 0.1f, 0.67f,0.4f},
	{0.3333f, 0.1f, 1.0f, 0.4f},
	{0.3333f, 0.1f, 0.33f,0.5f},
	{0.3333f, 0.1f, 0.67f,0.5f},
	{0.3333f, 0.1f, 1.0f, 0.5f},
	{0.3333f, 0.1f, 0.33f,0.6f},
	{0.3333f, 0.1f, 0.67f,0.6f},
	{0.3333f, 0.1f, 1.0f, 0.6f},
	{0.3333f, 0.1f, 0.33f,0.7f},
	{0.3333f, 0.1f, 0.67f,0.7f},
	{0.3333f, 0.1f, 1.0f, 0.7f},
	{0.3333f, 0.1f, 0.33f,0.8f},
	{0.3333f, 0.1f, 0.67f,0.8f},
	{0.3333f, 0.1f, 1.0f, 0.8f},
	{0.3333f, 0.1f, 0.33f,0.9f},
	{0.3333f, 0.1f, 0.67f,0.9f},
	{0.3333f, 0.1f, 1.0f, 0.9f},
};
BackGround* g_pBG;

bool InitGame(HWND hWnd)
{
	// HRESULT型が失敗しているかは
	// FAILEDマクロで判定する
	if (FAILED(InitDirectX(hWnd, 1280, 720)))
	{
		MessageBox(hWnd, "DirectX初期化失敗", "エラー", S_OK);
		return false;
	}

	// スプライト描画サポートの初期化
	InitSpriteDrawer(GetDevice(), GetContext(), 1280, 720);

	// 頂点バッファの作成
	Vertex vtx[] = { 
		{{-400.0f, -400.0f, 0.0f}, {0.0f, 0.0f}},
		{{-400.0f, 400.0f , 0.0f}, {0.0f, 1.0f}},
		{{400.0f, -400.0f, 0.0f}, {1.0f, 0.0f}},
		{{400.0f, 400.0f, 0.0f}, {1.0f, 1.0f}} };
	g_pVtxBuf = CreateVertexBuffer(vtx, 4);

	if (FAILED(LoadTextureFromFile(GetDevice(), "pipo-btleffect141.png", &g_pTex)))
	{
		MessageBox(hWnd, "テクスチャー読み込み失敗", "エラー", S_OK);
		return false;
	}

	g_pBG = new BackGround();

	return true;
}

void UninitGame()
{
	delete(g_pBG);
	UninitSpriteDrawer();
	UninitDirectX();
}

void UpdateGame()
{
	g_pBG->Update();

	if (g_animeFrame >= 11)
	{
		g_animeNo++;
		if (g_animeNo > 30)
		{
			g_animeNo = 0;
		}
		g_animeU = g_uv[g_animeNo][2];
		g_animeV = g_uv[g_animeNo][3];
		g_animeFrame = 0;
	}
	else
	{
		g_animeFrame++;
	}
}

void DrawGame()
{
	BeginDrawDirectX();

	g_pBG->Draw();

	SetSpriteUVScale(g_uv[g_animeNo][0], g_uv[g_animeNo][1]);
	SetSpriteUVPos(g_animeU, g_animeV);
	SetSpriteTexture(g_pTex);
	DrawSprite(g_pVtxBuf, sizeof(Vertex));
	
	EndDrawDirectX();
}