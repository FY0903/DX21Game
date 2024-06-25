#include "textBox.h"
#include "DirectXTex/TextureLoad.h"
#include "DirectX.h"
#include "SpriteDrawer.h"

CTextBox::CTextBox()
{
	m_fAnimeU = 0.0f;		// ���݂�U�l
	m_fAnimeV = 0.0f;		// ���݂�V�l
	m_nAnimeNo = 0;			// ���݂�UV�z��̔ԍ�
	m_uv = {
		{1.0f, 1.0f, 0.0f, 0.0f},
	};

	// ���_�o�b�t�@�̍쐬
	m_vtx = {
		{{-340.0f, -211.0f, 0.0f}, {0.0f, 0.0f}},
		{{-340.0f, 211.0f, 0.0f}, {0.0f, 1.0f}},
		{{340.0f, -211.0f, 0.0f}, {1.0f, 0.0f}},
		{{340.0f, 211.0f, 0.0f}, {1.0f, 1.0f}}
	};

	m_pVtxBuf = CreateVertexBuffer(m_vtx.data(), 4);
	if (FAILED(LoadTextureFromFile(GetDevice(), "texture/roboksfukidashi.png", &m_pTex)))
	{
		MessageBox(nullptr, "�e�N�X�`���[�ǂݍ��ݎ��s", "�G���[", S_OK);
	}
}

CTextBox::~CTextBox()
{
	if (m_pVtxBuf) m_pVtxBuf->Release();
	if (m_pTex) m_pTex->Release();
}

void CTextBox::Update()
{

}

void CTextBox::Draw()
{
	SetSpriteAngle(0.0f);
	SetSpritePos(400.0f, 300.0f);
	SetSpriteScale(1.0f, 1.0f);
	SetSpriteUVScale(m_uv[m_nAnimeNo][0], m_uv[m_nAnimeNo][1]);
	SetSpriteUVPos(m_fAnimeU, m_fAnimeV);
	SetSpriteTexture(m_pTex);
	DrawSprite(m_pVtxBuf, sizeof(Vertex));
}