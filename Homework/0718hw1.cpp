#include <iostream>

using std::cout;
using std::endl;

void main()
{
	int i, j;

	for (i = 2; i < 10; i++)
	{
		for (j = 2; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << '\n';
	}

	cout << "\nfor ³¡\n" << endl;

	i = j = 2;
	while (i < 10)
	{
		while (j < 10)
		{
			cout << i << " * " << j << " = " << i * j << endl;
			j++;
		}
		j = 2;
		i++;
		cout << '\n';
	}

	cout << "\nwhile ³¡\n" << endl;

	i = j = 2;
	do
	{
		do
		{
			cout << i << " * " << j << " = " << i * j << endl;
			j++;

		} while (j < 10);
		j = 2;
		i++;
		cout << '\n';

	} while (i < 10);

	cout << "\ndo ~ while ³¡\n" << endl;
}