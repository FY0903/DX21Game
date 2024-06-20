#pragma once
#include "VertexBuffer.h"
#include <vector>
#include <array>

class CExplotion
{
public:
	CExplotion();
	~CExplotion();
	void Update();
	void Draw();

	void InitAnimeNo();
	int GetAnimeNo();
	void SetAnimeNo(int nAnimeNo);
	int GetAnime();
private:
	int m_nAnimeNo{};	// 現在のUV配列の番号
	float m_fAnimeU{};	// 現在のU値
	float m_fAnimeV{};	// 現在のV値
	std::vector<std::array<float, 4>> m_uv;
	std::vector<Vertex> m_vtx;

	ID3D11Buffer* m_pVtxBuf;
	ID3D11ShaderResourceView* m_pTex;
};