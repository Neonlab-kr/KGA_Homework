#include <iostream>

using namespace std;


void* Function(int* a, int** b, int*** c)
{
	string** ansArray = new string *[3];
	for (int i = 0; i < 3; i++)
		ansArray[i] = new string[3];

	for (int player = 0; player < 3; player++)
	{
		for (int computer = 0; computer < 3; computer++)
		{
			if (computer == player) //���
			{
				ansArray[player][computer] = "�����ϴ�.";
			}
			else if ((player + 1) % 3 == computer) //��
			{
				ansArray[player][computer] = "�����ϴ�.";
			}
			else //�̱�
			{
				ansArray[player][computer] = "�̰���ϴ�.";
			}
		}
	}

	int computer, player;
	computer = rand() % 3;
	cout << "0. ���� 1. ���� 2. ��" << endl;
	cin >> player;

	cout << ansArray[player][computer] << endl;


	for (int i = 0; i < 3; i++)
		delete[] ansArray[i];

	delete[] ansArray;
	//���� �ۼ�
}

void main()
{
	// �̿ܿ� �ڵ尡 ������ �ȵȴ�.
	//Function(a, b, c);
}