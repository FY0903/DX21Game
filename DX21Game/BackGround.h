#ifndef ___BACK_GROUND_H___
#define ___BACK_GROUND_H___

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

class CBackGround
{
public:
	CBackGround();
	~CBackGround();
	void Update();
	void Draw();
private:
	ID3D11Buffer* m_pVtx;
	ID3D11ShaderResourceView* m_pTex;
	float m_offsetU;
};

#endif