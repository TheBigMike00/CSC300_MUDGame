#include "Room.hpp"
#include "Door.hpp"
#include <string>
#ifndef Student_hpp
#define Student_hpp

using namespace std;

class Student
{
    private:
        string name;
        Room* currentRoom;

    public:
        Student(string name, Room* startingPoint);
        Room* getCurrRoom();
        void move(string destination);
};

#endif