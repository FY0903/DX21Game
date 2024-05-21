#ifndef ___VERTEX_H___
#define ___VERTEX_H___

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

struct Vertex
{
	float pos[3];
	float uv[2];
};
ID3D11Buffer* CreateVertexBuffer(void* vtxData, UINT vtxNum);

#endif