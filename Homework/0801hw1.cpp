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
	cout << "�̸��� �Է��ϼ��� : ";
	getline(cin, student->name);

	cout << "���̸� �Է��ϼ��� : ";
	cin >> student->age;
	getchar();
	cout << "�ּҸ� �Է��ϼ��� : ";
	getline(cin, student->address);

	cout << "����ó�� �Է��ϼ��� : ";
	getline(cin, student->phone);

}

void printStudentInfo(Student* student)
{
	cout << "�̸� : " << student->name << endl;
	cout << "���� : " << student->age << endl;
	cout << "�ּ� : " << student->address << endl;
	cout << "����ó : " << student->phone << endl;
}
