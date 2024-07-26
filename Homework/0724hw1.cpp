#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void mySkill(string name);
void mySkill(string name,int damage);
void mySkill(string name,int damage,int critRate);
void mySkill(string name,int damage,int critRate, int range);

void main()
{
	string name;
	int damage, critRate, range;

	cout << "��ų�� �Է� : ";
	getline(cin, name);
	mySkill(name);

	cout << "������ �Է� : ";
	cin >> damage;
	mySkill(name, damage);

	cout << "ũ���� �Է�(%) : ";
	cin >> critRate;
	mySkill(name, damage, critRate);

	cout << "���� �Է� : ";
	cin >> range;
	mySkill(name, damage, critRate, range);
}

void mySkill(string name)
{
	cout << name << "��(��) ����ߴ�." << endl;
	cout << '\n';
}

void mySkill(string name, int damage)
{
	cout << name << "��(��) ����ߴ�." << endl;
	cout << damage << "�� ������." << endl;
	cout << '\n';
}

void mySkill(string name, int damage, int critRate)
{
	cout << name << "��(��) ����ߴ�." << endl;
	if (critRate > rand() % 100 + 1)
	{
		cout << damage*1.5 << "�� ũ��Ƽ�� ������!" << endl;
	}
	else
	{
		cout << damage << "�� ������." << endl;
	}
	cout << '\n';
}

void mySkill(string name, int damage, int critRate, int range)
{
	cout << name << "��(��) ����ߴ�." << endl;
	if (critRate > rand() % 100 + 1)
	{
		cout << damage * 1.5 << "�� ũ��Ƽ�� ������!" << endl;
	}
	else
	{
		cout << damage << "�� ������." << endl;
	}
	cout << range << "�� ���� ������ ���ظ� ����." << endl;
	cout << '\n';
}
