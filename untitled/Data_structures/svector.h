//
// Created by mhmd on 5/18/24.
//

#ifndef SELF_VECTOR_H
#define SELF_VECTOR_H
#include<iostream>
#include<memory>
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
    T access(size_t x, size_t y);
    void setVal(size_t x, size_t y, T val);
    bool isBoundValid(size_t x, size_t y);
    //TEST FUNCTIONS
    void print();
};

#endif //SELF_VECTOR_H
