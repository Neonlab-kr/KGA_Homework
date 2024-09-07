/*
과제3. 회오리 총알 구현

- 클라이언트 중점에서 바깥쪽으로 360도 회전을 하며 발사하는 총알을 구현할것.

- 자료구조 사용

- 양식 자유
*/

#pragma once
#include "GameNode.h"

class WhirlwindBulletGame : public GameNode
{
private:
	const int speed = 2;
	const int radius = 50;
	const int spawnCycle = 1;

	struct Circle
	{
		double cx, cy;
		double angle;
	};
	list<Circle> circleList;

	double angle;
	int time;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	WhirlwindBulletGame() {}
	~WhirlwindBulletGame() {}
};