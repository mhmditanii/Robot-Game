//
// Created by mhmd on 5/18/24.
//

#include "../robots_h/ShootingRobot.h"

ShootingRobot::ShootingRobot(int id, string name, size_t row, size_t column)
    : MainRobot(id,name,row,column)
{
    cout << "Shooting robot calling main" << endl;
}
ShootingRobot::~ShootingRobot() {
    cout << "Deleting Shooting Robot" << endl;
}
