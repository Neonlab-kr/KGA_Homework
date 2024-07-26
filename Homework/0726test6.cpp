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
        for (int j = 0; j < 5; j++) //k를 쓸 필요가 전혀 없겠다 그죠?
        {
            if (arr1[i] == arr2[j])
            {
                check = true;//배열1의 i번째 원소가 배열2의 원소중 같은게 있으면 true
            }
        }
        numCheck[arr1[i]] = check;//같은게 없었다면 false가, 하나라도 있었다면 true가 되겠죠?

        check = false;
        for (int j = 0; j < 4; j++)
        {
            if (arr1[i] == arr3[j])
            {
                check = true;//당연히 여기도
            }
        }
        numCheck[arr1[i]] = check;//위랑 똑같겠죠?
    }

	cout << "결과 : ";
	for (int i = 0; i < 21; i++)
	{
		if (numCheck[i]) cout << i << ' ';
	}
	
}