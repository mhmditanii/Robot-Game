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
        Node(std::shared_ptr<MainRobot> value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;
    Node* iterator;

public:
    LinkedList();
    ~LinkedList();
    void insertAtEnd(std::shared_ptr<MainRobot> value);
    void deleteValue(std::shared_ptr<MainRobot> value);
    int getSize() const;
    std::shared_ptr<MainRobot> iterate();
    Node* getHead() const;
};

#endif // LINKEDLIST_H
