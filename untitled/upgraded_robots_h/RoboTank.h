//
// Created by mhmd on 5/18/24.
//

#ifndef ROBOTANK_H
#define ROBOTANK_H
#include "MadBot.h"


class RoboTank : public MadBot{
public:
    RoboTank(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~RoboTank() override;
    pair<size_t,size_t> getTarget() const;
    bool shoot() override;
};



#endif //ROBOTANK_H
