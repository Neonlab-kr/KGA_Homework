#pragma once
#include "GameNode.h"

#define SQRT_MOLE_COUNT 3

const RECT pointPrintArea = { 0,0,120,23 };

class MoleCatchGame : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _hammerAwaitImage;
	GImage* _hammerActionImage;
	GImage* _EmptyHoleImage;
	GImage* _MolePopUpImage;
	GImage* _MoleGotHitImage;

	RECT moleHole[SQRT_MOLE_COUNT][SQRT_MOLE_COUNT];
	bitset<SQRT_MOLE_COUNT* SQRT_MOLE_COUNT> moleUp;
	bitset<SQRT_MOLE_COUNT* SQRT_MOLE_COUNT> moleOnceHit;
	DWORD upTime[SQRT_MOLE_COUNT* SQRT_MOLE_COUNT];
	RECT hammer;

	int score;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	MoleCatchGame() {}
	~MoleCatchGame() {}
};

