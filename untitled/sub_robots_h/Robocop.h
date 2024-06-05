//
// Created by mhmd on 5/18/24.
//

#ifndef ROBOCOP_H
#define ROBOCOP_H

#include<cstdlib>
#include<ctime>
#include <optional>

#include "../robots_h/MovingRobot.h"
#include "../robots_h/SeeingRobot.h"
#include "../robots_h/ShootingRobot.h"
class Robocop : public MovingRobot, public SeeingRobot, public ShootingRobot {
private:
    pair<size_t,size_t> temp;
public:
    Robocop(int id,string name, size_t row, size_t column, BattleGround* BGptr);
    ~Robocop() override;
    void move() override;
    bool look() override;
    bool shoot() override;
    void executeTurn() override;

    //Move functions
    pair<size_t,size_t> moveUp() const;
    pair<size_t,size_t> moveRight() const;
    pair<size_t,size_t> moveDown() const;
    pair<size_t,size_t> moveLeft() const;
    pair<size_t,size_t> moveDecision() const;
};



#endif //ROBOCOP_H
