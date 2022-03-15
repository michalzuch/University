#include "LinkedQueue.hpp"
#include <vector>
#include <iostream>

void radix(std::vector<int>& v);

int main(){
    std::ios_base::sync_with_stdio(false);

    int x;
    std::vector<int> v;

    while (std::cin >> x)
        v.push_back(x);

    radix(v);

    for (const auto& i : v)
        std::cout << i << std::endl;
}

void radix(std::vector<int>& v) {

    std::vector<int> tempVector;
    std::vector<int> vSorted = v;
    int digit = 1;

    while (digit != 1000000000) {
        Queue sortingTab[10];

        for (const auto& i : vSorted) {
            int temp = (i / digit) % 10;
            sortingTab[temp].push(i);
        }

        vSorted.clear();

        for (int a = 0; a < 10; a++) {
            while(sortingTab[a].size() > 0) {
                int tttemp = sortingTab[a].pop();
                tempVector.push_back(tttemp);
            }
            for (const auto& i : tempVector) {
                vSorted.push_back(i);
            }
            tempVector.clear();
        }
        digit *= 10;
    }
    v.clear();

    for (const auto& i : vSorted)
        v.push_back(i);
}