#ifndef LINKEDQUEUE_HPP
#define LINKEDQUEUE_HPP

#include <iostream>

class Queue {
private:
    struct Node {
        int data;
        Node* link;
        Node(int d) {
            data = d;
            link = NULL;
        }
    };

    int _size = 0;
    Node* front = NULL;
    Node* end = NULL;

public:
    // Default constructor
    Queue();

    // Adds element x to queue (enqueue)
    void push(int x);

    // Removes element from queue and returns its value (dequeue)
    int pop();

    // Returns amount of elements in queue
    int size();

    // Checks if queue is empty
    bool empty();
};

#endif //LINKEDQUEUE_HPP