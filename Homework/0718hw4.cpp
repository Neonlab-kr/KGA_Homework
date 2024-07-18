#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int startNum, currentNum, count;
	cout << "-10 ~ 10 사이의 정수 하나를 입력하세요(이외의 경우 종료됨)" << endl;
	cin >> startNum;

	currentNum = startNum;
	count = 0;
	while (-10 <= startNum && startNum <= 10 && currentNum >= -15)
	{
		count++;
		currentNum -= 5;
		cout << "현재 반복 횟수 : "<< count << " 시작 값 : " << startNum << " num 값 : " << currentNum << endl;
	}
	cout << "while문 종료됨" << endl;
}