/**
* @file Game.h
*/
#include <Windows.h>

#ifndef ___GAME_H___
#define ___GAME_H___

//=== �v���g�^�C�v�錾 ===
bool InitGame(HWND hWnd);
void UninitGame();
void UpdateGame();
void DrawGame();

int GetFrame();
void SetFrame(int nFrame);
#endif