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

#pragma region Human 구현부
void Human::atkBuff()
{
	cout << "공격력이 5 증가합니다." << endl;
	atk += 5;
}

void Human::defBuff()
{
	cout << "방어력이 5 증가합니다." << endl;
	def += 5;
}

void Human::heal()
{
	cout << "공격력의 절반만큼 체력을 회복합니다." << endl;
	health += atk;
}

void Human::normalAttack(int& atkdamage) const
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "치명타 적중! 공격력의 1.5배만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk * 1.5;
		cout << "위력 : " << atkdamage << endl;
	}
	else
	{
		cout << "공격력만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk;
		cout << "위력 : " << atkdamage << endl;
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
	cout << "이번 턴에 할 행동을 선택하세요" << endl;
	cout << "1. 공격력 증가 스킬 사용" << endl;
	cout << "2. 방어력 증가 스킬 사용" << endl;
	cout << "3. 회복 스킬 사용" << endl;
	cout << "4. 일반 공격 스킬 사용" << endl;

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
		cout << "잘못된 입력입니다." << endl;
		break;
	}
}
#pragma endregion

#pragma region Orc 구현부
void Orc::normalAttack(int& atkdamage) const
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "치명타 적중! 공격력의 1.5배만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk * 1.5;
		cout << "위력 : " << atkdamage << endl;
	}
	else
	{
		cout << "공격력만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk;
		cout << "위력 : " << atkdamage << endl;
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
	cout << "이번 턴에 할 행동을 선택하세요" << endl;
	cout << "1. 일반 공격 스킬 사용" << endl;

	sel = _getch() - '0';

	switch (sel)
	{
	case 1:
		cout << "\n";
		normalAttack(atkdamage);
		return false;

	default:
		system("cls");
		cout << "잘못된 입력입니다." << endl;
		break;
	}
}
#pragma endregion

#pragma region Elf 구현부
void Elf::piercingArrow(int& atkdamage, int& pureDamage) const
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "치명타 적중! 공격력의 1.5배만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk * 0.75;
		pureDamage = atk * 0.75;
		cout << "일반 위력 : " << atkdamage << endl;
		cout << "고정 피해 : " << pureDamage << endl;
	}
	else
	{
		cout << "공격력만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk * 0.5;
		pureDamage = atk * 0.5;
		cout << "위력 : " << atkdamage << endl;
		cout << "고정 피해 : " << pureDamage << endl;
	}
}

void Elf::critBuff()
{
	cout << "크리율이 5% 증가합니다." << endl;
	critRate += 5;
}

void Elf::dodgeBuff()
{
	cout << "회피율이 5% 증가합니다." << endl;
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
	cout << "이번 턴에 할 행동을 선택하세요" << endl;
	cout << "1. 크리율 증가 스킬 사용" << endl;
	cout << "2. 회피율 증가 스킬 사용" << endl;
	cout << "3. 관통 화살 스킬 사용" << endl;

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
		cout << "잘못된 입력입니다." << endl;
		break;
	}
}
#pragma endregion

#pragma region Dracula 구현부
void Dracula::bloodSucking(int& atkdamage)
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "치명타 적중! 공격력의 1.5배만큼의 위력으로 공격하고 위력의 50%를 회복합니다." << endl;
		atkdamage = atk * 1.5;
		health += atkdamage * 0.5;
		cout << "위력 : " << atkdamage << endl;
		cout << "회복량 : " << atkdamage * 0.5 << endl;
	}
	else
	{
		cout << "공격력 만큼의 위력으로 공격하고 위력의 50%를 회복합니다." << endl;
		atkdamage = atk;
		health += atkdamage * 0.5;
		cout << "위력 : " << atkdamage << endl;
		cout << "회복량 : " << atkdamage * 0.5 << endl;
	}
}

void Dracula::hemophilia(int& atkdamage)
{
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "치명타 적중! 원래 위력의 1.5배만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk * 1.5 * 1.5;
		cout << "잃은 체력 : " << health / 20 << endl;
		health -= health / 20;
		cout << "위력 : " << atkdamage << endl;
	}
	else
	{
		cout << "현재 체력의 5%를 소모하여 공격력의 1.5배 만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk * 1.5;
		cout << "잃은 체력 : " << health / 20 << endl;
		health -= health / 20;
		cout << "위력 : " << atkdamage << endl;
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
	cout << "이번 턴에 할 행동을 선택하세요" << endl;
	cout << "1. 흡혈 공격 스킬 사용" << endl;
	cout << "2. 혈사병 스킬 사용" << endl;

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
		cout << "잘못된 입력입니다." << endl;
		break;
	}
}
#pragma endregion

