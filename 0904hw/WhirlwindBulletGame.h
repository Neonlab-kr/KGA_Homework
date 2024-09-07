/*
����3. ȸ���� �Ѿ� ����

- Ŭ���̾�Ʈ �������� �ٱ������� 360�� ȸ���� �ϸ� �߻��ϴ� �Ѿ��� �����Ұ�.

- �ڷᱸ�� ���

- ��� ����
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