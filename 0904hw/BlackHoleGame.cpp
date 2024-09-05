#include "Stdafx.h"
#include "BlackHoleGame.h"

HRESULT BlackHoleGame::init(void)
{
    GameNode::init();
    time = 0;
    ShowCursor(false);
    return S_OK;
}

void BlackHoleGame::release(void)
{
    GameNode::release();
}

void BlackHoleGame::update(void)
{
    GameNode::update();
    time++;

    //블랙홀 처리
    for (auto& i : BulletList)
    {
        int xDis = _ptMouse.x - i.cx;
        int yDis = _ptMouse.y - i.cy;
        if(!i.center)
        {
            i.angle = atan2(yDis, xDis);
        }

        if (xDis * xDis + yDis * yDis <= blackHoleRadius) i.center = true;
    }

    //원 이동
    for (auto& i : BulletList)
    {
        i.cx += speed * cos(i.angle);
        i.cy += speed * sin(i.angle);
    }

    //화면 밖으로 나간 원 제거
    for (auto it = BulletList.begin(); it != BulletList.end();)
    {
        if (it->cx < -radius || it->cx > WINSIZE_X + radius || it->cy < -radius || it->cy > WINSIZE_Y + radius)
        {
            it = BulletList.erase(it);
        }
        else
        {
            ++it;
        }
    }

    //원 생성
    if (time >= spawnCycle && BulletList.size() <= 100000)
    {
        BULLET newBullet;
        newBullet.cx = RND->getInt(WINSIZE_X);
        newBullet.cy = RND->getInt(WINSIZE_Y);
        newBullet.angle = atan2(_ptMouse.y - newBullet.cy, _ptMouse.x - newBullet.cx);
        newBullet.spawn = true;
        newBullet.center = false;
        BulletList.push_back(newBullet);
        time = 0;
    }

    if (KEYMANAGER->isOnceKeyDown('R'))
    {
        time = 0;
        BulletList.clear();
    }
}

void BlackHoleGame::render(HDC hdc)
{
    HDC memDC = this->getBackBuffer()->getMemDC();
    PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    EllipseMakeCenter(memDC, _ptMouse.x, _ptMouse.y, blackHoleRadius, blackHoleRadius);

    for (auto it = BulletList.begin(); it != BulletList.end();++it)
    {
        if (it->spawn)
        {
            EllipseMakeCenter(memDC, it->cx, it->cy, radius * 2, radius * 2);
            it->spawn = false;
        }
        else
        {
            EllipseMakeCenter(memDC, it->cx, it->cy, radius, radius);
        }
    }


    this->getBackBuffer()->render(hdc, 0, 0);
}
