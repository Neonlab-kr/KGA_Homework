#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int startNum, currentNum, count;
	cout << "-10 ~ 10 ������ ���� �ϳ��� �Է��ϼ���(�̿��� ��� �����)" << endl;
	cin >> startNum;

	currentNum = startNum;
	count = 0;
	while (-10 <= startNum && startNum <= 10 && currentNum >= -15)
	{
		count++;
		currentNum -= 5;
		cout << "���� �ݺ� Ƚ�� : "<< count << " ���� �� : " << startNum << " num �� : " << currentNum << endl;
	}
	cout << "while�� �����" << endl;
}