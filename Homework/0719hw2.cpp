#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int month;
	for (int i = 0; i < 5; i++)
	{
		cout << "�� ���� Ȯ���ϰ� ���� ���� �Է��ϼ���(1 ~ 12) : ";
		cin >> month;

		switch (month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			cout << month <<"���� 31�ϱ��� �ֽ��ϴ�." << endl;
			break;

		case 2:
			cout << month << "���� 28�ϱ��� �ֽ��ϴ�." << endl;
			break;

		case 4: case 6: case 9: case 11:
			cout << month << "���� 30�ϱ��� �ֽ��ϴ�." << endl;
			break;

		default:
			cout << "�߸��� �� �Է�" << endl;
			break;
		}
	}
}