#include "Room.hpp"
#include <iostream>
#include "Door.hpp"

using namespace std;

Room::Room(string title)
{
    this->title = title;
    this->currentNumberOfDoors = 0;
    this->currNumOfItems = 0;
}

void Room::addDoor(Door* aDoor)
{
    this->collectionOfDoors[this->currentNumberOfDoors] = aDoor;
    this->currentNumberOfDoors++;
    this->theStudents = new LinkedListOfStudents();
}

void Room::addStudent(Student* aStudent)
{
    if(this->theStudents->indexOf(aStudent) == -1)
    {
        this->theStudents->addFront(aStudent);
        aStudent->setCurrentRoom(this);
    } 
}

void Room::removeStudent(Student* aStudent)
{
    int indexOfStudent = this->theStudents->indexOf(aStudent);
    if(indexOfStudent != -1)
    {
        this->theStudents->removeAtIndex(indexOfStudent);
        aStudent->setCurrentRoom(0); //the student is in limbo
    }
}

void Room::takeDoor(Student* aStudent, string direction)
{
    Door* tempDoor;
    Room* currentRoom = this;
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        if(tempDoor->getDirectionToOtherRoom(currentRoom) == direction)
        {
            Room* theOtherRoom = tempDoor->getTheOtherRoom(currentRoom);
            
            //remove the student from the current room
            this->removeStudent(aStudent);

            //put the student in the new room
            theOtherRoom->addStudent(aStudent);
        }
    }
}

void Room::display()
{
    cout << this->title << "\n";

    //show the potential doors
    cout << "Obvious Exits: ";
    Door* tempDoor = 0;
    
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        cout << tempDoor->getDirectionToOtherRoom(this) << " ";
    }
    cout << "\n Also Here: ";
    Student* tempStudent;

    for(int i = 0; i < this->theStudents->getCount(); i++)
    {
        tempStudent = this->theStudents->getAtIndex(i);
        cout << tempStudent->getName() << " ";
    }
    cout << "\n";
}

void Room::addItem(string itemName)
{
    Item* anItem = new Item(itemName);
    if (currNumOfItems < 10)
    {
        itemsInRoom[currNumOfItems] = anItem;
        currNumOfItems++;
    }
}

bool Room::isAItem(string itemName)
{
    for (int i = 0; i < this->currNumOfItems; i++)
    {
        if (itemName == this->itemsInRoom[i]->getName())
        {
            return true;
        }
    }
    return false;
}

int Room::getItemIndex(string itemName)
{
    bool verificate = isAItem(itemName);
    if (verificate = true)
    {
        for (int i = 0; i < this->currNumOfItems; i++)
        {
            if (itemName == this->itemsInRoom[i]->getName())
            {
                return i;
            }
        }
    }
    return -1;
}

void Room::lookAround()
{
    for (int i = 0; i<currNumOfItems; i++)
    {
        cout << itemsInRoom[i]->getName() << "\n";
    }
}

int Room::getCurrNumOfItems()
{
    return this->currNumOfItems;
}