//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/BlueThunder.h"

BlueThunder::BlueThunder(int id, string name, size_t row, size_t column, BattleGround* BGptr)
    :   MainRobot(id,name,row,column,BGptr), ShootingRobot(id,name,row,column,BGptr)
{
    cout << "Blue thunder created" << endl;
}
BlueThunder::~BlueThunder() {
    cout << "Deleting Blue Thunder" << endl;
}

bool BlueThunder::shoot() {
    switch(clockTurn) {
        case 12: {
            this->clockTurn = 3;
            return this->attack(aimUp(), getColumnLoc());
        }
        case 3: {
            this->clockTurn = 6;
            return this->attack(getRowLoc(),aimRight());
        }
        case 6: {
            this->clockTurn = 9;
            return this->attack(aimDown(),getColumnLoc());
        }
        case 9: {
            this->clockTurn = 12;
            return this->attack(getRowLoc(),aimLeft());
        }
        default: {
            //assert(0,"BLUE THUNDER SHOOT / ERROR AIMING");
            return false;
        }
    }
    return true;
}

void BlueThunder::executeTurn() {
     this->shoot();
}


//       ********* IMPLEMENTING AIMING GETTERS ***********

size_t BlueThunder::aimUp() const {
    return getRowLoc() - 1;
}

size_t BlueThunder::aimRight() const {
    return getColumnLoc() + 1;
}

size_t BlueThunder::aimDown() const {
    return getRowLoc() + 1;
}

size_t BlueThunder::aimLeft() const {
    return getColumnLoc() - 1;
}