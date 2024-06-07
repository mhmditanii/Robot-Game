//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/Robocop.h"

#include "../BattleGround.h"

static std::random_device rd;    //Device used to generate random numbers
static std::mt19937 gen(rd());


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
    this->look();
    this->move();
    this->shoot();
}
bool Robocop::look() {
    do {
        temp = this->decisionMaker(true);
        // Check if the proposed move is within bounds
        if (!BGptr->isWithinBounds(temp.first, temp.second)) {
            continue;
        }
        // Check if the location is occupied
        if (!this->checkBG(temp.first, temp.second)) {
            // If within bounds and not occupied, exit the loop
            break;
        }
    } while (true); // Continue looping until a valid move is found

    return true;    //Doesn't matter what the function returns here
}

void Robocop::move() {
    BGptr->moveRobot
    (this->getRowLoc(),this->getColumnLoc(),temp.first,temp.second);
}

bool Robocop::shoot() {
    pair<size_t,size_t> target;
    //Loop to shoot 3 times
    for(int i = 0; i < 3; ++i) {
        target = this->decisionMaker(false);
        if(target.first==this->getRowLoc() && target.second == this->getColumnLoc()) {
            assert(false && "ROBOCOP IS ATTEMPTING SUICIDE");
        }
        this->attack(target.first,target.second);
    }

    return true;
}


//              ********MOVE / SHOOT + DECISION MAKING************

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
    uniform_int_distribution<> dis(1, 4); // +1 because I don't need a 0 result
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

pair<size_t, size_t> Robocop::fireDecision() const {
    // Values should be ranging from (-10,10) to include the whole range
    uniform_int_distribution<> dis(-10, 10);
    int x, y;
    int rowLoc = static_cast<int>(this->getRowLoc());
    int colLoc = static_cast<int>(this->getColumnLoc());

    // This loop computes the possible target location
    do {
        int tempX = dis(gen);
        int tempY = dis(gen);

        // Convert to absolute distance from current location
        x = abs(tempX - rowLoc);
        y = abs(tempY - colLoc);

        // Check if the computed coordinates are not the current location
        // and the sum of distances is within the allowed range
        // and the target location is within bounds
    } while ((x == rowLoc && y == colLoc) ||     // Prevent targeting current location
             (x + y > 10) ||                     // Ensure x + y <= 10
             !this->BGptr->isWithinBounds(x, y)); // Check if location is valid

    return make_pair(static_cast<size_t>(x), static_cast<size_t>(y));
}


pair<size_t, size_t> Robocop::decisionMaker(bool const move) const {
    if (move) {
        return moveDecision();
    }
    else {
        return fireDecision();
    }
}