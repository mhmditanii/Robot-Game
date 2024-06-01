//
// Created by mhmd on 5/18/24.
//

#include "svector.h"

#include "../robots_h/MainRobot.h"
using namespace std;

template<typename T>
svector<T>::svector(size_t const rows, size_t const columns, T init) : rows(rows), columns(columns) {
    data = new T[rows * columns];
    for (size_t i = 0; i < rows * columns; i++) {
        data[i] = init;
    }
}

template<typename T>
svector<T>::~svector() {
    delete[] data;
}

template<typename T>
T svector<T>::access(size_t const x, size_t const y) {
         return data[x * columns + y];
}

template<typename T>
void svector<T>::setVal(size_t const x, size_t const y, T val) {
    data[x * columns + y] = val;
}

template<typename T>
void svector<T>::print() {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            cout << data[i * columns + j];
        }
        cout << endl;
    }
}
template<>
bool svector<bool>::isBoundValid(size_t const x, size_t const y) {
    return (rows > x && columns > y); //if (x || y) < 0, UNDERFLOW -> maximum value set
}
template<>
size_t svector<unsigned long>::getRows() {
    return rows;
}
template<>
size_t svector<int>::getColumns() {
    return columns;
}



template class svector<int>;
template class svector<size_t>;