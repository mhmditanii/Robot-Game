//
// Created by mhmd on 5/18/24.
//
#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H
//C++ Libraries
#include <iostream>
#include<memory>
#include<cassert>

//HEADERS TESTING
#include "Data_structures/svector.h"
//#include"Handlers/Robots_unifier.h"
#include"robots_h/MainRobot.h"
#include "robots_h/SeeingRobot.h"
#include "robots_h/ShootingRobot.h"
#include "robots_h/MovingRobot.h"
#include "robots_h/SteppingRobot.h"
#include "sub_robots_h/BlueThunder.h"
#include "sub_robots_h/Robocop.h"
#include "sub_robots_h/Terminator.h"

class BattleGround {
private:
    int stepCount;
    // svector<size_t>* matrix;
    svector<size_t>* matrix;
    svector<MainRobot*>* activeRobots;

public:

    BattleGround(size_t x, size_t y , int robotsnumber,int stepcount);

    // BATTLEGROUND CONTROL
    bool isOccupied(size_t x, size_t y);
    void incSimulation();
    shared_ptr<MainRobot> provideVision(size_t row,size_t column,int scope);

    // ROBOT Handling
    void robotCreate(int robotsNumber,int id,string name,size_t row,size_t column);
    void robotMove();
     shared_ptr<MainRobot> robotInit(int id, string name, size_t row,size_t column);
};



#endif //BATTLEGROUND_H
