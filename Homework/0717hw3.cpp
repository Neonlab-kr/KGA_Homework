#include <iostream>
#include <time.h>

using std::cout;
using std::endl;

void RandomNumber(int min, int max)
{
	//������ ���� ���� ���� ����
	int randomNumber;

	//���� �õ�
	srand(time(NULL));

	//�������� ������ ���� �Ҵ�
	randomNumber = rand() % (max - min + 1) + min;

	//���
	cout << min << " ~ " << max << "������ ���� ���� : " << randomNumber << endl;
}


void main()
{
	RandomNumber(1, 5);
	RandomNumber(6, 19);
	RandomNumber(23, 189);
}

