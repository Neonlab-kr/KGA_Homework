/*
����1. ĳ���� �����
- �̹��� �ʼ�(��� / �� / ĳ���� : ���, �̵�(�� / ��), ����(��� / �ϰ�), �� ��� ���)
(�ϸ�, �ް��� ���� ���Ұ�)
- �⺻������ ���� �������� ���� ���� �𼭸��� ��´�.
- ��, �� �߰��� �����ÿ��� õõ�� �������� ��������.
- ĳ���Ͱ� ���� ����ִ� ���¿��� �� �Ǵ� �Ʒ� ����Ű�� ������ �ö󰡰ų� ������ �� �־���Ѵ�.
- ĳ���ʹ� �� ���� �ö� ���� �ٽ� �Ʒ��� �����ϸ� ���� ���� ������ �� �վ���Ѵ�.

- ���� ĳ���� ���� ������ ������ �����ϰ� ĳ���ʹ� ���� �ؿ��� ������ ���� ���� �ö� �� ������ OK
- ������ �ö� ĳ���ʹ� �ٽ� �������� ������ �� ������ �ȴ�.

++
- ���� ������ ���� ������ �ο��� ���� ������ �̴ϸʰ� ������ ��ų ��
- �̴ϸʰ� ������ ���� �ο��� ī�޶�(�þ�)�� ������ �� ��
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

	//���� ĳ���� �̹����� ���� ������
	GImage* _plImage;

	//�̹���
	GImage* _bgImage;
	GImage* _wallImage;
	GImage* _paddleImage;
	GImage* _awaitImage;
	GImage* _moveImage;
	GImage* _inAirUpImage;
	GImage* _inAirDownImage;
	GImage* _onWallImage;

	//��, ����
	RECT _wallRc;
	RECT _paddleRc[4];

	//�÷��̾� ��ġ
	int _playerPosX;
	int _playerPosY;
	int _playerDy;

	//�ִϸ��̼ǿ�
	int _time;
	bool _isLeft;
	int _playerIndex;
	int _paddleIndex;

	//���� Ȯ�ο�
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