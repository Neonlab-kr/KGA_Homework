#pragma once
#include "Character.h"
#include "Monster.h"
#include "Shop.h"

class Battle
{
private:
	bool turn = 0;
	Shop shop;
	Character* player;
	Monster* monster;

	void CursorView(bool show);
	void printStartScreen();
	void printRules();
	void selClass();
	void mainMenu();
	void shopMenu();
	void shopMenu_buyItem();
	void shopMenu_sellItem();
	void inventoryMenu();
	void inventoryMenu_equipItem();
	void inventoryMenu_unequipItem();
	void Fight();
	void playerTurn();
	bool playerDead(Character*& savePlayerData);
	void monsterTurn();
	bool monsterDead(Character*& savePlayerData);
public:
	~Battle();
	void gameStart();
};