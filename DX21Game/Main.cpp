#include <Windows.h>
#include <string.h>
#include <stdio.h>

#include "Dialog.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow)
{
	int nScore = 0;			// 正答数
	int nNowQestion = 0;	// 現在問題番号
	bool bFlag = false;		// 開始フラグ
	char cResult[255];		// 結果発表用文字
	char cNowQestion[255];	// 現在問題表示用文字列
	char cTitle[255] = "藤原アキネーター";	// タイトル文字
	char cQestion[3][255] = { {"藤原佑埜の身長は165cm以上である"}, {"藤原佑埜の体重は50kg以上である"}, {"藤原佑埜は基本情報技術者試験を取得している"}};	// 問題内容

	// 開始処理
	if (IDYES == MessageBox(NULL, "アキネーターを開始しますか", cTitle, MB_YESNO | MB_ICONQUESTION))
	{
		bFlag = true;
	}
	else
	{
		MessageBox(NULL, "終了します", cTitle, NULL);
	}

	if (bFlag)
	{
		for (nNowQestion = 0; nNowQestion < 3; nNowQestion++)
		{
			sprintf(cNowQestion, "第%d問", nNowQestion + 1);
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
				sprintf(cResult, "結果は%d点でした", nScore);
				MessageBox(NULL, cResult, "結果発表", MB_OK | MB_ICONINFORMATION);
				break;
			}
		}
	}

	return 0;
}