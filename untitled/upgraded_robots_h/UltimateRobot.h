//
// Created by mhmd on 5/18/24.
//

#ifndef ULTIMATEROBOT_H
#define ULTIMATEROBOT_H
#include "RoboTank.h"
#include "TerminatorRoboCop.h"


class UltimateRobot : public RoboTank,TerminatorRoboCop{
public:
    UltimateRobot(RoboTank&&) noexcept;
    UltimateRobot(TerminatorRoboCop&&) noexcept;
    ~UltimateRobot() override;

    void executeTurn() override;

    using RoboTank::shoot;
    using TerminatorRoboCop::move;
    using TerminatorRoboCop::step;
    using TerminatorRoboCop::look;
};



#endif //ULTIMATEROBOT_H
