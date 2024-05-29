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
    svector(size_t row, size_t column);
    ~svector();

    //               SETTERS AND GETTERS
    MainRobot* getRobot(size_t row, size_t column) const;
    void setRobot(size_t row,size_t column, MainRobot* robot);
    size_t getRows() const;
    size_t getColumns() const;
    size_t getRobRow() const;
    size_t getRobCol() const;


    //Testing functions
    bool isInBounds(size_t row,size_t column);
};



#endif //SVECTOR_ROBOT_PTR_H
