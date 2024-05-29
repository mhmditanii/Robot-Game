//
// Created by mhmd on 5/29/24.
//

#include "svector_robot_ptr.h"


svector<MainRobot*>::svector(size_t const row, size_t const column) : rows(row), columns(column) {
    robots = new MainRobot * [rows * columns];
    for (size_t i = 0; i < rows * columns; i++) {
        robots[i] = nullptr;
    }
}
svector<MainRobot*>::~svector() {
    delete[] robots;
}




//                 ***********SETTERS AND GETTERS****************

size_t svector<MainRobot*>::getRows() const {
    return rows;
}

size_t svector<MainRobot*>::getColumns() const {
    return columns;
}

MainRobot* svector<MainRobot *>::getRobot(size_t const row, size_t const column) const {
   //if(isInBounds(column)) assert(0,"ACCESSING OUT OF BOUDNS IN SVECTOR_robot_ptr");
    return robots[row * columns + column];
}
void svector<MainRobot *>::setRobot(size_t const row, size_t const column, MainRobot* const robot) {
    robots[row * columns + column] = robot;
}



//                  *********** TESTING/CHECKING FUNCTIONS **************


bool svector<MainRobot*>::isInBounds(size_t const row, size_t column) {
    return row < rows && column < columns;
}



//DELETED FUNCTIONS MAY BE RE-USED


// svector<MainRobot*>::svector(size_t const column, MainRobot* init)
//     : columns(column) {
//     robots = new MainRobot * [rows * column];
//     for (size_t i = 0; i < rows * column; i++) {
//         robots[i] = init;
//     }
// }