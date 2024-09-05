#pragma once
#include "CScene.h"

class StartScene : public CScene
{
private:
	GImage* _bgImage;
	GImage* _TextImage;

	int count;
	bool showText;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	StartScene() {}
	~StartScene() {}
};