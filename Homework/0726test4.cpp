#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int num;
	cout << "숫자를 입력하세요 : ";
	cin >> num;

	int exponent = 0, divider = 1;
	while (num >= divider)
	{
		divider *= 2;
		exponent++;
	}

	cout << "입력한 숫자의 2진수 표현 : ";
	for (int i = exponent-1; i >= 0; i--) {
		int lastBit = num >> i & 1;
		cout << lastBit;
	}
}