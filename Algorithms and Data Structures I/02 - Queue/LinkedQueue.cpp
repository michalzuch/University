#include "LinkedQueue.hpp"

Queue::Queue() = default;

void Queue::push(int x) {
    Node* temp = new Node(x);

    if (end == NULL) {
        front = temp;
        end = temp;
    }

    end->link = temp;
    end = temp;
    _size++;
}

int Queue::pop() {
    int return_value = front->data;
    front = front->link;

    if (front == NULL)
        end = NULL;
        
    _size--;
    return return_value;
}

int Queue::size() {
    return _size;
}

bool Queue::empty() {
    return _size == 0;
}