//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/Terminator.h"

#include "../BattleGround.h"

Terminator::Terminator(int const id, string name, size_t row, size_t column, BattleGround* BGptr)
    :   MainRobot(id,name,row,column, BGptr),
        MovingRobot(id,name,row,column, BGptr), SeeingRobot(id,name,row,column, BGptr)
{
    cout << "CREATED TERMINATOR" << endl;
}
Terminator::~Terminator() {
    cout << "Delting terminator" << endl;
}

bool Terminator::look(){
    if(BGptr->getVision(this->getRowLoc(),this->getColumnLoc(),3)) {
        this->random = false;
        return true;
    }
    //No robot in scope and sets random movement to true
    this->random = true;
    return false;
}

void Terminator::move() {
    if(random) {
        this->randMove();
    }
    else {
        this->defMove();
    }
}

void Terminator::executeTurn(){
    //Move to the robot position
    if(this->look()) {
        this->move();
    }
    //Move randomly (No robots in scope)
}

//             ************SPECIAL TERMINATOR FUNCTIONS*******************

void Terminator::randMove() {
    // Create a random device and a random number generator
    random_device rd;
    mt19937 gen(rd());

    // Define the range for random movement, e.g., -3 to 3
    uniform_int_distribution<int> dist(-3, 3);

    // Randomly change x and y within bounds [0, 3]
    // int newX = static_cast<int>(this->getRowLoc()) + dist(gen);
    // int newY = static_cast<int>(this->getColumnLoc()) + dist(gen);

    // Ensure new coordinates are within the bounds of the 4x4 matrix
//     x = clamp(newX, , 3);
//     y = clamp(newY, 0, 3);
}

void Terminator::defMove() {
    // No need to check for bounds here because this is not random
    const auto dest = BGptr->getVision(this->getRowLoc(),this->getColumnLoc(),3);
    BGptr->robotDelete(dest->first,dest->second);
    BGptr->moveRobot(this->getRowLoc(),this->getColumnLoc(),dest->first,dest->second);
}
