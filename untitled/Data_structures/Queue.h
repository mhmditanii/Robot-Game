//
// Created by mhmd on 6/7/24.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include "linked_list.h"

class Queue {
private:
    LinkedList Qlist;

public:
    Queue();
    ~Queue();

    void enqueue(std::shared_ptr<MainRobot> value);
    shared_ptr<MainRobot> dequeue();
    bool isEmpty() const;

};



#endif //QUEUE_H
