#include "LinkedStack.hpp"
#include <iostream>

Stack::Stack(int capacity) {
    _capacity = capacity;
}

void Stack::push(int x) {
    if (_counter >= _capacity) {
        throw std::out_of_range("Stack overflow.");
    } else {
        struct Node* node = new Node();
        node->data = x;
        node->link = top;
        _counter++;
        top = node;
    }
}


int Stack::pop() {
    struct Node* node;
    int return_value = top->data;
    if (_counter <= 0) {
        throw std::out_of_range("Stack underflow.");
    } else {
        _counter--;
        node = top;
        top = top->link;
        node->link = NULL;
    }
    delete node;
    return return_value;
}

int Stack::size() {
    return _counter;
}

bool Stack::empty() {
    return _counter == 0;
}
