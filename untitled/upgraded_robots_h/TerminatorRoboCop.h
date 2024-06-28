//
// Created by mhmd on 5/18/24.
//

#ifndef TERMINATORROBOCOP_H
#define TERMINATORROBOCOP_H
#include "../sub_robots_h/Robocop.h"
#include "../sub_robots_h/Terminator.h"


class TerminatorRoboCop : public Robocop, Terminator{
public:
    TerminatorRoboCop(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~TerminatorRoboCop() override;
    TerminatorRoboCop(Robocop&&) noexcept;
    TerminatorRoboCop(Terminator&&) noexcept;
    void executeTurn() override;

    //Terminator methods
    using Terminator::look;
    using Terminator::move;
    using Terminator::step;
    //Robocop methods
    using Robocop::shoot;
};



#endif //TERMINATORROBOCOP_H
