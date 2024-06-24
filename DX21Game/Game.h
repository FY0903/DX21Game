/**
* @file Game.h
*/
#include <Windows.h>

#ifndef ___GAME_H___
#define ___GAME_H___

//=== 定数・マクロ定義 ===
#define PI 3.14159265358979323846f

//=== プロトタイプ宣言 ===
bool InitGame(HWND hWnd);
void UninitGame();
void UpdateGame();
void DrawGame();

int GetFrame();
void SetFrame(int nFrame);
#endif