#include <iostream>
#include <string>
#include "BinaryTree.hpp"

int main() {
    std::ios_base::sync_with_stdio(false);

    std::string amountInput;
    std::cin >> amountInput;
    int amount = stoi(amountInput);


    BinaryTree binary_tree;
    std::string input;

    for (int i = 0; i < amount; i++) {
        std::cin >> input;
        binary_tree.insert(stoi(input));
    }

    std::cout << binary_tree.size() << " " << binary_tree.depth() << " "
        << binary_tree.minimum() << " " << binary_tree.maximum() << std::endl;
    
    binary_tree.preorder();

    for (int j = 1; j <= 9; j++) {
        if (binary_tree.search(j) != nullptr)
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }

    return 0;
}