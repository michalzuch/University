#include <iostream>
#include <vector>
#include <chrono>

template <class T> void sort(std::vector<T>& input_vector) {
    int size = input_vector.size();

    for (int i = 1; i < size; i++) {
        T temp = input_vector.at(i);
        int j = i - 1;
        
        while (j >= 0 && input_vector.at(j) > temp) {
            input_vector.at(j + 1) = input_vector.at(j);
            --j;
        }
        input_vector.at(j + 1) = temp;
    }
}

int main(void) {
    // Store input in vector
    int input_line;
    std::vector<int> data;
    while (std::cin >> input_line)
        data.push_back(input_line);

    // Insertion sort
    // auto start = std::chrono::high_resolution_clock::now();
    sort(data);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed = end - start;
    // std::cerr << "Elapsed time [s] = " << elapsed.count() << std::endl;

    // Print the output
    for (const auto& i : data)
        std::cout << i << std::endl;

    return 0;
}