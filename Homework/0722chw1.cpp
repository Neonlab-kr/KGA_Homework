#include <iostream>

void ReverseWords(char* output, int outputArraySize, const char* input);

void main()
{
    const char* input = "Hello World this is Pearl Abyss";
    int outputArraySize = 0;
    char ch;

    //문자열의 길이 + 1 구하기(null문자까지)
    while ((ch = input[outputArraySize++]) != '\0');

    //동적 할당
    char* output = new char[outputArraySize];

    ReverseWords(output, outputArraySize, input);

    //동적 할당 메모리 해제
    delete[] output;
}

void ReverseWords(char* output, int outputArraySize, const char* input)
{
    // 단어의 시작과 끝을 기록할 인덱스 변수들
    int startOfWord = outputArraySize - 2;
    int endOfWord = outputArraySize - 2;
    int outputIndex = 0;
    bool flag = true;

    // 입력 문자열을 단어 단위 역순으로 output에 복사
    while (startOfWord >= 0)
    {
        // 단어의 끝 찾기
        while (startOfWord >= 0 && input[startOfWord] != ' ')
        {
            startOfWord--;
            //첫 공백은 무시
            if (flag && input[startOfWord] == ' ')
            {
                flag = false;
                startOfWord--;
                continue;
            }
        }

        // 단어를 output에 복사
        for (int i = startOfWord + 1; i <= endOfWord; i++)
        {
            output[outputIndex++] = input[i];
        }

        // 공백 추가
        if (startOfWord >= 0)
        {
            output[outputIndex++] = ' ';
        }

        startOfWord--;
        endOfWord = startOfWord;
    }

    output[outputIndex] = '\0';

    std::cout << output << std::endl;
}