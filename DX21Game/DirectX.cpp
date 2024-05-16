/**
* @file DirectX.cpp
*/
#include "DirectX.h"

// DirectXでアセットの作成を行う機能
ID3D11Device* g_pDevice;
// DirectXで描画命令を発行する機能
ID3D11DeviceContext* g_pContext;
// フレームバッファとディスプレイの橋渡し（スワップチェイン）
IDXGISwapChain* g_pSwapChain;
// フレームバッファそのもの（レンダーターゲットビューと呼ばれる）
ID3D11RenderTargetView* g_pRTV;

// 色指定
float g_color[4];

HRESULT InitDirectX(HWND hWnd, UINT width, UINT height)
{
	bool fullScreen = false;
	g_color[3] = 1.0f;

	// HRESULT...DirectXの処理結果を表すデータ
	// S_OKはプログラムの成功を表す
	// これ以外はエラー情報
	HRESULT hr = E_FAIL;

	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferDesc.Width = width;						// フレームバッファの幅
	sd.BufferDesc.Height = height;						// フレームバッファの高さ
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	// フレームバッファの色情報（各8bit）
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.SampleDesc.Count = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;	// バックバッファの使用方法
	sd.BufferCount = 1;									// バックバッファの数
	sd.OutputWindow = hWnd;								// 関連付けるウィンドウ
	sd.Windowed = fullScreen ? FALSE : TRUE;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	// ドライバの種類
	D3D_DRIVER_TYPE driverType;
	D3D_DRIVER_TYPE driverTypes[] = { D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP, D3D_DRIVER_TYPE_REFERENCE };
	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	// 機能レベル
	D3D_FEATURE_LEVEL featureLevel;
	D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0, D3D_FEATURE_LEVEL_9_3, D3D_FEATURE_LEVEL_9_2, D3D_FEATURE_LEVEL_9_1 };
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	// 作成可能な設定でDirectXの機能を有効化
	for (UINT i = 0; i < numDriverTypes; i++)
	{
		driverType = driverTypes[i];
		hr = D3D11CreateDeviceAndSwapChain(NULL, driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pDevice, &featureLevel, &g_pContext);
		if (SUCCEEDED(hr)) { break; }
	}
	if (FAILED(hr)) { return hr; }

	// フレームバッファへのポインタを取得
	ID3D11Texture2D* pBackBuffer = nullptr;
	hr = g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	// フレームバッファへのポインタで紐づけて、レンダーターゲットビューを作成
	if (SUCCEEDED(hr))
	{
		hr = g_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_pRTV);
		g_pContext->OMSetRenderTargets(1, &g_pRTV, nullptr);	// GPUの出力先設定
	}
}

void UninitDirectX()
{
	g_pRTV->Release();
	g_pSwapChain->SetFullscreenState(false, NULL);
	g_pSwapChain->Release();
	g_pContext->ClearState();
	g_pContext->Release();
	g_pDevice->Release();
}

void BeginDrawDirectX()
{
	for (int i = 0; i < 3; i++)
	{
		g_color[0] += 0.01f;
		g_color[1] += 0.01f;
		g_color[2] += 0.01f;
		if (g_color[i] > 1.0f) g_color[i] = 0.0f;
	}

	// 描画開始時に画面をクリア
	//float color[4] = { 0.8f, 0.9f, 1.0f, 1.0f };
	g_pContext->ClearRenderTargetView(g_pRTV, g_color);
}

void EndDrawDirectX()
{
	// 描画完了時に画面へ出力
	g_pSwapChain->Present(0, 0);
}