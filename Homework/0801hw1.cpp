#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Student
{
	string name, address, phone;
	int age;
};

void getStudentInfo(Student* student);
void printStudentInfo(Student* student);

int main()
{
	Student student;
	getStudentInfo(&student);
	printStudentInfo(&student);
	return 0;
}

void getStudentInfo(Student* student)
{
	cout << "이름을 입력하세요 : ";
	getline(cin, student->name);

	cout << "나이를 입력하세요 : ";
	cin >> student->age;
	getchar();
	cout << "주소를 입력하세요 : ";
	getline(cin, student->address);

	cout << "연락처를 입력하세요 : ";
	getline(cin, student->phone);

}

void printStudentInfo(Student* student)
{
	cout << "이름 : " << student->name << endl;
	cout << "나이 : " << student->age << endl;
	cout << "주소 : " << student->address << endl;
	cout << "연락처 : " << student->phone << endl;
}
