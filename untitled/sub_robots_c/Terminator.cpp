//
// Created by mhmd on 5/18/24.
//

#include "../sub_robots_h/Terminator.h"
#include "../BattleGround.h"

Terminator::Terminator(int const id, string name, size_t row, size_t column, BattleGround* BGptr)
    :   MainRobot(id,name,row,column, BGptr),
        MovingRobot(id,name,row,column, BGptr), SeeingRobot(id,name,row,column, BGptr)
        ,SteppingRobot(id,name,row,column, BGptr)
{
    cout << "CREATED TERMINATOR" << endl;
}

Terminator::Terminator(Terminator&& other) noexcept :
    MainRobot(std::move(other)), MovingRobot(std::move(other)),SeeingRobot(std::move(other))
    , SteppingRobot(std::move(other))
{
}

Terminator::~Terminator() {
    cout << "Delting terminator" << endl;
}

bool Terminator::look(){
    if(BGptr->getVision(this->getRowLoc(),this->getColumnLoc(),3) != nullopt) {
        return true; //found a robot
    }
    //No robot in scope
    return false;
}


void Terminator::step() {
    // No need to check for bounds (Checked in look function)
    const auto dest = BGptr->getVision(this->getRowLoc(),this->getColumnLoc(),3);
    if (getRowLoc() == dest->first && getColumnLoc() == dest->second) {
        assert(false && "TERMINATOR TRYING TO COMMIT SUICIDE IN STEP FUNCTION");
    }
    cout << "ATTACKING USING STEP FUNCTION" << endl;
    this->attack(dest->first,dest->second);
    BGptr->moveRobot(this->getRowLoc(),this->getColumnLoc(),dest->first,dest->second);
}

void Terminator::move() {
    // Create a random device and a random number generator
    random_device rd;
    mt19937 gen(rd());
    //Variables initialization for bounds and result
    auto[minX,minY] = this->moveLimitBackGen();
    auto[maxX,maxY] = this->moveLimitFrontGen();
    size_t resX,resY;

    //Initialize the generators with the limits
    uniform_int_distribution<size_t> XGen(minX,maxX);
    uniform_int_distribution<size_t> YGen(minY,maxY);

    //Looping to find a valid destination
    do {
        // Generate random coordinates
        resX = XGen(gen);
        resY = YGen(gen);
        cout << resX << "  " << resY << endl;
    } while(abs(static_cast<int>(resX) - static_cast<int>(getRowLoc())) > 3
            || abs(static_cast<int>(resY) - static_cast<int>(getColumnLoc())) > 3
            || (resX == getRowLoc() && resY == getColumnLoc())
            || (BGptr->getRobot(resX, resY) != nullptr));

    BGptr->moveRobot(getRowLoc(),getColumnLoc(),resX,resY);
}

void Terminator::executeTurn(){
    //Checks for robots in scope then executes based on result of look
    if(this->look()) {
        this->step();
    }
    else {
        this->move();
    }
}

//Checks the bounds for the terminator move function
pair<size_t, size_t> Terminator::moveLimitFrontGen() const {
    size_t x , y;

    auto [limX, limY] = BGptr->getMatrixBounds();
    //if Location + scope > bounds -> your scope limit is bounds
    x = this->getRowLoc() + 3 >= limX - 1 ? limX  - 1: this->getRowLoc() + 3;
    y = this->getColumnLoc() + 3 >= limY - 1 ? limY - 1: this->getColumnLoc() + 3;

    return make_pair(x,y);
}

pair<size_t, size_t> Terminator::moveLimitBackGen() const {
    size_t x, y;

    // Ensuring robot doesn't go below 0 (no -3 because it may cause underflow)
    x = (this->getRowLoc() < 3) ? 0 : this->getRowLoc() - 3;
    y = (this->getColumnLoc() < 3) ? 0 : this->getColumnLoc() - 3;

    return make_pair(x, y);
}

