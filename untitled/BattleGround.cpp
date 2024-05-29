//
// Created by mhmd on 5/18/24.
//

#include "BattleGround.h"


BattleGround::BattleGround(size_t const x, size_t const y ,int const stepcount)
    :stepCount(stepcount)
{
    matrix = new svector<MainRobot*>(x,y);
}

bool BattleGround::isOccupied(size_t const x, size_t const y) {
    return matrix->getRobot(x,y) != nullptr;
}

void BattleGround::incSimulation() {
    stepCount++;
}

void BattleGround::robotInit(int id, string name, size_t  row,size_t  column) {
    switch(id) {
        case 10: {
            auto temp1 = make_shared<BlueThunder>(id,name,row,column);
            shared_ptr<MainRobot> temp10 = static_pointer_cast<ShootingRobot>(temp1);
            matrix->setRobot(row,column,temp10.get());
        }
        case 20: {
            auto temp2 = make_shared<Robocop>(id,name,row,column);
            shared_ptr<MainRobot> temp20 = static_pointer_cast<MovingRobot>(temp2);
            matrix->setRobot(row,column,temp20.get());
        }
        case 30: {
            auto temp3 = make_shared<Terminator>(id,name,row,column);
            shared_ptr<MainRobot> temp30 = static_pointer_cast<SeeingRobot>(temp3);
            matrix->setRobot(row,column,temp30.get());
        }
        //default for unit testing
        default: {
            assert(0,"Can not init robot / ERROR BATTLEGROUND_UTIL.cpp");
        }
    }
}
MainRobot* BattleGround::provideVision(size_t const row,size_t const col, int const scope) const {
    // Define the range of the vision based on scope
    const size_t half_scope = scope / 2;
    const size_t x_start = max<size_t>(0, row - half_scope);
    const size_t x_end = min<size_t>(matrix->getRows() - 1, row + half_scope);
    const size_t y_start = max<size_t>(0, col - half_scope);
    const size_t y_end = min<size_t>(matrix->getColumns() - 1, col + half_scope);


    //Check for robots in the visible range
     for (size_t i = x_start; i <= x_end; i++) {
         for (size_t j = y_start; j <= y_end; j++) {
             if (matrix->getRobot(i,j) != nullptr) {
                 return matrix->getRobot(i,j);
                 //should i break or continue?
             };
         }
     }

    return nullptr;
}
