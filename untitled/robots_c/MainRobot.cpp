//
// Created by mhmd on 5/18/24.
//
#include "../robots_h/MainRobot.h"

#include "../BattleGround.h"




void MainRobot::upgradeRobot() {

}

//                ***********SETTERS AND GETTERS*******************

size_t MainRobot::getRowLoc() const {
    return rowLoc;
}

size_t MainRobot::getColumnLoc() const {
    return columnLoc;
}

void MainRobot::setLoc(size_t const row,size_t const col) {
    rowLoc = row;
    columnLoc = col;
}

void MainRobot::decrementLife() {
    this->lives = this->lives - 1;
}

int MainRobot::getLife() const {
    return this->lives;
}


//              *********ROBOT ATTRIBUTES CONTROL************

void MainRobot::incKillScore() {
    //Increment while checking if MAX SCORE to upgrade was attained
    if(++killScore==3) {

    }
}


//TESTING

MainRobot::~MainRobot() {
    cout << "Main robot deleted " << endl;
}

void MainRobot::printlife() {
    cout << lives << endl;
}

bool MainRobot::checkBG(size_t const row, size_t const column) const {
    return BGptr->isOccupied(row,column);
}

MainRobot::MainRobot(const MainRobot& other)
    : id(other.id), name(other.name), rowLoc(other.rowLoc), columnLoc(other.columnLoc), BGptr(other.BGptr) {
    cout << "Copy Constructed Main" << endl;
}

MainRobot::MainRobot(MainRobot&& other) noexcept
        : id(other.id), name(move(other.name)), rowLoc(other.rowLoc), columnLoc(other.columnLoc), BGptr(other.BGptr) {
    other.BGptr = nullptr;
    cout << "Move Constructed Main" << endl;
}

bool MainRobot::attack(size_t const row,size_t const column) {
    if(this->checkBG(row,column)) {
        BGptr->robotDelete(row,column);
        this->incKillScore();
    }
    return true;
}
