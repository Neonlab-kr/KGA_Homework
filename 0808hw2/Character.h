#pragma once
#include <iostream>
#include <vector>
#include "Item.h"

class Character
{
protected:
	std::vector<Item*> inventory;
	std::string className;
	int money = 0;
	int atk;
	int def;
	int critRate;
	int dodgeRate;
	int health;

public:
	void printStatus() const;
	void printInventory() const;
	bool rateCheck(const int rate) const;
	void Defence(const int atkdamage, const int puredamage);
	void incMoney(int money);
	int getHealth() const;
	int getMoney() const;
	int getInventorySize() const;
	Item* getItem(int selection);
	Item* sell(int selection);
	void buy(Item* item);
	void equip(EquipItem* item);
	void unequip(EquipItem* item);
	virtual ~Character();
	virtual Character* clone() const = 0;
	virtual bool Act(int& atkdamage, int& pureDamage) = 0;
};

class Dracula : public Character
{
private:
	void bloodSucking(int& atkdamage);
	void hemophilia(int& atkdamage);

public:
	Dracula();
	~Dracula() override {}
	virtual Character* clone() const override { return new Dracula(*this); }
	bool Act(int& atkdamage, int& pureDamage) override;
};

class Elf : public Character
{
private:
	void piercingArrow(int& atkdamage, int& pureDamage) const;
	void critBuff();
	void dodgeBuff();

public:
	Elf();
	~Elf() override {}
	virtual Character* clone() const override { return new Elf(*this); }
	bool Act(int& atkdamage, int& pureDamage) override;
};

class Human : public Character
{
private:
	void atkBuff();
	void defBuff();
	void heal();
	void normalAttack(int& atkdamage) const;

public:
	Human();
	~Human() override {}
	virtual Character* clone() const override { return new Human(*this); }
	bool Act(int& atkdamage, int& pureDamage) override;
};

class Orc : public Character
{
private:
	void normalAttack(int& atkdamage) const;

public:
	Orc();
	~Orc() override {}
	virtual Character* clone() const override { return new Orc(*this); }
	bool Act(int& atkdamage, int& pureDamage) override;
};