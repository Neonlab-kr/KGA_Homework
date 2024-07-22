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
	cout << "가위바위보 게임을 시작합니다." << endl;
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

		cout << i << "번째 가위바위보 게임입니다." << endl;

		bet = moneyBet(money);
		player = selectedAnswer();

		money += gameJudge(computer, player, bet);
		cout << "현재 소지금 : " << money << endl;


		if (isbankruptcy(money))
		{
			cout << "파산하셨습니다." << endl;
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
		cout << "치트 : 가위" << endl;
		break;
	case 1:
		cout << "치트 : 바위 " << endl;
		break;
	default:
		cout << "치트 : 보" << endl;
		break;
	}
}

int moneyBet(int money)
{
	int bet;
	do
	{
		cout << "현재 소지금 : " << money << endl;
		cout << "베팅하실 금액을 입력하세요(최소 1000, 현재 소지금을 넘을 순 없음.) : ";
		cin >> bet;
	} while (bet < 1000 && bet > money);

	return bet;
}

int selectedAnswer()
{
	int player;

	do {
		cout << "0. 가위 1. 바위 2. 보" << endl;
		cout << "본인의 패를 결정하세요(잘못 입력시 재실행됩니다.) : ";
		cin >> player;
	} while (player > 2 && player < 0);

	return player;
}

int gameJudge(int computer, int player, int bet)
{
	int money = 0;
	if (computer == player)
	{
		cout << "비겼습니다." << endl;
		money += 5 * bet;
	}
	else if ((player + 1) % 3 == computer)
	{
		cout << "졌습니다." << endl;
		money -= 7 * bet;
	}
	else
	{
		cout << "이겼습니다." << endl;
		money += 3 * bet;
	}

	return money;
}

bool isbankruptcy(int money)
{
	return (money <= 0);
}
