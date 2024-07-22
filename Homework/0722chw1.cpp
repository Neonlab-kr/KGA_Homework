#include <iostream>
void ReverseWords(char* output, int outptArraysize, const char* input);


void main()
{
	char* output;
	const char* input = "Hello World this is Pearl Abyss";

	int count = 0;
	char ch;

	while (ch != '\0') ch = input[count++];

	ReverseWords(output, count, input);
}

void ReverseWords(char* output, int outptArraysize, const char* input)
{

	output = new char[outptArraysize];

	output[outptArraysize] = '\0';

	int count = 0;
	char ch;

	while (ch != ' ') ch = input[count++];





}