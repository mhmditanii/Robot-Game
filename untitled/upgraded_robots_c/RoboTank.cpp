//
// Created by mhmd on 5/18/24.
//

#include "../upgraded_robots_h/RoboTank.h"
random_device rdRobo;
mt19937 genRobo(rdRobo());

RoboTank::RoboTank(int id, string name, size_t row, size_t column, BattleGround *BGptr) :
MainRobot(id,name,row,column,BGptr), BlueThunder(id,name,row,column,BGptr)
{
cout << "RoboTank created" << endl;
}

RoboTank::RoboTank(BlueThunder &&other) noexcept
    : MainRobot(std::move(other)),BlueThunder(std::move(other))
{
    cout << "UPGRADING TO ROBOTANK USING MOVE OPERATOR" << endl;
}

RoboTank::~RoboTank() {
    cout << "Robotank deleted" << endl;
}

pair<size_t, size_t> RoboTank::getTarget() const {
    auto[rowCount, colCount] = this->BGptr->getMatrixBounds();
    uniform_int_distribution<size_t> rowDis(0, rowCount - 1); // -1 because 0 based matrix
    uniform_int_distribution<size_t> colDis(0, colCount - 1);

    pair<size_t, size_t> currentPosition = make_pair(getRowLoc(),getColumnLoc());
    pair<size_t, size_t> target;

    //loop to prevent returning the caller coordinates
    do {
        target.first = rowDis(genRobo);
        target.second = colDis(genRobo);
    } while (target == currentPosition);

    return target;
}

bool RoboTank::shoot() {
    auto[x,y] = this->getTarget(); // Structured binding
    return this->attack(x,y);
}

void RoboTank::executeTurn() {
    this->shoot();
}
