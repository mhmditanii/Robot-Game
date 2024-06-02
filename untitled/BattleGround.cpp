//
// Created by mhmd on 5/18/24.
//

#include "BattleGround.h"


BattleGround::BattleGround(size_t const x, size_t const y ,int const stepcount)
    :stepCount(stepcount)
{
    matrix = new svector<shared_ptr<MainRobot>>(x,y);
}

BattleGround::~BattleGround() = default;


bool BattleGround::isOccupied(size_t const x, size_t const y) const {
    return matrix->getRobot(x,y) != nullptr;
}

void BattleGround::incSimulation() {
    stepCount++;
}

void BattleGround::robotInit(int id, string name, size_t const row,size_t const column) {
    switch(id) {
        case 10: {
            auto temp1 = make_shared<BlueThunder>(id,name,row,column,this);
            shared_ptr<MainRobot> temp10 = static_pointer_cast<ShootingRobot>(temp1);
            matrix->setRobot(row,column,temp10);
            break;
        }
        case 20: {
            auto temp2 = make_shared<Robocop>(id,name,row,column,this);
            shared_ptr<MainRobot> temp20 = static_pointer_cast<MovingRobot>(temp2);
            matrix->setRobot(row,column,temp20);
            break;
        }
        case 30: {
            auto temp3 = make_shared<Terminator>(id,name,row,column,this);
            shared_ptr<MainRobot> temp30 = static_pointer_cast<SeeingRobot>(temp3);
            matrix->setRobot(row,column,temp30);
            break;
        }
        //default for unit testing
        default: {
            assert(false && "Can not init robot because of INVALID ID/ ERROR BATTLEGROUND_UTIL.cpp");

        }
    }
    cout << "DONE WITH INIT" << endl;
}


//              **********SETTERS AND GETTERS**********

bool BattleGround::getVision(size_t const row,size_t const col, int const scope) const {
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
                 return true;
                 //should i break or continue?
             };
         }
     }

    return false;
}

shared_ptr<MainRobot> BattleGround::getRobot(size_t const row, size_t const column) const {
    return matrix->getRobot(row,column);
}


//     ************************************************************************

void BattleGround::robotDelete(size_t const row, size_t const column) const {
    matrix->deleteData(row,column);
}




//          ********* MAIN ROBOT CONSTRUCTOR ***********

MainRobot::MainRobot(int id, string name, size_t const row, size_t const column,BattleGround* BGptr) {
    this->name = name;
    this->rowLoc = row;
    this->columnLoc = column;
    this->id = -1;
    this->BGptr = BGptr;
    cout <<"Construced Main" << endl;
}