//
// Created by mhmd on 5/18/24.
//

#ifndef MAINROBOT_H
#define MAINROBOT_H
#include<iostream>
#include<cassert>

using namespace std;
class BattleGround;

class MainRobot {
private:
    int id;
    string name;
    int lives = 3;
    int attempts = 3;
    int killScore = 0;
    size_t rowLoc; size_t columnLoc;  // location of the robot
    BattleGround* BGptr;
public:


    //Setters and Getters (DEC , INC included)
    size_t getRowLoc() const;
    size_t getColumnLoc() const;
    void setLoc(size_t row, size_t col); // Set the loc in one go no need for 2 setters

    void decrementLife();
    int getLife() const;


    //ROBOTS ATTRIBUTE CONTROL
    virtual bool executeTurn() = 0; // Every robot will implement this function base on his abilities
                                    // and will return true if a kill was secured (for upgrade purposes)

    //killRobot uses addToQueue (to try and implement one change for one function)


    void incKillScore();
    void upgradeRobot();


    //TESTING
    MainRobot(int id,string name, size_t row, size_t column);
    MainRobot(int id,string name, size_t row, size_t column,BattleGround* BGptr);
    virtual ~MainRobot();
    void printlife();
    void checkBG();
};



#endif //MAINROBOT_H
