//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/Terminator.h"
#include "../BattleGround.h"

Terminator::Terminator(int const id, string name, size_t row, size_t column, BattleGround* BGptr)
    :   MainRobot(id,name,row,column, BGptr),
        MovingRobot(id,name,row,column, BGptr), SeeingRobot(id,name,row,column, BGptr)
        ,SteppingRobot(id,name,row,column, BGptr)
{
    cout << "CREATED TERMINATOR" << endl;
}
Terminator::~Terminator() {
    cout << "Delting terminator" << endl;
}

bool Terminator::look(){
    if(BGptr->getVision(this->getRowLoc(),this->getColumnLoc(),3) != nullopt) {
        return true; //found a robot
    }
    //No robot in scope
    return false;
}

void Terminator::move() {
    // Create a random device and a random number generator
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<int> dist();
}

void Terminator::step() {
    // No need to check for bounds (Checked in look function)
    const auto dest = BGptr->getVision(this->getRowLoc(),this->getColumnLoc(),3);
    if (getRowLoc() == dest->first && getColumnLoc() == dest->second) {
        assert(false && "TERMINATOR TRYING TO COMMIT SUICIDE IN STEP FUNCTION");
    }
    this->attack(dest->first,dest->second);
    BGptr->moveRobot(this->getRowLoc(),this->getColumnLoc(),dest->first,dest->second);
}


void Terminator::executeTurn(){
    //Checks for robots in scope then executes based on result of look
    if(this->look()) {
        this->step();
    }
    else {
        this->move();
    }
}


