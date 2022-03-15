#ifndef ARRAYQUEUE_HPP
#define ARRAYQUEUE_HPP

class Queue {
private:

    int _top = 0;
    int _end = 0;
    int _size;
    int* _buffer = new int;

    int circularPosition(int index);

public:
    // Default constructor
    Queue(int size);

    // Adds element x to queue (enqueue)
    void push(int x);

    // Removes element from queue and returns its value (dequeue)
    int pop();

    // Returns amount of elements in queue
    int size();

    // Checks if queue is empty
    bool empty();
};

#endif //ARRAYQUEUE_HPP