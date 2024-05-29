//
// Created by mhmd on 5/29/24.
//

#ifndef SVECTOR_ROBOT_PTR_H
#define SVECTOR_ROBOT_PTR_H
#include "svector.h"
template<>
class svector<MainRobot*> {
private:
    MainRobot** robots; //Double * used to store pointers (ptr to ptr)
                        // to avoid creating objects in constructor
    size_t rows;
    size_t columns;
public:
    //Constructor for the robot svector used in battleground
    //Initialize the vector to nullptr
    svector(size_t rows, size_t columns, MainRobot* init );
    ~svector();
    MainRobot* getRobot(size_t row,size_t column);
    void setRobot(size_t row, size_t column, MainRobot* robot);
    //Testing functions
    bool isInBounds(size_t row, size_t column);
};



#endif //SVECTOR_ROBOT_PTR_H
