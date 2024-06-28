//
// Created by mhmd on 5/18/24.
//

#ifndef ROBOTANK_H
#define ROBOTANK_H
#include "MadBot.h"

using namespace std;

class RoboTank : public BlueThunder {
private:
public:
    RoboTank(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~RoboTank() override;
    RoboTank(BlueThunder&&) noexcept;
    pair<size_t,size_t> getTarget() const;
    bool shoot() override;
    void executeTurn() override;
};



#endif //ROBOTANK_H
