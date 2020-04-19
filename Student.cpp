#include "Student.hpp"

Student::Student(string name, Room* startingPos)
{
    this->currRoom = startingPos;
    this->name = name;
    this->currRoom->numOfPeople++;
}

void Student::move(int direction)
{
    if(direction == 1 && this->currRoom->northRoom)
    {
        this->currRoom->numOfPeople--;
        this->currRoom = this->currRoom->northRoom;
        this->currRoom->numOfPeople++;
    }
    else if(direction == 2 && this->currRoom->eastRoom)
    {
        this->currRoom->numOfPeople--;
        this->currRoom = this->currRoom->eastRoom;
        this->currRoom->numOfPeople++;
    }
    else if(direction == 3 && this->currRoom->southRoom)
    {
        this->currRoom->numOfPeople--;
        this->currRoom = this->currRoom->southRoom;
        this->currRoom->numOfPeople++;
    }
    else if(direction == 4 && this->currRoom->westRoom)
    {
        this->currRoom->numOfPeople--;
        this->currRoom = this->currRoom->westRoom;
        this->currRoom->numOfPeople++;
    }
    this->currRoom->DisplayRoomInfo();
}

Room* Student::getCurrRoom()
{
    return this->currRoom;
}