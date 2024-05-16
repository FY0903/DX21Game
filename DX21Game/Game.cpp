/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"

bool InitGame(HWND hWnd)
{
	// HRESULT�^�����s���Ă��邩��
	// FAILED�}�N���Ŕ��肷��
	if (FAILED(InitDirectX(hWnd, 1280, 720)))
	{
		MessageBox(hWnd, "DirectX���������s", "�G���[", S_OK);
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