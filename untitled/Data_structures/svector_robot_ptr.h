//
// Created by mhmd on 5/29/24.
//

#ifndef SVECTOR_ROBOT_PTR_H
#define SVECTOR_ROBOT_PTR_H
#include"../robots_h/MainRobot.h"
#include"svector.h"
#include<memory>
#include"linked_list.h"
#include"Queue.h"
#include<random>

template<typename T>
class svector<T*> {
private:
    T** data;
    size_t rows;
    size_t columns;
public:
    svector(size_t rows, size_t columns, T* init);
    ~svector();
    T* getData(size_t rows, size_t columns) const;
    void setData(size_t rows, size_t columns, T* value);
    void print();
    bool isInBounds(size_t row, size_t column) const;
};


template<>
class svector<shared_ptr<MainRobot>> {
private:
    shared_ptr<shared_ptr<MainRobot>[]> robots; //Double * used to store pointers (ptr to ptr)
                                                // to avoid creating objects in constructor
    size_t BGrows;
    size_t BGcolumns;


public:

    //LS responsible for handling the robots execution and turns
    LinkedList* activeList;
    //Q responsible for inactive robots
    Queue* waitQueue;


    //Constructor for the robot svector used in building the battleground matrix
    //Initializes the battleground to nullptr
    svector(size_t row, size_t column);
    ~svector();

    //                      SETTERS AND GETTERS
    shared_ptr<MainRobot> getRobot(size_t row, size_t column) const;
    void setRobot(size_t row,size_t column, shared_ptr<MainRobot> robot);
    size_t getRows() const;
    size_t getColumns() const;
    void setRobotToList(shared_ptr<MainRobot>) const;

    //                      Testing functions
    bool isInBounds(size_t row,size_t column) const;
    void moveData(size_t curRow, size_t curCol, size_t destRow, size_t destCol);
    void print() const;
    //Used to delete the robots from the matrix(Battleground)
    void deleteData(size_t row, size_t column);

    void enqueueData(size_t row, size_t column) const;
    shared_ptr<MainRobot> dequeueData() const;

    pair<size_t,size_t> genRandPos() const;

};



#endif //SVECTOR_ROBOT_PTR_H
