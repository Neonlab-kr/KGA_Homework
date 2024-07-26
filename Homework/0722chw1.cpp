#include <iostream>

void ReverseWords(char* output, int outputArraySize, const char* input);

void main()
{
    const char* input = "Hello World this is Pearl Abyss";
    int outputArraySize = 0;
    char ch;

    //���ڿ��� ���� + 1 ���ϱ�(null���ڱ���)
    while ((ch = input[outputArraySize++]) != '\0');

    //���� �Ҵ�
    char* output = new char[outputArraySize];

    ReverseWords(output, outputArraySize, input);

    //���� �Ҵ� �޸� ����
    delete[] output;
}

void ReverseWords(char* output, int outputArraySize, const char* input)
{
    // �ܾ��� ���۰� ���� ����� �ε��� ������
    int startOfWord = outputArraySize - 2;
    int endOfWord = outputArraySize - 2;
    int outputIndex = 0;
    bool flag = true;

    // �Է� ���ڿ��� �ܾ� ���� �������� output�� ����
    while (startOfWord >= 0)
    {
        // �ܾ��� �� ã��
        while (startOfWord >= 0 && input[startOfWord] != ' ')
        {
            startOfWord--;
            //ù ������ ����
            if (flag && input[startOfWord] == ' ')
            {
                flag = false;
                startOfWord--;
                continue;
            }
        }

        // �ܾ output�� ����
        for (int i = startOfWord + 1; i <= endOfWord; i++)
        {
            output[outputIndex++] = input[i];
        }

        // ���� �߰�
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