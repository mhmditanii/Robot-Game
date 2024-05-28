//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/Terminator.h"

Terminator::Terminator(int id, string name, size_t row, size_t column)
    :   MainRobot(id,name,row,column),
        MovingRobot(id,name,row,column), SeeingRobot(id,name,row,column)
{
    cout << "CREATED TERMINATOR" << endl;
}
Terminator::~Terminator() {
    cout << "Delting terminator" << endl;
}

bool Terminator::look() {
    //will ask the battleground to provide a view for his surrounding 3*3
    return true;
}
void Terminator::move() {
    cout << "TERMINATOR IS MOVING" << endl;
}

