#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 추상 클래스
class PersonInfo {
protected:
    string name;
    string age;
    string contact;
    string address;
    string email;

public:
    // 가상 함수
    virtual void GetInfo() = 0;
    virtual void PrintInfo() = 0;
};

// 클래스 구현
class KGA_StudentInfo : public PersonInfo {
private:
    string determination;
    string desired_company;
    string game_idea;
    string hobby;
    vector<string> header = { "이름", "나이", "연락처", "주소", "이메일", "각오", "가고 싶은 회사", "만들고 싶은 게임", "취미" };

public:
    void GetInfo() override {
        cout << "\n[정보 입력]\n";
        for (int i = 0; i < header.size(); i++)
        {
            cout << header[i] << "을(를) 입력하세요 : \n";
            string input;
            getline(cin, input);

            switch (i) {
            case 0: name = input; break;
            case 1: age = input; break;
            case 2: contact = input; break;
            case 3: address = input; break;
            case 4: email = input; break;
            case 5: determination = input; break;
            case 6: desired_company = input; break;
            case 7: game_idea = input; break;
            case 8: hobby = input; break;
            default: break;
            }
        }
    }

    void PrintInfo() override {
        int max_header_width = 0;

        //최대 머릿글 길이 계산
        for (std::string header : header)
            max_header_width = header.length() > max_header_width ? header.length() : max_header_width;

        cout << "\n[" << name << "님의 정보]\n";
        for (int i = 0; i < header.size(); i++)
        {
            cout.width(max_header_width);
            cout << left << header[i] << " : ";

            switch (i) {
            case 0: cout << name; break;
            case 1: cout << age; break;
            case 2: cout << contact; break;
            case 3: cout << address; break;
            case 4: cout << email; break;
            case 5: cout << determination; break;
            case 6: cout << desired_company; break;
            case 7: cout << game_idea; break;
            case 8: cout << hobby; break;
            default: break;
            }

            cout << '\n';
        }
    }
};

int main() {
    KGA_StudentInfo person;

    person.GetInfo();
    person.PrintInfo();

    return 0;
}
