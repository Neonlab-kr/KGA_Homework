#include "Monster.h"
#include <iostream>
#include <time.h>

using std::cout;
using std::endl;

Monster::Monster()
{
	name = "Goblin";
	atk = 7;
	def = 3;
	critRate = 20;
	dodgeRate = 10;
	health = 10;
	rewardMoney = 1000;
}

void Monster::printInfo() const
{
	cout << "이름 : " << name << endl;
	cout << "공격력 : " << atk << endl;
	cout << "방어력 : " << def << endl;
	cout << "크리티컬 확률 : " << critRate << "%" << endl;
	cout << "회피 확률 : " << dodgeRate << "%" << endl;
	cout << "현재 체력 : " << health << endl;
}

bool Monster::rateCheck(const int rate) const
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

void Monster::normalAttack(int& atkdamage, int& pureDamage)
{
	cout << name << "의 일반 공격!" << endl;
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "치명타 적중!" << name << "이 공격력의 1.5배만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk * 1.5;
		cout << "위력 : " << atkdamage << endl;
	}
	else
	{
		cout << name << "이 공격력만큼의 위력으로 공격합니다." << endl;
		atkdamage = atk;
		cout << "위력 : " << atkdamage << endl;
	}
}

void Monster::TakeDamage(int atkDamage, int pureDamage)
{
	if (atkDamage != 0 || pureDamage != 0)
	{
		if (rateCheck(dodgeRate))
		{
			cout << name <<"이 회피에 성공했습니다." << endl;
		}
		else
		{
			int damage;
			damage = (atkDamage - def);
			if (damage <= 0) damage = 0;
			damage += pureDamage;
			cout << name << "이 " << damage << "의 피해를 입었습니다." << endl;
			health -= damage;
		}
	}
}

void Monster::attack(int& atkdamage, int& pureDamage)
{
	normalAttack(atkdamage, pureDamage);
}

int Monster::getHealth() const
{
	return health;
}

int Monster::getRewardMoney() const
{
	return rewardMoney;
}
