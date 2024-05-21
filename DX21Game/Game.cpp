/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "VertexBuffer.h"

//=== �O���[�o���錾 ===
ID3D11Buffer* g_pVtxBuf;

bool InitGame(HWND hWnd)
{
	// HRESULT�^�����s���Ă��邩��
	// FAILED�}�N���Ŕ��肷��
	if (FAILED(InitDirectX(hWnd, 1280, 720)))
	{
		MessageBox(hWnd, "DirectX���������s", "�G���[", S_OK);
		return false;
	}

	// �X�v���C�g�`��T�|�[�g�̏�����
	InitSpriteDrawer(GetDevice(), GetContext(), 1280, 720);

	Vertex vtx[] = { {{10.0f, 10.0f, 10.0f}, {0.0f, 0.0f}}, {{20.0f, 10.0f, 10.0f}, {0.0f, 0.0f}}, {{10.0f, 2.0f, 10.0f}, {0.0f, 0.0f}}, {{20.0f, 20.0f, 10.0f}, {0.0f, 0.0f}} };
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
	DrawSprite(g_pVtxBuf);
	EndDrawDirectX();
}