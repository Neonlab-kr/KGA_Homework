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
			if (computer == player) //비김
			{
				ansArray[player][computer] = "비겼습니다.";
			}
			else if ((player + 1) % 3 == computer) //짐
			{
				ansArray[player][computer] = "졌습니다.";
			}
			else //이김
			{
				ansArray[player][computer] = "이겼습니다.";
			}
		}
	}

	int computer, player;
	computer = rand() % 3;
	cout << "0. 가위 1. 바위 2. 보" << endl;
	cin >> player;

	cout << ansArray[player][computer] << endl;


	for (int i = 0; i < 3; i++)
		delete[] ansArray[i];

	delete[] ansArray;
	//내용 작성
}

void main()
{
	// 이외에 코드가 있으면 안된다.
	//Function(a, b, c);
}