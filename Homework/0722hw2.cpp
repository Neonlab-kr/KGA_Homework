#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printWelcome();
void RCPGame(const int replay);
void printCheat(int computer);
int moneyBet(int money);
int selectedAnswer();
int gameJudge(int computer, int player, int bet);
bool isbankruptcy(int money);

void main()
{
	printWelcome();
	RCPGame(5);
}

void printWelcome()
{
	cout << "===========================" << endl;
	cout << "���������� ������ �����մϴ�." << endl;
	cout << "===========================" << endl;
}

void RCPGame(const int replay)
{
	int money = 10'000;
	for (int i = 1; i <= replay; i++)
	{
		srand(time(NULL));
		int player, computer, bet;
		computer = rand() % 3;

		printCheat(computer);

		cout << i << "��° ���������� �����Դϴ�." << endl;

		bet = moneyBet(money);
		player = selectedAnswer();

		money += gameJudge(computer, player, bet);
		cout << "���� ������ : " << money << endl;


		if (isbankruptcy(money))
		{
			cout << "�Ļ��ϼ̽��ϴ�." << endl;
			break;
		}

		cout << '\n';
	}
}

void printCheat(int computer)
{
	switch (computer)
	{
	case 0:
		cout << "ġƮ : ����" << endl;
		break;
	case 1:
		cout << "ġƮ : ���� " << endl;
		break;
	default:
		cout << "ġƮ : ��" << endl;
		break;
	}
}

int moneyBet(int money)
{
	int bet;
	do
	{
		cout << "���� ������ : " << money << endl;
		cout << "�����Ͻ� �ݾ��� �Է��ϼ���(�ּ� 1000, ���� �������� ���� �� ����.) : ";
		cin >> bet;
	} while (bet < 1000 && bet > money);

	return bet;
}

int selectedAnswer()
{
	int player;

	do {
		cout << "0. ���� 1. ���� 2. ��" << endl;
		cout << "������ �и� �����ϼ���(�߸� �Է½� �����˴ϴ�.) : ";
		cin >> player;
	} while (player > 2 && player < 0);

	return player;
}

int gameJudge(int computer, int player, int bet)
{
	int money = 0;
	if (computer == player)
	{
		cout << "�����ϴ�." << endl;
		money += 5 * bet;
	}
	else if ((player + 1) % 3 == computer)
	{
		cout << "�����ϴ�." << endl;
		money -= 7 * bet;
	}
	else
	{
		cout << "�̰���ϴ�." << endl;
		money += 3 * bet;
	}

	return money;
}

bool isbankruptcy(int money)
{
	return (money <= 0);
}
