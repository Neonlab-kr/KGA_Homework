#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

void main()
{
	string str;
	cout << "문자열을 입력하세요 : ";
	getline(cin,str);

	int wordCount = 0;
	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		if (ch == ' ') wordCount++;
	}
	wordCount++;

	cout << "입력한 문자열의 단어 수 : " << wordCount << endl;
}