#include <iostream>
#include "Item.h"

using std::cout;
using std::endl;

ConsumptionItem::ConsumptionItem(const std::string& name, int price, int amount) : Item(name, price, amount) {}

void ConsumptionItem::printInfo()
{
	cout << "아이템명 : " << name << endl;
	cout << "가격 : " << price << endl;
	cout << "수량 : " << amount << endl;
}

EquipItem::EquipItem(const std::string& name, int price, int amount, int atk, int def, int hp, int dodgeRate, int criticalRate)
	:Item(name,price,amount), atk(atk), def(def),hp(hp),dodgeRate(dodgeRate),criticalRate(criticalRate) {}

void EquipItem::printInfo()
{
	cout << "아이템명 : " << name << endl;
	cout << "가격 : " << price << endl;
	cout << "수량 : " << amount << endl;
	if (atk != 0) cout << "공격력 : " << atk << endl;
	if (def != 0) cout << "방어력 : " << def << endl;
	if (hp != 0) cout << "체력 : " << hp << endl;
	if (dodgeRate != 0) cout << "회피율 : " << dodgeRate << '%' << endl;
	if (criticalRate != 0) cout << "크리율 : " << criticalRate << '%' << endl;
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
