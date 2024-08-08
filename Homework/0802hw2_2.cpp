#include <iostream>
#include <limits>
#include <Windows.h>
#include <conio.h>

using std::cout;
using std::endl;
using std::string;

class CharacterClass
{
protected:
	string className;
	int atk;
	int def;
	int critRate;
	int dodgeRate;
	int health;

public:
	void printInfo() const;
	bool rateCheck(const int rate) const;
	void Defence(const int atkdamage, const int puredamage);
	int getHealth() const;
	virtual ~CharacterClass() {};
	virtual bool Act(int& atkdamage, int& pureDamage) = 0;
};

class Human : public CharacterClass
{
private:
	void atkBuff();
	void defBuff();
	void heal();
	void normalAttack(int& atkdamage) const;

public:
	Human();
	~Human() override {};
	bool Act(int& atkdamage, int& pureDamage) override;
};

class Orc : public CharacterClass
{
private:
	void normalAttack(int& atkdamage) const;

public:
	Orc();
	~Orc() override {};
	bool Act(int& atkdamage, int& pureDamage) override;
};

class Elf : public CharacterClass
{
private:
	void piercingArrow(int& atkdamage, int& pureDamage) const;
	void critBuff();
	void dodgeBuff();

public:
	Elf();
	~Elf() override {};
	bool Act(int& atkdamage, int& pureDamage) override;
};

class Dracula : public CharacterClass
{
private:
	void bloodSucking(int& atkdamage);
	void hemophilia(int & atkdamage);

public:
	Dracula();
	~Dracula() override {};
	bool Act(int& atkdamage, int& pureDamage) override;
};

class Battle
{
private:
	bool turn = 0;
	CharacterClass* player[2];

	void CursorView(bool show);
	void printStartScreen();
	void printRules();
	void selClass();
	void turnProgress(bool turn);
	bool endCheck();
public:
	~Battle();
	void gameStart();
};

int main()
{
	Battle game;
	game.gameStart();
	return 0;
}

#pragma region Human ������
void Human::atkBuff()
{
	cout << "���ݷ��� 5 �����մϴ�." << endl;
	atk += 5;
}

void Human::defBuff()
{
	cout << "������ 5 �����մϴ�." << endl;
	def += 5;
}

void Human::heal()
{
	cout << "���ݷ��� ���ݸ�ŭ ü���� ȸ���մϴ�." << endl;
	health += atk;
}

void Human::normalAttack(int& atkdamage) const
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "ġ��Ÿ ����! ���ݷ��� 1.5�踸ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk * 1.5;
		cout << "���� : " << atkdamage << endl;
	}
	else
	{
		cout << "���ݷ¸�ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk;
		cout << "���� : " << atkdamage << endl;
	}
}

Human::Human()
{
	className = "Human";
	atk = 10;
	def = 5;
	critRate = 20;
	dodgeRate = 20;
	health = 100;
}

bool Human::Act(int& atkdamage, int& pureDamage)
{
	int sel;
	cout << "�̹� �Ͽ� �� �ൿ�� �����ϼ���" << endl;
	cout << "1. ���ݷ� ���� ��ų ���" << endl;
	cout << "2. ���� ���� ��ų ���" << endl;
	cout << "3. ȸ�� ��ų ���" << endl;
	cout << "4. �Ϲ� ���� ��ų ���" << endl;

	sel = _getch() - '0';

	switch (sel)
	{
	case 1:
		cout << "\n";
		atkBuff();
		return false;

	case 2:
		cout << "\n";
		defBuff();
		return false;

	case 3:
		cout << "\n";
		heal();
		return false;

	case 4:
		cout << "\n";
		normalAttack(atkdamage);
		return false;

	default:
		system("cls");
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
}
#pragma endregion

#pragma region Orc ������
void Orc::normalAttack(int& atkdamage) const
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "ġ��Ÿ ����! ���ݷ��� 1.5�踸ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk * 1.5;
		cout << "���� : " << atkdamage << endl;
	}
	else
	{
		cout << "���ݷ¸�ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk;
		cout << "���� : " << atkdamage << endl;
	}
}

