#include <Windows.h>
#include <string.h>
#include <stdio.h>

#include "Dialog.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow)
{
	int nScore = 0;			// ������
	int nNowQestion = 0;	// ���ݖ��ԍ�
	bool bFlag = false;		// �J�n�t���O
	char cResult[255];		// ���ʔ��\�p����
	char cNowQestion[255];	// ���ݖ��\���p������
	char cTitle[255] = "�����A�L�l�[�^�[";	// �^�C�g������
	char cQestion[3][255] = { {"�����C�W�̐g����165cm�ȏ�ł���"}, {"�����C�W�̑̏d��50kg�ȏ�ł���"}, {"�����C�W�͊�{���Z�p�Ҏ������擾���Ă���"}};	// �����e

	// �J�n����
	if (IDYES == MessageBox(NULL, "�A�L�l�[�^�[���J�n���܂���", cTitle, MB_YESNO | MB_ICONQUESTION))
	{
		bFlag = true;
	}
	else
	{
		MessageBox(NULL, "�I�����܂�", cTitle, NULL);
	}

	if (bFlag)
	{
		for (nNowQestion = 0; nNowQestion < 3; nNowQestion++)
		{
			sprintf(cNowQestion, "��%d��", nNowQestion + 1);
			switch (nNowQestion)
			{
			case 0:
				if (IDYES != MessageBox(NULL, cQestion[nNowQestion], cNowQestion, MB_YESNO | MB_ICONQUESTION))
				{
					nScore++;
				}
				break;
			case 1:
				if (IDYES != MessageBox(NULL, cQestion[nNowQestion], cNowQestion, MB_YESNO | MB_ICONQUESTION))
				{
					nScore++;
				}
				break;
			case 2:
				if (IDYES == MessageBox(NULL, cQestion[nNowQestion], cNowQestion, MB_YESNO | MB_ICONQUESTION))
				{
					nScore++;
					bFlag = false;
				}
				sprintf(cResult, "���ʂ�%d�_�ł���", nScore);
				MessageBox(NULL, cResult, "���ʔ��\", MB_OK | MB_ICONINFORMATION);
				break;
			}
		}
	}

	return 0;
}