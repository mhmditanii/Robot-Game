//
// Created by mhmd on 5/18/24.
//
#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H
//C++ Libraries
#include <iostream>
#include<memory>
#include<cassert>
#include<optional>

//HEADERS
#include "Data_structures/svector.h"
#include"robots_h/MainRobot.h"
#include "Data_structures/svector_robot_ptr.h"

#include"sub_robots_h/Robocop.h"
#include"sub_robots_h/Terminator.h"
#include"sub_robots_h/BlueThunder.h"
#include"upgraded_robots_h/all_upgraded.h"

class BattleGround {
private:
    int stepCount;
    svector<shared_ptr<MainRobot>>* matrix;    //using svector_robot_ptr to build
                                               //a matrix of pointers

public:

    BattleGround(size_t x, size_t y , int stepcount);
    ~BattleGround();
    // BATTLEGROUND CONTROL
    [[nodiscard]]bool isOccupied(size_t x, size_t y) const;
    void incSimulation();
    bool isWithinBounds(size_t row, size_t column) const;

    //      *******SETTERS AND GETTERS********
    [[nodiscard]]optional<pair<size_t,size_t>> getVision(size_t row,size_t column,int scope) const;
    [[nodiscard]]shared_ptr<MainRobot> getRobot(size_t row,size_t column) const;
    pair<size_t,size_t> getMatrixBounds() const;
    pair<size_t,size_t> getRandomPosition() const;
    // ROBOT Handling
    void robotInit(int id, string name, size_t row,size_t column,bool random);
    void moveRobot(size_t curRow, size_t curCol, size_t destRow, size_t destCol);
    void robotEnqueue(size_t row, size_t column) const;
    void robotDequeue() const;

    //Used for simplification and usage in mainrobot class in attack
    void robotDelete(size_t row, size_t column) const;
    //Handles the enqueue or eliminating robots
    void deathHandler(size_t row,size_t col) const;
    //Eliminates the robot (life = 0)
    void robotKill(size_t row,size_t col) const;


    //TEST
    void print();
    void robotExecute(size_t row, size_t col); // will automate it later used for testing
    void startCycle();
    void gameHandler();
    shared_ptr<MainRobot> upgradePointerParcing(shared_ptr<MainRobot>) const;
    void upgradeFinal(pair<size_t,size_t>, shared_ptr<MainRobot>) const;
};



#endif //BATTLEGROUND_H
