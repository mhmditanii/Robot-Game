//
// Created by mhmd on 5/18/24.
//

#ifndef MADBOT_H
#define MADBOT_H
#include "../BattleGround.h"
#include "../sub_robots_h/BlueThunder.h"


class MadBot : public BlueThunder{
private:

public:
    MadBot(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~MadBot() override;
    bool shoot() override;
    void executeTurn() override;
};



#endif //MADBOT_H
