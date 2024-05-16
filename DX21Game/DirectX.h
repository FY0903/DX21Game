/**
* @file DirectX.h
*/
#ifndef ___DIRECTX_H___
#define ___DIRECTX_H___

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

HRESULT InitDirectX(HWND hWnd, UINT width, UINT height);

void UninitDirectX();
void BeginDrawDirectX();
void EndDrawDirectX();

#endif