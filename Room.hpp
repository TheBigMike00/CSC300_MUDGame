#ifndef Room_hpp
#define Room_hpp

#include <string>
#include "LinkedListOfStudents.hpp"

class Door; // allows us to reference door when door refereneces Room.

using namespace std;

class Room
{
    private:
        string title;
        Door* collectionOfDoors[10];
        int currentNumberOfDoors;
        LinkedListOfStudents* theStudents;
        //Item* itemsInRoom[10];
        int currNumOfItems;
    
    public:
        
        Item* itemsInRoom[10];
        Room(string title);
        void addDoor(Door* aDoor);
        void display();
        void addStudent(Student* aStudent);
        void removeStudent(Student* aStudent);
        void takeDoor(Student* aStudent, string direction);
        void addItem(string itemName);
        void lookAround();

        bool isAItem(string itemName);
        int getItemIndex(string ItemName);
        int getCurrNumOfItems();
};
#endif