//-for / while / do ~while�� ��� ����� ����
//- 1���� 20���� ����Ͻÿ�.�� ¦����
//- 20���� 1���� ����Ͻÿ�.

#include <iostream>

using std::cout;
using std::endl;

void main()
{
	int i;


	cout << "1 ~ 20������ ������ ¦���� ���(for��)" << endl;
	for (i = 2; i <= 20; i+=2)
	{
		cout << i << ' ';
	}

	cout << '\n';
	cout << '\n';

	cout << "1 ~ 20������ ������ ¦���� ���(while��)" << endl;
	i = 2;
	while (i <= 20)
	{
		cout << i << ' ';
		i += 2;
	}

	cout << '\n';
	cout << '\n';

	cout << "1 ~ 20������ ������ ¦���� ���(do ~ while��)" << endl;
	i = 2;
	do
	{
		cout << i << ' ';
		i += 2;
	} while (i <= 20);

	cout << '\n';
	cout << '\n';

	cout << "20 ~ 1������ ���ڸ� ���(for��)" << endl;

	for (i = 20; i > 0; i--)
	{
		cout << i << ' ';
	}

	cout << '\n';
	cout << '\n';

	cout << "20 ~ 1������ ���ڸ� ���(while��)" << endl;
	i = 20;
	while (i > 0)
	{
		cout << i << ' ';
		i--;
	}

	cout << '\n';
	cout << '\n';

	cout << "20 ~ 1������ ���ڸ� ���(do ~ while��)" << endl;
	i = 20;
	do
	{
		cout << i << ' ';
		i--;
	} while (i > 0);

	cout << '\n';
	cout << '\n';
}