Orc::Orc()
{
	className = "Orc";
	atk = 20;
	def = 10;
	critRate = 50;
	dodgeRate = 0;
	health = 150;
}

bool Orc::Act(int& atkdamage, int& pureDamage)
{
	int sel;
	cout << "�̹� �Ͽ� �� �ൿ�� �����ϼ���" << endl;
	cout << "1. �Ϲ� ���� ��ų ���" << endl;

	sel = _getch() - '0';

	switch (sel)
	{
	case 1:
		cout << "\n";
		normalAttack(atkdamage);
		return false;

	default:
		system("cls");
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
}
#pragma endregion

#pragma region Elf ������
void Elf::piercingArrow(int& atkdamage, int& pureDamage) const
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "ġ��Ÿ ����! ���ݷ��� 1.5�踸ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk * 0.75;
		pureDamage = atk * 0.75;
		cout << "�Ϲ� ���� : " << atkdamage << endl;
		cout << "���� ���� : " << pureDamage << endl;
	}
	else
	{
		cout << "���ݷ¸�ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk * 0.5;
		pureDamage = atk * 0.5;
		cout << "���� : " << atkdamage << endl;
		cout << "���� ���� : " << pureDamage << endl;
	}
}

void Elf::critBuff()
{
	cout << "ũ������ 5% �����մϴ�." << endl;
	critRate += 5;
}

void Elf::dodgeBuff()
{
	cout << "ȸ������ 5% �����մϴ�." << endl;
	dodgeRate += 5;
}

Elf::Elf()
{
	className = "Elf";
	atk = 15;
	def = 7;
	critRate = 10;
	dodgeRate = 40;
	health = 80;
}

bool Elf::Act(int& atkdamage, int& pureDamage)
{
	int sel;
	cout << "�̹� �Ͽ� �� �ൿ�� �����ϼ���" << endl;
	cout << "1. ũ���� ���� ��ų ���" << endl;
	cout << "2. ȸ���� ���� ��ų ���" << endl;
	cout << "3. ���� ȭ�� ��ų ���" << endl;

	sel = _getch() - '0';

	switch (sel)
	{
	case 1:
		cout << "\n";
		critBuff();
		return false;

	case 2:
		cout << "\n";
		dodgeBuff();
		return false;

	case 3:
		cout << "\n";
		piercingArrow(atkdamage,pureDamage);
		return false;

	default:
		system("cls");
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
}
#pragma endregion

#pragma region Dracula ������
void Dracula::bloodSucking(int& atkdamage)
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "ġ��Ÿ ����! ���ݷ��� 1.5�踸ŭ�� �������� �����ϰ� ������ 50%�� ȸ���մϴ�." << endl;
		atkdamage = atk * 1.5;
		health += atkdamage * 0.5;
		cout << "���� : " << atkdamage << endl;
		cout << "ȸ���� : " << atkdamage * 0.5 << endl;
	}
	else
	{
		cout << "���ݷ� ��ŭ�� �������� �����ϰ� ������ 50%�� ȸ���մϴ�." << endl;
		atkdamage = atk;
		health += atkdamage * 0.5;
		cout << "���� : " << atkdamage << endl;
		cout << "ȸ���� : " << atkdamage * 0.5 << endl;
	}
}

void Dracula::hemophilia(int& atkdamage)
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "ġ��Ÿ ����! ���� ������ 1.5�踸ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk * 1.5 * 1.5;
		cout << "���� ü�� : " << health / 20 << endl;
		health -= health / 20;
		cout << "���� : " << atkdamage << endl;
	}
	else
	{
		cout << "���� ü���� 5%�� �Ҹ��Ͽ� ���ݷ��� 1.5�� ��ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk * 1.5;
		cout << "���� ü�� : " << health / 20 << endl;
		health -= health / 20;
		cout << "���� : " << atkdamage << endl;
	}
}

