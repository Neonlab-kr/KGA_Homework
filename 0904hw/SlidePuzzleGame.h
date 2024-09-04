/*
과제1. 슬라이스 게임

- 자료구조 사용

- 치트 필수
    1. 1개의 퍼즐을 제외하고 나머지는 정렬
    2. 플레이어가 남은 1개를 맞추면서 종료되는 버전

- 화면 왼쪽에는 원본사진 출력 <-> 화면 오른쪽에는 9등분된 이미지 출력할것

- 9등분된 이미지 제일 아래 오른쪽 칸이 시작칸

- 퍼즐이 완성되면 알파 블렌딩 효과로 이미지를 중앙에서 나타나게 처리할것.

- 왼쪽 아래는 원본이미지 작게
- 우측 아래가 시작점.
- 3 X 3과 시작점 우측 하단.
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

