#pragma once
#include "GImage.h"//������ �����°� ����(�̹��� �Ŵ��� ��)

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