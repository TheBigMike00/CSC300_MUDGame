#include <iostream>

using namespace std;

class Room
{
    private:
        string name;
        int direction; //1=North, 2=East, 3=South, 4=West  
        Room* currRoom; 
        
    public:
        Room* getCurrRoom(); 
        Room(string name);
        int numOfPeople;
        Room* northRoom;
        Room* westRoom;
        Room* southRoom;
        Room* eastRoom;
        //Room(string name, Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);
        void Connect(Room* next, int direction);
        void Add(string name, int direction);
        void Traverse(int direction);
        void DisplayRoomInfo();
};