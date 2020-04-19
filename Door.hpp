#include "Room.hpp"
#include <iostream>
using namespace std;

class Door
{
    private:
        Room* currRoom;
        Room* accessRoom;
        
        
    public:
        Door(Room* currRoom, Room* accessRoom, bool isLocked);
        bool isLocked;
        
};