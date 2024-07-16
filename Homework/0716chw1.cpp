#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �߻� Ŭ����
class PersonInfo {
protected:
    string name;
    string age;
    string contact;
    string address;
    string email;

public:
    // ���� �Լ�
    virtual void GetInfo() = 0;
    virtual void PrintInfo() = 0;
};

// Ŭ���� ����
class KGA_StudentInfo : public PersonInfo {
private:
    string determination;
    string desired_company;
    string game_idea;
    string hobby;
    vector<string> header = { "�̸�", "����", "����ó", "�ּ�", "�̸���", "����", "���� ���� ȸ��", "����� ���� ����", "���" };

public:
    void GetInfo() override {
        cout << "\n[���� �Է�]\n";
        for (int i = 0; i < header.size(); i++)
        {
            cout << header[i] << "��(��) �Է��ϼ��� : \n";
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

        //�ִ� �Ӹ��� ���� ���
        for (std::string header : header)
            max_header_width = header.length() > max_header_width ? header.length() : max_header_width;

        cout << "\n[" << name << "���� ����]\n";
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
