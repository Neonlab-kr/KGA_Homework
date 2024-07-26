#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

void bingoGame();
void initBingoBoard(int bingoBoard[][5]);
void printBingoBoard(int bingoBoard[][5]);
int bingoCheck(int bingoBoard[][5]);

void main()
{
	bingoGame();
}

void bingoGame()
{
	int bingoBoard[5][5];

	//빙고판 랜덤 생성
	initBingoBoard(bingoBoard);

	while (true)
	{
		printBingoBoard(bingoBoard);

		cout << '\n';

		int sel;
		cout << "숫자를 입력하세요 : ";
		cin >> sel;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingoBoard[i][j] == sel)
				{
					bingoBoard[i][j] = -1;
				}
			}
		}

		cout << '\n';

		system("cls");

		int bingoCount = bingoCheck(bingoBoard);
		cout << "[현재 빙고 " << bingoCount << "줄 완성]" << endl;
		if (bingoCount == 3)
		{
			cout << "ㅊㅋㅊㅋ 님 승리" << endl;
			break;
		}

		cout << '\n';
	}
}

void initBingoBoard(int bingoBoard[][5])
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 24);

	int numbers[25];

	for (int i = 0; i < 25; i++)
	{
		numbers[i] = i + 1;
	}

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
			bingoBoard[i][j] = numbers[i * 5 + j];
		}
	}
}

void printBingoBoard(int bingoBoard[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (bingoBoard[i][j] > 0)
			{
				printf("%3d ", bingoBoard[i][j]);
			}
			else
			{
				printf("%3c ",'*');
			}
		}
		cout << '\n';
	}
}

int bingoCheck(int bingoBoard[][5])
{
	int bingoCount = 0;
	bool check;

	//가로 빙고 확인
	for (int i = 0; i < 5; i++)
	{
		check = true;
		for (int j = 0; j < 5; j++)
		{
			if (bingoBoard[i][j] != -1)
			{
				check = false;
			}
		}
		if (check)	bingoCount++;
	}

	//세로 빙고 확인
	for (int j = 0; j < 5; j++)
	{
		check = true;
		for (int i = 0; i < 5; i++)
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
	for (int i = 0, j = 0; i < 5 ; i++, j++)
	{
		if (bingoBoard[i][j] != -1)
		{
			check = false;
		}
	}
	if (check) bingoCount++;

	//우상향 빙고
	check = true;
	for (int i = 0, j = 4; i < 5; i++, j--)
	{
		if (bingoBoard[i][j] != -1)
		{
			check = false;
		}
	}
	if (check) bingoCount++;


	return bingoCount;
}

