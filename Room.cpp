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

void Room::DisplayRoomInfo()
{
    cout <<"You are currently at " << this->title << "\n";
    for (int i =0; i < this->currentNumberOfDoors; i++)
    {
        if(this->getTitle() == collectionOfDoors[i]->roomA->title)
        {
            cout << collectionOfDoors[i]->roomB->title << " is to your " << 
                collectionOfDoors[i]->directionToRoomB << ".\n";
            //collectionOfDoors[i]->DisplayDoofo();
        }
        else if(this->getTitle() == collectionOfDoors[i]->roomB->title)
        {
            cout << collectionOfDoors[i]->roomA->title << " is to your " << 
                collectionOfDoors[i]->directionToRoomA << ".\n";
            //collectionOfDoors[i]->DisplayDoofo();
        }
    }
}

string Room::getTitle()
{
    return this->title;
}