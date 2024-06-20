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
	int m_nAnimeNo{};	// åªç›ÇÃUVîzóÒÇÃî‘çÜ
	float m_fAnimeU{};	// åªç›ÇÃUíl
	float m_fAnimeV{};	// åªç›ÇÃVíl
	std::vector<std::array<float, 4>> m_uv;
	std::vector<Vertex> m_vtx;

	ID3D11Buffer* m_pVtxBuf;
	ID3D11ShaderResourceView* m_pTex;
};