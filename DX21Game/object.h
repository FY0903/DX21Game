#pragma once
#include "VertexBuffer.h"
#include <vector>
#include <array>

class CObject
{
public:
	CObject();
	~CObject();
	void Draw();

	void InitAnimeNo();
	int GetAnimeNo();
	void SetAnimeNo(int nAnimeNo);
	int GetAnime();
private:
	int m_nAnimeNo{};	// ���݂�UV�z��̔ԍ�
	float m_fAnimeU{};	// ���݂�U�l
	float m_fAnimeV{};	// ���݂�V�l
	std::vector<std::array<float, 4>> m_uv;
	std::vector<Vertex> m_vtx;

	ID3D11Buffer* m_pVtxBuf;
	ID3D11ShaderResourceView* m_pTex;
};