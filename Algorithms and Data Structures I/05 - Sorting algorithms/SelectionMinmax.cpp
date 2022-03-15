#include <iostream>
#include <vector>
#include <algorithm>

template <class T> void sort(std::vector<T>& input_vector) {
    int size = input_vector.size();

    for (int i = 0; i < size / 2; i++) {

        // Find minimum / maximum value and its index
        T min = *min_element(input_vector.begin() + i, input_vector.end());
        T max = *max_element(input_vector.begin(), input_vector.end() - i);
        
        int j = i;
        int k = size - 1 - i;

        while (input_vector.at(j) != min)
            j++;
        while (input_vector.at(k) != max)
            k--;

        std::swap(input_vector.at(i), input_vector.at(j));
        std::swap(input_vector.at(size - 1 - i), input_vector.at(k));
    }
}

int main(void) {
    // Store input in vector
    int input_line;
    std::vector<int> data;
    while (std::cin >> input_line)
        data.push_back(input_line);

    // Selection sort - min max
    sort(data);

    // Print the output
    for (const auto& i : data)
        std::cout << i << std::endl;

    return 0;
}