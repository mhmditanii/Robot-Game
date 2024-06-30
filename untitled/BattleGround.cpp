//
// Created by mhmd on 5/18/24.
//

#include "BattleGround.h"

#include "upgraded_robots_h/UltimateRobot.h"


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
                //No returning the location of the calling robot (suicide)
                if(i == row && j == col) {
                    //skips to next iteration
                    continue;
                }
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

pair<size_t, size_t> BattleGround::getRandomPosition() const {
    return this->matrix->genRandPos();
}


//     ************************************************************************


//     ***************** ROBOT HANDLING *************************

void BattleGround::robotDelete(size_t const row, size_t const column) const {
    this->deathHandler(row,column);
}

void BattleGround::robotKill(size_t const row, size_t const column) const {
    matrix->deleteData(row,column);
}


void BattleGround::deathHandler(size_t const row, size_t const column) const {
    //Checks if robot should be deleted or queue
    auto temp = matrix->getRobot(row,column);
    temp->decrementLife();

    if(matrix->getRobot(row,column) == nullptr) {
        assert(false && "deathHandler in BG trying to use nullptr");
    }
    if(temp->getLife() == 0) {
        cout << temp->getName() << " IS GOING TO BE REMOVED FROM THE GAME " << endl;
        this->robotKill(row,column);
        return;
    }
    cout << temp->getName() << " IS BEING ADDED TO THE QUEUE"<<endl;
    this->robotEnqueue(row,column);
}

void BattleGround::robotEnqueue(size_t const row, size_t const column) const {
    matrix->enqueueData(row,column);
}

void BattleGround::robotDequeue() const {

    shared_ptr<MainRobot> tempRobot = this->matrix->dequeueData();;
    //If nullptr -> Queue is empty so do nothing
    if(tempRobot != nullptr) {
        auto const tempPos = this->matrix->genRandPos();
        if(!this->isWithinBounds(tempPos.first,tempPos.second)) {
            assert(false && "Random position generated is out of bounds in robotDequeue battleground");
        }
        tempRobot->updateLoc(tempPos);
        this->matrix->setRobotToList(tempRobot);
        this->matrix->setRobot(tempPos.first,tempPos.second,tempRobot);
        cout << tempRobot->getName() << " IS GOING BACK IN THE GAME"<<endl;
    }
}




void BattleGround::robotInit(int id, string name, size_t const row, size_t const column,bool random) {
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
        case 40: {
            const auto temp4 = make_shared<MadBot>(id, name, row, column, this);
            const shared_ptr<MainRobot> temp40 = static_pointer_cast<ShootingRobot>(temp4);
            matrix->setRobotToList(temp40);
            matrix->setRobot(row, column, temp40);
            break;
        }
        case 50: {
            const auto temp5 = make_shared<RoboTank>(id, name, row, column, this);
            const shared_ptr<MainRobot> temp50 = static_pointer_cast<BlueThunder>(temp5);
            matrix->setRobotToList(temp50);
            matrix->setRobot(row, column, temp50);
            break;
        }
        case 60: {
            const auto temp6 = make_shared<TerminatorRoboCop>(id, name, row, column, this);
            const shared_ptr<MainRobot> temp60 = static_pointer_cast<Robocop>(temp6);
            matrix->setRobotToList(temp60);
            matrix->setRobot(row, column, temp60);
            break;
        }
        // default for unit testing
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
    if(getRobot(row,col)==nullptr) assert(false&& "robotExecute accessing nullptr (SUICIDE maybe)");
    matrix->getRobot(row,col)->executeTurn();
}

