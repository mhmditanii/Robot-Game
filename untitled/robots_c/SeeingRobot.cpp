//
// Created by mhmd on 5/18/24.
//

#include "../robots_h/SeeingRobot.h"

SeeingRobot::SeeingRobot(int id, string name, size_t row, size_t column, BattleGround* BGptr)
    : MainRobot(id,name,row,column,BGptr)
{
    cout << "SEEING ROBOT USING MAIN" << endl;
}
SeeingRobot::~SeeingRobot() {
    cout << "deleting seeing" << endl;
}
SeeingRobot::SeeingRobot(SeeingRobot &&other) noexcept : MainRobot(std::move(other))
{
}


SeeingRobot &SeeingRobot::operator=(SeeingRobot && other) noexcept{
    if(this != &other) {
        MainRobot::operator=(std::move(other));
    }
    return *this;
}