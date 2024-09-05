#pragma once
#include "GImage.h"

class CScene abstract
{
public:
	enum SCENE_TYPE
	{
		START = 0, MAIN, END
	};

	virtual HRESULT init(void) = 0;
	virtual void release(void) = 0;
	virtual void update(void) = 0;
	virtual void render(HDC hdc) = 0;

	CScene() {}
	virtual ~CScene() {}
};

