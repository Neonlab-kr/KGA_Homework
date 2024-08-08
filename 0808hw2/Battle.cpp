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
		cout << "[게임 규칙]\n";
		cout << "● 플레이어 1명이 진행하는 게임입니다.\n";
		cout << "● 플레이어, 몬스터 순으로 직업을 결정합니다.\n";
		cout << "● 플레이어가 선공입니다.\n";
		cout << "● 키보드의 상단 숫자키를 통해 선택지를 선택합니다.\n";
		cout << endl;
		cout << "Press Any Button To Continue" << endl;
		Sleep(500);
		if (_kbhit()) break;


		system("cls");
		cout << "[게임 규칙]\n";
		cout << "● 플레이어 1명이 진행하는 게임입니다.\n";
		cout << "● 플레이어, 몬스터 순으로 직업을 결정합니다.\n";
		cout << "● 플레이어가 선공입니다.\n";
		cout << "● 키보드의 상단 숫자키를 통해 선택지를 선택합니다.\n";
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
		cout << "Player의 종족을 선택하세요.\n" << endl;
		cout << "[종족 목록]\n" << endl;
		cout << "1. 인간" << endl;
		cout << "- 인간은 끝없이 성장하는 종족입니다." << endl;
		cout << "- 기본 능력치는 낮지만, 공격력과 방어력을 매턴 올릴 수 있습니다." << endl;
		cout << "- 또한 자가 회복이 가능하며 일반 공격이 가능합니다.\n" << endl;
		cout << "2. 오크" << endl;
		cout << "- 오크는 가장 단순하지만 강력한 종족입니다." << endl;
		cout << "- 기본 능력치가 높은 대신 일반 공격만 가능합니다.\n" << endl;
		cout << "3. 엘프" << endl;
		cout << "- 엘프는 민첩하고 치명적인 공격을 하는 종족입니다." << endl;
		cout << "- 매턴 치명타와 회피율을 매턴 올릴 수 있습니다." << endl;
		cout << "- 피해량의 50%는 고정 피해로 들어갑니다.\n" << endl;
		cout << "4. 드라큘라" << endl;
		cout << "- 드라큘라는 체력을 기반으로 한 스킬을 사용하는 종족입니다." << endl;
		cout << "- 적에게 피해를 주며 체력을 회복하거나, 체력을 소모하여 강력한 공격이 가능합니다.\n" << endl;
		cout << "" << endl;

		sel = _getch() - '0';

		switch (sel)
		{
		case 1:
			system("cls");
			player = new Human();
			cout << "Player는 인간 종족입니다.";
			notSelected = false;
			Sleep(1500);
			system("cls");
			break;

		case 2:
			system("cls");
			player = new Orc();
			cout << "Player는 오크 종족입니다.";
			notSelected = false;
			Sleep(1500);
			system("cls");
			break;

		case 3:
			system("cls");
			player = new Elf();
			cout << "Player는 엘프 종족입니다.";
			notSelected = false;
			Sleep(1500);
			system("cls");
			break;

		case 4:
			system("cls");
			player = new Dracula();
			cout << "Player는 드라큘라 종족입니다.";
			notSelected = false;
			Sleep(1500);
			system("cls");
			break;

		default:
			system("cls");
			cout << "잘못된 입력입니다!" << endl;
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
		cout << "[메인 메뉴]" << endl;
		cout << "1. 상점" << endl;
		cout << "2. 전투" << endl;
		cout << "3. 인벤토리" << endl;
		cout << "4. 스테이터스 확인" << endl;
		cout << "5. 게임종료" << endl;

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
			cout << "게임을 종료합니다." << endl;
			Sleep(3000);
			exit(0);

		default:
			cout << "잘못된 입력입니다." << endl;
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
		cout << "1. 구입" << endl;
		cout << "2. 판매" << endl;
		cout << "3. 뒤로가기" << endl;

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
			cout << "잘못된 입력입니다." << endl;
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
		cout << "현재 소지금 : " << player->getMoney() << endl;
		cout << "구입하실 아이템의 번호를 입력하세요(0 입력시 뒤로가기) : ";

		std::cin >> sel;

		if (sel > shop.getListSize())
		{
			cout << "잘못된 입력입니다." << endl;
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
				cout << "소지금이 부족합니다." << endl;
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
		cout << "판매하실 아이템의 번호를 입력하세요(0 입력시 뒤로가기) : ";

		std::cin >> sel;

		if (sel > player->getInventorySize())
		{
			cout << "잘못된 입력입니다." << endl;
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
				cout << "장착중인 아이템입니다." << endl;
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
		cout << "1. 인벤토리 확인" << endl;
		cout << "2. 장착하기" << endl;
		cout << "3. 해제하기" << endl;
		cout << "4. 뒤로가기" << endl;

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
			cout << "잘못된 입력입니다." << endl;
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
		cout << "장착하실 아이템의 번호를 입력하세요(0 입력시 뒤로가기) : ";

		std::cin >> sel;

		if (sel > player->getInventorySize())
		{
			cout << "잘못된 입력입니다." << endl;
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
					cout << item->getName() << "을 장착했습니다." << endl;
					player->equip(item);
				}
				else
				{
					cout << item->getName() << "은 이미 장착중입니다." << endl;
				}
			}
			else
			{
				cout << "장비아이템이 아닙니다." << endl;
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
		cout << "장착 해제하실 아이템의 번호를 입력하세요(0 입력시 뒤로가기) : ";

		std::cin >> sel;

		if (sel > player->getInventorySize())
		{
			cout << "잘못된 입력입니다." << endl;
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
					cout << item->getName() << "을 장착해제 했습니다." << endl;
					player->unequip(item);
				}
				else
				{
					cout << item->getName() << "은 장착중이 아닙니다." << endl;
				}
			}
			else
			{
				cout << "장비아이템이 아닙니다." << endl;
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
	cout << "메인 메뉴로 돌아갑니다..." << endl;
	mainMenu();
}

void Battle::playerTurn()
{
	int atkdamage = 0, pureDamage = 0;
	bool notActed = true;

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	while (notActed)
	{
		cout << "[player의 턴]\n" << endl;

		cout << "[적 정보]" << endl;
		monster->printInfo();
		cout << endl;

		cout << "[나의 정보]" << endl;
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
		cout << "player 사망!" << endl;
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

	cout << "[Monster의 턴]\n" << endl;
	Sleep(1000);
	monster->attack(atkdamage, pureDamage);
	player->Defence(atkdamage, pureDamage);
}

bool Battle::monsterDead(Character*& savePlayerData)
{
	if (monster->getHealth() <= 0)
	{
		system("cls");
		cout << "적 처치 성공!" << endl;
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