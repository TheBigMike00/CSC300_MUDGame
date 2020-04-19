#include <iostream>
#include "Student.hpp"
using namespace std;


int main()
{
    //Creation and connection of rooms and a locked door to locklairs office.
    Room* locklair = new Room("Dr. Locklair's Office");
    Room* lobby = new Room("Lobby");
    Door* locklobby = new Door(lobby, locklair, true);
    locklair->Connect(lobby, 2);
    Room* server = new Room("Server Room");
    lobby->Connect(server, 1);
    Room* esports = new Room("ESports");
    lobby->Connect(esports, 3);
    Room* hall0 = new Room("Hallway 0");
    lobby->Connect(hall0, 2);
    Room* s120 = new Room("Classroom S120");
    hall0->Connect(s120, 3);
    Room* hall1 = new Room("Hallway 1");
    hall1->Connect(hall0, 3);
    Room* hall1_5 = new Room("Hallway 1.5");
    hall1->Connect(hall1_5, 1);
    Room* hall1_75 = new Room("Hallway 1.75");
    hall1_5->Connect(hall1_75, 2);
    Room* hall2 = new Room("Hallway 2");
    hall1_5->Connect(hall2, 1);
    Room* advLab1 = new Room("Advanced Lab 1");
    hall2->Connect(advLab1, 2);
    Room* advLab2 = new Room("Advanced Lab 2");
    advLab1->Connect(advLab2, 1);
    Room* s118 = new Room("Classroom S118");
    hall2->Connect(s118, 4);
    Room* macLab2 = new Room("Mac Lab2");
    s118->Connect(macLab2, 1);
    Room* macLab1 = new Room("MacLab1");
    macLab2->Connect(macLab1, 2);
    hall2->Connect(macLab1, 1);

    //Student creation
    Student* newGuy = new Student("Wahl-Breaker", hall1_75);
    newGuy->getCurrRoom()->DisplayRoomInfo();

    //Implement user input
    int usrInput = 0;
    while(usrInput != -1)
    {
        cout<<"Where would you like to go?(Type '-1' to quit) ";
        cin>>usrInput;
        newGuy->move(usrInput);
    }

}