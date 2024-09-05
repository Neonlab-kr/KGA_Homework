#include "Stdafx.h"
#include "TankGame.h"
HRESULT TankGame::init(void)
{
    GameNode::init();

    _bgImage = new GImage();
    _bgImage->init("Resource/Images/BackGround/hw1/MetalSlugBG.bmp", WINSIZE_X, WINSIZE_Y);

    _plImage = new GImage();
    _plImage->init
    (
        "Resource/Images/Object/hw1/Tank.bmp",
        WINSIZE_X / 2 - 200,
        WINSIZE_Y - 350,
        840 * 3, 200 * 3,
        7, 2,
        true, RGB(255, 0, 255)
    );

    return S_OK;
}

void TankGame::release(void)
{
    GameNode::release();

    SAFE_DELETE(_bgImage);
    SAFE_DELETE(_plImage);
}

void TankGame::update(void)
{
    GameNode::update();

    _isMoving = false;
    if (KEYMANAGER->isStayKeyDown(VK_LEFT))
    {
        if (_isRight)
        {
            _index = 6 - _index;
            _plImage->setFrameX(_index);
        }
        _isRight = false;
        _isMoving = true;
        _plImage->setX(_plImage->getX() - 8.0f);
    }

    if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
    {
        if (!_isRight)
        {
            _index = 6 - _index;
            _plImage->setFrameX(_index);
        }
        _isRight = true;
        _isMoving = true;
        _plImage->setX(_plImage->getX() + 8.0f);
    }

    _count++;
    if (_isRight)
    {
        _plImage->setFrameY(1);
        if (_count % 3 == 0)
        {
            if(_isMoving)
            {
                if (_index > 0) _index--;
                else _index = 3;
            }
            else
            {
                if (_index < 6) _index++;
            }
            _plImage->setFrameX(_index);
        }
    }
    else
    {
        _plImage->setFrameY(0);
        if (_count % 3 == 0)
        {
            if (_isMoving)
            {
                if (_index < 6) _index++;
                else _index = 3;
            }
            else
            {
                if (_index > 0) _index--;
            }
            _plImage->setFrameX(_index);
        }
    }
}

void TankGame::render(HDC hdc)
{
    HDC memDC = this->getBackBuffer()->getMemDC();
    PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    _bgImage->render(memDC, 0, 0);
    _plImage->frameRender(memDC, _plImage->getX(), _plImage->getY());

    this->getBackBuffer()->render(hdc, 0, 0);
}