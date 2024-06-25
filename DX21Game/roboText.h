#pragma once
#include "VertexBuffer.h"
#include <vector>
#include <array>

class CRoboText
{
public:
	CRoboText();
	~CRoboText();
	void Update();
	void Draw();
private:
	int m_nAnimeNo{};	// åªç›ÇÃUVîzóÒÇÃî‘çÜ
	float m_fAnimeU{};	// åªç›ÇÃUíl
	float m_fAnimeV{};	// åªç›ÇÃVíl
	float m_fRad{};
	float m_fSize{};
	int m_nFrame{};
	std::vector<std::array<float, 4>> m_uv;
	std::vector<Vertex> m_vtx;

	ID3D11Buffer* m_pVtxBuf;
	ID3D11ShaderResourceView* m_pTex;
};