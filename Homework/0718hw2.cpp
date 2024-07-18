#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int num1, num2, num3;

	cout << "문제 a : 두개의 정수를 받아서 두 수의 덧셈과 뺄셈의 결과를 출력하시오." << endl;
	cout << "첫번째 정수를 입력하세요 : " << endl;
	cin >> num1;
	
	cout << "두번째 정수를 입력하세요 : " << endl;
	cin >> num2;

	cout << "두 수의 합은 " << num1 + num2 << "이고, 두 수의 차는 " << num1 - num2 << "입니다." << endl;

	cout << '\n';

	cout << "문제 b : 3개의 정수를 받아서 (num1 + num2) * (num3 + num1) % num1의 결과를 출력하시오." << endl;
	cout << "첫번째 정수를 입력하세요 : " << endl;
	cin >> num1;

	cout << "두번째 정수를 입력하세요 : " << endl;
	cin >> num2;

	cout << "세번째 정수를 입력하세요 : " << endl;
	cin >> num3;

	cout << "연산 결과는 " << (num1 + num2) * (num3 + num1) % num1 << "입니다." << endl;

	cout << '\n';

	cout << "문제 c : 입력 받은 두 정수를 나누었을때 얻게 되는 몫과 나머지를 출력하시오." << endl;

	cout << "첫번째 정수를 입력하세요 : " << endl;
	cin >> num1;

	cout << "두번째 정수를 입력하세요 : " << endl;
	cin >> num2;

	cout << "몫은 " << num1 / num2 << "이고, 나머지는 " << num1 % num2 << "입니다." << endl;
}