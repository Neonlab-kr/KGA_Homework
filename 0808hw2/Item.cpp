#include <iostream>
#include "Item.h"

using std::cout;
using std::endl;

ConsumptionItem::ConsumptionItem(const std::string& name, int price, int amount) : Item(name, price, amount) {}

void ConsumptionItem::printInfo()
{
	cout << "�����۸� : " << name << endl;
	cout << "���� : " << price << endl;
	cout << "���� : " << amount << endl;
}

EquipItem::EquipItem(const std::string& name, int price, int amount, int atk, int def, int hp, int dodgeRate, int criticalRate)
	:Item(name,price,amount), atk(atk), def(def),hp(hp),dodgeRate(dodgeRate),criticalRate(criticalRate) {}

void EquipItem::printInfo()
{
	cout << "�����۸� : " << name << endl;
	cout << "���� : " << price << endl;
	cout << "���� : " << amount << endl;
	if (atk != 0) cout << "���ݷ� : " << atk << endl;
	if (def != 0) cout << "���� : " << def << endl;
	if (hp != 0) cout << "ü�� : " << hp << endl;
	if (dodgeRate != 0) cout << "ȸ���� : " << dodgeRate << '%' << endl;
	if (criticalRate != 0) cout << "ũ���� : " << criticalRate << '%' << endl;
}

bool EquipItem::getEquipped()
{
	return equipped;
}

void EquipItem::setEquipped(bool equipped)
{
	this->equipped = equipped;
}

int EquipItem::getAtk() const
{
	return atk;
}

int EquipItem::getDef() const
{
	return def;
}

int EquipItem::getHp() const
{
	return hp;
}

int EquipItem::getDodgeRate() const
{
	return dodgeRate;
}

int EquipItem::getCriticalRate() const
{
	return criticalRate;
}

std::string Item::getName() const
{
	return name;
}

int Item::getPrice() const
{
	return price;
}

void Item::setPrice(int price)
{
	this->price = price;
}

void Item::addAmount(int amount)
{
	this->amount += amount;
}

int Item::getAmount() const
{
	return amount;
}

void Item::setAmount(int amount)
{
	this->amount = amount;
}
