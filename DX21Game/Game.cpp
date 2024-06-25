/**
* @file Game.cpp
*/
#include "Game.h"
#include "DirectX.h"
#include "SpriteDrawer.h"
#include "VertexBuffer.h"
#include "DirectXTex/TextureLoad.h"
#include "BackGround.h"
<<<<<<< HEAD
=======
#include "field.h"
#include "missile.h"
#include "explotion.h"
#include "object.h"
>>>>>>> f68ad1e (06/20 20:43 ファイル刁E��)

//=== �O���[�o���錾 ===
ID3D11Buffer* g_pVtxBufBg;
ID3D11Buffer* g_pVtxBufObj;
ID3D11Buffer* g_pVtxBufBoom;
ID3D11Buffer* g_pVtxBufMissile;
ID3D11ShaderResourceView* g_pTexBg;
ID3D11ShaderResourceView* g_pTexObj;
ID3D11ShaderResourceView* g_pTexBoom;
ID3D11ShaderResourceView* g_pTexMissile;

int g_frame = 0;		// �t���[���J�E���^
int g_animeFrame = 0;	// �A�j���[�V�����؂�ւ��t���[��

<<<<<<< HEAD
int g_animeBgNo = 0;		// ���݂�UV�z��̔ԍ�
float g_animeBgU = 0.0f;	// ���݂�U�l
float g_animeBgV = 0.0f;	// ���݂�V�l
float g_uvbg[][4] = {
		{0.5f, 1.0f, 0.0f, 0.0f},
		{0.5f, 1.0f, 0.5f, 0.0f},
};

int g_animeMissileNo = 0;		// ���݂�UV�z��̔ԍ�
float g_animeMissileU = 0.0f;	// ���݂�U�l
float g_animeMissileV = 0.0f;	// ���݂�V�l
float g_uvmissile[][4] = {
		{0.33f, 1.0f, 0.0f, 0.0f},
		{0.33f, 1.0f, 0.33f, 0.0f},
		{0.33f, 1.0f, 0.66f, 0.0f},
};

int g_animeBoomNo = 0;		// ���݂�UV�z��̔ԍ�
float g_animeBoomU = 0.0f;	// ���݂�U�l
float g_animeBoomV = 0.0f;	// ���݂�V�l
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
=======
CBackGround* g_pCBackGround;
CField* g_pCField;
CMissile* g_pCMissile;
CExplotion* g_pCExplotion;
CObject* g_pCObject;
>>>>>>> f68ad1e (06/20 20:43 ファイル刁E��)

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

<<<<<<< HEAD
	// ���_�o�b�t�@�̍쐬
	Vertex Bg[] = { 
		{{-1280.0f, -720.0f, 0.0f}, {0.0f, 0.0f}},
		{{-1280.0f, 720.0 , 0.0f}, {0.0f, 1.0f}},
		{{1280.0f, -720.0f, 0.0f}, {1.0f, 0.0f}},
		{{1280.0f, 720.0f, 0.0f}, {1.0f, 1.0f}} };
	g_pVtxBufBg = CreateVertexBuffer(Bg, 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/Bg4.bmp", &g_pTexBg)))
	{
		MessageBox(hWnd, "�e�N�X�`���[�ǂݍ��ݎ��s", "�G���[", S_OK);
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
		MessageBox(hWnd, "�e�N�X�`���[�ǂݍ��ݎ��s", "�G���[", S_OK);
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
		MessageBox(hWnd, "�e�N�X�`���[�ǂݍ��ݎ��s", "�G���[", S_OK);
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
		MessageBox(hWnd, "�e�N�X�`���[�ǂݍ��ݎ��s", "�G���[", S_OK);
		return false;
	}

	g_pBG = new BackGround();
=======
	g_pCBackGround = new CBackGround();
	g_pCField = new CField();
	g_pCMissile = new CMissile();
	g_pCExplotion = new CExplotion();
	g_pCObject = new CObject();
>>>>>>> f68ad1e (06/20 20:43 ファイル刁E��)

	return true;
}

void UninitGame()
{
<<<<<<< HEAD
	delete(g_pBG);
=======
	delete(g_pCBackGround);
	delete(g_pCField);
	delete(g_pCMissile);
	delete(g_pCExplotion);
	delete(g_pCObject);
>>>>>>> f68ad1e (06/20 20:43 ファイル刁E��)
	UninitSpriteDrawer();
	UninitDirectX();
}

void UpdateGame()
{
	g_pBG->Update();
	
	g_frame++;
<<<<<<< HEAD
=======
	
	g_pCObject->Update();
>>>>>>> f68ad1e (06/20 20:43 ファイル刁E��)

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

<<<<<<< HEAD
	SetSpriteUVScale(g_uvbg[g_animeBgNo][0], g_uvbg[g_animeBgNo][1]);
	SetSpriteUVPos(g_animeBgU, g_animeBgV);
	SetSpriteTexture(g_pTexBg);
	DrawSprite(g_pVtxBufBg, sizeof(Vertex));

	SetSpriteUVScale(1.0f, 1.0f);
	SetSpriteUVPos(0.0f, 0.0f);
	SetSpriteTexture(g_pTexObj);
	DrawSprite(g_pVtxBufObj, sizeof(Vertex));
=======
	g_pCField->Draw();
>>>>>>> f68ad1e (06/20 20:43 ファイル刁E��)

	g_pCObject->Draw();


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