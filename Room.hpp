#include <string>
#include "Door.hpp"
#ifndef Room_hpp
#define Room_hpp



using namespace std;
//class Door;

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
        void DisplayRoomInfo();
        string getTitle();

};
#endif