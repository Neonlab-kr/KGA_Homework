/*
과제2. 미니맵 만들기

- 2가지 버전으로 만들어 올것.
- 1. 화면에 표시되는 GUI 형태의 작은 미니맵
- 2. 화면위에 그려지는 투명도를 가진 전체화면 미니맵

- 플레이어의 움직임을 미니맵에서도 확인할 수 있어야 한다.
*/
#pragma once
#include "GameNode.h"

class MiniMapGame : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _plImage;
	GImage* _MinimapBgImage;
	GImage* _MinimapPlImage;

	RECT _rc;
	RECT _overlayMinimapRc;
	RECT _MinimapRc;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	MiniMapGame() {}
	~MiniMapGame() {}
};