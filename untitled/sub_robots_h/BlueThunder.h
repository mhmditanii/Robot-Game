//
// Created by mhmd on 5/18/24.
//

#ifndef BLUETHUNDER_H
#define BLUETHUNDER_H
#include "../robots_h/ShootingRobot.h"


class BlueThunder : public ShootingRobot{
private:
    int clockTurn = 1;
public:
    BlueThunder(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~BlueThunder() override;
    BlueThunder(const BlueThunder& other);
    bool shoot() override;
    void executeTurn() override;

    //Shooting functions to keep each function to do one task
    pair<size_t,size_t> getTargetCoordinates(int def = -1) const;
    void updateClockTurn();
    size_t aimUp() const;
    size_t aimRight() const;
    size_t aimDown() const;
    size_t aimLeft() const;
    pair<size_t,size_t> aimUpRight() const;
    pair<size_t,size_t> aimDownRight() const;
    pair<size_t,size_t> aimUpLeft() const;
    pair<size_t,size_t> aimDownLeft() const;

};



#endif //BLUETHUNDER_H
