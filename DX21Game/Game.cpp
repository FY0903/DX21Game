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
#include "object.h"

//=== グローバル宣言 ===
int g_frame = 0;		// フレームカウンタ
int g_animeFrame = 0;	// アニメーション切り替えフレーム

CBackGround* g_pCBackGround;
CField* g_pCField;
CMissile* g_pCMissile;
CExplotion* g_pCExplotion;
CObject* g_pCObject;

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

	g_pCBackGround = new CBackGround();
	g_pCField = new CField();
	g_pCMissile = new CMissile();
	g_pCExplotion = new CExplotion();
	g_pCObject = new CObject();

	return true;
}

void UninitGame()
{
	delete(g_pCBackGround);
	delete(g_pCField);
	delete(g_pCMissile);
	delete(g_pCExplotion);
	delete(g_pCObject);
	UninitSpriteDrawer();
	UninitDirectX();
}

void UpdateGame()
{
	g_pCBackGround->Update();
	
	g_frame++;
	
	g_pCObject->Update();

	if (!(g_animeFrame % 7))
	{
		if (g_frame > 490)
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

	if (g_frame > 630)
	{
		g_pCExplotion->InitAnimeNo();
		g_frame = 0;
		g_animeFrame = 0;
	}
}

void DrawGame()
{
	BeginDrawDirectX();

	g_pCField->Draw();

	g_pCObject->Draw();


	if (g_frame > 300 && g_frame < 480)
	{
		g_pCMissile->Draw();
	}
	
	if (g_frame > 480)
	{
		g_pCExplotion->Draw();
	}
	else
	{
		g_pCBackGround->Draw();
	}
	
	EndDrawDirectX();
}