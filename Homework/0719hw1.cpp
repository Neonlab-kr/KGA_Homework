#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	cout << "===========================" << endl;
	cout << "���������� ������ �����մϴ�." << endl;
	cout << "===========================" << endl;

	for (int i = 1; i <= 5; i++)
	{
		srand(time(NULL));
		int player, computer;
		computer = rand() % 3;

		if (computer == 0) cout << "ġƮ : ����" << endl;
		else if (computer == 1) cout << "ġƮ : ���� " << endl;
		else cout << "ġƮ : ��" << endl;

		cout << i << "��° ���������� �����Դϴ�." << endl;
		cout << "0. ���� 1. ���� 2. ��" << endl;
		cin >> player;


		if (player > 2 || player < 0)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		else if (computer == player)
		{
			cout << "�����ϴ�." << endl;
		}
		else if ((player + 1) % 3 == computer)
		{
			cout << "�����ϴ�." << endl;
		}
		else
		{
			cout << "�̰���ϴ�." << endl;
		}

		cout << '\n';
	}
}