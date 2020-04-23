#include <string>
#ifndef Room_hpp
#define Room_hpp
#include "Door.hpp"


using namespace std;

class Room
{
    private:
        Door* collectionOfDoors[10];
        int currentNumberOfDoors;
    
    public:
        int inhabitants;
        string title;
        Room(string title);
        void addDoor(Door* newDoor, Room* otherSide);
        void display();
        Door* getDoorAtIndex(int index);
        int getNumOfDoors();

};
#endif