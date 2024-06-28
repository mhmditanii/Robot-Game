//
// Created by mhmd on 5/18/24.
//
#include "../upgraded_robots_h/MadBot.h"


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
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,8);
    int random;
    pair<size_t,size_t> target;
    do {
        random = dis(gen);
        target = this->getTargetCoordinates(random);
    }while(!this->BGptr->isWithinBounds(target.first,target.second));

    return this->attack(target.first,target.second);
}

void MadBot::executeTurn() {
    this->shoot();
}


