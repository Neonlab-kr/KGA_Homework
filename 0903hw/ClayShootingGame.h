#pragma once
#include "GameNode.h"

class ClayShootingGame : public GameNode
{
private:
	enum ClayType
	{
		RECTANGLE = 0, CIRCLE, POLYGON, ENUM_END
	};
	struct Clay
	{
		ClayType type;
		RECT rc;
		int dx, dy;
		int angleCount;
		int randStartAngle;
		bool gotHit;
	};
	DWORD GameStartTime;
	DWORD GenerateTime;
	vector<Clay> clayVector;
	int score;

	GImage* _bgImage;
	GImage* _KingPigImage;
	GImage* _KingPigGotShotImage;
	GImage* _NormalPigImage;
	GImage* _NormalPigGotShotImage;
	GImage* _AngryBirdImage;
	GImage* _AngryBirdGotShotImage;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	void PolygonMake(HDC hdc, int x, int y, int width, int height, int angleCount, int randStartAngle);

	ClayShootingGame() {}
	~ClayShootingGame() {}
};

