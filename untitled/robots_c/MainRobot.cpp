//
// Created by mhmd on 5/18/24.
//
#include "../robots_h/MainRobot.h"

#include "../BattleGround.h"




bool MainRobot::checkForUpgrade() const{
    return killScore >= 3 && id != 70;
}

//                ***********SETTERS AND GETTERS*******************

size_t MainRobot::getRowLoc() const {
    return rowLoc;
}

size_t MainRobot::getColumnLoc() const {
    return columnLoc;
}

BattleGround *MainRobot::getBGptr() const {
    return this->BGptr;
}

void MainRobot::setID(int const id) {
    this->id = id;
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


int MainRobot::getId() const {
    return this->id;
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
        :  name(move(other.name)), rowLoc(other.rowLoc), columnLoc(other.columnLoc), BGptr(other.BGptr)
           ,lives(other.lives)
{
    id = 0;
    killScore = 0;
    cout << "Move Constructed Main" << endl;
}

MainRobot &MainRobot::operator=(MainRobot &&other) noexcept {
    if(this != &other) {
        name = move(other.name);
        rowLoc = (other.rowLoc);
        columnLoc = (other.columnLoc);
        BGptr = (other.BGptr);
        killScore = 0;
        lives = other.lives;
    }
    return *this;
}


bool MainRobot::attack(size_t const row,size_t const column) {
    cout << this->name <<" (" << this->rowLoc << "," << this->columnLoc
        << ")"<<" IS ATTACKING LOCATION (" << row << "," << column <<")"<< endl;
    if(this->checkBG(row,column)) {
        cout << this->name << " KILLED A ROBOT" << endl;
        BGptr->robotDelete(row,column);
        this->incKillScore();
    }
    return true;
}

void MainRobot::updateLoc(pair<size_t, size_t> const & newLoc) {
    this->rowLoc = newLoc.first;
    this->columnLoc = newLoc.second;
}

string MainRobot::getName() const {
    return this->name;
}
