/**
* @file Main.cpp
*/
#include <Windows.h>

#include "Game.h"
#include "Dialog.h"

//=== 定数・マクロ定義 ===
//#define DX0425
#define DX0509

//=== プロトタイプ宣言 ===
#ifdef DX0509
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow)
{
#ifdef DX0425 // 条件に応じて有効・無効を切り替える
	if (IDYES == MessageBox(NULL, "テキスト", "タイトル", MB_YESNO | MB_ICONERROR))
	{
		// はいの場合の処理
		MessageBox(NULL, "はい", "", MB_OK);
	}
	else
	{
		// いいえの場合の処理
		MessageBox(NULL, "いいえ", "", MB_OK);
	}
#endif

#ifdef DX0509
	// ウィンドウクラス情報の作成
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));
	wcex.hInstance = hInstance;
	wcex.lpszClassName = "Class Name";
	wcex.lpfnWndProc = WndProc;
	wcex.style = CS_HREDRAW | CS_VREDRAW;						// ウィンドウの挙動
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アプリのアイコン
	wcex.hIconSm = wcex.hIcon;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);					// マウスのアイコン
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景の色

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, "ウィンドウクラスの登録に失敗", "エラー", MB_OK);
		return 0;
	}

	HWND hWnd;
	hWnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,			// ウィンドウの見た目
		wcex.lpszClassName, "タイトル",	// タイトルバーに表示する文字
		WS_CAPTION | WS_SYSMENU,		// ウィンドウの見た目
		CW_USEDEFAULT, CW_USEDEFAULT,	// ウィンドウの表示位置
		960, 540,						// ウィンドウの大きさ
		HWND_DESKTOP, NULL, hInstance, NULL);
	if (hWnd == NULL)
	{
		MessageBox(NULL, "ウィンドウの作成に失敗", "エラー", MB_OK);
		return 0;
	}

	// ウィンドウの表示
	ShowWindow(hWnd, nCmdshow);
	UpdateWindow(hWnd);

	// ゲームの初期化処理
	if (!InitGame())
	{
		MessageBox(hWnd, "ゲームの初期化に失敗しました", "エラー", MB_OK);
		return 0;
	}

	// メッセージループ
	MSG message;
	while (1)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&message, NULL, 0, 0))
			{
				break;
			}
			else
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
		else // メッセージが何もないときにゲームの処理を行う
		{

		}
	}

	// 終了処理
	UninitGame();

#endif

	return 0;
}

#ifdef DX0509
// ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// ×ボタン押されたときのメッセージ
	case WM_CLOSE:
		if (IDNO == MessageBox(hWnd, "終了しますか", "確認", MB_YESNO))
		{
			return 0;	// WM_CLOSEの処理をここで終わる
		}
		break;
	case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
#endif