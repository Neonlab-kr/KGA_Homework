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

	for (int i = 0; i < 4; i++)
	{
		numCheck[arr1[i]] = true;
	}

	for (int i = 0; i < 21; i++)
	{
		if (numCheck[i])
		{
			bool check = false;
			for (int j = 0; j < 5; j++)
			{
				if (i == arr2[j]) check = true;
			}
			numCheck[i] = check;

			check = false;
			for (int j = 0; j < 4; j++)
			{
				if (i == arr3[j]) check = true;
			}
			numCheck[i] = check;
		}
	}

	cout << "°á°ú : ";
	for (int i = 0; i < 21; i++)
	{
		if (numCheck[i]) cout << i << ' ';
	}

}