//
// Created by mhmd on 6/1/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include"../robots_h/MainRobot.h"
#include<memory>

class LinkedList {
private:
    struct Node {
        std::shared_ptr<MainRobot> data;
        Node* next;

        Node(shared_ptr<MainRobot> value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;
public:
    LinkedList();
    ~LinkedList();

    void insertAtBeginning(shared_ptr<MainRobot> value);
    void insertAtEnd(shared_ptr<MainRobot> value);
    void deleteValue(shared_ptr<MainRobot> value);
    int getSize() const;
    Node* getHead() const;
    shared_ptr<MainRobot> iterate();
};

#endif // LINKEDLIST_H
