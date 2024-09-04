#include "Stdafx.h"
#include "WhirlwindBulletGame.h"

HRESULT WhirlwindBulletGame::init(void)
{
    GameNode::init();
    angle = 0;
    return S_OK;
}

void WhirlwindBulletGame::release(void)
{
    GameNode::release();
}

void WhirlwindBulletGame::update(void)
{
    GameNode::update();
    //�� �̵�
    for (auto& i : circleList)
    {
        i.cx += 3.0 * cos(i.angle * 3.14 / 180.0);
        i.cy -= 3.0 * sin(i.angle * 3.14 / 180.0);
    }

    //ȭ�� ������ ���� �� ����
    for (auto it = circleList.begin(); it != circleList.end();)
    {
        if (it->cx < -50 || it->cx > WINSIZE_X + 50 || it->cy < -50 || it->cy > WINSIZE_Y + 50)
        {
            it = circleList.erase(it);
        }
        else
        {
            ++it;
        }
    }

    //���� ����
    angle += 25;

    //�� ����
    Circle newCircle;
    newCircle.cx = WINSIZE_X / 2;
    newCircle.cy = WINSIZE_Y / 2;
    newCircle.angle = angle;
    circleList.push_back(newCircle);

}

void WhirlwindBulletGame::render(HDC hdc)
{
    HDC memDC = this->getBackBuffer()->getMemDC();
    PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    for (auto& i : circleList)
    {
        EllipseMakeCenter(memDC, i.cx, i.cy, 50, 50);
    }

    this->getBackBuffer()->render(hdc, 0, 0);
}
