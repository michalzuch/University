#include <iostream>
#include <cstring>

#define SIZE 1000

int main(int argc, const char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    
    // Write amount of operations
    std::cout << argv[1] << std::endl;

    // Possible operatios - ADD x, SIZE, DELETE
    const char* operations[6] = {"F", "B", "f", "b", "R", "S"};
    srand(time(0));

    // Generate list of instructions
    for (int i = 0; i < atoi(argv[1]); i++) {

        // Choose random operation
        int n = rand() % 6;
        const char* chosenOperation = operations[n];
        
        // If F or B - add random number to instruction
        if ((strcmp(chosenOperation, "F") == 0) || (strcmp(chosenOperation, "B") == 0)) {
            int x = rand() % SIZE;
            std::cout << chosenOperation << " " << x << std::endl;
        }
        // IF R - add two random numers to instruction
        else if (strcmp(chosenOperation, "R") == 0)  {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            std::cout << chosenOperation << " " << x << " " << y << std::endl;
        } else {
            std::cout << chosenOperation << std::endl;
        }
    }
    return 0;
}