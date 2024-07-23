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
			string name = "��";
			int health = 500;
			int EnemyAttack = 15;
			bool fightEnemy()
			{
				while (true)
				{
					Player::Human::health -= enemyTurn(1);
					cout << "���� ü�� : " << Player::Human::health << endl << endl;
					if (Player::Human::health <= 0)
					{
						cout << "����ϼ̽��ϴ�" << endl;
						return false;
					}

					Enemy::Animal::Bear::health -= playerTurn();
					cout << "���� ü�� : " << Enemy::Animal::Bear::health << endl << endl;
					if (Enemy::Animal::Bear::health <= 0)
					{
						cout << "���� ����̽��ϴ�!" << endl;
						Enemy::Animal::Bear::health = 500;
						cout << "ü�� ȸ�� 200, ��� 500ȹ��" << endl;
						Player::Human::health += 100;
						Player::money += 500;
						cout << "���� ü�� : " << Player::Human::health << ", ���� ��� : " << Player::money << endl;
						return true;
					}
				}
			}
		}

		namespace Tiger
		{
			string name = "ȣ����";
			int health = 200;
			int EnemyAttack = 30;
			bool fightEnemy()
			{
				while (true)
				{
					Player::Human::health -= enemyTurn(2);
					cout << "���� ü�� : " << Player::Human::health << endl << endl;
					if (Player::Human::health <= 0)
					{
						cout << "����ϼ̽��ϴ�" << endl;
						return false;
					}

					Enemy::Animal::Tiger::health -= playerTurn();
					cout << "ȣ������ ü�� : " << Enemy::Animal::Tiger::health << endl << endl;
					if (Enemy::Animal::Tiger::health <= 0)
					{
						cout << "ȣ���̸� ����̽��ϴ�!" << endl;
						Enemy::Animal::Tiger::health = 200;
						cout << "ü�� ȸ�� 100, ��� 300ȹ��" << endl;
						Player::Human::health += 100;
						Player::money += 300;
						cout << "���� ü�� : " << Player::Human::health << ", ���� ��� : " << Player::money << endl;
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
	cout << "����� ���� �����ϼ���(1. �� 2. ȣ����) : ";
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
		cout << "�߸��� �Է��Դϴ�." << endl;
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
	cout << "���� ���Դϴ�." << endl << endl;
	Sleep(1000);
	switch (sel)
	{
	case 1: 
		cout << EA::Bear::name << "�� ����!" << endl;
		damage = rand() % EA::Bear::EnemyAttack + EA::minimumDamage;
		cout << damage << "�� ������!" << endl;
		break;
	case 2:
		cout << EA::Tiger::name << "�� ����!" << endl;
		damage = rand() % EA::Tiger::EnemyAttack + EA::minimumDamage;
		cout << damage << "�� ������!" << endl;
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
	cout << "���� ���Դϴ�." << endl << endl;
	Sleep(1000);
	cout << "���� ����!" << endl;
	damage = rand() % Player::Human::damage + Player::minimumDamage;
	cout << damage << "�� ������!" << endl;
	return damage;
}

