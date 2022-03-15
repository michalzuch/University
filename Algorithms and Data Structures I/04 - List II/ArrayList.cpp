#include <iostream>

#include "ArrayList.hpp"

List::List() {
    _data = new int[_capacity];
    _size = 0;
}

void List::push_front(int x) {
    if (_size == _capacity)
        throw std::out_of_range("List is full");
    if (!empty())
        // for (int i = _size + 1; i > 0; i--)
        for (int i = _size; i > 0; i--)
            _data[i] = _data[i - 1];

    _data[0] = x;
    _size++;
}

int List::pop_front() {

    int returnValue = _data[0];

    for (int i = 1; i < _size; i++)
        _data[i - 1] = _data[i];

    _size--;

    return returnValue;

}

void List::push_back(int x) {
    if (_size == _capacity)
        throw std::out_of_range("List is full");

    _data[_size++] = x;
}

int List::pop_back() {
    
    int returnValue = _data[_size - 1];
    _size--;

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
}

int List::find(int x) {
    for(int i = 0; i < _size; i++)
        if (_data[i] == x)
            return i;

    return -1;
}

int List::erase(int i) {
    int returnValue = _data[i];

    for (int k = i; k < _size; k++) {
        _data[k] = _data[k + 1];
    }

    return returnValue;
}

void List::insert(int i, int x) {

    for (int k = i; k < _size; k++) {
        _data[k + 1] = _data[k];
    }
    _data[i] = x;

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
    _data[i] = x;
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
                // list.insert(index, y);
                // list.erase(index);
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