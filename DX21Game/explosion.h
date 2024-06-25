#pragma once
#include "VertexBuffer.h"
#include <vector>
#include <array>

class CExplosion
{
public:
	CExplosion(bool bExplosion = false);
	~CExplosion();
	void Update();
	void Draw();
private:
	int m_nAnimeNo{};	// åªç›ÇÃUVîzóÒÇÃî‘çÜ
	float m_fAnimeU{};	// åªç›ÇÃUíl
	float m_fAnimeV{};	// åªç›ÇÃVíl
	bool m_bExpolosionBig{};
	std::vector<std::array<float, 4>> m_uv;
	std::vector<Vertex> m_vtx;

	ID3D11Buffer* m_pVtxBuf;
	ID3D11ShaderResourceView* m_pTex;
};