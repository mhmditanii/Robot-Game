//
// Created by mhmd on 5/29/24.
//

#include "svector_robot_ptr.h"


svector<MainRobot*>::svector(size_t const rows, size_t const columns, MainRobot* init)
    : rows(rows), columns(columns) {
    robots = new MainRobot * [rows * columns];
    for (size_t i = 0; i < rows * columns; i++) {
        robots[i] = init;
    }
}
svector<MainRobot*>::~svector() {
    delete[] robots;
}
MainRobot* svector<MainRobot *>::getRobot(size_t const row, size_t const column) {
    if(isInBounds(row,column)) assert(0,"ACCESSING OUT OF BOUDNS IN SVECTOR_robot_ptr");
    return robots[row * columns + column];
}
// void svector<MainRobot *>::setRobot(size_t const column, MainRobot *robot) {
//
// }




//                  *********** TESTING/CHECKING FUNCTIONS **************


bool svector<MainRobot*>::isInBounds(size_t row, size_t column) {
    return row < rows && column < columns;
}