/**
* @file Game.h
*/
#include <Windows.h>

#ifndef ___GAME_H___
#define ___GAME_H___

//=== �萔�E�}�N����` ===
#define PI 3.141592f

//=== �v���g�^�C�v�錾 ===
bool InitGame(HWND hWnd);
void UninitGame();
void UpdateGame();
void DrawGame();

int GetFrame();
void SetFrame(int nFrame);
#endif