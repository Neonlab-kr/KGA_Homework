#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int num1, num2, num3;

	cout << "���� a : �ΰ��� ������ �޾Ƽ� �� ���� ������ ������ ����� ����Ͻÿ�." << endl;
	cout << "ù��° ������ �Է��ϼ��� : " << endl;
	cin >> num1;
	
	cout << "�ι�° ������ �Է��ϼ��� : " << endl;
	cin >> num2;

	cout << "�� ���� ���� " << num1 + num2 << "�̰�, �� ���� ���� " << num1 - num2 << "�Դϴ�." << endl;

	cout << '\n';

	cout << "���� b : 3���� ������ �޾Ƽ� (num1 + num2) * (num3 + num1) % num1�� ����� ����Ͻÿ�." << endl;
	cout << "ù��° ������ �Է��ϼ��� : " << endl;
	cin >> num1;

	cout << "�ι�° ������ �Է��ϼ��� : " << endl;
	cin >> num2;

	cout << "����° ������ �Է��ϼ��� : " << endl;
	cin >> num3;

	cout << "���� ����� " << (num1 + num2) * (num3 + num1) % num1 << "�Դϴ�." << endl;

	cout << '\n';

	cout << "���� c : �Է� ���� �� ������ ���������� ��� �Ǵ� ��� �������� ����Ͻÿ�." << endl;

	cout << "ù��° ������ �Է��ϼ��� : " << endl;
	cin >> num1;

	cout << "�ι�° ������ �Է��ϼ��� : " << endl;
	cin >> num2;

	cout << "���� " << num1 / num2 << "�̰�, �������� " << num1 % num2 << "�Դϴ�." << endl;
}