#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void main()
{
	int arr1[] = { 1,5,5,10 };
	int arr2[] = { 3,4,5,5,10 };
	int arr3[] = { 5,5,10,20 };

	bool numCheck[21] = { false, };
    bool check;

    for (int i = 0; i < 4; i++)
    {
        check = false;
        for (int j = 0; j < 5; j++) //k�� �� �ʿ䰡 ���� ���ڴ� ����?
        {
            if (arr1[i] == arr2[j])
            {
                check = true;//�迭1�� i��° ���Ұ� �迭2�� ������ ������ ������ true
            }
        }
        numCheck[arr1[i]] = check;//������ �����ٸ� false��, �ϳ��� �־��ٸ� true�� �ǰ���?

        check = false;
        for (int j = 0; j < 4; j++)
        {
            if (arr1[i] == arr3[j])
            {
                check = true;//�翬�� ���⵵
            }
        }
        numCheck[arr1[i]] = check;//���� �Ȱ�����?
    }

	cout << "��� : ";
	for (int i = 0; i < 21; i++)
	{
		if (numCheck[i]) cout << i << ' ';
	}
	
}