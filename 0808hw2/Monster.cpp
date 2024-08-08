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
	cout << "�̸� : " << name << endl;
	cout << "���ݷ� : " << atk << endl;
	cout << "���� : " << def << endl;
	cout << "ũ��Ƽ�� Ȯ�� : " << critRate << "%" << endl;
	cout << "ȸ�� Ȯ�� : " << dodgeRate << "%" << endl;
	cout << "���� ü�� : " << health << endl;
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
	cout << name << "�� �Ϲ� ����!" << endl;
	bool crit = rateCheck(critRate);
	if (crit)
	{
		cout << "ġ��Ÿ ����!" << name << "�� ���ݷ��� 1.5�踸ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk * 1.5;
		cout << "���� : " << atkdamage << endl;
	}
	else
	{
		cout << name << "�� ���ݷ¸�ŭ�� �������� �����մϴ�." << endl;
		atkdamage = atk;
		cout << "���� : " << atkdamage << endl;
	}
}

void Monster::TakeDamage(int atkDamage, int pureDamage)
{
	if (atkDamage != 0 || pureDamage != 0)
	{
		if (rateCheck(dodgeRate))
		{
			cout << name <<"�� ȸ�ǿ� �����߽��ϴ�." << endl;
		}
		else
		{
			int damage;
			damage = (atkDamage - def);
			if (damage <= 0) damage = 0;
			damage += pureDamage;
			cout << name << "�� " << damage << "�� ���ظ� �Ծ����ϴ�." << endl;
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
