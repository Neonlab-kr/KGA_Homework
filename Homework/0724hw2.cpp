#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int num, sum = 0;
	cout << "���� ������ �Է��ϼ��� : ";
	cin >> num;

	while (num != 0)
	{
		sum += num % 10;
		num = num / 10;
	}

	cout << "�� �ڸ����� ���� " << sum << "�Դϴ�." << endl;
}