#include "Stdafx.h"
#include "MainScene.h"

HRESULT MainScene::init(void)
{
    _bgImage = new GImage();
    _bgImage->init("Resource/Images/BackGround/MainBG.bmp", WINSIZE_X, WINSIZE_Y);
    _awaitImage = new GImage();
    _awaitImage->init("Resource/Images/Object/Await.bmp", WINSIZE_X / 2.78, WINSIZE_Y / 2, 3600, 400, 9, 1, true, RGB(255, 0, 255));
    _walkingLeftImage = new GImage();
    _walkingLeftImage->init("Resource/Images/Object/WalkingLeft.bmp", WINSIZE_X / 2.78, WINSIZE_Y / 2, 4000, 400, 10, 1, true, RGB(255, 0, 255));
    _walkingRightImage = new GImage();
    _walkingRightImage->init("Resource/Images/Object/WalkingRight.bmp", WINSIZE_X / 2.78, WINSIZE_Y / 2, 4000, 400, 10, 1, true, RGB(255, 0, 255));
    _StingLeftImage = new GImage();
    _StingLeftImage->init("Resource/Images/Object/StingLeft.bmp", WINSIZE_X / 6.5, WINSIZE_Y / 2.1, 7200, 500, 9, 1, true, RGB(255, 0, 255));
    _StingRightImage = new GImage();
    _StingRightImage->init("Resource/Images/Object/StingRight.bmp", WINSIZE_X / 2.78, WINSIZE_Y / 2.1, 7200, 500, 9, 1, true, RGB(255, 0, 255));
    _DiagonalStingImage = new GImage();
    _DiagonalStingImage->init("Resource/Images/Object/DiagonalSting.bmp", WINSIZE_X / 4.2, WINSIZE_Y / 2.7, 5600, 600, 7, 1, true, RGB(255, 0, 255));
    _ContinuousStingLeftImage = new GImage();
    _ContinuousStingLeftImage->init("Resource/Images/Object/ContinuousStingLeft.bmp", WINSIZE_X / 9.5, WINSIZE_Y / 2, 9000, 450, 10, 1, true, RGB(255, 0, 255));
    _ContinuousStingRightImage = new GImage();
    _ContinuousStingRightImage->init("Resource/Images/Object/ContinuousStingRight.bmp", WINSIZE_X / 2.3, WINSIZE_Y / 2, 9000, 450, 10, 1, true, RGB(255, 0, 255));
    _SpinCircleImage = new GImage();
    _SpinCircleImage->init("Resource/Images/Object/SpinCircle.bmp", WINSIZE_X / 3.5, WINSIZE_Y / 5.5, 4550, 800, 7, 1, true, RGB(255, 0, 255));
    _VictoryPoseImage = new GImage();
    _VictoryPoseImage->init("Resource/Images/Object/VictoryPose.bmp", WINSIZE_X / 4.5, WINSIZE_Y / 2.2, 16100, 500, 23, 1, true, RGB(255, 0, 255));
    _SkillClimaxImage = new GImage();
    _SkillClimaxImage->init("Resource/Images/Object/SkillClimax.bmp", WINSIZE_Y / 1.5, WINSIZE_Y / 3, true, RGB(255, 0, 255));

    _curImage = _awaitImage;

    reverse = false;

    for (int i = 0; i < BUTTON_MAX; i++)
    {
        button[i] = RectMake(WINSIZE_X - 200, 60 * i + WINSIZE_Y / 4, 180, 50);
    }

    selButtonNum = 0;

    buttonStr[0] = "대기";
    buttonStr[1] = "이동(좌)";
    buttonStr[2] = "이동(우)";
    buttonStr[3] = "찌르기(좌)";
    buttonStr[4] = "찌르기(우)";
    buttonStr[5] = "대각선 찌르기";
    buttonStr[6] = "연속 찌르기(좌)";
    buttonStr[7] = "연속 찌르기(우)";
    buttonStr[8] = "원 돌리기";
    buttonStr[9] = "승리포즈";
    buttonStr[10] = "스킬 클라이막스 연출";

    skillClimaxRc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, WINSIZE_X, WINSIZE_Y / 3);
    _alphaA = 255;
	return S_OK;
}

void MainScene::release(void)
{
    SAFE_DELETE(_bgImage);
    SAFE_DELETE(_awaitImage);
    SAFE_DELETE(_walkingLeftImage);
    SAFE_DELETE(_walkingRightImage);
    SAFE_DELETE(_StingLeftImage);
    SAFE_DELETE(_StingRightImage);
    SAFE_DELETE(_DiagonalStingImage);
    SAFE_DELETE(_ContinuousStingLeftImage);
    SAFE_DELETE(_ContinuousStingRightImage);
    SAFE_DELETE(_SpinCircleImage);
    SAFE_DELETE(_VictoryPoseImage);
    SAFE_DELETE(_SkillClimaxImage);
}

void MainScene::update(void)
{

    if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON))
    {
        for (int i = 0; i < BUTTON_MAX; i++)
        {
            if (PtInRect(&button[i], _ptMouse))
            {
                _index = 0;
                selButtonNum = i;
            }
        }
    }

    if (_count++ >= animationSpeed)
    {
        switch (selButtonNum)
        {
        case 0:case 10:
            _curImage = _awaitImage;
            reverse = false;
            break;

        case 1:
            _curImage = _walkingLeftImage;
            reverse = false;
            break;

        case 2:
            _curImage = _walkingRightImage;
            reverse = false;
            break;

        case 3:
            _curImage = _StingLeftImage;
            reverse = false;
            break;

        case 4:
            _curImage = _StingRightImage;
            reverse = true;
            break;

        case 5:
            _curImage = _DiagonalStingImage;
            reverse = false;
            break;

        case 6:
            _curImage = _ContinuousStingLeftImage;
            reverse = false;
            break;

        case 7:
            _curImage = _ContinuousStingRightImage;
            reverse = true;
            break;

        case 8:
            _curImage = _SpinCircleImage;
            reverse = false;
            break;
            
        case 9:
            _curImage = _VictoryPoseImage;
            reverse = false;
            break;
        }

        if (reverse) _index--;
        else _index++;

        if (_index > _curImage->getMaxFrameX()) _index = 0;
        if (_index < 0) _index = _curImage->getMaxFrameX();

        _curImage->setFrameX(_index);
        _curImage->setFrameY(0);
        _count = 0;

    }

    if (selButtonNum == 10)
    {
        _alphaA-=2;
        if (_alphaA <= 30)
        {
            selButtonNum = 0;
            _alphaA = 255;
        }
    }
}

void MainScene::render(HDC hdc)
{
    PatBlt(hdc, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    _bgImage->render(hdc, 0, 0);
    for (int i = 0; i < BUTTON_MAX; i++)
    {
        DrawRectMake(hdc, button[i]);
    }
    EllipseMakeCenter(hdc, (button[selButtonNum].left + button[selButtonNum].right) / 2, (button[selButtonNum].top + button[selButtonNum].bottom) / 2, 50, 50);   
    for (int i = 0; i < BUTTON_MAX; i++)
    {
        TextOut(hdc, button[i].left + 5, (button[i].top + button[i].bottom) / 2 - 5, buttonStr[i], strlen(buttonStr[i]));
    }

    _curImage->frameRender(hdc, _curImage->getX(), _curImage->getY());
    
    if (selButtonNum == 10)
    {
        DrawRectMake(hdc, skillClimaxRc);
        _SkillClimaxImage->alphaRender(hdc, skillClimaxRc.right - WINSIZE_Y / 1.5, skillClimaxRc.top, _alphaA);
    }
}