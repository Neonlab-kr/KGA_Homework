#pragma once
#include "GImage.h"//패턴이 들어오는게 좋음(이미지 매니저 등)

class GameNode abstract
{
private:
	GImage* _backBuffer;
	void setBackBuffer();

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	GImage* getBackBuffer(void) { return _backBuffer; }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	GameNode() {};
	virtual ~GameNode() {}
};