#include "Dialog.h"
#include <Windows.h>

void ErrorMessage(const char* string)
{
	MessageBox(NULL, string, "ƒGƒ‰[", MB_OK | MB_ICONERROR);
}