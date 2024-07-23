#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int enemyTurn(int sel);
int playerTurn();

namespace Player
{
	const int minimumDamage = 30;
	int money = 0;

	namespace Human
	{
		int health = 100;
		int damage = 50;
	}
}

namespace Enemy
{
	namespace Animal
	{
		int const minimumDamage = 5;

		namespace Bear
		{
			string name = "곰";
			int health = 500;
			int EnemyAttack = 15;
			bool fightEnemy()
			{
				while (true)
				{
					Player::Human::health -= enemyTurn(1);
					cout << "유저 체력 : " << Player::Human::health << endl << endl;
					if (Player::Human::health <= 0)
					{
						cout << "사망하셨습니다" << endl;
						return false;
					}

					Enemy::Animal::Bear::health -= playerTurn();
					cout << "곰의 체력 : " << Enemy::Animal::Bear::health << endl << endl;
					if (Enemy::Animal::Bear::health <= 0)
					{
						cout << "곰을 무찌르셨습니다!" << endl;
						Enemy::Animal::Bear::health = 500;
						cout << "체력 회복 200, 골드 500획득" << endl;
						Player::Human::health += 100;
						Player::money += 500;
						cout << "현재 체력 : " << Player::Human::health << ", 현재 골드 : " << Player::money << endl;
						return true;
					}
				}
			}
		}

		namespace Tiger
		{
			string name = "호랑이";
			int health = 200;
			int EnemyAttack = 30;
			bool fightEnemy()
			{
				while (true)
				{
					Player::Human::health -= enemyTurn(2);
					cout << "유저 체력 : " << Player::Human::health << endl << endl;
					if (Player::Human::health <= 0)
					{
						cout << "사망하셨습니다" << endl;
						return false;
					}

					Enemy::Animal::Tiger::health -= playerTurn();
					cout << "호랑이의 체력 : " << Enemy::Animal::Tiger::health << endl << endl;
					if (Enemy::Animal::Tiger::health <= 0)
					{
						cout << "호랑이를 무찌르셨습니다!" << endl;
						Enemy::Animal::Tiger::health = 200;
						cout << "체력 회복 100, 골드 300획득" << endl;
						Player::Human::health += 100;
						Player::money += 300;
						cout << "현재 체력 : " << Player::Human::health << ", 현재 골드 : " << Player::money << endl;
						return true;
					}
				}
			}
		}
	}
}

namespace EA = Enemy::Animal;

void main()
{
	srand(time(NULL));
	bool alive;

	SELECTION:
	int enemySelect;
	cout << "상대할 적을 선택하세요(1. 곰 2. 호랑이) : ";
	cin >> enemySelect;

	switch (enemySelect)
	{
	case 1:
		alive = EA::Bear::fightEnemy();
		break;
	case 2:
		alive = EA::Tiger::fightEnemy();
		break;
	default:
		cout << "잘못된 입력입니다." << endl;
		goto SELECTION;
		break;
	}

	if (alive)
	{
		goto SELECTION;
	}
	else
	{
		cout << "Game Over" << endl;
	}
}


int enemyTurn(int sel)
{
	int damage;
	Sleep(1000);
	cout << "적의 턴입니다." << endl << endl;
	Sleep(1000);
	switch (sel)
	{
	case 1: 
		cout << EA::Bear::name << "의 공격!" << endl;
		damage = rand() % EA::Bear::EnemyAttack + EA::minimumDamage;
		cout << damage << "의 데미지!" << endl;
		break;
	case 2:
		cout << EA::Tiger::name << "의 공격!" << endl;
		damage = rand() % EA::Tiger::EnemyAttack + EA::minimumDamage;
		cout << damage << "의 데미지!" << endl;
		break;
	default:
		break;
	}
	
	return damage;
}

int playerTurn()
{
	int damage;
	Sleep(1000);
	cout << "나의 턴입니다." << endl << endl;
	Sleep(1000);
	cout << "나의 공격!" << endl;
	damage = rand() % Player::Human::damage + Player::minimumDamage;
	cout << damage << "의 데미지!" << endl;
	return damage;
}

