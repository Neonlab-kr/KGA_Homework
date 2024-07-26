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
		cout << "������ ���� : " << relation << endl;
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
		switch (sex)
		{
		case Sexuality::MEN:
			cout << "���� : Men" << endl;
			break;
		case Sexuality::WOMEN:
			cout << "���� : Women" << endl;
			break;
		case Sexuality::DEFAULT:
			cout << "���� : ���Է�" << endl;
			break;
		default:
			break;
		}
		cout << "========================" << endl;
	}
};

void main()
{
	Family mother("��Ӵ�", "OOO", 00, Sexuality::WOMEN);
	Family father("�ƹ���", "OOO", 00, Sexuality::MEN);
	Family brother("����", "OOO", 00, Sexuality::MEN);
	Family me("��", "OOO", 00, Sexuality::MEN);

	mother.printInfo();
	father.printInfo();
	brother.printInfo();
	me.printInfo();
}