//
// Created by mhmd on 5/18/24.
//
#include "../robots_h/MainRobot.h"

// MainRobot::MainRobot(int id,BattleGround* BGptr, string name, size_t const row, size_t const column) {
//     this->BGptr = BGptr;
//     this->name = name;
//     this->rowLoc = row;
//     this->columnLoc = column;
//     this->id = -1;
// }
void MainRobot::loselife() {
    lives--;
    if(lives == 0) {
       //delete the robot from the battleground and add him to the back of the queue
   }
}
void MainRobot::respawn() {

}

//TESTING
MainRobot::MainRobot(int id, string name, size_t const row, size_t const column) {
        this->name = name;
        this->rowLoc = row;
        this->columnLoc = column;
        this->id = -1;
        cout <<"Construced Main" << endl;
    }
MainRobot::~MainRobot() {
    cout << "Main robot deleted " << endl;
}

void MainRobot::printlife() {
    cout << lives << endl;
}
