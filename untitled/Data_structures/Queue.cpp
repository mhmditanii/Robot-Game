//
// Created by mhmd on 6/7/24.
//

#include "Queue.h"

Queue::Queue() {}

Queue::~Queue() {}

void Queue::enqueue(shared_ptr<MainRobot> value) {
    Qlist.insertAtEnd(value);
}

shared_ptr<MainRobot> Queue::dequeue() {
    if (isEmpty()) {
        throw out_of_range("Queue is empty");
    }
    shared_ptr<MainRobot> frontValue = Qlist.getHead()->data;
    Qlist.deleteValue(frontValue);
    return frontValue;
}

bool Queue::isEmpty() const {
    return Qlist.getHead() == nullptr;
}