Dracula::Dracula()
{
	className = "Dracula";
	atk = 20;
	def = 7;
	critRate = 20;
	dodgeRate = 0;
	health = 120;
}

bool Dracula::Act(int& atkdamage, int& pureDamage)
{
	int sel;
	cout << "�̹� �Ͽ� �� �ൿ�� �����ϼ���" << endl;
	cout << "1. ���� ���� ��ų ���" << endl;
	cout << "2. ���纴 ��ų ���" << endl;

	sel = _getch() - '0';

	switch (sel)
	{
	case 1:
		cout << "\n";
		bloodSucking(atkdamage);
		return false;

	case 2:
		cout << "\n";
		hemophilia(atkdamage);
		return false;

	default:
		system("cls");
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
}
#pragma endregion

#pragma region Battle ������
void Battle::CursorView(bool show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Battle::printStartScreen()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	while (true)
	{
		system("cls");
		cout << "[Player VS Player]\n";
		cout << endl;
		cout << "Press Any Button To Continue" << endl;
		Sleep(500);
		if (_kbhit()) break;


		system("cls");
		cout << "[Player VS Player]\n";
		Sleep(500);
		if (_kbhit()) break;
	}
	system("cls");
}

void Battle::printRules()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	while (true)
	{
		system("cls");
		cout << "[���� ��Ģ]\n";
		cout << "�� �÷��̾� 2���� �����ϴ� �����Դϴ�.\n";
		cout << "�� �÷��̾� 1,2 ������ ������ �����մϴ�.\n";
		cout << "�� ������ ���� ���� ������ ������ 1�� �÷��̾ �����Դϴ�.\n";
		cout << "�� Ű������ ��� ����Ű�� ���� �������� �����մϴ�.\n";
		cout << endl;
		cout << "Press Any Button To Continue" << endl;
		Sleep(500);
		if (_kbhit()) break;


		system("cls");
		cout << "[���� ��Ģ]\n";
		cout << "�� �÷��̾� 2���� �����ϴ� �����Դϴ�.\n";
		cout << "�� �÷��̾� 1,2 ������ ������ �����մϴ�.\n";
		cout << "�� ������ ���� ���� ������ ������ 1�� �÷��̾ �����Դϴ�." << endl;
		cout << "�� Ű������ ��� ����Ű�� ���� �������� �����մϴ�.\n";
		Sleep(500);
		if (_kbhit()) break;
	}
	system("cls");
}

void Battle::selClass()
{
	for(int i = 0; i < 2; i++)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		int sel;
		bool notSelected = true;

		system("cls");
		while (notSelected)
		{
			cout << "Player" << i + 1 << "�� ������ �����ϼ���.\n" << endl;
			cout << "[���� ���]\n" << endl;
			cout << "1. �ΰ�" << endl;
			cout << "- �ΰ��� ������ �����ϴ� �����Դϴ�." << endl;
			cout << "- �⺻ �ɷ�ġ�� ������, ���ݷ°� ������ ���� �ø� �� �ֽ��ϴ�." << endl;
			cout << "- ���� �ڰ� ȸ���� �����ϸ� �Ϲ� ������ �����մϴ�.\n" << endl;
			cout << "2. ��ũ" << endl;
			cout << "- ��ũ�� ���� �ܼ������� ������ �����Դϴ�." << endl;
			cout << "- �⺻ �ɷ�ġ�� ���� ��� �Ϲ� ���ݸ� �����մϴ�.\n" << endl;
			cout << "3. ����" << endl;
			cout << "- ������ ��ø�ϰ� ġ������ ������ �ϴ� �����Դϴ�." << endl;
			cout << "- ���� ġ��Ÿ�� ȸ������ ���� �ø� �� �ֽ��ϴ�." << endl;
			cout << "- ���ط��� 50%�� ���� ���ط� ���ϴ�.\n" << endl;
			cout << "4. ���ŧ��" << endl;
			cout << "- ���ŧ��� ü���� ������� �� ��ų�� ����ϴ� �����Դϴ�." << endl;
			cout << "- ������ ���ظ� �ָ� ü���� ȸ���ϰų�, ü���� �Ҹ��Ͽ� ������ ������ �����մϴ�.\n" << endl;
			cout << "" << endl;

			sel = _getch() - '0';

			switch (sel)
			{
			case 1:
				system("cls");
				player[i] = new Human();
				cout << "Player" << i + 1 << "�� �ΰ� �����Դϴ�.";
				notSelected = false;
				Sleep(1500);
				system("cls");
				break;

			case 2:
				system("cls");
				player[i] = new Orc();
				cout << "Player" << i + 1 << "�� ��ũ �����Դϴ�.";
				notSelected = false;
				Sleep(1500);
				system("cls");
				break;

			case 3:
				system("cls");
				player[i] = new Elf();
				cout << "Player" << i + 1 << "�� ���� �����Դϴ�.";
				notSelected = false;
				Sleep(1500);
				system("cls");
				break;

			case 4:
				system("cls");
				player[i] = new Dracula();
				cout << "Player" << i + 1 << "�� ���ŧ�� �����Դϴ�.";
				notSelected = false;
				Sleep(1500);
				system("cls");
				break;

			default:
				system("cls");
				cout << "�߸��� �Է��Դϴ�!" << endl;
				break;
			}
		}
	}
}

