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

class slidePuzzleGame
{
private:
	const int width;
	const int height;
	int** puzzleBoard;
	int x, y;

	void initPuzzleBoard();
	void findAsterisk();
	void printPuzzleBoard();
	Direction getInput();
	void swapSlide(Direction dir);
	bool isComplete();

public:
	slidePuzzleGame(const int width, const int height) :width(width), height(height)
	{
		puzzleBoard = new int* [height];
		for (int i = 0; i < height; i++)
		{
			puzzleBoard[i] = new int[width];
		}
		initPuzzleBoard();

		findAsterisk();
	}

	~slidePuzzleGame()
	{
		for (int i = 0; i < height; i++)
		{
			delete puzzleBoard[i];
			puzzleBoard[i] = nullptr;
		}
		delete puzzleBoard;
		puzzleBoard = nullptr;
	}
	void gameStart();
};

void main()
{
	slidePuzzleGame* game = new slidePuzzleGame(5,5);
	game->gameStart();
	delete game;
	game = nullptr;
}

void slidePuzzleGame::initPuzzleBoard()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, width * height - 1);

	int* numbers = new int[width * height];

	for (int i = 0; i < width * height - 1; i++)
	{
		numbers[i] = i + 1;
	}
	numbers[width * height - 1] = -1;

	for (int i = 0; i < width * height; i++)
	{
		int sour, temp;
		sour = dist(gen);

		//swap
		temp = numbers[i];
		numbers[i] = numbers[sour];
		numbers[sour] = temp;
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			puzzleBoard[i][j] = numbers[i * width + j];
		}
	}
	delete[] numbers;
	numbers = nullptr;
}

void slidePuzzleGame::findAsterisk()
{
	for (y = 0; y < height; y += 1)
	{
		for (x = 0; x < width; x += 1)
		{
			if (puzzleBoard[y][x] == -1) return;
		}
	}
}

void slidePuzzleGame::printPuzzleBoard()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
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

Direction slidePuzzleGame::getInput()
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

void slidePuzzleGame::swapSlide(Direction dir)
{
	switch (dir)
	{
	case UP:
		if (y == 0) break;
		puzzleBoard[y][x] = puzzleBoard[y - 1][x];
		puzzleBoard[y - 1][x] = -1;
		y--;
		break;

	case DOWN:
		if (y == (height - 1)) break;
		puzzleBoard[y][x] = puzzleBoard[y + 1][x];
		puzzleBoard[y + 1][x] = -1;
		y++;
		break;

	case RIGHT:
		if (x == (width - 1)) break;
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

bool slidePuzzleGame::isComplete()
{
	bool result1 = true, result2 = true;

	//별표가 마지막칸인 경우
	for (int i = 0; i < height-1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (puzzleBoard[i][j] != i * width + j + 1) result1 = false;
		}
	}
	for (int i = 0; i < width-1; i++)
	{
		if (puzzleBoard[height - 1][i] != width * (height - 1) + i + 1) result1 = false;
	}

	//별표가 첫칸인 경우
	for (int i = 1; i < width; i++)
	{
		if (puzzleBoard[0][i] != i) result2 = false;
	}
	for (int i = 1; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (puzzleBoard[i][j] != i * width + j) result2 = false;
		}
	}

	return (result1 || result2);
}

void slidePuzzleGame::gameStart()
{
	while (true)
	{
		system("cls");

		printPuzzleBoard();

		if (isComplete()) break;

		swapSlide(getInput());
	}
	cout << "\"ㅊㅋㅊㅋ 님 성공함\"" << endl;
}
