#include <iostream>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Player
{
private:
	const int mAtk;
	const int mDef;
	int mHealth;
public:
	Player(const int atk, const int def, const int health) : mAtk(atk), mDef(def), mHealth(health) {}

	int getAtk() const
	{
		return mAtk;
	}

	int getDef() const
	{
		return mDef;
	}

	int getHealth() const
	{
		return mHealth;
	}

	void getDamage(int damage)
	{
		mHealth -= damage;
	}
};

class Monster
{
private:
	const int mAtk;
	const int mDef;
	int mHealth;

public:
	Monster(const int atk, const int def, const int health) :mAtk(atk), mDef(def), mHealth(health)
	{

	}

	int getAtk() const
	{
		return mAtk;
	}

	int getDef() const
	{
		return mDef;
	}

	int getHealth() const
	{
		return mHealth;
	}

	void getDamage(int damage)
	{
		mHealth -= damage;
	}

};

class PvMGame
{
private:
	bool turn;
	Player* player;
	Monster* monster;

	void printFirstTurn();
	bool playerTurn();
	bool mosterTurn();

public:
	PvMGame(int pAtk=15, int pDef=5, int pHealth=100, int mAtk=15, int mDef=3, int mHealth=100)
	{
		int num;
		cout << "�����佺�� �����մϴ�." << endl;
		cout << "�ո�(0)�� �޸�(1)�� �ϳ��� �����ϼ��� : " << endl;
		cin >> num;

		srand(time(NULL));
		int coin = rand() % 2;
		Sleep(1000);

		if (coin == 0)
		{
			cout << "�ո��� ���Խ��ϴ�" << endl;
		}
		else
		{
			cout << "�޸��� ���Խ��ϴ�." << endl;
		}

		turn = (num == coin);

		player = new Player(pAtk, pDef, pHealth);
		monster = new Monster(mAtk, mDef, mHealth);
	}

	~PvMGame()
	{
		delete player;
		delete monster;
		player = nullptr;
		monster = nullptr;
	}

	void gameStart()
	{
		printFirstTurn();

		while (true)
		{
			bool end;
			if (turn)
			{
				end = playerTurn();
			}
			else
			{
				end = mosterTurn();
			}
			if (end) break;
			turn = !turn;
			Sleep(1000);
		}
	}
};

int main()
{
	PvMGame game;
	game.gameStart();
	return 0;
}

void PvMGame::printFirstTurn()
{
	Sleep(1000);
	system("cls");
	if (turn)
	{
		cout << "Player�� ����!" << endl << endl;
		Sleep(1000);
	}
	else
	{
		cout << "Monster�� ����!" << endl << endl;
		Sleep(1000);
	}
}

bool PvMGame::playerTurn()
{
	int damage, health;
	cout << "[Player�� ��]" << endl;

	damage = player->getAtk() - monster->getDef();
	cout << damage << "�� ������!" << endl;
	monster->getDamage(damage);

	health = monster->getHealth();
	cout << "Monster�� �ܿ� ü�� : " << health << endl << endl;

	if (health <= 0)
	{
		Sleep(1000);
		cout << "Player�� �¸�!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool PvMGame::mosterTurn()
{
	int damage, health;
	cout << "[Monster�� ��]" << endl;

	damage = monster->getAtk() - player->getDef();
	cout << damage << "�� ������!" << endl;
	player->getDamage(damage);

	health = player->getHealth();
	cout << "Player�� �ܿ� ü�� : " << health << endl << endl;

	if (health <= 0)
	{
		Sleep(1000);
		cout << "Monster�� �¸�!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
