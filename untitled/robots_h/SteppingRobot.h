//
// Created by mhmd on 5/18/24.
//

#ifndef STEPPINGROBOT_H
#define STEPPINGROBOT_H
#include "MainRobot.h"


class SteppingRobot : public virtual MainRobot{

public:
    SteppingRobot(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~SteppingRobot() override;

    virtual void step() = 0;
};



#endif //STEPPINGROBOT_H
