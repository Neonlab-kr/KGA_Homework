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
	cout << "���ڿ��� �Է��ϼ��� : ";
	getline(cin,str);

	int wordCount = 0;
	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		if (ch == ' ') wordCount++;
	}
	wordCount++;

	cout << "�Է��� ���ڿ��� �ܾ� �� : " << wordCount << endl;
}