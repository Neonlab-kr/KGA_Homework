//-for / while / do ~while을 모두 사용해 볼것
//- 1부터 20까지 출력하시오.→ 짝수만
//- 20에서 1까지 출력하시오.

#include <iostream>

using std::cout;
using std::endl;

void main()
{
	int i;


	cout << "1 ~ 20까지의 숫자중 짝수만 출력(for문)" << endl;
	for (i = 2; i <= 20; i+=2)
	{
		cout << i << ' ';
	}

	cout << '\n';
	cout << '\n';

	cout << "1 ~ 20까지의 숫자중 짝수만 출력(while문)" << endl;
	i = 2;
	while (i <= 20)
	{
		cout << i << ' ';
		i += 2;
	}

	cout << '\n';
	cout << '\n';

	cout << "1 ~ 20까지의 숫자중 짝수만 출력(do ~ while문)" << endl;
	i = 2;
	do
	{
		cout << i << ' ';
		i += 2;
	} while (i <= 20);

	cout << '\n';
	cout << '\n';

	cout << "20 ~ 1까지의 숫자를 출력(for문)" << endl;

	for (i = 20; i > 0; i--)
	{
		cout << i << ' ';
	}

	cout << '\n';
	cout << '\n';

	cout << "20 ~ 1까지의 숫자를 출력(while문)" << endl;
	i = 20;
	while (i > 0)
	{
		cout << i << ' ';
		i--;
	}

	cout << '\n';
	cout << '\n';

	cout << "20 ~ 1까지의 숫자를 출력(do ~ while문)" << endl;
	i = 20;
	do
	{
		cout << i << ' ';
		i--;
	} while (i > 0);

	cout << '\n';
	cout << '\n';
}