void Battle::turnProgress(bool turn)
{
	int atkdamage = 0, pureDamage = 0;
	bool crit = false;
	bool notActed = true;

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	while (notActed)
	{
		cout << "[player" << turn + 1 << "�� ��]\n" << endl;

		cout << "[��� ����]" << endl;
		player[!turn]->printInfo();
		cout << endl;

		cout << "[���� ����]" << endl;
		player[turn]->printInfo();
		cout << endl;
		notActed = player[turn]->Act(atkdamage, pureDamage);
	}

	player[!turn]->Defence(atkdamage, pureDamage);
}

bool Battle::endCheck()
{
	system("cls");
	for (int i = 0; i < 2; i++)
	{
		if (player[i]->getHealth() <= 0)//isPlayerDead(){return getHealth() <= 0;}
		{
			cout << "player" << i + 1 << " �й�!" << endl;
			return true;
		}
	}
	return false;
}

Battle::~Battle()
{
	delete player[0];
	player[0] = nullptr;
	delete player[1];
	player[1] = nullptr;
}

void Battle::gameStart()
{
	CursorView(false);
	printStartScreen();
	printRules();

	selClass();

	while (true)
	{
		turnProgress(turn);
		Sleep(2000);
		if (endCheck()) break;
		turn = !turn;
	}
	CursorView(true);
}
#pragma endregion

#pragma region CharacterClass������
void CharacterClass::printInfo() const
{
	cout << "���� : " << className << endl;
	cout << "���ݷ� : " << atk << endl;
	cout << "���� : " << def << endl;
	cout << "ũ��Ƽ�� Ȯ�� : " << critRate << "%" << endl;
	cout << "ȸ�� Ȯ�� : " << dodgeRate << "%" << endl;
	cout << "���� ü�� : " << health << endl;
}

bool CharacterClass::rateCheck(const int rate) const
{
	int temp;
	srand(time(NULL));
	temp = rand() % 100 + 1;
	if (rate >= temp)
	{
		return true;
	}
	return false;
}

void CharacterClass::Defence(const int atkdamage, const int puredamage)
{
	if (atkdamage != 0 || puredamage != 0)
	{
		if (rateCheck(dodgeRate))
		{
			cout << "���� ȸ�ǿ� �����߽��ϴ�." << endl;
		}
		else
		{
			int damage;
			damage = (atkdamage - def);
			if (damage <= 0) damage = 0;
			damage += puredamage;
			cout << "���� " << damage << "�� ���ظ� �Ծ����ϴ�." << endl;
			health -= damage;
		}
	}
}

int CharacterClass::getHealth() const
{
	return health;
}
#pragma endregion