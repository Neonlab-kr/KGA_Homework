#pragma once
#include "SingletonBase.h"
#include "MainScene.h"

class SceneManager : public SingletonBase<SceneManager>
{
private:
	CScene* _currentScene;

public:
	HRESULT init(void);
	//�������
	void release(void);
	void update(void);
	void render(HDC hdc);
	//������� �����ϰ� getCurrentScene�߰� MainGame���� ó��?

	void loadScene(CScene::SCENE_TYPE type);

	SceneManager() {}
	~SceneManager() {}
};