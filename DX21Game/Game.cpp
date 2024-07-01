/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "BackGround.h"
#include "Field.h"

//=== グローバル宣言 ===
BackGround* g_pBG;
Block* g_pBlock;
Field* g_pField;

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

	g_pBG = new BackGround();
	g_pField = new Field();

	return true;
}

void UninitGame()
{
	delete(g_pField);
	delete(g_pBG);
	UninitSpriteDrawer();
	UninitDirectX();
}

void UpdateGame()
{
	g_pBG->Update();
	g_pField->Update();
}

void DrawGame()
{
	BeginDrawDirectX();

	g_pBG->Draw();
	g_pField->Draw();
	
	EndDrawDirectX();
}