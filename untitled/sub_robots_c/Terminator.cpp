//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/Terminator.h"

Terminator::Terminator(int id, string name, size_t row, size_t column, BattleGround* BGptr)
    :   MainRobot(id,name,row,column, BGptr),
        MovingRobot(id,name,row,column, BGptr), SeeingRobot(id,name,row,column, BGptr)
{
    cout << "CREATED TERMINATOR" << endl;
}
Terminator::~Terminator() {
    cout << "Delting terminator" << endl;
}

bool Terminator::look(){
    return true;
}
void Terminator::move() {
    cout << "TERMINATOR IS MOVING" << endl;
}
void Terminator::executeTurn(){
}

