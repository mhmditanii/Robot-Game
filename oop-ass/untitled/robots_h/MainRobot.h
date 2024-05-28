//
// Created by mhmd on 5/18/24.
//

#ifndef MAINROBOT_H
#define MAINROBOT_H
#include<iostream>
#include<cassert>
//#include "../BattleGround.h"

using namespace std;

class MainRobot {
private:
    int id;
    string name;
    int lives = 3;
    int attempts = 3;
    size_t rowLoc; size_t columnLoc;  // location of the robot
protected:
    //BattleGround* BGptr;  //used to gain access to the battlefield functions like gain vision and check boundaries
public:
    //MainRobot(int id,BattleGround* BGptr,string name, size_t row, size_t column);
    void loselife();
    void respawn();

    //ROBOTS FUNCTIONS
    virtual bool executeTurn() = 0; // Every robot will implement this function base on his abilities
                                    // and will return true if a kill was secured (for upgrade purposes)

    //TESTING
    MainRobot(int id,string name, size_t row, size_t column);
    virtual ~MainRobot();
    void printlife();
};



#endif //MAINROBOT_H
