#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Battle.h"
#include "Character.h"

using std::cout;
using std::endl;

void Battle::CursorView(bool show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Battle::printStartScreen()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	while (true)
	{
		system("cls");
		cout << "[Player VS Monster]\n";
		cout << endl;
		cout << "Press Any Button To Continue" << endl;
		Sleep(500);
		if (_kbhit()) break;


		system("cls");
		cout << "[Player VS Monster]\n";
		Sleep(500);
		if (_kbhit()) break;
	}
	system("cls");
}

void Battle::printRules()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	while (true)
	{
		system("cls");
		cout << "[���� ��Ģ]\n";
		cout << "�� �÷��̾� 1���� �����ϴ� �����Դϴ�.\n";
		cout << "�� �÷��̾�, ���� ������ ������ �����մϴ�.\n";
		cout << "�� �÷��̾ �����Դϴ�.\n";
		cout << "�� Ű������ ��� ����Ű�� ���� �������� �����մϴ�.\n";
		cout << endl;
		cout << "Press Any Button To Continue" << endl;
		Sleep(500);
		if (_kbhit()) break;


		system("cls");
		cout << "[���� ��Ģ]\n";
		cout << "�� �÷��̾� 1���� �����ϴ� �����Դϴ�.\n";
		cout << "�� �÷��̾�, ���� ������ ������ �����մϴ�.\n";
		cout << "�� �÷��̾ �����Դϴ�.\n";
		cout << "�� Ű������ ��� ����Ű�� ���� �������� �����մϴ�.\n";
		Sleep(500);
		if (_kbhit()) break;
	}
	system("cls");
}

void Battle::selClass()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	int sel;
	bool notSelected = true;

	system("cls");
	while (notSelected)
	{
		cout << "Player�� ������ �����ϼ���.\n" << endl;
		cout << "[���� ���]\n" << endl;
		cout << "1. �ΰ�" << endl;
		cout << "- �ΰ��� ������ �����ϴ� �����Դϴ�." << endl;
		cout << "- �⺻ �ɷ�ġ�� ������, ���ݷ°� ������ ���� �ø� �� �ֽ��ϴ�." << endl;
		cout << "- ���� �ڰ� ȸ���� �����ϸ� �Ϲ� ������ �����մϴ�.\n" << endl;
		cout << "2. ��ũ" << endl;
		cout << "- ��ũ�� ���� �ܼ������� ������ �����Դϴ�." << endl;
		cout << "- �⺻ �ɷ�ġ�� ���� ��� �Ϲ� ���ݸ� �����մϴ�.\n" << endl;
		cout << "3. ����" << endl;
		cout << "- ������ ��ø�ϰ� ġ������ ������ �ϴ� �����Դϴ�." << endl;
		cout << "- ���� ġ��Ÿ�� ȸ������ ���� �ø� �� �ֽ��ϴ�." << endl;
		cout << "- ���ط��� 50%�� ���� ���ط� ���ϴ�.\n" << endl;
		cout << "4. ���ŧ��" << endl;
		cout << "- ���ŧ��� ü���� ������� �� ��ų�� ����ϴ� �����Դϴ�." << endl;
		cout << "- ������ ���ظ� �ָ� ü���� ȸ���ϰų�, ü���� �Ҹ��Ͽ� ������ ������ �����մϴ�.\n" << endl;
		cout << "" << endl;

		sel = _getch() - '0';

		switch (sel)
		{
		case 1:
			system("cls");
			player = new Human();
			cout << "Player�� �ΰ� �����Դϴ�.";
			notSelected = false;
			Sleep(1500);
			system("cls");
			break;

		case 2:
			system("cls");
			player = new Orc();
			cout << "Player�� ��ũ �����Դϴ�.";
			notSelected = false;
			Sleep(1500);
			system("cls");
			break;

		case 3:
			system("cls");
			player = new Elf();
			cout << "Player�� ���� �����Դϴ�.";
			notSelected = false;
			Sleep(1500);
			system("cls");
			break;

		case 4:
			system("cls");
			player = new Dracula();
			cout << "Player�� ���ŧ�� �����Դϴ�.";
			notSelected = false;
			Sleep(1500);
			system("cls");
			break;

		default:
			system("cls");
			cout << "�߸��� �Է��Դϴ�!" << endl;
			break;
		}
	}
}

