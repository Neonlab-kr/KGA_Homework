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

	cout << "배열에 저장된 데이터 ";
	for (int i = 0; i < 10; i++)
	{
		cout << myArray[i] << ' ';
	}
	cout << endl;

	cout << "짝수만 출력 : ";
	for (int i = 1; i < 10; i += 2)
	{
		cout << myArray[i] << ' ';
	}
}