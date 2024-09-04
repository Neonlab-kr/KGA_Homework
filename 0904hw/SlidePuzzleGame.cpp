#include "Stdafx.h"
#include "SlidePuzzleGame.h"

HRESULT SlidePuzzleGame::init(void)
{
	GameNode::init();

	_puzzleImage = new GImage();
	_puzzleImage->init("Resource/Images/BackGround/hw1/EnderLiliesBG.bmp", WINSIZE_X, WINSIZE_Y / 4 * 3);

	_answerImage = new GImage();
	_answerImage->init("Resource/Images/BackGround/hw1/EnderLiliesBG.bmp", WINSIZE_X / 3 - 20, WINSIZE_Y / 4 - 20);

	for (int i = 0; i < 9; i++)
	{
		puzzlePiece[i].rc = RectMake(WINSIZE_X / 3 * (i % 3), WINSIZE_Y / 4 * (i / 3), WINSIZE_X / 3, WINSIZE_Y / 4);
		puzzlePiece[i].index = i;
	}

	while (true)
	{
		int inversion = 0;
		for (int i = 0; i < 8; i++)
		{
			int sel = RND->getInt(8);
			int temp = puzzlePiece[i].index;
			puzzlePiece[i].index = puzzlePiece[sel].index;
			puzzlePiece[sel].index = temp;
		}

		for (int i = 7; i > 0; i--)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (puzzlePiece[j].index > puzzlePiece[i].index)
					inversion++;
			}
		}
		if (inversion % 2 == 0) break;
	}


	puzzlePiece[9].rc = RectMake(WINSIZE_X / 3 * 2, WINSIZE_Y / 4 * 3, WINSIZE_X / 3, WINSIZE_Y / 4);
	puzzlePiece[9].index = 9;

	GameEnd = false;
	_alphaA = 0;

	return S_OK;
}

void SlidePuzzleGame::release(void)
{
	GameNode::release();
	SAFE_DELETE(_puzzleImage);
	SAFE_DELETE(_answerImage);
}

void SlidePuzzleGame::update(void)
{
	GameNode::update();
	if(!GameEnd)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			int pos;
			for (int i = 0; i < 10; i++)
			{
				if (puzzlePiece[i].index == 9) pos = i;
			}
			if (pos == 9)
			{
				PuzzlePiece temp;
				temp.index = puzzlePiece[pos].index;
				puzzlePiece[pos].index = puzzlePiece[pos - 1].index;
				puzzlePiece[pos - 1].index = temp.index;
			}
			else if (pos >= 3)
			{
				PuzzlePiece temp;
				temp.index = puzzlePiece[pos].index;
				puzzlePiece[pos].index = puzzlePiece[pos - 3].index;
				puzzlePiece[pos - 3].index = temp.index;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			int pos;
			for (int i = 0; i < 10; i++)
			{
				if (puzzlePiece[i].index == 9) pos = i;
			}
			if (pos == 8)
			{
				PuzzlePiece temp;
				temp.index = puzzlePiece[pos].index;
				puzzlePiece[pos].index = puzzlePiece[pos + 1].index;
				puzzlePiece[pos + 1].index = temp.index;
			}
			else if (pos != 9 && pos / 3 != 2)
			{
				PuzzlePiece temp;
				temp.index = puzzlePiece[pos].index;
				puzzlePiece[pos].index = puzzlePiece[pos + 3].index;
				puzzlePiece[pos + 3].index = temp.index;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			int pos;
			for (int i = 0; i < 10; i++)
			{
				if (puzzlePiece[i].index == 9) pos = i;
			}
			if (pos % 3 != 2 && pos != 9)
			{
				PuzzlePiece temp;
				temp.index = puzzlePiece[pos].index;
				puzzlePiece[pos].index = puzzlePiece[pos + 1].index;
				puzzlePiece[pos + 1].index = temp.index;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			int pos;
			for (int i = 0; i < 10; i++)
			{
				if (puzzlePiece[i].index == 9) pos = i;
			}
			if (pos % 3 != 0 && pos != 9)
			{
				PuzzlePiece temp;
				temp.index = puzzlePiece[pos].index;
				puzzlePiece[pos].index = puzzlePiece[pos - 1].index;
				puzzlePiece[pos - 1].index = temp.index;
			}
		}

		GameEnd = true;
		for (int i = 0; i < 10; i++)
		{
			if (puzzlePiece[i].index != i) GameEnd = false;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_F1))
		{
			for (int i = 0; i < 8; i++)
			{
				puzzlePiece[i].index = i;
			}
			puzzlePiece[8].index = 9;
			puzzlePiece[9].index = 8;
		}
	}
	else
	{
		if (_alphaA < 255) _alphaA++;
	}
}

void SlidePuzzleGame::render(HDC hdc)
{
    HDC memDC = this->getBackBuffer()->getMemDC();
    PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	if (!GameEnd)
	{
		for (int i = 0; i < 10; i++)
		{
			if (puzzlePiece[i].index != 9) _puzzleImage->render(memDC, puzzlePiece[i].rc.left, puzzlePiece[i].rc.top, puzzlePiece[puzzlePiece[i].index].rc.left, puzzlePiece[puzzlePiece[i].index].rc.top, WINSIZE_X / 3, WINSIZE_Y / 4);
			else DrawRectMake(memDC, puzzlePiece[i].rc);
		}
	}
	else _puzzleImage->alphaRender(memDC, _alphaA);

	_answerImage->render(memDC, 10, WINSIZE_Y / 4 * 3 + 10);
	//StretchBlt(memDC, 10, WINSIZE_Y / 4 * 3 + 10, WINSIZE_X / 3 - 20, WINSIZE_Y / 4 - 20, _puzzleImage->getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y / 4 * 3, SRCCOPY);

    this->getBackBuffer()->render(hdc, 0, 0);
}