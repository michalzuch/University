#include <iostream>
#include <cstring>

int main(int argc, const char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    
    // Write amount of operations
    std::cout << argv[1] << std::endl;

    // Possible operatios - ADD x, SIZE, DELETE
    const char* operations[3] = {"A", "S", "D"};
    srand(time(0));

    // Generate list of instructions
    for (int i = 0; i < atoi(argv[1]); i++) {

        // Choose random operation
        int n = rand() % 3;
        const char* chosenOperation = operations[n];
        
        // If A - add random number to instruction
        if (strcmp(chosenOperation, "A") == 0) {
            int x = rand() % 1000000;
            std::cout << chosenOperation << " " << x << std::endl;
        } else {
            std::cout << chosenOperation << std::endl;
        }
    }
    return 0;
}