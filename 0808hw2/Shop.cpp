#include "Shop.h"
#include <iostream>

Shop::Shop()
{
    sellingItemList.push_back(new EquipItem("°Ë", 1000, 1, 10, 0, 0, 0, 5));
    sellingItemList.push_back(new EquipItem("´ë°Ë", 1000, 2, 20, 0, 0, 0, -5));
    sellingItemList.push_back(new EquipItem("°©¿Ê", 1000, 1, 0, 10, 10, 0, 5));
}

Shop::~Shop()
{
    for (Item* item : sellingItemList)
    {
        delete item;
        item = nullptr;
    }
}

void Shop::showList()
{
    int index = 1;
    for (Item* item : sellingItemList)
    {
        std::cout << '[' << index++ << "¹ø ¾ÆÀÌÅÛ]" << std::endl;
        item->printInfo();
        std::cout << std::endl;
    }
}

int Shop::getListSize()
{
    return sellingItemList.size();
}

Item* Shop::sell(int selection)
{
    sellingItemList[selection - 1]->addAmount(-1);
    Item* soldItem = sellingItemList[selection - 1]->clone();

    if (sellingItemList[selection - 1]->getAmount() == 0)
    {
        delete sellingItemList[selection - 1];
        sellingItemList.erase(sellingItemList.begin() + (selection - 1));
    }

    return soldItem;
}

int Shop::getItemPrice(int selection) const
{
    return sellingItemList[selection-1]->getPrice();
}

void Shop::buy(Item* item)
{
    for (Item* myItem : sellingItemList)
    {
        if (myItem->getName() == item->getName())
        {
            myItem->addAmount(1);
            item->addAmount(-1);
        }
    }
    Item* newItem = item->clone();
    newItem->setAmount(1);
    newItem->setPrice(newItem->getPrice() * 2);
    sellingItemList.push_back(newItem);
}