//
// Created by mhmd on 5/18/24.
//

#include "../robots_h/ShootingRobot.h"

ShootingRobot::ShootingRobot(int id, string name, size_t row, size_t column, BattleGround* BGptr)
    : MainRobot(id,name,row,column,BGptr)
{
    cout << "Shooting robot calling main" << endl;
}
ShootingRobot::~ShootingRobot() {
    cout << "Deleting Shooting Robot" << endl;
}
ShootingRobot::ShootingRobot(const ShootingRobot &other){
    cout << "Using copy Shooting constructor" << "**************"<< endl << "***********" << endl;
}
