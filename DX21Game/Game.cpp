/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "BackGround.h"
#include "field.h"
#include "missile.h"
#include "explotion.h"

//=== グローバル宣言 ===
int g_frame = 0;		// フレームカウンタ
int g_animeFrame = 0;	// アニメーション切り替えフレーム

CBackGround* g_pCBackGround;
CField* g_pCField;
CMissile* g_pCMissile;
CExplotion* g_pCExplotion;

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

	//Vertex Obj[] = {
	//	{{-556.8f, -301.2f, 0.0f}, {0.0f, 0.0f}},
	//	{{-556.8f, 601.2, 0.0f}, {0.0f, 1.0f}},
	//	{{556.8f, -301.2f, 0.0f}, {1.0f, 0.0f}},
	//	{{556.8f, 601.2f, 0.0f}, {1.0f, 1.0f}} };
	//g_pVtxBufObj = CreateVertexBuffer(Obj, 4);
	//if (FAILED(LoadTextureFromFile(GetDevice(), "texture/niconico.png", &g_pTexObj)))
	//{
	//	MessageBox(hWnd, "テクスチャー読み込み失敗", "エラー", S_OK);
	//	return false;
	//}

	g_pCBackGround = new CBackGround();
	g_pCField = new CField();
	g_pCMissile = new CMissile();
	g_pCExplotion = new CExplotion();

	return true;
}

void UninitGame()
{
	delete(g_pCBackGround);
	delete(g_pCField);
	delete(g_pCMissile);
	delete(g_pCExplotion);
	UninitSpriteDrawer();
	UninitDirectX();
}

void UpdateGame()
{
	g_pCBackGround->Update();
	
	g_frame++;
	

	if (!(g_animeFrame % 5))
	{
		if (g_frame > 480)
		{
			g_pCExplotion->Update();
		}
	}
	
	if (g_animeFrame >= 60)
	{
		g_pCField->Update();
		if (g_frame > 360 && g_frame < 520)
		{
			g_pCMissile->Update();
		}
		g_animeFrame = 0;
	}
	else
	{
		g_animeFrame++;
	}

	if (g_frame > 570)
	{
		g_pCExplotion->InitAnimeNo();
		g_frame = 0;
		g_animeFrame = 0;
	}
}

void DrawGame()
{
	BeginDrawDirectX();

	//SetSpriteUVScale(1.0f, 1.0f);
	//SetSpriteUVPos(0.0f, 0.0f);
	//SetSpriteTexture(g_pTexObj);
	//DrawSprite(g_pVtxBufObj, sizeof(Vertex));

	g_pCField->Draw();

	if (g_frame > 300)
	{
		g_pCMissile->Draw();
	}
	
	if (g_frame > 475)
	{
		g_pCExplotion->Draw();
	}
	else
	{
		g_pCBackGround->Draw();
	}
	
	EndDrawDirectX();
}