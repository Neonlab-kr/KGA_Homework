#pragma once
#include "GImage.h"

class CScene abstract
{
public:
	enum SCENE_TYPE
	{
		MAIN = 0, END
	};

	virtual HRESULT init(void) = 0;
	virtual void release(void) = 0;
	virtual void update(void) = 0;
	virtual void render(HDC hdc) = 0;

	CScene() {}
	virtual ~CScene() {}
};

