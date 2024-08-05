#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

class BingoGame
{
private:
	const int size;
	int** bingoBoard;
	void initBingoBoard();
	void printBingoBoard();
	int bingoCheck();

public:
	BingoGame(const int size) : size(size)
	{
		bingoBoard = new int* [size];
		for (int i = 0; i < size; i++)
		{
			bingoBoard[i] = new int[size];
		}
	}

	~BingoGame()
	{
		for (int i = 0; i < size; i++)
		{
			delete bingoBoard[i];
		}
		delete bingoBoard;
	}

	void startGame();
};

void main()
{
	BingoGame game(5);
	game.startGame();
}

void BingoGame::startGame()
{
	//빙고판 랜덤 생성
	initBingoBoard();

	while (true)
	{
		printBingoBoard();

		cout << '\n';

		int sel;
		cout << "숫자를 입력하세요 : ";
		cin >> sel;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (bingoBoard[i][j] == sel)
				{
					bingoBoard[i][j] = -1;
				}
			}
		}

		cout << '\n';

		system("cls");

		int bingoCount = bingoCheck();
		cout << "[현재 빙고 " << bingoCount << "줄 완성]" << endl;
		if (bingoCount == 3)
		{
			cout << "ㅊㅋㅊㅋ 님 승리" << endl;
			break;
		}

		cout << '\n';
	}
}

void BingoGame::initBingoBoard()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, size * size - 1);

	int* numbers = new int[size * size];

	for (int i = 0; i < size * size; i++)
	{
		numbers[i] = i + 1;
	}

	for (int i = 0; i < size * size; i++)
	{
		int sour, temp;
		sour = dist(gen);

		//swap
		temp = numbers[i];
		numbers[i] = numbers[sour];
		numbers[sour] = temp;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			bingoBoard[i][j] = numbers[i * size + j];
		}
	}
}

void BingoGame::printBingoBoard()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (bingoBoard[i][j] > 0)
			{
				printf("%3d ", bingoBoard[i][j]);
			}
			else
			{
				printf("%3c ", '*');
			}
		}
		cout << '\n';
	}
}

int BingoGame::bingoCheck()
{
	int bingoCount = 0;
	bool check;

	//가로 빙고 확인
	for (int i = 0; i < size; i++)
	{
		check = true;
		for (int j = 0; j < size; j++)
		{
			if (bingoBoard[i][j] != -1)
			{
				check = false;
			}
		}
		if (check)	bingoCount++;
	}

	//세로 빙고 확인
	for (int j = 0; j < size; j++)
	{
		check = true;
		for (int i = 0; i < size; i++)
		{
			if (bingoBoard[i][j] != -1)
			{
				check = false;
			}
		}
		if (check)	bingoCount++;
	}

	//대각선 빙고 확인
	//우하향 빙고
	check = true;
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (bingoBoard[i][j] != -1)
		{
			check = false;
		}
	}
	if (check) bingoCount++;

	//우상향 빙고
	check = true;
	for (int i = 0, j = size - 1; i < size; i++, j--)
	{
		if (bingoBoard[i][j] != -1)
		{
			check = false;
		}
	}
	if (check) bingoCount++;


	return bingoCount;
}

