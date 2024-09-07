#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
    GameNode::init();
    SCENEMANAGER->init();
    return S_OK;
}

void MainGame::release(void)
{
    GameNode::release();
    SCENEMANAGER->release();
}

void MainGame::update(void)
{
    GameNode::update();
    SCENEMANAGER->update();
}

void MainGame::render(HDC hdc)
{
    HDC memDC = this->getBackBuffer()->getMemDC();
    SCENEMANAGER->render(memDC);
    this->getBackBuffer()->render(hdc, 0, 0);
}