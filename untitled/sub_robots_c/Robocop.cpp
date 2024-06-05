//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/Robocop.h"

#include "../BattleGround.h"

Robocop::Robocop(int id, string name, size_t row, size_t column, BattleGround* BGptr)
    :   MainRobot(id,name,row,column, BGptr),
        MovingRobot(id,name,row,column,BGptr),
        SeeingRobot(id,name,row,column,BGptr),
        ShootingRobot(id,name,row,column,BGptr)
{
    cout << "Creating Robocop" << endl;
}

Robocop::~Robocop() {
    cout << "Deleting Robocop" << endl;
}
void Robocop::executeTurn() {
    cout << "Robocop is executing his turn" << endl;
    this->look();
    this->move();
}
bool Robocop::look() {
    do {
        temp = moveDecision();
        if(!BGptr->isWithinBounds(temp.first,temp.second)) {
            continue;
        }
    }while(BGptr->isOccupied(temp.first,temp.second));  //If not occupied break and move
    if(!BGptr->isWithinBounds(temp.first,temp.second)) {
        assert(false && "ROBOCOP LOOK IS ACCESSING OUT OF BOUNDS");
    }
    return true;    //Doesn't matter what the function returns here
}

void Robocop::move() {
    BGptr->moveRobot
    (this->getRowLoc(),this->getColumnLoc(),temp.first,temp.second);
}

bool Robocop::shoot() {
    return true;
}


//              ********MOVE HELPER FUNCTIONS************

pair<size_t,size_t> Robocop::moveUp() const {
    return make_pair(getRowLoc() - 1,getColumnLoc());;
}

pair<size_t,size_t> Robocop::moveRight() const {
    return make_pair(getRowLoc(),getColumnLoc() + 1);
}

pair<size_t,size_t> Robocop::moveDown() const {
    return make_pair(getRowLoc() + 1,getColumnLoc());
}

pair<size_t,size_t> Robocop::moveLeft() const {
    return make_pair(getRowLoc(),getColumnLoc() - 1);
}

pair<size_t, size_t> Robocop::moveDecision() const {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 4); //+1 because I don't need a 0 result

    switch (dis(gen)) {
        case 1:
            return this->moveUp();
        case 2:
            return this->moveRight();
        case 3:
            return this->moveDown();
        case 4:
            return this->moveLeft();
        default:
            assert(false && "RANDOM NUMBER RETURNING OUT OF BOUND IN ROBOCOP");
    }
}
