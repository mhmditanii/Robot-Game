//
// Created by mhmd on 5/18/24.
//

#include "../upgraded_robots_h/UltimateRobot.h"

UltimateRobot::UltimateRobot(RoboTank &&other) noexcept
    : MainRobot(std::move(other)),RoboTank(std::move(other)),
    TerminatorRoboCop(70,other.getName(),other.getRowLoc(),other.getColumnLoc(),other.getBGptr())
{
    cout << "UPGRADING " << this->getName() <<" TO ULTIMATE ROBOT" << endl;
}

UltimateRobot::UltimateRobot(TerminatorRoboCop &&other) noexcept
    : MainRobot(std::move(other)),TerminatorRoboCop(std::move(other)),
    RoboTank(70,other.getName(),other.getRowLoc(),other.getColumnLoc(),other.getBGptr())
{
    cout << "UPGRADING " << this->getName() <<" TO ULTIMATE ROBOT" << endl;
}

UltimateRobot::~UltimateRobot() {
    cout << "ULTIMATE ROBOT IS BEING DELETED"<<endl;
}

void UltimateRobot::executeTurn() {
    if(this->look()) {
        this->step();
    }
    else {
        // No robot -> random move then shoot
        this->move();
    }

    for(int i =0; i < 3; i++) {
        this->shoot();
    }
}
