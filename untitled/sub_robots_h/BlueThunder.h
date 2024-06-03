//
// Created by mhmd on 5/18/24.
//

#ifndef BLUETHUNDER_H
#define BLUETHUNDER_H
#include "../robots_h/ShootingRobot.h"


class BlueThunder : public ShootingRobot{
private:
    int clockTurn = 12;
public:
    BlueThunder(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~BlueThunder() override;
    bool shoot() override;
    void executeTurn() override;

    //Shooting functions to keep each function to do one task
    size_t aimUp() const;
    size_t aimRight() const;
    size_t aimDown() const;
    size_t aimLeft() const;
};



#endif //BLUETHUNDER_H
