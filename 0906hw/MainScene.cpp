#include "Stdafx.h"
#include "MainScene.h"

HRESULT MainScene::init(void)
{
    _bgImage = new GImage();
    _bgImage->init("Resource/Images/BackGround/BG.bmp", WINSIZE_X, WINSIZE_Y);

    _wallRc = RectMake(WINSIZE_X / 5 * 4, WINSIZE_Y / 3 - floor, WINSIZE_X / 5, WINSIZE_Y / 3 * 2);
    _wallImage = new GImage();
    _wallImage->init("Resource/Images/Object/Wall.bmp", _wallRc.right - _wallRc.left, _wallRc.bottom - _wallRc.top);

    _paddleImage = new GImage();
    _paddleImage->init("Resource/Images/Object/AirPaddle.bmp", 268*3, 40*3, 4, 1, true, RGB(255, 0, 255));

    _awaitImage = new GImage();
    _awaitImage->init("Resource/Images/Character/Await.bmp", WINSIZE_X / 2.78, WINSIZE_Y - floor - 41 * 5 + 10, 204 * 5, 82 * 5, 6, 2, true, RGB(255, 0, 255));
    _moveImage = new GImage();
    _moveImage->init("Resource/Images/Character/Move.bmp", WINSIZE_X / 2.78, WINSIZE_Y - floor - 39 * 5 + 10, 369 * 5, 78 * 5, 9, 2, true, RGB(255, 0, 255));
    _inAirUpImage = new GImage();
    _inAirUpImage->init("Resource/Images/Character/InAirUp.bmp", WINSIZE_X / 2.78, WINSIZE_Y - floor - 46 * 5 + 10, 128 * 5, 92 * 5, 4, 2, true, RGB(255, 0, 255));
    _inAirDownImage = new GImage();
    _inAirDownImage->init("Resource/Images/Character/InAirDown.bmp", WINSIZE_X / 2.78, WINSIZE_Y - floor - 47 * 5 + 10, 132 * 5, 94 * 5, 4, 2, true, RGB(255, 0, 255));
    _onWallImage = new GImage();
    _onWallImage->init("Resource/Images/Character/OnWall.bmp", WINSIZE_X / 2.78, WINSIZE_Y - floor - 41 * 5 + 10, 132 * 5, 82 * 5, 4, 2, true, RGB(255, 0, 255));

    for (int i = 0; i < sizeof(_paddleRc) / sizeof(_paddleRc[0]); i++)
    {
        _paddleRc[i] = RectMake(WINSIZE_X / 8, WINSIZE_Y - floor - 150 * (i + 1), 193, 60);
    }

    _plImage = _awaitImage;

    _isLeft = false;
    _playerPosX = 0;
    _playerPosY = 0;

    return S_OK;
}

void MainScene::release(void)
{
    SAFE_DELETE(_bgImage);
    SAFE_DELETE(_wallImage);
    SAFE_DELETE(_paddleImage);
    SAFE_DELETE(_awaitImage);
    SAFE_DELETE(_moveImage);
    SAFE_DELETE(_inAirUpImage);
    SAFE_DELETE(_inAirDownImage);
    SAFE_DELETE(_onWallImage);
}

void MainScene::update(void)
{
    applyPlayerInput();

    handleCharacterCollision();

    updateCharacterImage();

    updateAnimationFrame();
}

