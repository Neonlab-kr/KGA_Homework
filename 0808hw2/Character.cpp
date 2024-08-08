#include <iostream>
#include <conio.h>
#include <vector>
#include "Character.h"

using std::cout;
using std::endl;

#pragma region Character
void Character::printStatus() const
{
	cout << "종족 : " << className << endl;
	cout << "공격력 : " << atk << endl;
	cout << "방어력 : " << def << endl;
	cout << "크리티컬 확률 : " << critRate << "%" << endl;
	cout << "회피 확률 : " << dodgeRate << "%" << endl;
	cout << "현재 체력 : " << health << endl;
}

void Character::printInventory() const
{
	int index = 1;
	for (Item* item : inventory)
	{
		std::cout << '[' << index++ << "번 아이템]" << std::endl;
		item->printInfo();
		std::cout << std::endl;
	}
	cout << "현재 골드 : " << money << endl;
}

bool Character::rateCheck(const int rate) const
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

void Character::Defence(const int atkdamage, const int puredamage)
{
	if (atkdamage != 0 || puredamage != 0)
	{
		if (rateCheck(dodgeRate))
		{
			cout << "회피에 성공했습니다." << endl;
		}
		else
		{
			int damage;
			damage = (atkdamage - def);
			if (damage <= 0) damage = 0;
			damage += puredamage;
			cout << damage << "의 피해를 입었습니다." << endl;
			health -= damage;
		}
	}
}

void Character::incMoney(int money)
{
	this->money += money;
}

int Character::getHealth() const
{
	return health;
}

int Character::getMoney() const
{
	return money;
}

int Character::getInventorySize() const
{
	return inventory.size();
}

Item* Character::getItem(int selection)
{
	return inventory[selection-1];
}

Item* Character::sell(int selection)
{
	inventory[selection - 1]->addAmount(-1);
	Item* soldItem = inventory[selection - 1]->clone();

	if (inventory[selection - 1]->getAmount() == 0)
	{
		delete inventory[selection - 1];
		inventory.erase(inventory.begin() + (selection - 1));
	}
	money += soldItem->getPrice();
	cout << soldItem->getName() << "판매 완료." << endl;
	cout << "현재 소지금 : " << money << endl;
	return soldItem;
}

void Character::buy(Item* item)
{
	for (Item* myItem : inventory)
	{
		if (myItem->getName() == item->getName())
		{
			myItem->addAmount(1);
			item->addAmount(-1);
			money -= item->getPrice();
			delete item;
			cout << myItem->getName() << "구입완료" << endl;
			cout << "남은 소지금 : " << money << endl;
			return;
		}
	}
	Item* newItem = item->clone();
	money -= item->getPrice();
	delete item;
	newItem->setAmount(1);
	newItem->setPrice(newItem->getPrice() / 2);
	inventory.push_back(newItem);
	cout << newItem->getName() << "구입완료" << endl;
	cout << "남은 소지금 : " << money << endl;
}

void Character::equip(EquipItem* item)
{
	atk += item->getAtk();
	def += item->getDef();
	health += item->getHp();
	dodgeRate += item->getDodgeRate();
	critRate += item->getCriticalRate();
}

void Character::unequip(EquipItem* item)
{
	atk -= item->getAtk();
	def -= item->getDef();
	health -= item->getHp();
	dodgeRate -= item->getDodgeRate();
	critRate -= item->getCriticalRate();
}

Character::~Character()
{
	for (Item* item : inventory)
	{
		delete item;
		item = nullptr;
	}
}
#pragma endregion

#pragma region Dracula
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

#pragma region Elf
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
		piercingArrow(atkdamage, pureDamage);
		return false;

	default:
		system("cls");
		cout << "잘못된 입력입니다." << endl;
		break;
	}
}
#pragma endregion

#pragma region Human
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
	inventory.push_back(new EquipItem("인간 기본템",0,1,0,0,0,0,0));
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

#pragma region Orc
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