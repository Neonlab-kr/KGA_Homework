#pragma once
#include "SingletonBase.h"
#include "StartScene.h"
#include "MainScene.h"

class SceneManager : public SingletonBase<SceneManager>
{
private:
	CScene* _currentScene;

public:
	HRESULT init(void);
	//여기부터
	void release(void);
	void update(void);
	void render(HDC hdc);
	//여기까지 제거하고 getCurrentScene추가 GameMain에서 처리

	void loadScene(CScene::SCENE_TYPE type);

	SceneManager() {}
	~SceneManager() {}
};