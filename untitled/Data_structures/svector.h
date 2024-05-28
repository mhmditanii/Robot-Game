//
// Created by mhmd on 5/18/24.
//

#ifndef SELF_VECTOR_H
#define SELF_VECTOR_H
#include<iostream>
#include<cassert>
#include"../robots_h/MainRobot.h"

template<typename T>
class svector {
private:
    T* data;
    size_t rows;
    size_t columns;

public:
    //REAL FUNCTIONS
    svector(size_t rows, size_t columns, T init);
    ~svector();
    // T access(size_t x, size_t y);
    // void setVal(size_t x, size_t y, T val);
    // bool isBoundValid(size_t x, size_t y);
    // size_t getRows();
    // size_t getColumns();
    //TEST FUNCTIONS
    // void print();
};

template<typename T>
class svector<T*> {
private:
    size_t rows;
    size_t columns;
    T** data;
public:
    svector(size_t const rows, size_t const columns, T* init);
    ~svector();
    T* getData(size_t rows, size_t columns) const;
    void setData(size_t rows, size_t columns, T* value);
    void print();
    bool isInBounds(size_t row, size_t column);
};

#endif //SELF_VECTOR_H
