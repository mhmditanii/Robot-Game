//
// Created by mhmd on 5/18/24.
//

#include "BattleGround.h"


BattleGround::BattleGround(size_t const x, size_t const y , int const robotsnumber,int const stepcount)
    :stepCount(stepcount)
{
    matrix = new svector<size_t>(x,y,0);
    activeRobots = new svector<shared_ptr<MainRobot>>(1,robotsnumber,nullptr);
}
void BattleGround::robotCreate(int const robotsNumber,int const id, string name, size_t const row, size_t const column ) {
    for(int i = 0 ; i < robotsNumber;i++) {
        robotInit(10,name,row,column);
    }
}

bool BattleGround::isOccupied(size_t const x, size_t const y) {
    return matrix->access(x,y) != -0;
}
void BattleGround::incSimulation() {
    stepCount++;
}
void BattleGround::robotMove() {

}
shared_ptr<MainRobot> BattleGround::robotInit(int id, string name, size_t  row,size_t  column) {
    switch(id) {
        case 10: {
            auto temp1 = make_shared<BlueThunder>(id,name,row,column);
            return static_pointer_cast<ShootingRobot>(temp1);
        }
            //return make_shared<BlueThunder>(2,"s",2,2);
        case 20: {
            auto temp2 = make_shared<Robocop>(id,name,row,column);
            return static_pointer_cast<MovingRobot>(temp2);
        }
        case 30: {
            auto temp3 = make_shared<Terminator>(id,name,row,column);
            return static_pointer_cast<SeeingRobot>(temp3);
        }
        default: {
            assert("Can not init robot / ERROR BATTLEGROUND_UTIL.cpp");
            return nullptr;
        }  //Unit testing
    }
}
shared_ptr<MainRobot> BattleGround::provideVision(size_t const x,size_t const y, int const scope) {
    // Define the range of the vision based on scope
    size_t half_scope = scope / 2;
    size_t x_start = max<size_t>(0, x - half_scope);
    size_t x_end = min<size_t>(matrix->getRows() - 1, x + half_scope);
    size_t y_start = max<size_t>(0, y - half_scope);
    size_t y_end = min<size_t>(matrix->getColumns() - 1, y + half_scope);


    //Check for robots in the visible range
    for (int i = x_start; i <= x_end; ++i) {
        for (int j = y_start; j <= y_end; ++j) {
            if (matrix->access(i,j) != 0) {
                return matrix->access(i,j);
            };
        }
    }

    return nullptr;
}
