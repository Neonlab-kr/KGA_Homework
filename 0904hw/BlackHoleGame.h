/*
����4. ��Ȧ ����

- ������ �����Ǵ� ������Ʈ ��ü

- �׸��� �ֺ� ������Ʈ�� ���Ƶ��̴� ��Ȧ�� �����Ұ�

- ������Ʈ�� ������ ��ġ�� �˱� ���� ����Ѵ�.
*/
#pragma once
#include "GameNode.h"
class BlackHoleGame : public GameNode
{
private:
	const int speed = 5;
	const int radius = 10;
	const int spawnCycle = 1;

	const int blackHoleRadius = 150;

	struct BULLET
	{
		float cx, cy;
		float angle;
		bool spawn;
		bool center;
	};

	list<BULLET> BulletList;
	int time;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	BlackHoleGame() {}
	~BlackHoleGame() {}
};
