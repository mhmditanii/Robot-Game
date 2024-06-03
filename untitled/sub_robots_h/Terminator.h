//
// Created by mhmd on 5/18/24.
//

#ifndef TERMINATOR_H
#define TERMINATOR_H
#include "../robots_h/MovingRobot.h"
#include "../robots_h/SeeingRobot.h"


class Terminator : public SeeingRobot, public MovingRobot{
private:
public:
    Terminator(int id, string name, size_t row, size_t column, BattleGround* BGptr);
    ~Terminator();
    bool look() override;
    void move() override;
    void executeTurn() override;
};



#endif //TERMINATOR_H
