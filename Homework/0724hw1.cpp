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

	cout << "스킬명 입력 : ";
	getline(cin, name);
	mySkill(name);

	cout << "데미지 입력 : ";
	cin >> damage;
	mySkill(name, damage);

	cout << "크리율 입력(%) : ";
	cin >> critRate;
	mySkill(name, damage, critRate);

	cout << "범위 입력 : ";
	cin >> range;
	mySkill(name, damage, critRate, range);
}

void mySkill(string name)
{
	cout << name << "을(를) 사용했다." << endl;
	cout << '\n';
}

void mySkill(string name, int damage)
{
	cout << name << "을(를) 사용했다." << endl;
	cout << damage << "의 데미지." << endl;
	cout << '\n';
}

void mySkill(string name, int damage, int critRate)
{
	cout << name << "을(를) 사용했다." << endl;
	if (critRate > rand() % 100 + 1)
	{
		cout << damage*1.5 << "의 크리티컬 데미지!" << endl;
	}
	else
	{
		cout << damage << "의 데미지." << endl;
	}
	cout << '\n';
}

void mySkill(string name, int damage, int critRate, int range)
{
	cout << name << "을(를) 사용했다." << endl;
	if (critRate > rand() % 100 + 1)
	{
		cout << damage * 1.5 << "의 크리티컬 데미지!" << endl;
	}
	else
	{
		cout << damage << "의 데미지." << endl;
	}
	cout << range << "의 범위 적에게 피해를 입힘." << endl;
	cout << '\n';
}
