#pragma once
#include "CScene.h"

#define BUTTON_MAX 11

class MainScene : public CScene
{
private:
	const int animationSpeed = 4;

	GImage* _curImage;

	GImage* _bgImage;
	GImage* _awaitImage;
	GImage* _walkingLeftImage;
	GImage* _walkingRightImage;
	GImage* _StingRightImage;
	GImage* _StingLeftImage;
	GImage* _DiagonalStingImage;
	GImage* _ContinuousStingLeftImage;
	GImage* _ContinuousStingRightImage;
	GImage* _VictoryPoseImage;
	GImage* _SpinCircleImage;
	GImage* _SkillClimaxImage;

	int _count;
	int _index;
	bool reverse;
	int _alphaA;

	RECT button[BUTTON_MAX];
	char* buttonStr[BUTTON_MAX];
	int selButtonNum;

	RECT skillClimaxRc;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	MainScene() {}
	~MainScene() {}
};