#include <iostream>
#include "Room.hpp"
using namespace std;


int main()
{
    // Door(string directionToRoomA, Room* roomA, string directionToRoomB, Room* roomB)
    //Creation and connection of rooms and a locked door to locklairs office.
    Room* locklair = new Room("Dr. Locklair's Office");
    Room* lobby = new Room("Lobby");
    Door* locklobby = new Door("west", locklair, "east", lobby);
    locklair->addDoor(locklobby, lobby);
    Room* server = new Room("Server Room");
    Door* serverlobby = new Door("north", server, "south", lobby);
    server->addDoor(serverlobby, lobby);
    Room* esports = new Room("ESports");
    Door* esportslobby = new Door("north", lobby, "south", esports);
    esports->addDoor(esportslobby, lobby);
    Room* hall0 = new Room("Hallway 0");
    Door* lobbyhall0 = new Door("east", hall0, "west", lobby);
    lobby->addDoor(lobbyhall0, hall0);
    Room* s120 = new Room("Classroom S120");
    Door* hall0s120 = new Door("north", hall0, "south", s120);
    s120->addDoor(hall0s120, hall0);
    Room* hall1 = new Room("Hallway 1");
    Door* hall1hall0 = new Door("north", hall1, "south", hall0);
    hall1->addDoor(hall1hall0, hall0);
    Room* hall1_5 = new Room("Hallway 1.5");
    Door* hall1_hall1_5 = new Door("north", hall1_5, "south", hall1);
    hall1_5->addDoor(hall1_hall1_5, hall1);
    Room* hall1_75 = new Room("Hallway 1.75");
    Door* hall1_5hall1_75 = new Door("east", hall1_75, "west", hall1_5);
    hall1_75->addDoor(hall1_5hall1_75, hall1_5);
    Room* hall2 = new Room("Hallway 2");
    Door* hall1_5hall2 = new Door("north", hall2, "south", hall1_5);
    hall2->addDoor(hall1_5hall2, hall1_5);
    Room* advLab1 = new Room("Advanced Lab 1");
    Door* hall2advLab1 = new Door("east", advLab1, "west", hall2);
    advLab1->addDoor(hall2advLab1, hall2);
    Room* advLab2 = new Room("Advanced Lab 2");
    Door* advLab1advLab2 = new Door("north", advLab2, "south", advLab1);
    advLab2->addDoor(advLab1advLab2, advLab1);
    Room* s118 = new Room("Classroom S118");
    Door* s118hall2 = new Door("east", hall2, "west", s118);
    s118->addDoor(s118hall2, hall2);
    Room* macLab2 = new Room("Mac Lab2");
    Door* macLab2s118 = new Door("north", macLab2, "south", s118);
    macLab2->addDoor(macLab2s118, s118);
    Room* macLab1 = new Room("MacLab1");
    Door* macLab1macLab2 = new Door("east", macLab1, "west", macLab2);
    macLab1->addDoor(macLab1macLab2, macLab2);
    Door* hall2macLab1 = new Door("north", macLab1, "south", hall2);
    hall2->addDoor(hall2macLab1, macLab1);


    //Student creation
    Student* wahl = new Student("Wahl-Breaker", hall1_75);
    newGuy->getCurrRoom()->DisplayRoomInfo();

    //Implement user input
    string usrInput = "";
    while(usrInput != q)
    {
        cout<<"Where would you like to go?(Type 'q' to quit) ";
        cin>>usrInput;
        newGuy->move(usrInput);
    }

}