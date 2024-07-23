#include <iostream>

using std::cout;
using std::cin;

void main()
{
	int input;
	int gugudan[9];
	cout << "구구단 몇단을 출력할까요? : ";
	cin >> input;
	for (int i = 1; i < 10; i++)
	{
		gugudan[i - 1] = input * i;
		printf("%d * %d = %d\n", input, i, gugudan[i - 1]);
	}
}