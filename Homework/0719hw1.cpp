#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	cout << "===========================" << endl;
	cout << "가위바위보 게임을 시작합니다." << endl;
	cout << "===========================" << endl;

	for (int i = 1; i <= 5; i++)
	{
		srand(time(NULL));
		int player, computer;
		computer = rand() % 3;

		if (computer == 0) cout << "치트 : 가위" << endl;
		else if (computer == 1) cout << "치트 : 바위 " << endl;
		else cout << "치트 : 보" << endl;

		cout << i << "번째 가위바위보 게임입니다." << endl;
		cout << "0. 가위 1. 바위 2. 보" << endl;
		cin >> player;


		if (player > 2 || player < 0)
		{
			cout << "잘못된 입력입니다." << endl;
		}
		else if (computer == player)
		{
			cout << "비겼습니다." << endl;
		}
		else if ((player + 1) % 3 == computer)
		{
			cout << "졌습니다." << endl;
		}
		else
		{
			cout << "이겼습니다." << endl;
		}

		cout << '\n';
	}
}