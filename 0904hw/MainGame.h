#pragma once
#include "GameNode.h"

class MainGame : public GameNode
{
private:
	//����ȭ�� ��� �̷� ��ü�� ó���� ���� �ȵ�. 
	//�Ŵ��� ��ü�� ��� ó����
	GImage* _bgImage;
	GImage* _plImage;

	RECT _rc;

	int _countA, _countB;
	int _alphaA, _alphaB;

	bool _isAlphaIncrese;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	MainGame() {}
	~MainGame() {}
};

