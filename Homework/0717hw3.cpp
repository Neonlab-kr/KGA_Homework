#include <iostream>
#include <time.h>

using std::cout;
using std::endl;

void RandomNumber(int min, int max)
{
	//랜덤한 값을 담을 변수 선언
	int randomNumber;

	//랜덤 시드
	srand(time(NULL));

	//랜덤으로 생성된 숫자 할당
	randomNumber = rand() % (max - min + 1) + min;

	//출력
	cout << min << " ~ " << max << "까지의 랜덤 숫자 : " << randomNumber << endl;
}


void main()
{
	RandomNumber(1, 5);
	RandomNumber(6, 19);
	RandomNumber(23, 189);
}

