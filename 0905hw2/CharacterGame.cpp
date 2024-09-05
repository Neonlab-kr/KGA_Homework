#include "Stdafx.h"
#include "CharacterGame.h"

HRESULT CharacterGame::init(void)
{
    GameNode::init();
    SCENEMANAGER->init();
    return S_OK;
}

void CharacterGame::release(void)
{
    GameNode::release();
    SCENEMANAGER->release();
}

void CharacterGame::update(void)
{
    GameNode::update();
    SCENEMANAGER->update();
}

void CharacterGame::render(HDC hdc)
{
    HDC memDC = this->getBackBuffer()->getMemDC();
    SCENEMANAGER->render(memDC);
    this->getBackBuffer()->render(hdc, 0, 0);
}