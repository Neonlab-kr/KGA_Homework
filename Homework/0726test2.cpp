#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int num1, num2, total = 0;
	cout << "�ΰ��� ������ �Է��ض� : ";
	cin >> num1 >> num2;

	if (num1 > num2)
	{
		int temp;
		temp = num1;
		num1 - num2;
		num2 - temp;
	}

	for (int i = num1; i <= num2; i++)
	{
		total += i;
	}

	cout << "��� ���� �� : " << total << endl;
}