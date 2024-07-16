#include <iostream>
#include <string>
#include <vector>


void main()
{
	int max_header_width = 0;
	std::vector<std::string> header = { "이름", "나이", "연락처", "주소", "이메일", "각오", "가고 싶은 회사", "만들고 싶은 게임", "취미"};
	std::vector<std::string> data = { "test", "24", "010-0000-0000", "Korea", "test@test.com", "I'll do my best", "not selected", "not selected", "game" };

	//최대 머릿글 길이 계산
	for (std::string header : header)
		max_header_width = header.length() > max_header_width ? header.length() : max_header_width;

	//출력
	for (int i = 0; i < header.size(); i++)
	{
		std::cout.width(max_header_width);
		std::cout << std::left << header[i] << " : " << data[i] << '\n';
	}
}