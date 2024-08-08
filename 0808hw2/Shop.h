#pragma once
#include<vector>
#include "Item.h"

class Shop
{
private:
	std::vector<Item*> sellingItemList;

public:
	Shop();
	~Shop();
	void showList();
	int getListSize();
	Item* sell(int selection);
	int getItemPrice(int selection) const;
	void buy(Item* item);
};

