#include <string>
#include <iostream>
#ifndef Door_hpp
#define Door_hpp
#include "Room.hpp"


using namespace std;

class Door
{
    private:

    public:
        Door(string directionToRoomA, Room* roomA, string directionToRoomB, Room* roomB);
        string directionToRoomA;
        string directionToRoomB;
        Room* roomA;
        Room* roomB;
};
#endif