#pragma region Battle 구현부
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
		cout << "[게임 규칙]\n";
		cout << "● 플레이어 2명이 진행하는 게임입니다.\n";
		cout << "● 플레이어 1,2 순으로 직업을 결정합니다.\n";
		cout << "● 형평성을 위해 먼저 직업을 선택한 1번 플레이어가 선공입니다.\n";
		cout << "● 키보드의 상단 숫자키를 통해 선택지를 선택합니다.\n";
		cout << endl;
		cout << "Press Any Button To Continue" << endl;
		Sleep(500);
		if (_kbhit()) break;


		system("cls");
		cout << "[게임 규칙]\n";
		cout << "● 플레이어 2명이 진행하는 게임입니다.\n";
		cout << "● 플레이어 1,2 순으로 직업을 결정합니다.\n";
		cout << "● 형평성을 위해 먼저 직업을 선택한 1번 플레이어가 선공입니다." << endl;
		cout << "● 키보드의 상단 숫자키를 통해 선택지를 선택합니다.\n";
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
			cout << "Player" << i + 1 << "의 종족을 선택하세요.\n" << endl;
			cout << "[종족 목록]\n" << endl;
			cout << "1. 인간" << endl;
			cout << "- 인간은 끝없이 성장하는 종족입니다." << endl;
			cout << "- 기본 능력치는 낮지만, 공격력과 방어력을 매턴 올릴 수 있습니다." << endl;
			cout << "- 또한 자가 회복이 가능하며 일반 공격이 가능합니다.\n" << endl;
			cout << "2. 오크" << endl;
			cout << "- 오크는 가장 단순하지만 강력한 종족입니다." << endl;
			cout << "- 기본 능력치가 높은 대신 일반 공격만 가능합니다.\n" << endl;
			cout << "3. 엘프" << endl;
			cout << "- 엘프는 민첩하고 치명적인 공격을 하는 종족입니다." << endl;
			cout << "- 매턴 치명타와 회피율을 매턴 올릴 수 있습니다." << endl;
			cout << "- 피해량의 50%는 고정 피해로 들어갑니다.\n" << endl;
			cout << "4. 드라큘라" << endl;
			cout << "- 드라큘라는 체력을 기반으로 한 스킬을 사용하는 종족입니다." << endl;
			cout << "- 적에게 피해를 주며 체력을 회복하거나, 체력을 소모하여 강력한 공격이 가능합니다.\n" << endl;
			cout << "" << endl;

			sel = _getch() - '0';

			switch (sel)
			{
			case 1:
				system("cls");
				player[i] = new Human();
				cout << "Player" << i + 1 << "은 인간 종족입니다.";
				notSelected = false;
				Sleep(1500);
				system("cls");
				break;

			case 2:
				system("cls");
				player[i] = new Orc();
				cout << "Player" << i + 1 << "은 오크 종족입니다.";
				notSelected = false;
				Sleep(1500);
				system("cls");
				break;

			case 3:
				system("cls");
				player[i] = new Elf();
				cout << "Player" << i + 1 << "은 엘프 종족입니다.";
				notSelected = false;
				Sleep(1500);
				system("cls");
				break;

			case 4:
				system("cls");
				player[i] = new Dracula();
				cout << "Player" << i + 1 << "은 드라큘라 종족입니다.";
				notSelected = false;
				Sleep(1500);
				system("cls");
				break;

			default:
				system("cls");
				cout << "잘못된 입력입니다!" << endl;
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
		cout << "[player" << turn + 1 << "의 턴]\n" << endl;

		cout << "[상대 정보]" << endl;
		player[!turn]->printInfo();
		cout << endl;

		cout << "[나의 정보]" << endl;
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
			cout << "player" << i + 1 << " 패배!" << endl;
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

#pragma region CharacterClass구현부
void CharacterClass::printInfo() const
{
	cout << "종족 : " << className << endl;
	cout << "공격력 : " << atk << endl;
	cout << "방어력 : " << def << endl;
	cout << "크리티컬 확률 : " << critRate << "%" << endl;
	cout << "회피 확률 : " << dodgeRate << "%" << endl;
	cout << "현재 체력 : " << health << endl;
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
			cout << "적이 회피에 성공했습니다." << endl;
		}
		else
		{
			int damage;
			damage = (atkdamage - def);
			if (damage <= 0) damage = 0;
			damage += puredamage;
			cout << "적은 " << damage << "의 피해를 입었습니다." << endl;
			health -= damage;
		}
	}
}

int CharacterClass::getHealth() const
{
	return health;
}
#pragma endregion