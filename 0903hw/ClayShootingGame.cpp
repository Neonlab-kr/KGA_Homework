#include "Stdafx.h"
#include "ClayShootingGame.h"

HRESULT ClayShootingGame::init(void)
{
    GameNode::init();
    GameStartTime = GetTickCount();
    GenerateTime = GetTickCount() + 500;
    score = 0;

    _bgImage = new GImage();
    _bgImage->init("Resource/Images/BackGround/hw2/hw2BG.bmp", WINSIZE_X, WINSIZE_Y);
    _KingPigImage = new GImage();
    _KingPigImage->init("Resource/Images/Object/hw2/King_Pig.bmp", 100, 100, true, RGB(255, 0, 255));
    _KingPigGotShotImage = new GImage();
    _KingPigGotShotImage->init("Resource/Images/Object/hw2/King_Pig_GotShot.bmp", 100, 100, true, RGB(255, 0, 255));
    _NormalPigImage = new GImage();
    _NormalPigImage->init("Resource/Images/Object/hw2/Normal_Pig.bmp", 100, 100, true, RGB(255, 0, 255));
    _NormalPigGotShotImage = new GImage();
    _NormalPigGotShotImage->init("Resource/Images/Object/hw2/Normal_Pig_GotShot.bmp", 100, 100, true, RGB(255, 0, 255));
    _AngryBirdImage = new GImage();
    _AngryBirdImage->init("Resource/Images/Object/hw2/Angry_Bird.bmp", 100, 100, true, RGB(255, 0, 255));
    _AngryBirdGotShotImage = new GImage();
    _AngryBirdGotShotImage->init("Resource/Images/Object/hw2/Angry_Bird_GotShot.bmp", 100, 100, true, RGB(255, 0, 255));

    return S_OK;
}

void ClayShootingGame::release(void)
{
    GameNode::release();
    SAFE_DELETE(_bgImage);
    SAFE_DELETE(_KingPigImage);
    SAFE_DELETE(_KingPigGotShotImage);
    SAFE_DELETE(_NormalPigImage);
    SAFE_DELETE(_NormalPigGotShotImage);
    SAFE_DELETE(_AngryBirdImage);
    SAFE_DELETE(_AngryBirdGotShotImage);
}

void ClayShootingGame::update(void)
{
    GameNode::update();

    if (GameStartTime + 60000 < GetTickCount())
    {
        if (KEYMANAGER->isOnceKeyDown('R'))
        {
            GameStartTime = GetTickCount();
            GenerateTime = GetTickCount() + 500;
            score = 0;
        }
        clayVector.clear();
        return;
    }

    //클레이의 위치 갱신
    for (auto& i : clayVector)
    {
        i.rc.left += i.dx;
        i.rc.right += i.dx;
        i.rc.top -= i.dy;
        i.rc.bottom -= i.dy;
    }

    //화면 밖으로 나간 클레이 제거
    for (auto it = clayVector.begin(); it != clayVector.end();)
    {
        if (it->rc.right < -100 || it->rc.left > WINSIZE_X || it->rc.bottom < 0 || it->rc.top > WINSIZE_Y)
        {
            it = clayVector.erase(it);
        }
        else
        {
            ++it;
        }
    }

    //클레이 생성
    if (GetTickCount() >= GenerateTime)
    {
        //클레이 생성 위치 결정
        int spawnX, spawnY;

        if (RND->getInt(2))
        {
            spawnX = WINSIZE_X;
        }
        else
        {
            spawnX = -100;
        }
        spawnY = RND->getFromTo(WINSIZE_Y / 4, WINSIZE_Y / 2);

        //클레이 생성
        Clay newClay;

        newClay.type = (ClayType)RND->getInt(ENUM_END);

        newClay.rc = RectMake(spawnX, spawnY, 100, 100);

        newClay.dx = RND->getFromTo(3, 10);
        if (spawnX == WINSIZE_X) newClay.dx *= -1;

        newClay.dy = RND->getInt(4);

        if (newClay.type == POLYGON)
        {
            newClay.angleCount = RND->getFromTo(5, 10);
            newClay.randStartAngle = RND->getFromTo(0, 360);
        }

        newClay.gotHit = false;

        clayVector.push_back(newClay);
        GenerateTime = GetTickCount() + 500;
    }

    //피격 판정
    if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
    {
        for (auto& i : clayVector)
        {
            if (PtInRect(&i.rc,_ptMouse) && !i.gotHit)
            {
                i.gotHit = true;
                i.dx = 0;
                i.dy = -5;
                switch (i.type)
                {
                case RECTANGLE:
                    score += 50;
                    break;

                case CIRCLE:
                    score -= 100;
                    break;

                case POLYGON:
                    score += 100;
                    break;
                }
            }
        }
    }

}

void ClayShootingGame::render(HDC hdc)
{
    char strPT[128];

    HDC memDC = this->getBackBuffer()->getMemDC();

    PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

    if (GameStartTime + 60000 < GetTickCount())
    {
        wsprintf(strPT, "Your score: %d", score);
        TextOut(memDC, WINSIZE_X / 2, WINSIZE_Y / 2 - 10, strPT, strlen(strPT));
        TextOut(memDC, WINSIZE_X / 2, WINSIZE_Y / 2 + 10, "Press 'R' to Restart", strlen("Press 'R' to Restart"));
        this->getBackBuffer()->render(hdc, 0, 0);
        return;
    }

    _bgImage->render(memDC, 0, 0);

    for (auto& i : clayVector)
    {
        switch (i.type)
        {
        case RECTANGLE:
            //DrawRectMake(memDC, i.rc);
            if (i.gotHit) _NormalPigGotShotImage->render(memDC, i.rc.left, i.rc.top);
            else _NormalPigImage->render(memDC, i.rc.left, i.rc.top);
            break;

        case CIRCLE:
            //EllipseMake(memDC, i.rc.left, i.rc.top, i.rc.right - i.rc.left, i.rc.bottom - i.rc.top);
            if (i.gotHit) _AngryBirdGotShotImage->render(memDC, i.rc.left, i.rc.top);
            else _AngryBirdImage->render(memDC, i.rc.left, i.rc.top);
            break;

        case POLYGON:
            //PolygonMake(memDC, i.rc.left, i.rc.top, i.rc.right - i.rc.left, i.rc.bottom - i.rc.top, i.angleCount, i.randStartAngle);
            if (i.gotHit) _KingPigGotShotImage->render(memDC, i.rc.left, i.rc.top);
            else _KingPigImage->render(memDC, i.rc.left, i.rc.top);
            break;
        }
    }
    this->getBackBuffer()->render(hdc, 0, 0);

    wsprintf(strPT, "SCORE: %d", score);
    TextOut(hdc, 0, 0, strPT, strlen(strPT));
}

void ClayShootingGame::PolygonMake(HDC hdc, int x, int y, int width, int height, int angleCount, int randStartAngle)
{
    POINT* points = new POINT[angleCount * 2];

    int cx = x + width / 2;
    int cy = y + height / 2;
    int r = width / 2;
    int angInc = 360 / angleCount;

    for (int i = 0; i < angleCount; i++)
    {
        randStartAngle += angInc;
        LONG px = cx + r * cos(randStartAngle * 3.14 / 180.0);
        LONG py = cy + r * sin(randStartAngle * 3.14 / 180.0);

        points[i] = { px, py };
    }

    Polygon(hdc, points, angleCount);
    SAFE_DELETE_ARRAY(points);
}
