#include "UIManager.h"
#include "macroFunction.h"
#include "Image.h"

HRESULT UIManager::Init()
{
	AddFontResource("Font/DungGeunMo.ttf");
	BHP = ImageManager::GetSingleton()->AddImage("bossHP", "Image/bossHP.bmp", 0, 0, 500, 20, 1, 1, true, RGB(255, 0, 255));

	HP = 500;
	posX = WINSIZE_X / 2;
	posY = 50;
	enemyWave = 0;

	

	score = 0;
	return S_OK;
}

void UIManager::Release()
{
	RemoveFontResource("Font/DungGeunMo.ttf");
}

void UIManager::Update()
{

}

void UIManager::Render(HDC hdc)
{
	PrintText(hdc);

	if (enemyWave > 9)
	{
		PrintHPbar(hdc);
	}
	

}

void UIManager::PrintText(HDC hdc)
{
	FONT text;
	char sZtext[256];

	//글꼴설정
	strcpy_s(text.lfFaceName, "둥근모꼴");
	text.lfHeight = 30;
	hFont = CreateFontIndirect((LOGFONTA*)&text);
	hOldFont = (HFONT)SelectObject(hdc, hFont);

	
	wsprintf(sZtext, "score : %d", score);
	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkMode(hdc, TRANSPARENT);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			TextOut(hdc, 30 - i, 30 - j, sZtext, strlen(sZtext));
			TextOut(hdc, 30 + i, 30 + j, sZtext, strlen(sZtext));
		}
	}
	
	SetTextColor(hdc, RGB(0, 0, 255));
	SetBkMode(hdc, TRANSPARENT);

	TextOut(hdc, 30, 30, sZtext, strlen(sZtext));

	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);

	

}

void UIManager::PrintContinue(HDC hdc, int continueCount)
{
	FONT text;
	char sZtext[256];

	//글꼴설정
	if (continueCount == 0)
	{
		strcpy_s(text.lfFaceName, "둥근모꼴");
		text.lfHeight = 50;
		hFont = CreateFontIndirect((LOGFONTA*)&text);
		hOldFont = (HFONT)SelectObject(hdc, hFont);


		wsprintf(sZtext, " > Continue");
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				TextOut(hdc, 157 - i, 440 - j, sZtext, strlen(sZtext));
				TextOut(hdc, 157 + i, 440 + j, sZtext, strlen(sZtext));
			}
		}

		SetTextColor(hdc, RGB(255, 0, 0));
		SetBkMode(hdc, TRANSPARENT);

		TextOut(hdc, 157, 440, sZtext, strlen(sZtext));

		text.lfHeight = 40;
		hFont = CreateFontIndirect((LOGFONTA*)&text);
		hOldFont = (HFONT)SelectObject(hdc, hFont);

		wsprintf(sZtext, "   Replay ");
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				TextOut(hdc, 172 - i, 520 - j, sZtext, strlen(sZtext));
				TextOut(hdc, 172 + i, 520 + j, sZtext, strlen(sZtext));
			}
		}

		SetTextColor(hdc, RGB(255, 0, 0));
		SetBkMode(hdc, TRANSPARENT);

		TextOut(hdc, 172, 520, sZtext, strlen(sZtext));

	}
	else
	{
		strcpy_s(text.lfFaceName, "둥근모꼴");
		text.lfHeight = 40;
		hFont = CreateFontIndirect((LOGFONTA*)&text);
		hOldFont = (HFONT)SelectObject(hdc, hFont);


		wsprintf(sZtext, "   Continue");
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				TextOut(hdc, 170 - i, 450 - j, sZtext, strlen(sZtext));
				TextOut(hdc, 170 + i, 450 + j, sZtext, strlen(sZtext));
			}
		}

		SetTextColor(hdc, RGB(255, 0, 0));
		SetBkMode(hdc, TRANSPARENT);

		TextOut(hdc, 170, 450, sZtext, strlen(sZtext));

		text.lfHeight = 50;
		hFont = CreateFontIndirect((LOGFONTA*)&text);
		hOldFont = (HFONT)SelectObject(hdc, hFont);

		wsprintf(sZtext, " > Replay ");
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				TextOut(hdc, 157 - i, 510 - j, sZtext, strlen(sZtext));
				TextOut(hdc, 157 + i, 510 + j, sZtext, strlen(sZtext));
			}
		}

		SetTextColor(hdc, RGB(255, 0, 0));
		SetBkMode(hdc, TRANSPARENT);

		TextOut(hdc, 157, 510, sZtext, strlen(sZtext));


	}

	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);
}


