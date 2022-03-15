#include "ArrayStack.hpp"
#include <iostream>
#include <stdexcept>

Stack::Stack(int capacity) {
    _capacity = capacity;
}

void Stack::push(int x) {
    try {
        if (_top >= _capacity) {
            throw std::out_of_range("Stack overflow.");
        } else {
            _top++;
            data[_top] = x;
        }
    } catch(std::out_of_range &msg) {
        std::cerr << msg.what() << std::endl;
    }
}

int Stack::pop() {
    int return_value = -1;
    try {
        if (_top <= 0) {
            throw std::out_of_range("Stack underflow.");
        } else {
            return_value = data[_top];
            data[_top] = '\0';
            _top--;
        }
    } catch(std::out_of_range msg) {
        std::cerr << msg.what() << std::endl;
    }
return return_value;
}

int Stack::size() {
    return _top;
}

bool Stack::empty() {
    if (_top == 0) {
        return true;
    } else {
        return false;
    }
}