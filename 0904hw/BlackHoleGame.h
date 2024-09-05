/*
과제4. 블랙홀 구현

- 무작위 생성되는 오브젝트 객체

- 그리고 주변 오브젝트를 빨아들이는 블랙홀을 구현할것

- 오브젝트는 생성된 위치를 알기 쉽게 출력한다.
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
