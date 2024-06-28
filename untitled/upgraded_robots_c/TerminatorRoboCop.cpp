//
// Created by mhmd on 5/18/24.
//

#include "../upgraded_robots_h/TerminatorRoboCop.h"

TerminatorRoboCop::TerminatorRoboCop(int id,string name, size_t row, size_t column, BattleGround* BGptr)
    : MainRobot(id,name,row,column,BGptr), Robocop(id,name,row,column,BGptr),
      Terminator(id,name,row,column,BGptr)
{
    cout << "Terminator ROBOCOP id created"<< endl;
}

TerminatorRoboCop::TerminatorRoboCop(Robocop&& other) noexcept
    : MainRobot(std::move(other)),Robocop(std::move(other))
    ,Terminator(60,other.getName(),other.getRowLoc(),other.getColumnLoc(),other.getBGptr())
{
    cout << "UPGRADING TO TERMIANTOR_ROBOCOP USING MOVE OPERATOR" << endl;
}

TerminatorRoboCop::TerminatorRoboCop(Terminator&& other) noexcept
    : MainRobot(std::move(other)),Robocop(60,other.getName(),other.getRowLoc(),other.getColumnLoc(),other.getBGptr())
    ,Terminator(std::move(other))
{
    cout << "UPGRADING TO TERMIANTOR_ROBOCOP USING MOVE OPERATOR" << endl;
}

TerminatorRoboCop::~TerminatorRoboCop() {
    cout << "Terminator Robocop is deleted" << endl;
}

void TerminatorRoboCop::executeTurn() {
    //Uses terminator look to check for robots in scope 3x3
    if(this->look()) {
        this->step();
        this->shoot();
    }
    else {
    // No robot -> random move then shoot
        this->move();
        this->shoot();
    }
}

