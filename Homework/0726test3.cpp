#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int myArray[10];

	for (int i = 0; i < 10; i++)
	{
		myArray[i] = i + 1;
	}

	cout << "�迭�� ����� ������ ";
	for (int i = 0; i < 10; i++)
	{
		cout << myArray[i] << ' ';
	}
	cout << endl;

	cout << "¦���� ��� : ";
	for (int i = 1; i < 10; i += 2)
	{
		cout << myArray[i] << ' ';
	}
}