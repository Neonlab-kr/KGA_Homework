#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

enum class Sexuality
{
	MEN, WOMEN, DEFAULT
};

struct Family
{
	string relation = "default";
	string name = "default";
	short age = 0;
	Sexuality sex = Sexuality::DEFAULT;

	Family(string _relation, string _name, short _age, Sexuality _sex)
	{
		relation = _relation;
		name = _name;
		age = _age;
		sex = _sex;
	}

	void printInfo()
	{
		cout << "========================" << endl;
		cout << "나와의 관계 : " << relation << endl;
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
		switch (sex)
		{
		case Sexuality::MEN:
			cout << "성별 : Men" << endl;
			break;
		case Sexuality::WOMEN:
			cout << "성별 : Women" << endl;
			break;
		case Sexuality::DEFAULT:
			cout << "성별 : 미입력" << endl;
			break;
		default:
			break;
		}
		cout << "========================" << endl;
	}
};

void main()
{
	Family mother("어머니", "OOO", 00, Sexuality::WOMEN);
	Family father("아버지", "OOO", 00, Sexuality::MEN);
	Family brother("형제", "OOO", 00, Sexuality::MEN);
	Family me("나", "OOO", 00, Sexuality::MEN);

	mother.printInfo();
	father.printInfo();
	brother.printInfo();
	me.printInfo();
}