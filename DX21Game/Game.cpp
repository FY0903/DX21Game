/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "BackGround.h"
#include "scene.h"
#include "startScene.h"
#include "field.h"
#include "missile.h"
#include "explotion.h"
#include "object.h"

//=== �O���[�o���錾 ===
int g_frame = 0;		// �t���[���J�E���^

CManager* g_pCManager;

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

	g_pCManager = new CManager();
	g_pCManager->m_pScene = new CStartScene(g_pCManager);

	return true;
}

void UninitGame()
{
	delete(g_pCManager);

	UninitSpriteDrawer();
	UninitDirectX();
}

void UpdateGame()
{
	g_frame++;

	g_pCManager->Update();

}

void DrawGame()
{
	BeginDrawDirectX();

	g_pCManager->Draw();

	EndDrawDirectX();
}

int GetFrame()
{
	return g_frame;
}

void SetFrame(int nFrame)
{
	g_frame = nFrame;
}
