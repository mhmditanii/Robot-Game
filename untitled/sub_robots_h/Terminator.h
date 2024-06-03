//
// Created by mhmd on 5/18/24.
//

#ifndef TERMINATOR_H
#define TERMINATOR_H
#include "../robots_h/MovingRobot.h"
#include "../robots_h/SeeingRobot.h"
#include<optional>
#include<algorithm>
#include<random>

class Terminator : public MovingRobot, public SeeingRobot{
private:
    //Decides if the move should be random or not
    bool random = false;

public:
    Terminator(int id, string name, size_t row, size_t column, BattleGround* BGptr);
    ~Terminator() override;
    bool look() override;
    void move() override;
    void executeTurn() override;

    //  SPECIAL Terminator function
    void randMove();
    void defMove();
};



#endif //TERMINATOR_H
