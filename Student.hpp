#include "Door.hpp"
#include <iostream>

using namespace std;

class Student
{
    private:
        string name;
        Room* currRoom;
        
    public:
        Student(string name, Room* startingPos);
        void move(int direction);
        Room* getCurrRoom();
        
};