#include <string>
#include <iostream>

#ifndef Door_hpp
#define Door_hpp


using namespace std;
class Room;

class Door
{
    private:
        

    public:
        string directionToRoomA;
        Room* roomA;
        string directionToRoomB;
        Room* roomB;
        Door(string directionToRoomA, Room* roomA, string directionToRoomB, Room* roomB);
};
#endif