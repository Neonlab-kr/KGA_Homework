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
		cout << "코인토스를 실행합니다." << endl;
		cout << "앞면(0)과 뒷면(1)중 하나를 선택하세요 : " << endl;
		cin >> num;

		srand(time(NULL));
		int coin = rand() % 2;
		Sleep(1000);

		if (coin == 0)
		{
			cout << "앞면이 나왔습니다" << endl;
		}
		else
		{
			cout << "뒷면이 나왔습니다." << endl;
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
		cout << "Player의 선턴!" << endl << endl;
		Sleep(1000);
	}
	else
	{
		cout << "Monster의 선턴!" << endl << endl;
		Sleep(1000);
	}
}

bool PvMGame::playerTurn()
{
	int damage, health;
	cout << "[Player의 턴]" << endl;

	damage = player->getAtk() - monster->getDef();
	cout << damage << "의 데미지!" << endl;
	monster->getDamage(damage);

	health = monster->getHealth();
	cout << "Monster의 잔여 체력 : " << health << endl << endl;

	if (health <= 0)
	{
		Sleep(1000);
		cout << "Player의 승리!" << endl;
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
	cout << "[Monster의 턴]" << endl;

	damage = monster->getAtk() - player->getDef();
	cout << damage << "의 데미지!" << endl;
	player->getDamage(damage);

	health = player->getHealth();
	cout << "Player의 잔여 체력 : " << health << endl << endl;

	if (health <= 0)
	{
		Sleep(1000);
		cout << "Monster의 승리!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
