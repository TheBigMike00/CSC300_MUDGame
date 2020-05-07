#include "Student.hpp"
#include "Room.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

Student::Student(string name)
{
    this->name = name;
    this->currentRoom = 0;
    this->maxItemCount = 10;
    this->currentItemCount = 0;
    this->backpack = (Item**)malloc(this->maxItemCount * sizeof(Item*));
}

void Student::displayBackpackContents()
{
    for(int i = 0; i < this->currentItemCount; i++)
    {
        cout << this->backpack[i]->getName() << "\n";
    }
}

bool Student::addItem(Item* anItem)
{
    if(this->currentItemCount == this->maxItemCount)
    {
        return false;
    }
    else
    {
        this->backpack[this->currentItemCount] = anItem;
        this->currentItemCount++;
        return true;
    } 
}

string Student::getName()
{
    return this->name;
}

void Student::setCurrentRoom(Room* aRoom)
{
    this->currentRoom = aRoom;
}

Room* Student::getCurrentRoom()
{
    return this->currentRoom;
}

Item* Student::dropItem(string itemToDrop)
{
    int index = getItemIndex(itemToDrop);
    Item* droppingItem = this->backpack[index];
    for (int i = index; i < this->currentItemCount; i++)
    {
        backpack[i] = backpack[i+1];
    }
    this->getCurrentRoom()->addItem(droppingItem->getName());
    this->currentItemCount--;
    return droppingItem;
}

void Student::pickupItem(string itemToPickup)
{
    bool verify = this->getCurrentRoom()->isAItem(itemToPickup);
    if (verify = true)
    {
        int roomItemIndex = this->getCurrentRoom()->getItemIndex(itemToPickup);
        Item* itemWeWillPickUp = this->getCurrentRoom()->itemsInRoom[roomItemIndex];
        for (int i = roomItemIndex; i < this->getCurrentRoom()->getCurrNumOfItems(); i++)
        {
            this->getCurrentRoom()->itemsInRoom[i] = this->getCurrentRoom()->itemsInRoom[i+1];
        }
        this->backpack[currentItemCount] = itemWeWillPickUp;
        currentItemCount++;
    }
}

int Student::getItemIndex(string itemName)
{
    bool verificate = isAItem(itemName);
    if (verificate = true)
    {
        for (int i = 0; i < this->currentItemCount; i++)
        {
            if (itemName == this->backpack[i]->getName())
            {
                return i;
            }
        }
    }
    return -1;
}

bool Student::isAItem(string itemName)
{
    for (int i = 0; i < this->currentItemCount; i++)
    {
        if (itemName == this->backpack[i]->getName())
        {
            return true;
        }
    }
    return false;
}