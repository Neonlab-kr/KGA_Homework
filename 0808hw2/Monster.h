#pragma once
#include <string>

class Monster
{
private:
	std::string name;
	int atk;
	int def;
	int critRate;
	int dodgeRate;
	int health;
	int rewardMoney;

	bool rateCheck(const int rate) const;
	void normalAttack(int& atkdamage, int& pureDamage);
public:
	Monster();
	void printInfo() const;
	void TakeDamage(int atkDamage,int  pureDamage);
	void attack(int& atkdamage, int& pureDamage);
	int getHealth() const;
	int getRewardMoney() const;
};

