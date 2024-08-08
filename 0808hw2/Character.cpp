#include <iostream>
#include <conio.h>
#include <vector>
#include "Character.h"

using std::cout;
using std::endl;

#pragma region Character
void Character::printStatus() const
{
	cout << "���� : " << className << endl;
	cout << "���ݷ� : " << atk << endl;
	cout << "���� : " << def << endl;
	cout << "ũ��Ƽ�� Ȯ�� : " << critRate << "%" << endl;
	cout << "ȸ�� Ȯ�� : " << dodgeRate << "%" << endl;
	cout << "���� ü�� : " << health << endl;
}

void Character::printInventory() const
{
	int index = 1;
	for (Item* item : inventory)
	{
		std::cout << '[' << index++ << "�� ������]" << std::endl;
		item->printInfo();
		std::cout << std::endl;
	}
	cout << "���� ��� : " << money << endl;
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
			cout << "ȸ�ǿ� �����߽��ϴ�." << endl;
		}
		else
		{
			int damage;
			damage = (atkdamage - def);
			if (damage <= 0) damage = 0;
			damage += puredamage;
			cout << damage << "�� ���ظ� �Ծ����ϴ�." << endl;
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
	cout << soldItem->getName() << "�Ǹ� �Ϸ�." << endl;
	cout << "���� ������ : " << money << endl;
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
			cout << myItem->getName() << "���ԿϷ�" << endl;
			cout << "���� ������ : " << money << endl;
			return;
		}
	}
	Item* newItem = item->clone();
	money -= item->getPrice();
	delete item;
	newItem->setAmount(1);
	newItem->setPrice(newItem->getPrice() / 2);
	inventory.push_back(newItem);
	cout << newItem->getName() << "���ԿϷ�" << endl;
	cout << "���� ������ : " << money << endl;
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

#pragma region Elf
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
		piercingArrow(atkdamage, pureDamage);
		return false;

	default:
		system("cls");
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
}
#pragma endregion

#pragma region Human
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
	inventory.push_back(new EquipItem("�ΰ� �⺻��",0,1,0,0,0,0,0));
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

#pragma region Orc
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