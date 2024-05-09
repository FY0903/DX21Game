/**
* @file Main.cpp
*/
#include <Windows.h>

#include "Game.h"
#include "Dialog.h"

//=== �萔�E�}�N����` ===
//#define DX0425
#define DX0509

//=== �v���g�^�C�v�錾 ===
#ifdef DX0509
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow)
{
#ifdef DX0425 // �����ɉ����ėL���E������؂�ւ���
	if (IDYES == MessageBox(NULL, "�e�L�X�g", "�^�C�g��", MB_YESNO | MB_ICONERROR))
	{
		// �͂��̏ꍇ�̏���
		MessageBox(NULL, "�͂�", "", MB_OK);
	}
	else
	{
		// �������̏ꍇ�̏���
		MessageBox(NULL, "������", "", MB_OK);
	}
#endif

#ifdef DX0509
	// �E�B���h�E�N���X���̍쐬
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));
	wcex.hInstance = hInstance;
	wcex.lpszClassName = "Class Name";
	wcex.lpfnWndProc = WndProc;
	wcex.style = CS_HREDRAW | CS_VREDRAW;						// �E�B���h�E�̋���
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�v���̃A�C�R��
	wcex.hIconSm = wcex.hIcon;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);					// �}�E�X�̃A�C�R��
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�̐F

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, "�E�B���h�E�N���X�̓o�^�Ɏ��s", "�G���[", MB_OK);
		return 0;
	}

	HWND hWnd;
	hWnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,			// �E�B���h�E�̌�����
		wcex.lpszClassName, "�^�C�g��",	// �^�C�g���o�[�ɕ\�����镶��
		WS_CAPTION | WS_SYSMENU,		// �E�B���h�E�̌�����
		CW_USEDEFAULT, CW_USEDEFAULT,	// �E�B���h�E�̕\���ʒu
		960, 540,						// �E�B���h�E�̑傫��
		HWND_DESKTOP, NULL, hInstance, NULL);
	if (hWnd == NULL)
	{
		MessageBox(NULL, "�E�B���h�E�̍쐬�Ɏ��s", "�G���[", MB_OK);
		return 0;
	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, nCmdshow);
	UpdateWindow(hWnd);

	// �Q�[���̏���������
	if (!InitGame())
	{
		MessageBox(hWnd, "�Q�[���̏������Ɏ��s���܂���", "�G���[", MB_OK);
		return 0;
	}

	// ���b�Z�[�W���[�v
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
		else // ���b�Z�[�W�������Ȃ��Ƃ��ɃQ�[���̏������s��
		{

		}
	}

	// �I������
	UninitGame();

#endif

	return 0;
}

#ifdef DX0509
// �E�B���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// �~�{�^�������ꂽ�Ƃ��̃��b�Z�[�W
	case WM_CLOSE:
		if (IDNO == MessageBox(hWnd, "�I�����܂���", "�m�F", MB_YESNO))
		{
			return 0;	// WM_CLOSE�̏����������ŏI���
		}
		break;
	case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
#endif