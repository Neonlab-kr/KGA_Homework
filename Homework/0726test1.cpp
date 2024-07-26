#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	int inputNum;
    bool* numArray;

	cout << "숫자를 입력하세요 : ";
	cin >> inputNum;

    numArray = new bool[inputNum + 1];

    for (int i = 0; i < inputNum + 1; i++)
    {
        numArray[i] = true;
    }

    for (int i = 2; i < inputNum + 1; i++)
    {
        if (!numArray[i]) continue;

        for (int j = 2 * i; j <= inputNum; j += i)
        {
            numArray[j] = false;
        }
    }

    if (numArray[inputNum])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    delete [] numArray;
}