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


class BattleGround {
private:
    int stepCount;
    // svector<size_t>* matrix;
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

    // ROBOT Handling
    void robotInit(int id, string name, size_t row,size_t column);
    void robotDelete(size_t row, size_t column) const;
    void moveRobot(size_t curRow, size_t curCol, size_t destRow, size_t destCol);
    void robotEnqueue(size_t row, size_t column) const;
    void robotDequeue() const;

    void deathHandler(size_t row,size_t col) const;

    //TEST
    void print();
    void robotExecute(size_t row, size_t col); // will automate it later used for testing
};



#endif //BATTLEGROUND_H
