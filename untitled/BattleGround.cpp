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
    if(!matrix->isInBounds(x,y)) {
        assert(false && "BG isOccupied trying to access out of bound");
    }
    return matrix->getRobot(x,y) != nullptr;
}

void BattleGround::incSimulation() {
    stepCount++;
}

bool BattleGround::isWithinBounds(size_t const row, size_t const column) const {
    return matrix->isInBounds(row,column);
}


//              **********SETTERS AND GETTERS**********

optional<pair<size_t, size_t>> BattleGround::getVision(size_t const row, size_t const col, int const scope) const {
    // Define the range of the vision based on scope
    const int half_scope = scope / 2;
    const size_t x_start = max<int>(0, static_cast<int>(row) - half_scope);
    const size_t x_end = min<size_t>(matrix->getRows() - 1, static_cast<size_t>(row + half_scope));
    const size_t y_start = max<int>(0, static_cast<int>(col) - half_scope);
    const size_t y_end = min<size_t>(matrix->getColumns() - 1, static_cast<size_t>(col + half_scope));

    // Check for robots in the visible range
    for (size_t i = x_start; i <= x_end; ++i) {
        for (size_t j = y_start; j <= y_end; ++j) {
            if (matrix->getRobot(i, j) != nullptr) {
                return make_pair(i, j);
            }
        }
    }

    return nullopt;
}

shared_ptr<MainRobot> BattleGround::getRobot(size_t const row, size_t const column) const {
    return matrix->getRobot(row,column);
}

pair<size_t, size_t> BattleGround::getMatrixBounds() const {
    return make_pair(this->matrix->getRows(),this->matrix->getColumns());
}


//     ************************************************************************


//     ***************** ROBOT HANDLING *************************

void BattleGround::robotDelete(size_t const row, size_t const column) const {
    matrix->deleteData(row,column);
}

void BattleGround::robotEnqueue(size_t const row, size_t const column) const {
    matrix->enqueueData(row,column);
}

void BattleGround::robotDequeue() const {
    shared_ptr<MainRobot> tempRobot = this->matrix->dequeueData();
    pair<size_t,size_t>   tempPos = this->matrix->genRandPos();
    tempRobot->setLoc(tempPos.first,tempPos.second);
    this->matrix->setRobot(tempPos.first,tempPos.second,tempRobot);
}

void BattleGround::deathHandler(size_t const row, size_t const column) const {
    //Checks if robot should be deleted or queue

    if(matrix->getRobot(row,column) == nullptr) {
        assert(false && "deathHandler in BG trying to use nullptr");
    }
    if(matrix->getRobot(row,column)->getLife() == 0) {
        this->robotDelete(row,column);
    }
    this->robotEnqueue(row,column);
}


void BattleGround::robotInit(int id, string name, size_t const row,size_t const column) {
    switch(id) {
        case 10: {
            const auto temp1 = make_shared<BlueThunder>(id,name,row,column,this);
            const shared_ptr<MainRobot> temp10 = static_pointer_cast<ShootingRobot>(temp1);
            matrix->setRobotToList(temp10);
            matrix->setRobot(row,column,temp10);
            break;
        }
        case 20: {
            const auto temp2 = make_shared<Robocop>(id,name,row,column,this);
            const shared_ptr<MainRobot> temp20 = static_pointer_cast<MovingRobot>(temp2);
            matrix->setRobotToList(temp20);
            matrix->setRobot(row,column,temp20);
            break;
        }
        case 30: {
            const auto temp3 = make_shared<Terminator>(id,name,row,column,this);
            const shared_ptr<MainRobot> temp30 = static_pointer_cast<SeeingRobot>(temp3);
            matrix->setRobotToList(temp30);
            matrix->setRobot(row,column,temp30);
            break;
        }
        //default for unit testing
        default: {
            assert(false && "Can not init robot because of INVALID ID/ ERROR BATTLEGROUND_UTIL.cpp");

        }
    }
}

void BattleGround::moveRobot(size_t const curRow, size_t const curCol, size_t const destRow, size_t const destCol) {
    this->matrix->moveData(curRow,curCol,destRow,destCol);
}



// TEST ****************************
void BattleGround::print() {
    matrix->print();
}
void BattleGround::robotExecute(size_t const row, size_t const col) {
    matrix->getRobot(row,col)->executeTurn();
}





//   *****************************************************************************

//          ********* MAIN ROBOT CONSTRUCTOR ***********

MainRobot::MainRobot(int id, string name, size_t const row, size_t const column,BattleGround* BGptr) {
    this->name = name;
    this->rowLoc = row;
    this->columnLoc = column;
    this->id = -1;
    this->BGptr = BGptr;
    cout <<"Construced Main" << endl;
}
