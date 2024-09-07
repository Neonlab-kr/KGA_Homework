/*
과제1. 캐릭터 벽잡기
- 이미지 필수(배경 / 벽 / 캐릭터 : 대기, 이동(좌 / 우), 점프(상승 / 하강), 벽 잡는 모션)
(록맨, 메가맨 등이 편할것)
- 기본적으로 벽을 잡을때는 가장 위쪽 모서리를 잡는다.
- 단, 벽 중간을 잡을시에는 천천히 지면으로 내려간다.
- 캐릭터가 벽을 잡고있는 상태에서 위 또는 아래 방향키를 누르면 올라가거나 내려갈 수 있어야한다.
- 캐릭터는 벽 위로 올라선 다음 다시 아래로 점프하면 지면 위에 착지할 수 밌어야한다.

- 또한 캐릭터 점프 높이의 지형이 존재하고 캐릭터는 지형 밑에서 점프로 지형 위로 올라갈 수 있으면 OK
- 지형에 올라선 캐릭터는 다시 지면으로 내려올 수 있으면 된다.

++
- 위의 내용이 전부 구현된 인원은 이전 과제인 미니맵과 연동을 시킬 것
- 미니맵과 연동을 끝낸 인원은 카메라(시야)를 적용해 볼 것
*/
#pragma once
#include "CScene.h"

class MainScene : public CScene
{
private:
	const int floor = 70;
	const int animationSpeed = 5;
	const int moveSpeed = 12;
	const int jumpHeight = 30;
	const int gravity = 2;

	//현재 캐릭터 이미지를 위한 포인터
	GImage* _plImage;

	//이미지
	GImage* _bgImage;
	GImage* _wallImage;
	GImage* _paddleImage;
	GImage* _awaitImage;
	GImage* _moveImage;
	GImage* _inAirUpImage;
	GImage* _inAirDownImage;
	GImage* _onWallImage;

	//벽, 발판
	RECT _wallRc;
	RECT _paddleRc[4];

	//플레이어 위치
	int _playerPosX;
	int _playerPosY;
	int _playerDy;

	//애니메이션용
	int _time;
	bool _isLeft;
	int _playerIndex;
	int _paddleIndex;

	//상태 확인용
	bool _isMoving;
	bool _inAir;
	bool _onWall;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	MainScene() {}
	~MainScene() {}

private:
	void applyPlayerInput();
	void handleCharacterCollision();
	void handleGroundCollision(RECT& playerBB);
	void handleWallCollision(RECT& playerBB);
	void updateCharacterImage();
	void updateAnimationFrame();
	void debugMode(HDC hdc);
};