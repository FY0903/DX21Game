/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"

//=== �O���[�o���錾 ===
ID3D11Buffer* g_pVtxBuf;
ID3D11ShaderResourceView* g_pTex;

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

	// ���_�o�b�t�@�̍쐬
	Vertex vtx[] = { 
		{{-100.0f, -100.0f, 0.0f}, {0.0f, 0.0f}}, 
		{{-100.0f, 100.0f, 0.0f}, {0.0f, 1.0f}}, 
		{{100.0f, -100.0f, 0.0f}, {1.0f, 0.0f}}, 
		{{100.0f, 100.0f, 0.0f}, {1.0f, 1.0f}} };
	g_pVtxBuf = CreateVertexBuffer(vtx, 4);

	if (FAILED(LoadTextureFromFile(GetDevice(), "test.jpg", &g_pTex)))
	{
		MessageBox(hWnd, "�e�N�X�`���[�ǂݍ��ݎ��s", "�G���[", S_OK);
		return false;
	}
	SetSpriteTexture(g_pTex);

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