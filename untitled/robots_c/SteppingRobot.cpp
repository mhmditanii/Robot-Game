//
// Created by mhmd on 5/18/24.
//

#include "../robots_h/SteppingRobot.h"

SteppingRobot::SteppingRobot(int id, string name, size_t row, size_t column, BattleGround* BGptr)
    : MainRobot(id,name,row,column,BGptr)
{
    cout << "Stepping robot calling main" << endl;
}
SteppingRobot::~SteppingRobot() {
    cout << "Deleting Stepping robot" << endl;
}

SteppingRobot::SteppingRobot(SteppingRobot &&other) noexcept : MainRobot(std::move(other))
{
}

SteppingRobot &SteppingRobot::operator=(SteppingRobot && other) noexcept{
    if(this != &other) {
        MainRobot::operator=(std::move(other));
    }
    return *this;
}