void MainScene::render(HDC hdc)
{
    PatBlt(hdc, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    _bgImage->render(hdc, 0, 0);

    _wallImage->render(hdc, _wallRc.left, _wallRc.top);

    for (int i = 0; i < sizeof(_paddleRc) / sizeof(_paddleRc[0]); i++)
    {
        _paddleImage->frameRender(hdc, _paddleRc[i].left - 2, _paddleRc[i].top);
    }
    _plImage->frameRender(hdc, _plImage->getX() + _playerPosX, _plImage->getY() - _playerPosY);


    GImage _minimap;
    _minimap.init(WINSIZE_X/4, WINSIZE_Y/4);
    HDC memDC = _minimap.getMemDC();
    StretchBlt(memDC, 10, 10, WINSIZE_X / 4-20, WINSIZE_Y / 4-20, hdc, 0, 0, WINSIZE_X, WINSIZE_Y, SRCCOPY);
    _minimap.alphaRender(hdc, 0, 0, 175);
    _minimap.release();

    if (KEYMANAGER->isToggleKey(VK_F1)) debugMode(hdc);
}

void MainScene::applyPlayerInput()
{
    _isMoving = false;
    if ((KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_LEFT)));
    else
    {
        if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !_onWall)
        {
            _isMoving = true;
            _isLeft = true;
            _playerPosX -= moveSpeed;
        }

        if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !_onWall)
        {
            _isMoving = true;
            _isLeft = false;
            _playerPosX += moveSpeed;
        }
    }

    if (KEYMANAGER->isStayKeyDown(VK_UP) && _onWall && _inAir)
    {
        _playerDy = moveSpeed/2;
    }

    if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _onWall)
    {
        _playerDy = -moveSpeed/2;
    }

    if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
    {
        if (_onWall)
        {
            _playerPosX -= moveSpeed * 2;
            _playerDy = jumpHeight;
        }
        else if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _onPaddle)
        {
            _playerDy = -5;
        }
        else if(!_inAir) _playerDy = jumpHeight;
    }

    _playerPosY += _playerDy;
}

void MainScene::handleCharacterCollision()
{
    RECT playerBB = _plImage->boundingBoxWithFrame();
    playerBB.left += _playerPosX;
    playerBB.right += _playerPosX;
    playerBB.top -= _playerPosY;
    playerBB.bottom -= _playerPosY;

    handleGroundCollision(playerBB);
    handleWallCollision(playerBB);
}

void MainScene::handleGroundCollision(RECT& playerBB)
{
    //바닥에 닿았는지 확인
    if (playerBB.bottom >= WINSIZE_Y - floor)
    {
        _playerPosY = 0;
        _playerDy = 0;
        _inAir = false;
        return;
    }

    //발판 밟았는지 확인
    for (int i = 0; i < 4; i++)
    {
        if (playerBB.right > _paddleRc[i].left && playerBB.left < _paddleRc[i].right && playerBB.bottom >= _paddleRc[i].top && playerBB.bottom < _paddleRc[i].top + 15 && _playerDy <= 0)
        {
            _playerPosY = WINSIZE_Y - _paddleRc[i].top - floor;
            _playerDy = 0;
            _inAir = false;
            _onPaddle = true;
            return;
        }
        else _onPaddle = false;
    }

    //벽 밟았는지 확인
    if (playerBB.right > _wallRc.left && playerBB.left < _wallRc.right && playerBB.bottom >= _wallRc.top && playerBB.bottom < _wallRc.top + 11 && _playerDy <= 0)
    {
        _playerPosY = WINSIZE_Y - _wallRc.top - floor;
        _playerDy = 0;
        _inAir = false;
        return;
    }   
    _inAir = true;
}

void MainScene::handleWallCollision(RECT& playerBB)
{
    //화면 왼쪽
    if (playerBB.left < 0) _playerPosX += 0 - playerBB.left;

    //화면 오른쪽
    if (playerBB.right > WINSIZE_X) _playerPosX += WINSIZE_X - playerBB.right;

    //벽 왼쪽
    _onWall = false;
    if (playerBB.right > _wallRc.left && playerBB.bottom > _wallRc.top + 10)
    {
        _playerPosX += _wallRc.left - playerBB.right + 10;

        //벽 타기
        if (playerBB.top > _wallRc.top && playerBB.bottom < _wallRc.bottom - 100)
        {
            _onWall = true;
            _playerDy = 0;
        }

        //매달리기
        else if (playerBB.top < _wallRc.top && playerBB.top > _wallRc.top - 50)
        {
            _playerPosX += 10;
            _inAir = false;
            _onWall = true;
            _playerDy = 0;
        }
    }

}

