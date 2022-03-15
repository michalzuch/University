#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP

class Stack {
private:
    struct Node {
        int data;
        struct Node* link;
    };

    struct Node* top;

    int _capacity;
    int _counter = 0;

public:

    // Constructor, argument - array size
    Stack(int capacity);

    // Adds element to stack
    void push(int x);

    // Removes the element from stack and returns its value
    int pop();

    // Returns amount of elements on stack
    int size();

    // Checks if stack is empty
    bool empty();

};

#endif //LINKEDSTACK_HPP
