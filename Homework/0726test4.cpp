#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int num;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> num;

	int exponent = 0, divider = 1;
	while (num >= divider)
	{
		divider *= 2;
		exponent++;
	}

	cout << "�Է��� ������ 2���� ǥ�� : ";
	for (int i = exponent-1; i >= 0; i--) {
		int lastBit = num >> i & 1;
		cout << lastBit;
	}
}