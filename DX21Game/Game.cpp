/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"

bool InitGame(HWND hWnd)
{
	// HRESULT型が失敗しているかは
	// FAILEDマクロで判定する
	if (FAILED(InitDirectX(hWnd, 1280, 720)))
	{
		MessageBox(hWnd, "DirectX初期化失敗", "エラー", S_OK);
		return false;
	}
	return true;
}

void UninitGame()
{
	UninitDirectX();
}

void UpdateGame()
{

}

void DrawGame()
{
	BeginDrawDirectX();
	EndDrawDirectX();
}