//
// Created by mhmd on 5/18/24.
//

#include "../upgraded_robots_h/RoboTank.h"
random_device rd;
mt19937 gen(rd());

RoboTank::RoboTank(int id, string name, size_t row, size_t column, BattleGround *BGptr) :
MainRobot(id,name,row,column,BGptr),MadBot(id,name,row,column,BGptr)
{
cout << "RoboTank created" << endl;
}

pair<size_t, size_t> RoboTank::getTarget() const {
    pair<size_t,size_t> bounds = this->BGptr->getMatrixBounds();
    uniform_int_distribution<size_t> rowDis(0,bounds.first - 1); //-1 because 0 based
    uniform_int_distribution<size_t> colDis(0,bounds.second - 1);
    return make_pair(rowDis(gen),colDis(gen));
}

bool RoboTank::shoot() {
    auto[x,y] = this->getTarget(); // Structured binding
    return this->attack(x,y);
}
