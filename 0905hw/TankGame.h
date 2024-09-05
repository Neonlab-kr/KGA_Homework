#pragma once
#include "GameNode.h"

class TankGame : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _plImage;

	int _count;
	int _index;
	bool _isRight;
	bool _isMoving;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	TankGame() {}
	~TankGame() {}
};