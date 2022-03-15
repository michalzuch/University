#include <iostream>
#include <string>
//#include "ArrayStack.hpp"
#include "LinkedStack.hpp"

int coder(std::string operation);
std::string decoder(int codedOperation);

int main(int argc, const char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    Stack stack(100);
    std::string input = "";
    bool first = true;

    while (std::cin >> input) {
        int tmpCoder = coder(input);
        if (tmpCoder == -1) {
            if (first) {
                std::cout << input;
                first = false;
            } else {
                std::cout << " " << input;
            }
        } else if (tmpCoder == 6) {
            int tmpDeCoder;
            while ((tmpDeCoder = stack.pop()) != 5) {
                std::cout << " " << decoder(tmpDeCoder);
            }
        } else {
            stack.push(tmpCoder);
        }
    }

    std::cout << std::endl;
    return 0;
}

int coder(std::string operation) {
    if (operation.compare("+") == 0) {
        return 1;
    }
    if (operation.compare("-") == 0) {
        return 2;
    }
    if (operation.compare("*") == 0) {
        return 3;
    }
    if (operation.compare("/") == 0) {
        return 4;
    }
    if (operation.compare("(") == 0) {
        return 5;
    }
    if (operation.compare(")") == 0) {
        return 6;
    }
    return -1;
}

std::string decoder(int codedOperation) {
    switch(codedOperation) {
        case 1:
            return "+";
        case 2:
            return "-";
        case 3:
            return "*";
        case 4:
            return "/";
        case 5:
            return "(";
        case 6:
            return ")";
    }
    return "";
}