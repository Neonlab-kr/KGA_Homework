#include <iostream>

using std::cout;
using std::endl;

void main()
{
	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}

	cout << '\n';

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}

	cout << '\n';

	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < 5-i; j++)
		{
			cout << ' ';
		}
		for (int k = 0; k < i; k++)
		{
			cout << '*';
		}
		cout << '\n';
	}

	cout << '\n';

	for (int i = 5; i > 0; i--)
	{
		for (int k = 0; k < i - 1; k++)
		{
			cout << ' ';
		}
		for (int j = 0; j < 6 - i; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}

	cout << '\n';

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 0; j < 6 - i; j++) cout << ' ';
		for (int j = 0; j < 2*i; j++) cout << '*';
		cout << '\n';
	}
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < 12 - 2 * i; j++) cout << '*';
		cout << '\n';
	}

}