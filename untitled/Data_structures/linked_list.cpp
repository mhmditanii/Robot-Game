#include "linked_list.h"

LinkedList::LinkedList() : head(nullptr), size(0), iterator(nullptr) {}

LinkedList::~LinkedList() {
    if (head == nullptr) return;
    Node* current = head;
    Node* nextNode;
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
    head = nullptr;
    iterator = nullptr;
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
    size++;
    if (iterator == nullptr) {
        iterator = head; // Initialize iterator if it was nullptr
    }
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
        if (size == 0) {
            iterator = nullptr; // Reset iterator if list is empty
        } else if (iterator == temp) {
            iterator = head; // Update iterator if it was pointing to the deleted node
        }
        return;
    }
    Node* current = head;
    do {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            if (iterator == temp) {
                iterator = current->next; // Update iterator if it was pointing to the deleted node
            }
            delete temp;
            size--;
            if (size == 0) {
                iterator = nullptr; // Reset iterator if list is empty
            }
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
        assert(false && "ITERATOR in linkedlist is returning a nullptr which is absurd");
    }
    if (iterator == nullptr) {
        iterator = head;
    }
    shared_ptr<MainRobot> data = iterator->data;
    iterator = iterator->next;
    if(data == nullptr) {
        assert(false && "ITERATOR is returning nullptr which is absurd");
    }
    return data;
}

LinkedList::Node* LinkedList::getHead() const {
    return this->head;
}