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

	//������ ���� ����
	initBingoBoard(bingoBoard);

	while (true)
	{
		printBingoBoard(bingoBoard);

		cout << '\n';

		int sel;
		cout << "���ڸ� �Է��ϼ��� : ";
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
		cout << "[���� ���� " << bingoCount << "�� �ϼ�]" << endl;
		if (bingoCount == 3)
		{
			cout << "�������� �� �¸�" << endl;
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

	//���� ���� Ȯ��
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

	//���� ���� Ȯ��
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

	//�밢�� ���� Ȯ��
	//������ ����
	check = true;
	for (int i = 0, j = 0; i < 5 ; i++, j++)
	{
		if (bingoBoard[i][j] != -1)
		{
			check = false;
		}
	}
	if (check) bingoCount++;

	//����� ����
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

