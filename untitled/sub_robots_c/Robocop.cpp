//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/Robocop.h"

Robocop::Robocop(int id, string name, size_t row, size_t column, BattleGround* BGptr)
    :   MainRobot(id,name,row,column, BGptr),
        MovingRobot(id,name,row,column,BGptr),
        SeeingRobot(id,name,row,column,BGptr),
        ShootingRobot(id,name,row,column,BGptr)
{
    cout << "Creating Robocop" << endl;
}

Robocop::~Robocop() {
    cout << "Deleting Robocop" << endl;
}
bool Robocop::executeTurn() {
    cout << "Robocop is executing his turn" << endl;
    return true;
}
bool Robocop::look() {
    return true;
}
void Robocop::move() {

}
bool Robocop::shoot() {
    return true;
}