void MainScene::updateCharacterImage()
{
    if (_inAir)
    {
        if (_onWall)
        {
            _plImage = _onWallImage;
            _playerDy -= gravity/2;
        }
        else
        {
            if (_playerDy > 0) _plImage = _inAirUpImage;
            else _plImage = _inAirDownImage;
            _playerDy -= gravity;
        }
    }
    else
    {
        if (_onWall)
        {
            _plImage = _onWallImage;
        }
        else
        {
            if (_isMoving) _plImage = _moveImage;
            else _plImage = _awaitImage;
        }
    }
}

void MainScene::updateAnimationFrame()
{
    _time++;

    //캐릭터
    _plImage->setFrameY(_isLeft);
    if (_time % animationSpeed == 0)
    {
        if (_isLeft)
        {
            _playerIndex--;
        }
        else
        {
            _playerIndex++;
        }


        if (_playerIndex > _plImage->getMaxFrameX()) _playerIndex = 0;
        if (_playerIndex < 0) _playerIndex = _plImage->getMaxFrameX();

        _plImage->setFrameX(_playerIndex);
    }

    //발판
    if (_time % animationSpeed == 0)
    {
        _paddleIndex++;
        if (_paddleIndex == 4) _paddleIndex = 0;
        _paddleImage->setFrameX(_paddleIndex);
        _paddleImage->setFrameY(0);
    }
}

void MainScene::debugMode(HDC hdc)
{
    for (int i = 0; i < sizeof(_paddleRc) / sizeof(_paddleRc[0]); i++)
    {
        DrawRectMake(hdc, _paddleRc[i]);
    }

    DrawRectMake(hdc, _wallRc);

    RECT playerBB = _plImage->boundingBoxWithFrame();
    playerBB.left += _playerPosX;
    playerBB.right += _playerPosX;
    playerBB.top -= _playerPosY;
    playerBB.bottom -= _playerPosY;
    DrawRectMake(hdc, playerBB);

    char str[128];
    sprintf_s(str, "_playerPosX : %d, _playerPosY : %d", _playerPosX, _playerPosY);
    TextOut(hdc, 10, 10, str, strlen(str));

    sprintf_s(str, "_playerDy : %d", _playerDy);
    TextOut(hdc, 10, 30, str, strlen(str));

    if (_isLeft) sprintf_s(str, "_reverse : false");
    else sprintf_s(str, "_reverse : true");
    TextOut(hdc, 10, 50, str, strlen(str));

    if (_plImage == _awaitImage) sprintf_s(str, "_plImage : _awaitImage");
    if (_plImage == _inAirUpImage) sprintf_s(str, "_plImage : _inAirUpImage");
    if (_plImage == _inAirDownImage) sprintf_s(str, "_plImage : _inAirDownImage");
    if (_plImage == _onWallImage) sprintf_s(str, "_plImage : _onWallImage");
    if (_plImage == _moveImage) sprintf_s(str, "_plImage : _moveImage");
    TextOut(hdc, 10, 70, str, strlen(str));

    if (_inAir) sprintf_s(str, "_inAir : true");
    else sprintf_s(str, "_inAir : false");
    TextOut(hdc, 10, 90, str, strlen(str));

    if (_isMoving) sprintf_s(str, "_isMoving : true");
    else sprintf_s(str, "_isMoving : false");
    TextOut(hdc, 10, 110, str, strlen(str));

    if (_onWall) sprintf_s(str, "_onWall : true");
    else sprintf_s(str, "_onWall : false");
    TextOut(hdc, 10, 130, str, strlen(str));

    if (_onPaddle) sprintf_s(str, "_onPaddle : true");
    else sprintf_s(str, "_onPaddle : false");
    TextOut(hdc, 10, 150, str, strlen(str));
}
