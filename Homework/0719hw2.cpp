#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int month;
	for (int i = 0; i < 5; i++)
	{
		cout << "일 수를 확인하고 싶은 달을 입력하세요(1 ~ 12) : ";
		cin >> month;

		switch (month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			cout << month <<"월은 31일까지 있습니다." << endl;
			break;

		case 2:
			cout << month << "월은 28일까지 있습니다." << endl;
			break;

		case 4: case 6: case 9: case 11:
			cout << month << "월은 30일까지 있습니다." << endl;
			break;

		default:
			cout << "잘못된 달 입력" << endl;
			break;
		}
	}
}