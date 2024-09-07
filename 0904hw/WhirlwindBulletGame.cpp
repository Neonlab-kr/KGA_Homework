#include "Stdafx.h"
#include "WhirlwindBulletGame.h"

HRESULT WhirlwindBulletGame::init(void)
{
    GameNode::init();
    angle = 0;
    time = 0;
    return S_OK;
}

void WhirlwindBulletGame::release(void)
{
    GameNode::release();
}

void WhirlwindBulletGame::update(void)
{
    GameNode::update();
    time++;

    //원 이동
    for (auto& i : circleList)
    {
        i.cx += speed * cos(i.angle * 3.141592 / 180.0);
        i.cy -= speed * sin(i.angle * 3.141592 / 180.0);
    }

    //화면 밖으로 나간 원 제거
    for (auto it = circleList.begin(); it != circleList.end();)
    {
        if (it->cx < -radius || it->cx > WINSIZE_X + radius || it->cy < -radius || it->cy > WINSIZE_Y + radius)
        {
            it = circleList.erase(it);
        }
        else
        {
            ++it;
        }
    }

    //원 생성
    if ((time >= spawnCycle))
    {
        angle += 25;
        Circle newCircle;
        newCircle.cx = WINSIZE_X / 2;
        newCircle.cy = WINSIZE_Y / 2;
        newCircle.angle = angle;
        circleList.push_back(newCircle);
        time = 0;
    }
    
    if (KEYMANAGER->isOnceKeyDown('R'))
    {
        angle = 0;
        time = 0;
        circleList.clear();
    }
}

void WhirlwindBulletGame::render(HDC hdc)
{
    char str[128];
    HDC memDC = this->getBackBuffer()->getMemDC();
    PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    for (auto& i : circleList)
    {
        EllipseMakeCenter(memDC, i.cx, i.cy, radius, radius);
    }

    this->getBackBuffer()->render(hdc, 0, 0);
}
