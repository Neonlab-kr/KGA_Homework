#include "Stdafx.h"
#include "MiniMapGame.h"

HRESULT MiniMapGame::init(void)
{
    GameNode::init();

    _bgImage = new GImage();
    _bgImage->init("Resource/Images/BackGround/hw2/LOLmap.bmp", WINSIZE_X / 4 * 3, WINSIZE_Y / 4 * 3);
    _plImage = new GImage();
    _plImage->init("Resource/Images/Object/hw2/Sona.bmp", WINSIZE_X / 16, WINSIZE_Y / 12, true, RGB(255, 0, 255));

    _MinimapBgImage = new GImage();
    _MinimapBgImage->init("Resource/Images/BackGround/hw2/LOLmap.bmp", WINSIZE_X / 4, WINSIZE_Y / 4);
    _MinimapPlImage = new GImage();
    _MinimapPlImage->init("Resource/Images/Object/hw2/Sona.bmp", WINSIZE_X / 48, WINSIZE_Y / 36, true, RGB(255, 0, 255));

    _rc = RectMakeCenter(WINSIZE_X / 8, WINSIZE_Y / 16 * 11, WINSIZE_X / 16, WINSIZE_Y / 12);
    _overlayMinimapRc = RectMakeCenter(WINSIZE_X / 4 * 3 + _rc.left / 3 + 15, _rc.top / 3 + 10, WINSIZE_X / 48, WINSIZE_Y / 36);
    _MinimapRc = RectMakeCenter(WINSIZE_X / 4 * 3 + _rc.left / 3 + 15, _rc.top / 3 + WINSIZE_Y / 4 +10, WINSIZE_X / 48, WINSIZE_Y / 36);

    return S_OK;
}

void MiniMapGame::release(void)
{
    GameNode::release();
    SAFE_DELETE(_bgImage);
    SAFE_DELETE(_plImage);
    SAFE_DELETE(_MinimapBgImage);
    SAFE_DELETE(_MinimapPlImage);
}

void MiniMapGame::update(void)
{
    GameNode::update();

    if (KEYMANAGER->isStayKeyDown(VK_UP))
    {
        _rc.top -= 3;
        _rc.bottom -= 3;
        _overlayMinimapRc.top -= 1;
        _overlayMinimapRc.bottom -= 1;
        _MinimapRc.top -= 1;
        _MinimapRc.bottom -= 1;
    }

    if (KEYMANAGER->isStayKeyDown(VK_DOWN))
    {
        _rc.top += 3;
        _rc.bottom += 3;
        _overlayMinimapRc.top += 1;
        _overlayMinimapRc.bottom += 1;
        _MinimapRc.top += 1;
        _MinimapRc.bottom += 1;
    }

    if (KEYMANAGER->isStayKeyDown(VK_LEFT))
    {
        _rc.left -= 3;
        _rc.right -= 3;
        _overlayMinimapRc.left -= 1;
        _overlayMinimapRc.right -= 1;
        _MinimapRc.left -= 1;
        _MinimapRc.right -= 1;
    }

    if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
    {
        _rc.left += 3;
        _rc.right += 3;
        _overlayMinimapRc.left += 1;
        _overlayMinimapRc.right += 1;
        _MinimapRc.left += 1;
        _MinimapRc.right += 1;
    }
}

void MiniMapGame::render(HDC hdc)
{
    HDC memDC = this->getBackBuffer()->getMemDC();
    PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    _bgImage->render(memDC, 0, 0);
    _MinimapBgImage->alphaRender(memDC, WINSIZE_X / 4 * 3, 0, 128);
    _MinimapBgImage->render(memDC, WINSIZE_X / 4 * 3, WINSIZE_Y / 4);

    _plImage->render(memDC, _rc.left, _rc.top);
    _MinimapPlImage->alphaRender(memDC, _overlayMinimapRc.left, _overlayMinimapRc.top, 128);
    _MinimapPlImage->render(memDC, _MinimapRc.left, _MinimapRc.top);

    this->getBackBuffer()->render(hdc, 0, 0);
}
