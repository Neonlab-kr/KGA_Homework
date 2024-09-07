#include "Stdafx.h"
#include "SceneManager.h"

HRESULT SceneManager::init(void)
{
    loadScene(CScene::SCENE_TYPE::MAIN);
    return S_OK;
}

void SceneManager::release(void)
{
    if (_currentScene)
    {
        _currentScene->release();
        SAFE_DELETE(_currentScene);
    }
}

void SceneManager::update(void)
{
    _currentScene->update();
}

void SceneManager::render(HDC hdc)
{
    _currentScene->render(hdc);
}

void SceneManager::loadScene(CScene::SCENE_TYPE type)
{
    if (_currentScene) this->release();
    switch (type)
    {
    case CScene::SCENE_TYPE::MAIN:
        _currentScene = new MainScene();
        break;
    }
    _currentScene->init();
}

//addScene