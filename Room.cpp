#include "Room.hpp"
#include <iostream>
using namespace std;

Room::Room(string title)
{
    this->title = title;
    this->currentNumberOfDoors = 0;
}

void Room::addDoor(Door* newDoor, Room* otherSide)
{
    this->collectionOfDoors[this->currentNumberOfDoors] = newDoor;
    otherSide->collectionOfDoors[otherSide->currentNumberOfDoors] = newDoor;
    otherSide->currentNumberOfDoors++;
    this->currentNumberOfDoors++;
}

void Room::display()
{
    cout<<"You are currently in room: " << this->title << "\n";
    cout<<"Current Inahitants: " << this->inhabitants << "\nAvailable Doors: " << this->currentNumberOfDoors << "\n";
}

Door* Room::getDoorAtIndex(int index)
{
    if(index < this->currentNumberOfDoors && index>=0)
    {
        return this->collectionOfDoors[index];
    }
}

int Room::getNumOfDoors()
{
    return this->currentNumberOfDoors;
}