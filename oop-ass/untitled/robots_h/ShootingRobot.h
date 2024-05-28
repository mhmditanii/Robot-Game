//
// Created by mhmd on 5/18/24.
//

#ifndef SHOOTINGROBOT_H
#define SHOOTINGROBOT_H
#include"MainRobot.h"


class ShootingRobot : public virtual MainRobot{
private:

public:
    ShootingRobot(int id,string name, size_t row, size_t column);
    ~ShootingRobot() override;

    virtual bool shoot() = 0;
};



#endif //SHOOTINGROBOT_H
