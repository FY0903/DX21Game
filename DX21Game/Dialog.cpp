/**
* @file Dialog.cpp
*/
#include "Dialog.h"
#include <Windows.h>

void ErrorMessage(const char* string)
{
	MessageBox(NULL, string, "ÉGÉâÅ[", MB_OK | MB_ICONERROR);
}