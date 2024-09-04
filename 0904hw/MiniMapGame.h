/*
����2. �̴ϸ� �����

- 2���� �������� ����� �ð�.
- 1. ȭ�鿡 ǥ�õǴ� GUI ������ ���� �̴ϸ�
- 2. ȭ������ �׷����� ������ ���� ��üȭ�� �̴ϸ�

- �÷��̾��� �������� �̴ϸʿ����� Ȯ���� �� �־�� �Ѵ�.
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