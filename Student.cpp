#include "Student.hpp"

Student::Student(string name, Room* startingPoint)
{
    this->name = name;
    this->currentRoom = startingPoint;
}

Room* Student::getCurrRoom()
{
    return this->currentRoom;
}

void Student::move(string destination)
{
    for(int i = 0; i<this->currentRoom->getNumOfDoors(); i++)
    {
        Door* tempDoor = this->currentRoom->getDoorAtIndex(i);
        if(this->currentRoom->title == tempDoor->roomA->title)
        {
            if(tempDoor->directionToRoomB == destination)
            {
                this->currentRoom->inhabitants--;
                this->currentRoom = tempDoor->roomB;
                tempDoor->roomA->inhabitants++;
            }
        }
        else if(this->currentRoom->title == tempDoor->roomB->title)
        {
            if(tempDoor->directionToRoomA == destination)
            {
                this->currentRoom->inhabitants--;
                this->currentRoom = tempDoor->roomA;
                tempDoor->roomA->inhabitants++;
            }
        }
        
    }
}