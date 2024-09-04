/*
����1. �����̽� ����

- �ڷᱸ�� ���

- ġƮ �ʼ�
    1. 1���� ������ �����ϰ� �������� ����
    2. �÷��̾ ���� 1���� ���߸鼭 ����Ǵ� ����

- ȭ�� ���ʿ��� �������� ��� <-> ȭ�� �����ʿ��� 9��е� �̹��� ����Ұ�

- 9��е� �̹��� ���� �Ʒ� ������ ĭ�� ����ĭ

- ������ �ϼ��Ǹ� ���� ���� ȿ���� �̹����� �߾ӿ��� ��Ÿ���� ó���Ұ�.

- ���� �Ʒ��� �����̹��� �۰�
- ���� �Ʒ��� ������.
- 3 X 3�� ������ ���� �ϴ�.
*/

#pragma once
#include "GameNode.h"
class SlidePuzzleGame : public GameNode
{
private:
	struct PuzzlePiece
	{
		RECT rc;
		int index;
	};

	GImage* _puzzleImage;
	GImage* _answerImage;

	PuzzlePiece puzzlePiece[10];

	bool GameEnd;

	int _alphaA;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

    SlidePuzzleGame() {}
    ~SlidePuzzleGame() {}
};

