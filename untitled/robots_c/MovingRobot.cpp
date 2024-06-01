//
// Created by mhmd on 5/18/24.w
//

#include "../robots_h/MovingRobot.h"

MovingRobot::MovingRobot(int id, string name, size_t row, size_t column, BattleGround* BGptr)
    : MainRobot(id,name,row,column, BGptr)
{
    cout << "MOVING ROBOT USING MAIN" << endl;
}
MovingRobot::~MovingRobot() {
    cout << "deleting moving robot " << endl;
}

void MovingRobot::moveUp() {}
void MovingRobot::moveDown() {}
void MovingRobot::moveLeft() {}
void MovingRobot::moveRight() {}
void MovingRobot::moveUL() {}
void MovingRobot::moveUR() {}
void MovingRobot::moveDL() {}
void MovingRobot::moveDR() {}
