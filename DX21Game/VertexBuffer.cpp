#include "VertexBuffer.h"
#include "DirectX.h"
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

ID3D11Buffer* CreateVertexBuffer(void* vtxData, UINT vtxNum)
{
	// �o�b�t�@���@�ݒ�
	D3D11_BUFFER_DESC vtxBufDesc;
	ZeroMemory(&vtxBufDesc, sizeof(vtxBufDesc));
	vtxBufDesc.ByteWidth = sizeof(Vertex) * vtxNum;
	vtxBufDesc.Usage = D3D11_USAGE_DEFAULT;
	vtxBufDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	// �o�b�t�@�����f�[�^�@�ݒ�
	D3D11_SUBRESOURCE_DATA vtxSubResource;
	ZeroMemory(&vtxSubResource, sizeof(vtxSubResource));
	vtxSubResource.pSysMem = vtxData;

	// �쐬
	HRESULT hr;
	ID3D11Buffer* pVtxBuf;
	hr = GetDevice()->CreateBuffer(&vtxBufDesc, &vtxSubResource, &pVtxBuf);
	if (FAILED(hr)) { return nullptr; };
	return pVtxBuf;
}