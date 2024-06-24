//
// Created by mhmd on 5/18/24.
//

#ifndef TERMINATOR_H
#define TERMINATOR_H
#include "../robots_h/MovingRobot.h"
#include "../robots_h/SeeingRobot.h"
#include<optional>
#include<random>

#include "../robots_h/SteppingRobot.h"

class Terminator : public MovingRobot, public SeeingRobot, public SteppingRobot{

public:
    Terminator(int id, string name, size_t row, size_t column, BattleGround* BGptr);
    ~Terminator() override;
    bool look() override;
    void move() override;
    void executeTurn() override;
    void step() override;

    pair<size_t,size_t> moveLimitFrontGen() const;
    pair<size_t,size_t> moveLimitBackGen() const;

};



#endif //TERMINATOR_H
