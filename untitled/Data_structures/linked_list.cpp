#include "linked_list.h"

LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::~LinkedList() {
    if (head == nullptr) return;
    Node* current = head;
    Node* nextNode;
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
}

void LinkedList::insertAtBeginning(shared_ptr<MainRobot> value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        newNode->next = head;
        current->next = newNode;
        head = newNode;
    }
    size++; // Increment size
}

void LinkedList::insertAtEnd(shared_ptr<MainRobot> value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    size++; // Increment size
}

void LinkedList::deleteValue(shared_ptr<MainRobot> value) {
    if (head == nullptr) {
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = head->next;
            head = head->next;
        }
        delete temp;
        size--; // Decrement size
        return;
    }
    Node* current = head;
    do {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--; // Decrement size
            return;
        }
        current = current->next;
    } while (current != head);
}

int LinkedList::getSize() const {
    return size;
}

shared_ptr<MainRobot> LinkedList::iterate() {
    if (head == nullptr) {
        return nullptr;
    }
    shared_ptr<MainRobot> data = head->data;
    head = head->next;
    return data;
}

LinkedList::Node *LinkedList::getHead() const {
    return this->head;
}