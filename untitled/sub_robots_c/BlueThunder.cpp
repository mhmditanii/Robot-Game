//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/BlueThunder.h"

BlueThunder::BlueThunder(int id, string name, size_t row, size_t column)
    :   MainRobot(id,name,row,column), ShootingRobot(id,name,row,column)
{
    cout << "Blue thunder created" << endl;
}
BlueThunder::~BlueThunder() {
    cout << "Deleting Blue Thunder" << endl;
}
bool BlueThunder::shoot() {
    cout << "SHOOTING" << endl;
    return true;
}
bool BlueThunder::executeTurn() {
    cout << "Blue thunder using main exec function" << endl;
    return true;
}

