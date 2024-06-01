//
// Created by mhmd on 5/18/24.
//

#ifndef MOVINGROBOT_H
#define MOVINGROBOT_H
#include"MainRobot.h"


class MovingRobot : public virtual MainRobot{
private:

public:
    MovingRobot(int id, string name, size_t row, size_t column, BattleGround* BGptr);
    ~MovingRobot();
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void moveUL(); // UL = UP LEFT
    void moveUR();
    void moveDL(); // DOWN LEFT
    void moveDR();
    virtual void move() = 0 ;
};



#endif //MOVINGROBOT_H
