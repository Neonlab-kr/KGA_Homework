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
	struct Circle
	{
		double cx, cy;
		double angle;
	};
	list<Circle> circleList;

	double angle;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	WhirlwindBulletGame() {}
	~WhirlwindBulletGame() {}
};