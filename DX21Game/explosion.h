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
	int m_nAnimeNo{};	// 現在のUV配列の番号
	float m_fAnimeU{};	// 現在のU値
	float m_fAnimeV{};	// 現在のV値
	bool m_bExpolosionBig{};
	std::vector<std::array<float, 4>> m_uv;
	std::vector<Vertex> m_vtx;

	ID3D11Buffer* m_pVtxBuf;
	ID3D11ShaderResourceView* m_pTex;
};