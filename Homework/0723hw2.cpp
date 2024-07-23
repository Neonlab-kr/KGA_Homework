#include <iostream>
#include <time.h>
#include <Windows.h>

using std::cout;
using std::cin;

void main()
{
	const int width = 5;
	const int length = 4;
	int randomArray[length][width];

	int total = 0;
	int lengthSum[width] = {};

	srand(time(NULL));

	for (int i = 0; i < length; i++)
	{
		int widthSum = 0;
		for (int j = 0; j < width; j++)
		{
			randomArray[i][j] = rand() % 100 + 1;
			widthSum += randomArray[i][j];
			lengthSum[j] += randomArray[i][j];
			printf("%03d ", randomArray[i][j]);
		}
		cout << widthSum << '\n';
	}

	for (int i = 0; i < width; i++)
	{
		printf("%03d ", lengthSum[i]);
		total += lengthSum[i];
	}

	cout << total << '\n';
}