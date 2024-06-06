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
    //if(!isInBounds(row,column)){assert(0 && "OUT OF BOUND SET VECTOR");}
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
bool svector<T *>::isInBounds(size_t row, size_t column) const {
        return row < rows && column < columns;
}



//             ********** MAIN ROBOTG CLASS SVECTOR ***********


svector<shared_ptr<MainRobot>>::svector(size_t const row, size_t const column) : BGrows(row), BGcolumns(column) {
    robots = std::shared_ptr<std::shared_ptr<MainRobot>[]>(new std::shared_ptr<MainRobot>[BGrows * BGcolumns]);
    for (size_t i = 0; i < BGrows * BGcolumns; i++) {
        robots[static_cast<int>(i)] = nullptr;
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

shared_ptr<MainRobot> svector<shared_ptr<MainRobot>>::getRobot(size_t const row, size_t const column) const {
    if(!isInBounds(row,column)) assert(false && "ACCESSING OUT OF BOUDNS IN SVECTOR_robot_ptr getRobot() : ");
    const int temp = static_cast<int>(row * BGcolumns + column);
    return robots[temp];
}
void svector<shared_ptr<MainRobot>>::setRobot(size_t const row, size_t const column, shared_ptr<MainRobot> robot) {
    const int temp = static_cast<int>(row * BGcolumns + column);
    robots[temp] = robot;
}



//                  *********** TESTING/CHECKING FUNCTIONS **************

void svector<shared_ptr<MainRobot> >::deleteData(size_t const row, size_t const column) {
    const int temp = static_cast<int>(row * BGcolumns + column);
    robots[temp] = nullptr;
}

bool svector<shared_ptr<MainRobot>>::isInBounds(size_t const row, size_t const column) const {
    return row < BGrows && column < BGcolumns;
}

void svector<shared_ptr<MainRobot>>::moveData
(size_t const curRow, size_t const curCol, size_t const destRow, size_t const destCol) {
    this->setRobot(destRow,destCol,this->getRobot(curRow,curCol));
    this->deleteData(curRow,curCol);
}

void svector<shared_ptr<MainRobot>>::print() const {
    for (size_t i = 0; i < BGrows; ++i) {
        for (size_t j = 0; j < BGcolumns; ++j) {
            if(this->getRobot(i,j) == nullptr) {
                cout << "0" << " : ";
            }
            else {
                cout << "1" << " : ";
            }

        }
        cout << endl;
    }
}