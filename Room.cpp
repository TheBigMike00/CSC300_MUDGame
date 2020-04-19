#include "Room.hpp"

Room::Room(string name)
{
    this->name = name;
    this->northRoom = 0;
    this->eastRoom = 0;
    this->southRoom = 0;
    this->westRoom = 0;
    this->currRoom = this;
}

/*
Room::Room(string name,  Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom)
{
    this->name = name;
    this->northRoom = northRoom;
    this->eastRoom = eastRoom;
    this->southRoom = southRoom;
    this->westRoom = westRoom;
}*/

void Room::Connect(Room* next, int direction)
{
    if(direction == 1)
    {
        this->northRoom = next;
        next->southRoom = this;
    }
    else if(direction == 2)
    {
        this->eastRoom = next;
        next->westRoom = this;
    }
    else if(direction == 3)
    {
        this->southRoom = next;
        next->northRoom = this;
    }
    else if(direction == 4)
    {
        this->westRoom = next;
        next->eastRoom = this;
    }
}

void Room::Add(string name, int direction)
{
    Room* newerRoom = new Room(name);
    //Connect(this, newerRoom, direction);
    this->currRoom = newerRoom;
}

void Room::Traverse(int direction)
{
    if(direction == 1 && this->currRoom->northRoom)
    {
        this->currRoom = this->currRoom->northRoom;
        cout<<"I wuz here";
    }
    else if(direction == 2 && this->currRoom->eastRoom)
    {
        this->currRoom = this->currRoom->eastRoom;
        cout<<"I wuz here";
    }
    else if(direction == 3 )
    {
        this->currRoom = this->southRoom;
        cout<<"I wuz here";
    }
    else if(direction == 4 && this->currRoom->westRoom)
    {
        this->currRoom = this->currRoom->westRoom;
    }
}

Room* Room::getCurrRoom()
{
    return this->currRoom;
}

void Room::DisplayRoomInfo()
{
    cout << "You are currently in the " << this->name << " (" << this->numOfPeople<< " inhabitants) \n";
    if (northRoom)
    {
        cout << this->northRoom->name << " is to your north." << this->northRoom->numOfPeople <<" inhabitants \nType '1' to go North.\n\n";
    }
    if (eastRoom)
    {
        cout << this->eastRoom->name << " is to your east." << this->eastRoom->numOfPeople <<" inhabitants  \nType '2' to go East.\n\n";
    }
    if (southRoom)
    {
        cout << this->southRoom->name << " is to your south." << this->southRoom->numOfPeople <<" inhabitants  \nType '3' to go South.\n\n";
    }
    if (westRoom)
    {
        cout << this->westRoom->name << " is to your west." << this->westRoom->numOfPeople <<" inhabitants  \nType '4' to go West.\n\n";
    }
    cout<<"-----------------------------------\n";
}