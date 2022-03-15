#include "ArrayQueue.hpp"
#include <iostream>
#include <stdexcept>

Queue::Queue(int size) {
    _size = size;
};

void Queue::push(int x) {

    if (_end == _size) {
        std::cout << "Queue overflow" << std::endl;
    }

    _buffer[circularPosition(_end)] = x;
    _end++;
}

int Queue::pop() {
    if (_top == _end) {
        std::cout << "empty q" << std::endl;
    }
    int temp = _buffer[circularPosition(_top)];
    _top++;
    return temp;
}

int Queue::size() {
    return _end - _top;
}

bool Queue::empty() {
    return _top == _end;
}

int Queue::circularPosition(int index) {
    return index % _size;
}