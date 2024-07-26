#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int num, sum = 0;
	cout << "양의 정수를 입력하세요 : ";
	cin >> num;

	while (num != 0)
	{
		sum += num % 10;
		num = num / 10;
	}

	cout << "각 자릿수의 합은 " << sum << "입니다." << endl;
}