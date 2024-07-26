#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void main()
{
	int a , b;
	int monthDays[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	string dayOfTheWeek[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int day = 0;

	cout << "월, 일을 입력해라 : ";
	cin >> a >> b;

	for (int i = 0; i < a - 1; i++)
	{
		day += monthDays[i];
	}

	day += b;

	cout << a << "월 " << b << "일은 " << dayOfTheWeek[(day - 1) % 7] << "입니다.";
}

