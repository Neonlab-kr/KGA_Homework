#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

void numberBaseball();

void main()
{
	const int gameCount = 3;
	for (int i = 0; i < gameCount; i++)
	{
		cout << "[3�� �� " << i + 1 << "��° �����Դϴ�.]" << endl;
		numberBaseball();
	}
	cout << "Game Over" << endl;
}

void numberBaseball()
{
	const int numberCount = 3; //���� �߱��� ������ ���� ����
	const int randMin = 1; //�ּ� ����
	const int randMax = 10; //�ִ� ����

	//���� ó��
	if (numberCount > (randMax - randMin + 1))
	{
		cout << "numberCount ���� ����" << endl;
		exit(EXIT_FAILURE);
	}

	int computerNumber[numberCount];
	int playerNumber[numberCount];


	//Computer Number Generate
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, randMax - randMin);

	int number[randMax - randMin + 1];

	for (int i = 0; i < randMax - randMin + 1; i++)
	{
		number[i] = randMin + i;
	}

	for (int i = 0; i < (randMax - randMin + 1) * (randMax - randMin + 1); i++)
	{
		int dest, sour, temp;
		dest = dist(gen);
		sour = dist(gen);

		//swap
		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	for (int i = 0; i < numberCount; i++)
	{
		computerNumber[i] = number[i];
	}

	//Cheat
	cout << "Cheat : ";
	for (int i = 0; i < numberCount; i++) cout << computerNumber[i] << ' ';
	cout << '\n';

	int ball, strike;
	do
	{
		ball = strike = 0;

		//Player Number Input
		for (int i = 0; i < numberCount; i++)
		{
			cout << i + 1 << "��° ���� �Է��ϼ��� :";
			cin >> playerNumber[i];
			if (playerNumber[i] > randMax || playerNumber[i] < randMin) i--;
		}

		//Compare
		for (int i = 0; i < numberCount; i++)
		{
			if (playerNumber[i] == computerNumber[i]) strike++;
			else
			{
				for (int j = 0; j < numberCount; j++)
				{
					if (playerNumber[i] == computerNumber[j]) ball++;
				}
			}
		}
		
		//Result
		if ((strike + ball) == 0)
		{
			cout << "OUT�Դϴ�.\n";
		}
		else
		{
			printf("%d strike %d ball�Դϴ�.\n", strike, ball);
		}
	} while (strike != numberCount);

	//GameEnd
	cout << "�����մϴ�. �����Դϴ�.\n";
}