void UIManager::PrintClearScore(HDC hdc, int Life, int _score, bool ending)
{
	FONT text;
	int printscore = _score;
	char sZtext[256];

	if (!ending)
	{
	
		//글꼴설정
		strcpy_s(text.lfFaceName, "둥근모꼴");
		text.lfHeight = 30;
		hFont = CreateFontIndirect((LOGFONTA*)&text);
		hOldFont = (HFONT)SelectObject(hdc, hFont);

		wsprintf(sZtext, "X %d = %d", Life, Life * 1000);
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				TextOut(hdc, 250 - i, 620 - j, sZtext, strlen(sZtext));
				TextOut(hdc, 250 + i, 620 + j, sZtext, strlen(sZtext));
			}
		}

		SetTextColor(hdc, RGB(0, 0, 255));
		SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, 250, 620, sZtext, strlen(sZtext));

		wsprintf(sZtext, "score : %d", _score);
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				TextOut(hdc, 208 - i, 650 - j, sZtext, strlen(sZtext));
				TextOut(hdc, 208 + i, 650 + j, sZtext, strlen(sZtext));
			}
		}

		SetTextColor(hdc, RGB(0, 0, 255));
		SetBkMode(hdc, TRANSPARENT);

		TextOut(hdc, 208, 650, sZtext, strlen(sZtext));
	}
	else
	{
		
		//글꼴설정
		strcpy_s(text.lfFaceName, "둥근모꼴");
		text.lfHeight = 50;
		hFont = CreateFontIndirect((LOGFONTA*)&text);
		hOldFont = (HFONT)SelectObject(hdc, hFont);

		wsprintf(sZtext, "Your Score!!!");
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				TextOut(hdc, 150 - i, 520 - j, sZtext, strlen(sZtext));
				TextOut(hdc, 150 + i, 520 + j, sZtext, strlen(sZtext));
			}
		}

		SetTextColor(hdc, RGB(100, 0, 255));
		SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, 150, 520, sZtext, strlen(sZtext));

		text.lfHeight = 50;
		wsprintf(sZtext, "score : %d", score);
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				TextOut(hdc, 160 - i, 590 - j, sZtext, strlen(sZtext));
				TextOut(hdc, 160 + i, 590 + j, sZtext, strlen(sZtext));
			}
		}

		SetTextColor(hdc, RGB(100, 0, 255));
		SetBkMode(hdc, TRANSPARENT);

		TextOut(hdc, 160, 590, sZtext, strlen(sZtext));

	}

	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);


}

void UIManager::PrintHPbar(HDC hdc)
{
	hBrush = CreateSolidBrush(RGB(178, 178, 178));
	hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, 50, 0, 550, 20);

	SelectObject(hdc, hOldBrush);
	DeleteObject(hBrush);


	if (HP <= 150)
	{
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Rectangle(hdc, 50, 0, HP + 50, 20);

		SelectObject(hdc, hOldBrush);
		DeleteObject(hBrush);
	}
	else if (HP <= 300)
	{
		hBrush = CreateSolidBrush(RGB(246, 187, 67));
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Rectangle(hdc, 50, 0, HP + 50, 20);

		SelectObject(hdc, hOldBrush);
		DeleteObject(hBrush);
	}
	else
	{
		hBrush = CreateSolidBrush(RGB(0, 255, 62));
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Rectangle(hdc, 50, 0, HP + 50, 20);

		SelectObject(hdc, hOldBrush);
		DeleteObject(hBrush);
	}



	if (BHP)
	{
		BHP->Render(hdc, 300, 10);
	}

}



void UIManager::Reset()
{
	HP = 500;
	posX = WINSIZE_X / 2;
	posY = 50;
	enemyWave = 0;



	score = 0;
}

UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}
