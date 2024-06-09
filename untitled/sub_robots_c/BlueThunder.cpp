//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/BlueThunder.h"

#include <memory>

BlueThunder::BlueThunder(int id, string name, size_t row, size_t column, BattleGround* BGptr)
    :   MainRobot(id,name,row,column,BGptr), ShootingRobot(id,name,row,column,BGptr)
{
    cout << "Blue thunder created" << endl;
}
BlueThunder::~BlueThunder() {
    cout << "Deleting Blue Thunder" << endl;
}

BlueThunder::BlueThunder(const BlueThunder &other) : MainRobot(other),ShootingRobot(other) {
    this->clockTurn= other.clockTurn;
    cout << "Using copy constructor" << "**************"<< endl << "***********" << endl;
}

bool BlueThunder::shoot() {
    const pair<size_t, size_t> target = this->getTargetCoordinates();
    updateClockTurn();
    return this->attack(target.first, target.second);
}

void BlueThunder::executeTurn() {
     this->shoot();
}


//       ********* IMPLEMENTING AIMING GETTERS ***********

//Created to improve the readablity of the shooting function
pair<size_t, size_t> BlueThunder::getTargetCoordinates(int def) const {
    // Checks if there was an argument passed as a direction to shoot
    // else uses clockTurn, Used for MADBOT
    const int decision = (def != -1) ? def : this->clockTurn;

    switch(decision) {
        case 1:
            return {aimUp(), getColumnLoc()};
        case 2:
            return aimUpRight();
        case 3:
            return {getRowLoc(), aimRight()};
        case 4:
            return aimDownRight();
        case 5:
            return {aimDown(), getColumnLoc()};
        case 6:
            return aimDownLeft();
        case 7:
            return {getRowLoc(), aimLeft()};
        case 8:
            return aimUpLeft();
        default: {
            assert(false && "BLUE THUNDER SHOOT / ERROR AIMING");
            return {0, 0}; // not reachable (compiler issues)
        }
    }
}

void BlueThunder::updateClockTurn() {
    switch(clockTurn) {
        case 1:
            this->clockTurn = 2;
        break;
        case 2:
            this->clockTurn = 3;
        break;
        case 3:
            this->clockTurn = 4;
        break;
        case 4:
            this->clockTurn = 5;
        break;
        case 5:
            this->clockTurn = 6;
        break;
        case 6:
            this->clockTurn = 7;
        break;
        case 7:
            this->clockTurn = 8;
        break;
        case 8:
            this->clockTurn = 1;
        break;
        default:
            assert(false && "BLUE THUNDER SHOOT / ERROR UPDATING CLOCK TURN");
    }
}


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

pair<size_t, size_t> BlueThunder::aimUpRight() const {
    return {getRowLoc() - 1, getColumnLoc() + 1};
}

pair<size_t, size_t> BlueThunder::aimDownRight() const {
    return {getRowLoc() + 1, getColumnLoc() + 1};
}

pair<size_t, size_t> BlueThunder::aimUpLeft() const {
    return {getRowLoc() - 1, getColumnLoc() - 1};
}

pair<size_t, size_t> BlueThunder::aimDownLeft() const {
    return {getRowLoc() + 1, getColumnLoc() - 1};
}