#include "text.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"

CText::CText()
{
	m_nAnimeNo = 0;			// ���݂�UV�z��̔ԍ�
	m_fAnimeU = 0.0f;		// ���݂�U�l
	m_fAnimeV = 0.0f;		// ���݂�V�l
	m_uv = {
		{1.0f, 1.0f, 0.0f, 0.0f},
	};

	// ���_�o�b�t�@�̍쐬
	m_vtx = {
		{{-680.0f, -260.0f, 0.0f}, {0.0f, 0.0f}},
		{{-680.0f, 480.0 , 0.0f}, {0.0f, 1.0f}},
		{{680.0f, -260.0f, 0.0f}, {1.0f, 0.0f}},
		{{680.0f, 480.0f, 0.0f}, {1.0f, 1.0f}} };

	m_pVtxBuf = CreateVertexBuffer(m_vtx.data(), 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/text.png", &m_pTex)))
	{
		MessageBox(nullptr, "�e�N�X�`���[�ǂݍ��ݎ��s", "�G���[", S_OK);
	}
}

CText::~CText()
{
	if (m_pVtxBuf) m_pVtxBuf->Release();
	if (m_pTex) m_pTex->Release();
}

void CText::Update()
{
}

void CText::Draw()
{
	SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
	SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}
