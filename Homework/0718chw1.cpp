#include <iostream>

using std::cout;
using std::string;

void main()
{
    //n�� ���� �� ���� �� ������ ����
    for (int i = 1, n = 6, result; i < 2 * n; result = ((n - i) + ((n - i) >> 31)) ^ ((n - i) >> 31), cout << string(result, ' ') << string(2 * (n - result), '*') << '\n', i++);
}