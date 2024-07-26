#include <iostream>
#include <random>
#include <conio.h>

using std::cin;
using std::cout;
using std::endl;

enum Direction
{
	UP, DOWN, RIGHT, LEFT
};

void slidePuzzleGame();
void initPuzzleBoard(int puzzleBoard[][5]);
void findAsterisk(int puzzleBoard[][5], int& x, int& y);
void printPuzzleBoard(int puzzleBoard[][5]);
int puzzleCheck(int puzzleBoard[][5]);
Direction getInput();
void swapSlide(Direction dir, int puzzleBoard[][5], int& x, int& y);
bool isComplete(int puzzleBoard[][5]);

void main()
{
	slidePuzzleGame();
}

void slidePuzzleGame()
{
	int puzzleBoard[5][5];

	initPuzzleBoard(puzzleBoard);

	int x, y;
	findAsterisk(puzzleBoard,x,y);

	while (true)
	{
		system("cls");

		printPuzzleBoard(puzzleBoard);

		if (isComplete(puzzleBoard)) break;

		swapSlide(getInput(), puzzleBoard, x, y);
	}
	cout << "\"ㅊㅋㅊㅋ 님 성공함\"" << endl;
}

void initPuzzleBoard(int puzzleBoard[][5])
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 24);

	int numbers[25];

	for (int i = 0; i < 24; i++)
	{
		numbers[i] = i + 1;
	}
	numbers[24] = -1;

	for (int i = 0; i < 1000; i++)
	{
		int dest, sour, temp;
		dest = dist(gen);
		sour = dist(gen);

		//swap
		temp = numbers[dest];
		numbers[dest] = numbers[sour];
		numbers[sour] = temp;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			puzzleBoard[i][j] = numbers[i * 5 + j];
		}
	}
}

void findAsterisk(int puzzleBoard[][5], int& x, int& y)
{
	for (y = 0; y < 5; y+=1)
	{
		for (x = 0; x < 5; x+=1)
		{
			if (puzzleBoard[y][x] == -1) break;
		}
		if (puzzleBoard[y][x] == -1) break;
	}
}

void printPuzzleBoard(int puzzleBoard[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (puzzleBoard[i][j] > 0)
			{
				printf("%3d ", puzzleBoard[i][j]);
			}
			else
			{
				printf("%3c ", '*');
			}
		}
		cout << '\n';
	}
}

int puzzleCheck(int puzzleBoard[][5])
{
	return 0;
}

Direction getInput()
{
	int input;
	cout << "\n*의 이동 방향을 입력하세요(키보드 상하좌우)";
	while (true)
	{
		input = _getch();
		if (input == 224)
		{
			input = _getch();
			if (input == 72)
			{
				return UP;
			}
			else if (input == 80)
			{
				return DOWN;
			}
			else if (input == 77)
			{
				return RIGHT;
			}
			else if (input == 75)
			{
				return LEFT;
			}
		}
	}
}

void swapSlide(Direction dir, int puzzleBoard[][5],int& x, int& y)
{
	int temp;
	switch (dir)
	{
	case UP:
		if (y == 0) break;
		puzzleBoard[y][x] = puzzleBoard[y-1][x];
		puzzleBoard[y - 1][x] = -1;
		y--;
		break;

	case DOWN:
		if (y == 4) break;
		puzzleBoard[y][x] = puzzleBoard[y + 1][x];
		puzzleBoard[y + 1][x] = -1;
		y++;
		break;

	case RIGHT:
		if (x == 4) break;
		puzzleBoard[y][x] = puzzleBoard[y][x + 1];
		puzzleBoard[y][x + 1] = -1;
		x++;
		break;

	case LEFT:
		if (x == 0) break;
		puzzleBoard[y][x] = puzzleBoard[y][x - 1];
		puzzleBoard[y][x - 1] = -1;
		x--;
		break;

	default:
		break;
	}
}

bool isComplete(int puzzleBoard[][5])
{
	int result1 = true, result2 = true;

	//별표가 마지막칸인 경우
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(puzzleBoard[i][j] != i * 5 + j + 1) result1 = false;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (puzzleBoard[4][i] != 21 + i) result1 = false;
	}

	//별표가 첫칸인 경우
	for (int i = 1; i < 5; i++)
	{
		if (puzzleBoard[0][i] != i) result2 = false;
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (puzzleBoard[i][j] != i * 5 + j) result2 = false;
		}
	}

	return (result1 || result2);
}