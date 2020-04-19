#include "Door.hpp"
#include <iostream>
using namespace std;

Door::Door(Room* currRoom, Room* accessRoom, bool isLocked)
{
    this->currRoom = currRoom;
    this->accessRoom = accessRoom;
    this->isLocked = isLocked;
}