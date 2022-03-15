#include <iostream>

#include "LinkedList.hpp"

List::List() {
    // Implementation suggested by Linus Torvalds
    // Size
    guard->data = 0;
    // First element of node string (head)
    guard->prev = guard;
    // Last element of node string (tail)
    guard->next = guard;
}

void List::push_front(int x) {
    // Create new node
    Node* temp = new Node();

    // Add value
    temp->data = x;

    // Change linking
    temp->next = guard->prev;
    temp->prev = guard->next;
    temp->next->prev = temp;
    temp->prev->next = temp;
    guard->prev = temp;

    // Increment size
    guard->data++;
}

int List::pop_front() {
    // Take the popped value
    int return_value = guard->prev->data;

    // Change linking
    guard->prev = guard->prev->next;

    // Decrement size
    guard->data--;
    
    // If list becomes empty reset pointers for first and last element
    if (size() == 0) {
        guard->prev = guard;
        guard->next = guard;
    }

    return return_value;

}

void List::push_back(int x) {
    // Create new node
    Node* temp = new Node();

    // Add value
    temp->data = x;

    // Change linking
    temp->next = guard->prev;
    temp->prev = guard->next;
    temp->prev->next = temp;
    temp->next->prev = temp;
    guard->next = temp;
    
    // Increment size
    guard->data++;
}

int List::pop_back() {
    // Take the popped value
    int return_value = guard->next->data;

    // Change linking
    guard->next = guard->next->prev;
    
    // Decrement size
    guard->data--;
    
    // If list becomes empty reset pointers for first and last element
    if (size() == 0) {
        guard->prev = guard;
        guard->next = guard;
    }

    return return_value;
}

int List::size() {
    return guard->data;
}

bool List::empty() {
    return guard->data == 0;
}

void List::clear() {
    while(!empty())
        pop_front();
}

int List::find(int x) {
    iterator finder{};
    finder.ptr = guard->prev;

    for (int i = 0; i < size(); i++) {
        if (*finder == x)
            return i;

        ++finder;
    }
    return -1;
}

int List::erase(int i) {
    iterator it{};
    it.ptr = guard->prev;

    // Go to element at index i
    for (int j = 0; j < i; j++)
        ++it;

    Node* temp = new Node();
    temp = it.ptr;

    // Change linking
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    // Decrement size
    guard->data--;

    return *it;
}

void List::insert(int i, int x) {
    Node* temp = new Node();
    temp->data = x;

    iterator it{};
    it.ptr = guard->prev;

    // Go to element at index i
    for (int j = 0; j < i; j++)
        ++it;

    // Change linking
    temp->next = it.ptr->next;
    temp->prev = it.ptr;

    it.ptr->next->prev = temp;
    it.ptr->next = temp;

    // Check if added item isn't the first one
    if (it.ptr == guard->next)
        guard->next = temp;

    // Check if added item isn't the last one
    if (it.ptr == guard->prev)
        guard->prev = temp;

    // Increment size
    guard->data++;
}

int List::remove(int x) {
    int counter = 0;
    while (find(x) != -1) {
        erase(find(x));
        counter++;
        guard->data--;
    }

    return counter;
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
                list.insert(index, y);
                list.erase(index);
                std::cout << "TRUE" << std::endl;
            }
        }

        if (input.find('S') == 0) {
            std::cout << list.size() << std::endl;
        }
    }

    return 0;
}