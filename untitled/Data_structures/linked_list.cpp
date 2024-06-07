#include "linked_list.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::insertAtBeginning(shared_ptr<MainRobot> value) {
    cout << "ADDING ROOBT TO LIST" << endl;
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(shared_ptr<MainRobot> value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::deleteValue(shared_ptr<MainRobot> value) {
    if (head == nullptr) {
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    if (current->next == nullptr) {
        return;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

LinkedList::Node *LinkedList::getHead() const {
    return this->head;
}
