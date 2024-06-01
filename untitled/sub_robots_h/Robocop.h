//
// Created by mhmd on 5/18/24.
//

#ifndef ROBOCOP_H
#define ROBOCOP_H
#include "../robots_h/MovingRobot.h"
#include "../robots_h/SeeingRobot.h"
#include "../robots_h/ShootingRobot.h"
class Robocop : public MovingRobot, public SeeingRobot, public ShootingRobot {
private:
public:
    Robocop(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~Robocop() override;
    void move() override;
    bool look() override;
    bool shoot() override;
    bool executeTurn() override;
};



#endif //ROBOCOP_H
