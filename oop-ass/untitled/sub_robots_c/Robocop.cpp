//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/Robocop.h"

Robocop::Robocop(int id, string name, size_t row, size_t column)
    :   MainRobot(id,name,row,column),
        MovingRobot(id,name,row,column),
        SeeingRobot(id,name,row,column),
        ShootingRobot(id,name,row,column)
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


