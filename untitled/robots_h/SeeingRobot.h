//
// Created by mhmd on 5/18/24.
//

#ifndef SEEINGROBOT_H
#define SEEINGROBOT_H
#include"MainRobot.h"


class SeeingRobot : public virtual MainRobot{
private:

public:
    SeeingRobot(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~SeeingRobot();
    virtual bool look() = 0;
};



#endif //SEEINGROBOT_H
