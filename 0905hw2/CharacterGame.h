#pragma once
#include "GameNode.h"

class CharacterGame : public GameNode
{
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	CharacterGame() {}
	~CharacterGame() {}
};