#include <iostream>
#include <vector>

template <class T> int sort(std::vector<T>& input_vector) {
    int counter = 0;
    int size = input_vector.size();
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++) {
            // counter++;
            if (input_vector.at(j) > input_vector.at(j + 1)) {
                counter++;
                std::swap(input_vector.at(j), input_vector.at(j + 1));
            }
        }
        return counter;
}

int main(void) {
    // Store input in vector
    int input_line;
    std::vector<int> data;
    while (std::cin >> input_line)
        data.push_back(input_line);

    // Bubble sort
    int counter = sort(data);

    // Print the output
    std::cout << "Amount of swaps: " << counter << std::endl;

    return 0;
}