void Battle::mainMenu()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	int sel;
	bool notSelected = true;
	while (notSelected)
	{
		system("cls");
		cout << "[���� �޴�]" << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �κ��丮" << endl;
		cout << "4. �������ͽ� Ȯ��" << endl;
		cout << "5. ��������" << endl;

		sel = _getch() - '0';

		switch (sel)
		{
		case 1:
			shopMenu();
			notSelected = false;
			break;

		case 2:
			Fight();
			notSelected = false;
			break;

		case 3:
			inventoryMenu();
			notSelected = false;
			break;

		case 4:
			system("cls");
			player->printStatus();
			Sleep(3000);
			notSelected = false;
			mainMenu();
			break;

		case 5:
			cout << "������ �����մϴ�." << endl;
			Sleep(3000);
			exit(0);

		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(1000);
			break;
		}
	}
}

void Battle::shopMenu()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	int sel;
	bool notSelected = true;
	while (notSelected)
	{
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. �Ǹ�" << endl;
		cout << "3. �ڷΰ���" << endl;

		sel = _getch() - '0';

		switch (sel)
		{
		case 1:
			system("cls");
			shopMenu_buyItem();
			notSelected = false;
			break;

		case 2:
			system("cls");
			shopMenu_sellItem();
			notSelected = false;
			break;

		case 3:
			mainMenu();
			notSelected = false;
			break;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(1000);
			break;
		}
	}
}

void Battle::shopMenu_buyItem()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	CursorView(true);
	int sel;
	while (true)
	{
		system("cls");
		shop.showList();
		cout << "���� ������ : " << player->getMoney() << endl;
		cout << "�����Ͻ� �������� ��ȣ�� �Է��ϼ���(0 �Է½� �ڷΰ���) : ";

		std::cin >> sel;

		if (sel > shop.getListSize())
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(1000);
		}
		else if (sel == 0)
		{
			CursorView(false);
			shopMenu();
			break;
		}
		else
		{
			if (player->getMoney() < shop.getItemPrice(sel))
			{
				cout << "�������� �����մϴ�." << endl;
			}
			else
			{
				player->buy(shop.sell(sel));
			}
			Sleep(2000);
		}
	}
	CursorView(false);
}

void Battle::shopMenu_sellItem()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	CursorView(true);
	int sel;
	while (true)
	{
		system("cls");
		player->printInventory();
		cout << "�Ǹ��Ͻ� �������� ��ȣ�� �Է��ϼ���(0 �Է½� �ڷΰ���) : ";

		std::cin >> sel;

		if (sel > player->getInventorySize())
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(1000);
		}
		else if (sel == 0)
		{
			CursorView(false);
			shopMenu();
			break;
		}
		else
		{
			EquipItem* item = dynamic_cast<EquipItem*>(player->getItem(sel));
			if (item && item->getEquipped())
			{
				cout << "�������� �������Դϴ�." << endl;
			}
			else
			{
				shop.buy(player->sell(sel));
			}
			Sleep(2000);
		}
	}
	CursorView(false);
}

void Battle::inventoryMenu()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	int sel;
	bool notSelected = true;
	while (notSelected)
	{
		system("cls");
		cout << "1. �κ��丮 Ȯ��" << endl;
		cout << "2. �����ϱ�" << endl;
		cout << "3. �����ϱ�" << endl;
		cout << "4. �ڷΰ���" << endl;

		sel = _getch() - '0';

		switch (sel)
		{
		case 1:
			system("cls");
			player->printInventory();
			Sleep(3000);
			inventoryMenu();
			notSelected = false;
			break;

		case 2:
			system("cls");
			inventoryMenu_equipItem();
			notSelected = false;
			break;

		case 3:
			system("cls");
			inventoryMenu_unequipItem();
			notSelected = false;
			break;

		case 4:
			mainMenu();
			notSelected = false;
			break;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(1000);
			break;
		}
	}
}

