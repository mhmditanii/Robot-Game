//
// Created by mhmd on 5/18/24.
//
#include "../robots_h/MainRobot.h"

#include "../BattleGround.h"

MainRobot::MainRobot(int id, string name, size_t const row, size_t const column) {
    this->name = name;
    this->rowLoc = row;
    this->columnLoc = column;
    this->id = -1;
    cout <<"Construced Main" << endl;
}



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

MainRobot::MainRobot(const MainRobot &other) {
    cout << "COPY CONSTRUCTOR CALLED" << endl;

}

bool MainRobot::attack(size_t const row,size_t const column) {
    if(this->checkBG(row,column)) {
        BGptr->robotDelete(row,column);
        this->incKillScore();
    }
    return true;
}
