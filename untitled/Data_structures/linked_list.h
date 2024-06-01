//
// Created by mhmd on 6/1/24.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../robots_h/MainRobot.h"



class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void insertAtBeginning(MainRobot* value);
    void insertAtEnd(MainRobot* value);
    void deleteValue(MainRobot* value);

private:
    struct Node {
        MainRobot* data;
        Node* next;
        Node(MainRobot* value) : data(value), next(nullptr) {}
    };

    Node* head;
};


#endif //LINKED_LIST_H
