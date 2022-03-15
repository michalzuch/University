#include "ArrayQueue.hpp"
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);

    std::string amountInput;
    std::string task;

    std::cin >> amountInput;
    int amount = stoi(amountInput);

    Queue queue(amount);

    std::string input;

    for (int i = 0; i <= amount; i++) {
        getline(std::cin, input);
        if (input.find('A') == 0) {
            int num = stoi(input.substr(2, input.length()));
            queue.push(num);
        }

        if (input == "D") {
            if (queue.empty()) {
                std::cout << "EMPTY" << std::endl;
            } else {
                std::cout << queue.pop() << std::endl;
            }
        }

        if (input == "S") { std::cout << queue.size() << std::endl; }
    }

    return 0;
}