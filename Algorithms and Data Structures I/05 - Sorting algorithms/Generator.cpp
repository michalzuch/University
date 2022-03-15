#include <iostream>

int main(int argc, const char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    int n = atoi(argv[1]);
    int max = atoi(argv[2]);
    srand(time(0));

    for (int i = 0; i < n; i++)
        std::cout << rand() % max + 1 << std::endl;

    return 0;
}