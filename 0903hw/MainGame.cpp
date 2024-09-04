#include "Stdafx.h"
#include "MainGame.h"

// 관리자
HRESULT MainGame::init(void)
{
    GameNode::init();

    _bgImage = new GImage();
    _bgImage->init("Resource/Images/BackGround/EnderLiliesBG.bmp", WINSIZE_X, WINSIZE_Y);

    _plImage = new GImage();
    _plImage->init("Resource/Images/Object/Lily.bmp", 100 , 200 , true, RGB(255, 0, 255));
    
    _rc = RectMakeCenter(WINSIZE_X / 2 - 500, WINSIZE_Y / 2 + 200, 100, 200);

    ShowCursor(false);

    return S_OK;
}

void MainGame::release(void)
{
    GameNode::release();

    SAFE_DELETE(_bgImage);
    SAFE_DELETE(_plImage);
}

void MainGame::update(void)
{
    GameNode::update();

    if (KEYMANAGER->isStayKeyDown(VK_UP))
    {
        _rc.top -= 3;
        _rc.bottom -= 3;
    }

    if (KEYMANAGER->isStayKeyDown(VK_DOWN))
    {
        _rc.top += 3;
        _rc.bottom += 3;
    }

    if (KEYMANAGER->isStayKeyDown(VK_LEFT))
    {
        _rc.left -= 3;
        _rc.right -= 3;
    }

    if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
    {
        _rc.left += 3;
        _rc.right += 3;
    }

    //if (PtInRect())
    //{

    //}
    //if (IntersectRect())
    //{

    //}
}

void MainGame::render(HDC hdc)
{
    // 백버퍼 가져오기
    HDC memDC = this->getBackBuffer()->getMemDC();

    // 검은색 비트맵 (빈)
    PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
    //====================================================================

    _bgImage->render(memDC, 0, 0);

    if (KEYMANAGER->isToggleKey(VK_F1))
    {
        Rectangle(memDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
    }

    _plImage->render(memDC, _rc.left, _rc.top);

    //====================================================================
    this->getBackBuffer()->render(hdc, 0, 0);
}
