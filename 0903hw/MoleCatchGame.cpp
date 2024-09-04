#include "Stdafx.h"
#include "MoleCatchGame.h"

HRESULT MoleCatchGame::init(void)
{
	GameNode::init();

	for (int i = 0; i < SQRT_MOLE_COUNT; i++)
	{
		for (int j = 0; j < SQRT_MOLE_COUNT; j++)
		{
			moleHole[i][j] = RectMakeCenter(j * (WINSIZE_X / SQRT_MOLE_COUNT) + WINSIZE_X / SQRT_MOLE_COUNT / 2, i * (WINSIZE_Y / SQRT_MOLE_COUNT) + WINSIZE_Y / SQRT_MOLE_COUNT / 2, WINSIZE_X / SQRT_MOLE_COUNT / 2, WINSIZE_Y / SQRT_MOLE_COUNT / 4 * 3);
			upTime[i * SQRT_MOLE_COUNT + j] = GetTickCount() + RND->getFromTo(2000, 5000);
		}
	}

	hammer = RectMake(0, 0, 100, 150);
	moleUp.reset();
	moleOnceHit.reset();;
	score = 0;

	_bgImage = new GImage();
	_bgImage->init("Resource/Images/BackGround/hw1/hw1BG.bmp", WINSIZE_X, WINSIZE_Y);
	_hammerAwaitImage = new GImage();
	_hammerAwaitImage->init("Resource/Images/Object/hw1/Hammer_Await.bmp", 100, 150,true,RGB(255,0,255));
	_hammerActionImage = new GImage();
	_hammerActionImage->init("Resource/Images/Object/hw1/Hammer_Active.bmp", 130, 150, true, RGB(255, 0, 255));
	_EmptyHoleImage = new GImage();
	_EmptyHoleImage->init("Resource/Images/Object/hw1/Empty_Hole.bmp", WINSIZE_X / SQRT_MOLE_COUNT / 2, WINSIZE_Y / SQRT_MOLE_COUNT / 4 * 3, true, RGB(255, 0, 255));
	_MolePopUpImage = new GImage();
	_MolePopUpImage->init("Resource/Images/Object/hw1/Mole_PopUp.bmp", WINSIZE_X / SQRT_MOLE_COUNT / 2, WINSIZE_Y / SQRT_MOLE_COUNT / 4 * 3, true, RGB(255, 0, 255));
	_MoleGotHitImage = new GImage();
	_MoleGotHitImage->init("Resource/Images/Object/hw1/Mole_GotHit.bmp", WINSIZE_X / SQRT_MOLE_COUNT / 2, WINSIZE_Y / SQRT_MOLE_COUNT / 4 * 3, true, RGB(255, 0, 255));
	return S_OK;
}

void MoleCatchGame::release(void)
{
	GameNode::release();
	SAFE_DELETE(_hammerAwaitImage);
	SAFE_DELETE(_hammerActionImage);
	SAFE_DELETE(_EmptyHoleImage);
	SAFE_DELETE(_MolePopUpImage);
	SAFE_DELETE(_MolePopUpImage);
	SAFE_DELETE(_MoleGotHitImage);
}

void MoleCatchGame::update(void)
{
	GameNode::update();
	HDC hdc = GetDC(_hWnd);

	RECT temp;

	DWORD recentTime = GetTickCount();

	hammer = RectMakeCenter(_ptMouse.x, _ptMouse.y, 100, 150);

	for (int i = 0; i < SQRT_MOLE_COUNT; i++)
	{
		for (int j = 0; j < SQRT_MOLE_COUNT; j++)
		{
			//두더지 소환 시간이 지남
			if (upTime[i * SQRT_MOLE_COUNT + j] <= recentTime)
			{
				//두더지가 안올라와있으면
				if (!moleUp[i * SQRT_MOLE_COUNT + j])
				{
					//올라오게 하기
					moleUp.set(i * SQRT_MOLE_COUNT + j, true);
				}
				//두더지가 올라와있으면
				else
				{
					//내려감 처리
					if (upTime[i * SQRT_MOLE_COUNT + j] + 2000 <= recentTime)
					{
						moleUp.set(i * SQRT_MOLE_COUNT + j, false);
						moleOnceHit.set(i * SQRT_MOLE_COUNT + j, false);
						//다음소환 시간 결정
						upTime[i * SQRT_MOLE_COUNT + j] = recentTime + RND->getFromTo(3000, 8000);
					}
				}
			}
		}
	}

	//잡기 판정
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < SQRT_MOLE_COUNT; i++)
		{
			for (int j = 0; j < SQRT_MOLE_COUNT; j++)
			{
				if (moleUp[i * SQRT_MOLE_COUNT + j] && IntersectRect(&temp, &moleHole[i][j], &hammer) && !moleOnceHit[i * SQRT_MOLE_COUNT + j])
				{
					moleOnceHit.set(i * SQRT_MOLE_COUNT + j, true);
					upTime[i * SQRT_MOLE_COUNT + j] = recentTime - 1000;
					score++;
				}
			}
		}
	}
}

void MoleCatchGame::render(HDC hdc)
{
	char strPT[128];

	HDC memDC = this->getBackBuffer()->getMemDC();

	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	_bgImage->render(memDC, 0, 0);
	
	for (int i = 0; i < SQRT_MOLE_COUNT; i++)
	{
		for (int j = 0; j < SQRT_MOLE_COUNT; j++)
		{
			if (moleUp[i * SQRT_MOLE_COUNT + j])
			{
				if (moleOnceHit[i * SQRT_MOLE_COUNT + j])
				{
					_MoleGotHitImage->render(memDC, moleHole[i][j].left, moleHole[i][j].top);
				}
				else
				{
					_MolePopUpImage->render(memDC, moleHole[i][j].left, moleHole[i][j].top);
				}
			}
			else
			{
				_EmptyHoleImage->render(memDC, moleHole[i][j].left, moleHole[i][j].top);
			}
		}
	}

	if (KEYMANAGER->isStayKeyDown(MK_LBUTTON)) _hammerActionImage->render(memDC, hammer.left, hammer.top);
	else _hammerAwaitImage->render(memDC, hammer.left, hammer.top);

	this->getBackBuffer()->render(hdc, 0, 0);

	wsprintf(strPT, "SCORE: %d", score);
	TextOut(hdc, 0, 0, strPT, strlen(strPT));
}
