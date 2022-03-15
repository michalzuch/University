#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

template <class T> void sort(std::vector<T>& input_vector) {
    int size = input_vector.size();

    for (int i = 0; i < size - 1; i++) {

        // Find minimal value and its index
        T min = *min_element(input_vector.begin() + i, input_vector.end());
        int j = i;
        while (input_vector.at(j) != min)
            j++;

        std::swap(input_vector.at(j), input_vector.at(i));
    }
}

int main(void) {
    // Store input in vector
    int input_line;
    std::vector<int> data;
    while (std::cin >> input_line)
        data.push_back(input_line);

    // Selection sort
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