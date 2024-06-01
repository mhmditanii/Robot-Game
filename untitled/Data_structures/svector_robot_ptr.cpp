//
// Created by mhmd on 5/29/24.
//

#include "svector_robot_ptr.h"



template<typename T>
svector<T*>::svector(size_t const rows, size_t const columns, T* init)
    : rows(rows), columns(columns) {
    data = new T*[rows * columns];
    for (size_t i = 0; i < rows * columns; i++) {
        data[i] = init;
    }
}

template<typename T>
svector<T*>::~svector() {
    delete[] data;
}
template<typename T>
T* svector<T *>::getData(size_t const row, size_t const column) const {
    return data[row * columns + column];
}

template<typename T>
void svector<T *>::setData(size_t const row, size_t const column, T* const value){
    if(!isInBounds(row,column)){assert(0 && "OUT OF BOUND SET VECTOR");}
    data[row * columns + column] = value;
}

template<typename T>
void svector<T*>::print() {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if(data[i * columns + j] == nullptr)cout << "0";
            else cout << "1";
        }
        cout << endl;
    }
}

template<typename T>
bool svector<T *>::isInBounds(size_t row, size_t column) {
        return row < rows && column < columns;
}



//             ********** MAIN ROBOTG CLASS SVECTOR ***********


svector<shared_ptr<MainRobot>>::svector(size_t const row, size_t const column) : BGrows(row), BGcolumns(column) {
    robots = new MainRobot * [BGrows * BGcolumns];
    for (size_t i = 0; i < BGrows * BGcolumns; i++) {
        robots[i] = nullptr;
    }
}
svector<shared_ptr<MainRobot>>::~svector() {
    cout << "DELETING SVECTOR OF SHARED PTR" << endl;
}




//                 ***********SETTERS AND GETTERS****************

size_t svector<shared_ptr<MainRobot>>::getRows() const {
    return BGrows;
}

size_t svector<shared_ptr<MainRobot>>::getColumns() const {
    return BGcolumns;
}

MainRobot* svector<shared_ptr<MainRobot>>::getRobot(size_t const row, size_t const column) const {
    if(isInBounds(row,column)) assert(false && "ACCESSING OUT OF BOUDNS IN SVECTOR_robot_ptr");
    return robots[row * BGcolumns + column];
}
void svector<shared_ptr<MainRobot>>::setRobot(size_t const row, size_t const column, shared_ptr<MainRobot> robot) {
    robots[row * BGcolumns + column] = robot;
}



//                  *********** TESTING/CHECKING FUNCTIONS **************


bool svector<shared_ptr<MainRobot>>::isInBounds(size_t const row, size_t column) const {
    return row < BGrows && column < BGcolumns;
}



//DELETED FUNCTIONS MAY BE RE-USED


// svector<MainRobot*>::svector(size_t const column, MainRobot* init)
//     : columns(column) {
//     robots = new MainRobot * [rows * column];
//     for (size_t i = 0; i < rows * column; i++) {
//         robots[i] = init;
//     }
// }
