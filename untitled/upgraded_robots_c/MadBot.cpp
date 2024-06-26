//
// Created by mhmd on 5/18/24.
//
#include "../upgraded_robots_h/MadBot.h"

// RANDOM DEVICE GENERATOR
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(1,8);

MadBot::MadBot (int id, string name, size_t row, size_t column, BattleGround* BGptr)
    :   MainRobot(id,name,row,column,BGptr),BlueThunder(id,name,row,column,BGptr)
{
    cout << "MadBot created" << endl;
}
MadBot::~MadBot() {
    cout <<"Deleting MadBot" << endl;
}

MadBot::MadBot(BlueThunder &&other) noexcept
    : MainRobot(std::move(other)),BlueThunder(std::move(other))
{
    cout << "UPGRADING TO MADBOT USING MOVE OPERATOR"<<endl;
}

// MadBot &MadBot::operator=(MadBot &&other) {
//     if(this != &other) {
//
//     }
// }



bool MadBot::shoot() {
    const int random = dis(gen);
    auto[x,y] = this->getTargetCoordinates(random);
    return this->attack(x,y);
}

void MadBot::executeTurn() {
    this->shoot();
}


