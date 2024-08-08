#pragma once
#include<iostream>

class Item abstract
{
protected:
	const std::string name;
	int price;
	int amount;
public:
	Item(const std::string& name, int price, int amount) : name(name), price(price), amount(amount) {};
	virtual ~Item() {}
	virtual Item* clone() const = 0;
	std::string getName() const;
	int getPrice() const;
	void setPrice(int price);
	void addAmount(int amount);
	int getAmount() const;
	void setAmount(int amount);
	virtual void printInfo() = 0;
};

class ConsumptionItem : public Item
{
public:
	ConsumptionItem(const std::string& name, int price, int amount);
	~ConsumptionItem() override {}
	virtual Item* clone() const override {return new ConsumptionItem(*this);}
	void printInfo() override;
};

class EquipItem : public Item
{
private:
	const int atk, def, hp, dodgeRate, criticalRate;
	bool equipped = false;
public:
	EquipItem(const std::string& name, int price, int amount, int atk, int def, int hp, int dodgeRate, int criticalRate);
	~EquipItem() override {}
	virtual Item* clone() const override { return new EquipItem(*this); }
	void printInfo() override;
	bool getEquipped();
	void setEquipped(bool equipped);
	int getAtk()const;
	int getDef()const;
	int getHp()const;
	int getDodgeRate()const;
	int getCriticalRate()const;
};