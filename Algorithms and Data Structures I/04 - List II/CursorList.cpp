#include <iostream>

#include "CursorList.hpp"

List::List() {
    _head = 0;
    _tail = 0;
    _size = 0;
    _spare = 0;

    // Create linking for empty nodes
    for (int i = 0; i < _capacity; i++)
        _data[i].next = i + 1;
}

int List::allocate() {
    // Save and return value of first spare node
    int temp = _spare;
    // Save index of next spare node
    _spare = _data[_spare].next;
    return temp;
}

void List::push_front(int x) {
    int index = allocate();

    // Add value in the first empty node
    _data[index].x = x;

    // Add new linking to this node
    if (size() == 0)
        _tail = index;
    else
        _data[index].next = _head;

    // Update head and spare indexes
    _head = index;

    // Increpement size
    _size++;
}

int List::pop_front() {
    // Store value of current first element
    int returnValue = _data[_head].x;

    // Update head and spare indexes
    int index = _head;
    _head = _data[_head].next;
    _data[index].next = _spare;
    _spare = index;

    // Decrement size
    _size--;

    // If list becomes empty after removing element - reset
    if (_size == 0)
        clear();

    return returnValue;
}

void List::push_back(int x) {
    int index = allocate();

    // Add value in the first empty node
    _data[index].x = x;
    // Add new linking to this node
    if (size() == 0)
        _head = index;
    else
        _data[_tail].next = index;
    // Update tail and spare indexes
    _tail = index;

    // Increment size
    _size++;
}

int List::pop_back() {
    // Store value of current last element
    int returnValue = _data[_tail].x;

    // Update tail and spare indexes
    int index = _head;
    // Find item 2nd from the end
    // size - 1 -> indexes start from 0
    // size - 1 - 1 -> item before the last one
    for (int i = 0; i < _size - 2; i++)
        index = _data[index].next;

    _data[_tail].next = _spare;
    _spare = _tail;
    _tail = index;

    // Decrement size
    _size--;

    // If list becomes empty after removing element - reset
    if (_size == 0)
        clear();

    return returnValue;
}

int List::size() {
    return _size;
}

bool List::empty() {
    return _size == 0;
}

void List::clear() {
    _size = 0;
    _spare = 0;

    // Create linking for empty nodes
    for (int i = 0; i < _capacity; i++)
        _data[i].next = i + 1;
}

int List::find(int x) {
    // Iterate the array by linked elements starting with head
    int index = _head;
    for (int i = 0; i < _size; i++)
        if (_data[index].x == x)
            return i;
        else
            index = _data[index].next;
    // Item not found
    return -1;
}

int List::erase(int i) {
    // Iterate to desired index i
    int index = _head;
    for (int k = 0; k < i; k++)
        index = _data[index].next;

    // Update linking of spare, elemnt before removed one, and removed one
    int newSpare = _spare;
    _spare = _data[index].next;
    _data[index].next = _data[_data[index].next].next;
    _data[_spare].next = newSpare;
    
    // Decremenet size
    _size--;
    return _data[_spare].x;
}

void List::insert(int i, int x) {
    // Iterate to desired index i
    int index = _head;	
    for (int k = 0; k < i; k++)
        index = _data[index].next;
    
    // Update linking of spare, elemnt before added one, and added one
    int temp = _spare;
    _data[temp].x = x;
    _spare = _data[_spare].next;
    
    if (i == 0) {
        _data[temp].next = _head;
        _head = temp;
    } else {
        _data[temp].next = _data[index].next;
        _data[index].next = temp;
    }
    
    // Increment size
    _size++;
}

int List::remove(int x) {
    int counter = 0;
    while (find(x) != -1) {
        erase(find(x));
        counter++;
        _size--;
    }

    return counter;
}

void List::replace(int i, int x) {
    // Iterate unless reach desired index i
    int index = _head;
    for (int k = 0; k < i; k++)
        index = _data[index].next;

    // Update value
    _data[index].x = x;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::string amountInput;
    std::string task;

    std::cin >> amountInput;
    int amount = stoi(amountInput);

    List list;

    std::string input;

    for (int i = 0; i <= amount; i++) {
        getline(std::cin, input);

        if (input.find('F') == 0) {
            int num = stoi(input.substr(2, input.length()));
            list.push_front(num);
        }

        if (input.find('B') == 0) {
            int num = stoi(input.substr(2, input.length()));
            list.push_back(num);
        }

        if (input.find('f') == 0) {
            if (list.empty()) {
                std::cout << "EMPTY" << std::endl;
            } else {
                std::cout << list.pop_front() << std::endl;
            }
        }

        if (input.find('b') == 0) {
            if (list.empty()) {
                std::cout << "EMPTY" << std::endl;
            } else {
                std::cout << list.pop_back() << std::endl;
            }
        }

        if (input.find('R') == 0) {
            std::string nums = input.substr(2, input.length());
            char temp = 't';
            int i = 0;
            while (temp != ' ') {
                temp = nums[i];
                i++;
            }

            int x = stoi(input.substr(2, i));
            int y = stoi(input.substr(i + 2, input.length()));

            int index = list.find(x);
            if (index == -1) {
                std::cout << "FALSE" << std::endl;
            } else {
                // list.erase(index);
                // list.insert(index, y);
                list.replace(index, y);
                std::cout << "TRUE" << std::endl;
            }
        }

        if (input.find('S') == 0) {
            std::cout << list.size() << std::endl;
        }
    }

    return 0;
}