//
// Created by mhmd on 5/18/24.
//
#include "../robots_h/MainRobot.h"

MainRobot::MainRobot(int id, string name, size_t const row, size_t const column) {
    this->name = name;
    this->rowLoc = row;
    this->columnLoc = column;
    this->id = -1;
    cout <<"Construced Main" << endl;
}
void MainRobot::loselife() {
    lives--;
    if(lives == 0) {
       //delete the robot from the battleground and add him to the back of the queue
   }
}
void MainRobot::respawn() {

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

//TESTING

MainRobot::~MainRobot() {
    cout << "Main robot deleted " << endl;
}

void MainRobot::printlife() {
    cout << lives << endl;
}
