/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "VertexBuffer.h"

//=== グローバル宣言 ===
ID3D11Buffer* g_pVtxBuf;

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
		{{-100.0f, -100.0f, 0.0f}, {0.0f, 0.0f}}, 
		{{-100.0f, 100.0f, 0.0f}, {0.0f, 1.0f}}, 
		{{100.0f, -100.0f, 0.0f}, {1.0f, 0.0f}}, 
		{{100.0f, 100.0f, 0.0f}, {1.0f, 1.0f}} };
	g_pVtxBuf = CreateVertexBuffer(vtx, 4);

	return true;
}

void UninitGame()
{
	UninitSpriteDrawer();
	UninitDirectX();
}

void UpdateGame()
{

}

void DrawGame()
{
	BeginDrawDirectX();
	DrawSprite(g_pVtxBuf, sizeof(Vertex));
	EndDrawDirectX();
}