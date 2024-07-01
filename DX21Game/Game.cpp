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

//=== �O���[�o���錾 ===
BackGround* g_pBG;
Block* g_pBlock;
Field* g_pField;

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