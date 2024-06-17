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
ID3D11Buffer* g_pVtxBufBg;
ID3D11Buffer* g_pVtxBufObj;
ID3D11Buffer* g_pVtxBufBoom;
ID3D11Buffer* g_pVtxBufMissile;
ID3D11ShaderResourceView* g_pTexBg;
ID3D11ShaderResourceView* g_pTexObj;
ID3D11ShaderResourceView* g_pTexBoom;
ID3D11ShaderResourceView* g_pTexMissile;

int g_frame = 0;		// フレームカウンタ
int g_animeFrame = 0;	// アニメーション切り替えフレーム

int g_animeBgNo = 0;		// 現在のUV配列の番号
float g_animeBgU = 0.0f;	// 現在のU値
float g_animeBgV = 0.0f;	// 現在のV値
float g_uvbg[][4] = {
		{0.5f, 1.0f, 0.0f, 0.0f},
		{0.5f, 1.0f, 0.5f, 0.0f},
};

int g_animeMissileNo = 0;		// 現在のUV配列の番号
float g_animeMissileU = 0.0f;	// 現在のU値
float g_animeMissileV = 0.0f;	// 現在のV値
float g_uvmissile[][4] = {
		{0.33f, 1.0f, 0.0f, 0.0f},
		{0.33f, 1.0f, 0.33f, 0.0f},
		{0.33f, 1.0f, 0.66f, 0.0f},
};

int g_animeBoomNo = 0;		// 現在のUV配列の番号
float g_animeBoomU = 0.0f;	// 現在のU値
float g_animeBoomV = 0.0f;	// 現在のV値
float g_uvboom[][4] = {
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
	Vertex Bg[] = { 
		{{-1280.0f, -720.0f, 0.0f}, {0.0f, 0.0f}},
		{{-1280.0f, 720.0 , 0.0f}, {0.0f, 1.0f}},
		{{1280.0f, -720.0f, 0.0f}, {1.0f, 0.0f}},
		{{1280.0f, 720.0f, 0.0f}, {1.0f, 1.0f}} };
	g_pVtxBufBg = CreateVertexBuffer(Bg, 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/Bg4.bmp", &g_pTexBg)))
	{
		MessageBox(hWnd, "テクスチャー読み込み失敗", "エラー", S_OK);
		return false;
	}

	Vertex Obj[] = {
		{{-556.8f, -301.2f, 0.0f}, {0.0f, 0.0f}},
		{{-556.8f, 601.2, 0.0f}, {0.0f, 1.0f}},
		{{556.8f, -301.2f, 0.0f}, {1.0f, 0.0f}},
		{{556.8f, 601.2f, 0.0f}, {1.0f, 1.0f}} };
	g_pVtxBufObj = CreateVertexBuffer(Obj, 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/niconico.png", &g_pTexObj)))
	{
		MessageBox(hWnd, "テクスチャー読み込み失敗", "エラー", S_OK);
		return false;
	}

	Vertex Boom[] = {
		{{-1280.0f, -720.0f, 0.0f}, {0.0f, 0.0f}},
		{{-1280.0f, 720.0 , 0.0f}, {0.0f, 1.0f}},
		{{1280.0f, -720.0f, 0.0f}, {1.0f, 0.0f}},
		{{1280.0f, 720.0f, 0.0f}, {1.0f, 1.0f}} };
	g_pVtxBufBoom = CreateVertexBuffer(Boom, 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/Explosion.png", &g_pTexBoom)))
	{
		MessageBox(hWnd, "テクスチャー読み込み失敗", "エラー", S_OK);
		return false;
	}

	Vertex Missile[] = {
		{{-1280.0f, -720.0f, 0.0f}, {0.0f, 0.0f}},
		{{-1280.0f, 720.0 , 0.0f}, {0.0f, 1.0f}},
		{{1280.0f, -720.0f, 0.0f}, {1.0f, 0.0f}},
		{{1280.0f, 720.0f, 0.0f}, {1.0f, 1.0f}} };
	g_pVtxBufMissile = CreateVertexBuffer(Missile, 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/missilemove.png", &g_pTexMissile)))
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
	
	g_frame++;

	if (!(g_animeFrame % 5))
	{
		if (g_frame > 480)
		{
			g_animeBoomU = g_uvboom[g_animeBoomNo][2];
			g_animeBoomV = g_uvboom[g_animeBoomNo][3];
			g_animeBoomNo++;
		}
	}

	if (g_animeFrame >= 60)
	{
		g_animeBgNo++;
		if (g_animeBgNo > 1)
		{
			g_animeBgNo = 0;
		}
		g_animeBgU = g_uvbg[g_animeBgNo][2];
		g_animeBgV = g_uvbg[g_animeBgNo][3];

		if (g_frame > 360)
		{
			g_animeMissileNo++;
			g_animeMissileU = g_uvmissile[g_animeMissileNo][2];
			g_animeMissileV = g_uvmissile[g_animeMissileNo][3];
		}
		g_animeFrame = 0;
	}
	else
	{
		g_animeFrame++;
	}

	if (g_animeBoomNo > 20)
	{
		g_animeBoomNo = 0;
		g_frame = 0;
		g_animeFrame = 0;
		g_animeMissileNo = 0;
		g_animeMissileU = g_uvmissile[g_animeMissileNo][2];
		g_animeMissileV = g_uvmissile[g_animeMissileNo][3];
	}
}

void DrawGame()
{
	BeginDrawDirectX();

	SetSpriteUVScale(g_uvbg[g_animeBgNo][0], g_uvbg[g_animeBgNo][1]);
	SetSpriteUVPos(g_animeBgU, g_animeBgV);
	SetSpriteTexture(g_pTexBg);
	DrawSprite(g_pVtxBufBg, sizeof(Vertex));

	SetSpriteUVScale(1.0f, 1.0f);
	SetSpriteUVPos(0.0f, 0.0f);
	SetSpriteTexture(g_pTexObj);
	DrawSprite(g_pVtxBufObj, sizeof(Vertex));

	if (g_frame > 300)
	{
		SetSpriteUVScale(g_uvmissile[g_animeMissileNo][0], g_uvmissile[g_animeMissileNo][1]);
		SetSpriteUVPos(g_animeMissileU, g_animeMissileV);
		SetSpriteTexture(g_pTexMissile);
		DrawSprite(g_pVtxBufMissile, sizeof(Vertex));
	}

	if (g_frame > 480)
	{
		SetSpriteUVScale(g_uvboom[g_animeBoomNo][0], g_uvboom[g_animeBoomNo][1]);
		SetSpriteUVPos(g_animeBoomU, g_animeBoomV);
		SetSpriteTexture(g_pTexBoom);
		DrawSprite(g_pVtxBufBoom, sizeof(Vertex));
	}
	else
	{
		g_pBG->Draw();
	}
	
	
	EndDrawDirectX();
}