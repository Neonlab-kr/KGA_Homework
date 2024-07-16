#include <iostream>
#include <string>
#include <vector>


void main()
{
	int max_header_width = 0;
	std::vector<std::string> header = { "�̸�", "����", "����ó", "�ּ�", "�̸���", "����", "���� ���� ȸ��", "����� ���� ����", "���"};
	std::vector<std::string> data = { "test", "24", "010-0000-0000", "Korea", "test@test.com", "I'll do my best", "not selected", "not selected", "game" };

	//�ִ� �Ӹ��� ���� ���
	for (std::string header : header)
		max_header_width = header.length() > max_header_width ? header.length() : max_header_width;

	//���
	for (int i = 0; i < header.size(); i++)
	{
		std::cout.width(max_header_width);
		std::cout << std::left << header[i] << " : " << data[i] << '\n';
	}
}