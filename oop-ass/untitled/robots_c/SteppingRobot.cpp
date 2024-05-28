//
// Created by mhmd on 5/18/24.
//

#include "../robots_h/SteppingRobot.h"

SteppingRobot::SteppingRobot(int id, string name, size_t row, size_t column)
    : MainRobot(id,name,row,column)
{
    cout << "Stepping robot calling main" << endl;
}
SteppingRobot::~SteppingRobot() {
    cout << "Deleting Stepping robot" << endl;
}