void BattleGround::startCycle() {
    shared_ptr<MainRobot> exetemp;
    int x = 0;
    while(stepCount > 0 && !this->matrix->endGame()) {
        cout << "ITERATION NUMBER : "  << ++x << endl;
        this->robotDequeue();
        cout << "ROBOTS ACTIVE : " << this->matrix->activeList->getSize() << endl;
        cout << endl;
        this->print();
        cout << endl;

        exetemp = matrix->activeList->iterate();
        if(exetemp == nullptr){assert(false && "Iterator returning nullptr");}
        if(getRobot(exetemp->getRowLoc(),exetemp->getColumnLoc())==nullptr) assert(false&& "iterate method in start cycle is accessing nullptr");

        this->robotExecute(exetemp->getRowLoc(),exetemp->getColumnLoc());

        //Handles upgrading of the robot
        if(exetemp->checkForUpgrade() && exetemp->getId()!= 0) {
            const pair<size_t,size_t> temploc = make_pair(exetemp->getRowLoc(),exetemp->getColumnLoc());
            shared_ptr<MainRobot> upgradedVersion = this->upgradePointerParcing(exetemp);
            this->upgradeFinal(temploc,upgradedVersion);
        }

        cout <<endl<< "AFTER EXECUTING" << endl;
        this->print();

        this->stepCount--;
        cout << endl << endl << "ITERATION " << x << " ENDED  " << endl << endl << endl;
    }
}

void BattleGround::gameHandler() {
    this->startCycle();
    cout << "***********" << endl << "GAME ENDED";
}

shared_ptr<MainRobot> BattleGround::upgradePointerParcing(shared_ptr<MainRobot> robot) const {
    const int idUpdate = robot->getId();
    switch(idUpdate) {
        case 10: {
            auto temp = dynamic_pointer_cast<BlueThunder>(robot);
            if(!temp){assert(false && "WRONG CASTING IN upgradePointerParcing");}
            const auto y = make_shared<MadBot>(std::move(*temp));
            return dynamic_pointer_cast<MainRobot>(y);
        }
        case 20: {
            auto temp = dynamic_pointer_cast<Robocop>(robot);
            if(!temp){assert(false && "WRONG CASTING IN upgradePointerParcing");}
            const auto y = make_shared<TerminatorRoboCop>(std::move(*temp));
            return dynamic_pointer_cast<MainRobot>(y);
        }
        case 30: {
            auto temp = dynamic_pointer_cast<Terminator>(robot);
            if(!temp){assert(false && "WRONG CASTING IN upgradePointerParcing");}
            const auto y = make_shared<TerminatorRoboCop>(std::move(*temp));
            return dynamic_pointer_cast<MainRobot>(y);
        }
        case 40: {
            auto temp = dynamic_pointer_cast<BlueThunder>(robot);
            if(!temp){assert(false && "WRONG CASTING IN upgradePointerParcing");}
            const auto y = make_shared<RoboTank>(std::move(*temp));
            return dynamic_pointer_cast<MainRobot>(y);
        }
        case 50: {
            auto temp = dynamic_pointer_cast<RoboTank>(robot);
            if(!temp){assert(false && "WRONG CASTING IN upgradePointerParcing");}
            const auto y = make_shared<UltimateRobot>(std::move(*temp));
            return dynamic_pointer_cast<MainRobot>(y);
        }
        case 60: {
            auto temp = dynamic_pointer_cast<TerminatorRoboCop>(robot);
            if(!temp){assert(false && "WRONG CASTING IN upgradePointerParcing");}
            const auto y = make_shared<UltimateRobot>(std::move(*temp));
            return dynamic_pointer_cast<MainRobot>(y);
        }
        default: {
            assert(false&&"FAILED TO UPGRADEPOINTERPARCING check id ");
            return nullptr;
        }
    }
}

void BattleGround::upgradeFinal(pair<size_t,size_t> oldRobot, shared_ptr<MainRobot> upgraded) const {
    //remove old robot and then add the new upgraded version in same position
    this->robotKill(oldRobot.first,oldRobot.second);
    if(this->getRobot(oldRobot.first,oldRobot.second) != nullptr) {
        assert(false && "In upgrade final old version is not being deleted properly");
    }
    this->matrix->setRobot(oldRobot.first,oldRobot.second,upgraded);
    this->matrix->setRobotToList(upgraded);
}


//   *****************************************************************************

//          ********* MAIN ROBOT CONSTRUCTOR ***********

MainRobot::MainRobot(int const id, string name, size_t const row, size_t const column,BattleGround* BGptr) {
    this->name = name;
    this->rowLoc = row;
    this->columnLoc = column;
    this->id = id;
    this->BGptr = BGptr;
}