void Battle::inventoryMenu_equipItem()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	CursorView(true);
	int sel;
	while (true)
	{
		system("cls");
		player->printInventory();
		cout << "�����Ͻ� �������� ��ȣ�� �Է��ϼ���(0 �Է½� �ڷΰ���) : ";

		std::cin >> sel;

		if (sel > player->getInventorySize())
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(1000);
		}
		else if (sel == 0)
		{
			CursorView(false);
			inventoryMenu();
			break;
		}
		else
		{
			EquipItem* item = dynamic_cast<EquipItem*>(player->getItem(sel));

			if (item)
			{
				if(!item->getEquipped())
				{
					item->setEquipped(true);
					cout << item->getName() << "�� �����߽��ϴ�." << endl;
					player->equip(item);
				}
				else
				{
					cout << item->getName() << "�� �̹� �������Դϴ�." << endl;
				}
			}
			else
			{
				cout << "���������� �ƴմϴ�." << endl;
			}
			Sleep(2000);
		}
	}
	CursorView(false);
}

void Battle::inventoryMenu_unequipItem()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	CursorView(true);
	int sel;
	while (true)
	{
		system("cls");
		player->printInventory();
		cout << "���� �����Ͻ� �������� ��ȣ�� �Է��ϼ���(0 �Է½� �ڷΰ���) : ";

		std::cin >> sel;

		if (sel > player->getInventorySize())
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(1000);
		}
		else if (sel == 0)
		{
			CursorView(false);
			inventoryMenu();
			break;
		}
		else
		{
			EquipItem* item = dynamic_cast<EquipItem*>(player->getItem(sel));

			if (item)
			{
				if(item->getEquipped())
				{
					item->setEquipped(false);
					cout << item->getName() << "�� �������� �߽��ϴ�." << endl;
					player->unequip(item);
				}
				else
				{
					cout << item->getName() << "�� �������� �ƴմϴ�." << endl;
				}
			}
			else
			{
				cout << "���������� �ƴմϴ�." << endl;
			}
			Sleep(2000);
		}
	}
	CursorView(false);
}

void Battle::Fight()
{
	if (monster)
	{
		delete monster;
		monster = nullptr;
	}
	monster = new Monster();
	Character* savePlayerData = player->clone();
	system("cls");
	while (true)
	{
		playerTurn();
		Sleep(2000);
		if (monsterDead(savePlayerData)) break;
		monsterTurn();
		Sleep(2000);
		if (playerDead(savePlayerData)) break;
	}
	Sleep(1500);
	cout << "���� �޴��� ���ư��ϴ�..." << endl;
	mainMenu();
}

void Battle::playerTurn()
{
	int atkdamage = 0, pureDamage = 0;
	bool notActed = true;

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	while (notActed)
	{
		cout << "[player�� ��]\n" << endl;

		cout << "[�� ����]" << endl;
		monster->printInfo();
		cout << endl;

		cout << "[���� ����]" << endl;
		player->printStatus();
		cout << endl;
		notActed = player->Act(atkdamage, pureDamage);
	}

	monster->TakeDamage(atkdamage, pureDamage);
}

bool Battle::playerDead(Character*& savePlayerData)
{
	if (player->getHealth() <= 0)
	{
		system("cls");
		cout << "player ���!" << endl;
		delete player;
		player = nullptr;
		player = savePlayerData;
		return true;
	}
	return false;
}

void Battle::monsterTurn()
{
	int atkdamage = 0, pureDamage = 0;

	cout << "[Monster�� ��]\n" << endl;
	Sleep(1000);
	monster->attack(atkdamage, pureDamage);
	player->Defence(atkdamage, pureDamage);
}

bool Battle::monsterDead(Character*& savePlayerData)
{
	if (monster->getHealth() <= 0)
	{
		system("cls");
		cout << "�� óġ ����!" << endl;
		delete player;
		player = nullptr;
		player = savePlayerData;
		player->incMoney(monster->getRewardMoney());
		return true;
	}
	return false;
}

Battle::~Battle()
{
	delete player;
	player = nullptr;
	delete monster;
	monster = nullptr;
}

void Battle::gameStart()
{
	CursorView(false);
	printStartScreen();
	printRules();

	selClass();

	mainMenu();

	CursorView(true);
}