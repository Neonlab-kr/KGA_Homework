#include "Stdafx.h"
#include "StartScene.h"

HRESULT StartScene::init(void)
{
    _bgImage = new GImage();
    _bgImage->init("Resource/Images/BackGround/StartBG.bmp", WINSIZE_X, WINSIZE_Y);

    _TextImage = new GImage();
    _TextImage->init("Resource/Images/Object/StartText.bmp", 1286, 146, true, RGB(255, 0, 255));

    count = 0;
    showText = false;
    return S_OK;
}

void StartScene::release(void)
{
    SAFE_DELETE(_bgImage);
    SAFE_DELETE(_TextImage);
}

void StartScene::update(void)
{
    count++;
    if (count > 30)
    {
        showText = !showText;
        count = 0;
    }

    if (KEYMANAGER->isOnceKeyDown('A')) SCENEMANAGER->loadScene(CScene::MAIN);
}

void StartScene::render(HDC hdc)
{
    PatBlt(hdc, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    _bgImage->render(hdc, 0, 0);

    if (showText)
    {
        _TextImage->render(hdc, WINSIZE_X / 6, WINSIZE_Y / 4 * 3);
    }
}
