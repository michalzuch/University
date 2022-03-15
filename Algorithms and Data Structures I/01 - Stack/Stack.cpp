#include <iostream>
#include <string>
#include "ArrayStack.hpp"
// #include "LinkedStack.hpp"

int main() {
    std::ios_base::sync_with_stdio(false);

    std::string amountInput;
    std::string task;

    std::cin >> amountInput;
    int amount = stoi(amountInput);

    Stack stack(amount);

    std::string input;

    for(int j = 0; j <= amount; j++) {
        getline(std::cin, input);
        if (input.find('A') == 0) {
            try {
                int num = stoi(input.substr(2, input.length()));
                stack.push(num);    
            } catch (std::out_of_range &msg) {
                std::cerr << msg.what() << std::endl;
            }
            
        }

        if (input == "D") {
            if (stack.empty()) {
                std::cout << "EMPTY" << std::endl;
            } else {
                try {
                    std::cout << stack.pop() << std::endl;
                } catch (std::out_of_range &msg) {
                    std::cerr << msg.what() << std::endl;
                }
            }
        }

        if (input == "S") { std::cout << stack.size() << std::endl; }
    }

    return 0;
}
