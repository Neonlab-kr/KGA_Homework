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
	void release(void);
	void update(void);
	void render(HDC hdc);

	// 매니저는 map이 적용 되어야함.(TYPE을 key로 하고 Scene을 넣어두는 구조)
	// node가 깊은 곳에 있으니 상호 참조를 걸어서 살짝만 건져내서 구현한다거나,,,
	// 포인터는 iterator나 스마트 포인터를 사용하는게 좋다. 일반 포인터보다 더 안전해야함.
	// 현재는 확장성과 안정성 문제가 많음.
	void loadScene(CScene::SCENE_TYPE type);

	SceneManager() {}
	~SceneManager() {}
};