#ifndef LEMPEL_ZIV_WELCH_DICT_HPP
#define LEMPEL_ZIV_WELCH_DICT_HPP

#include <iostream>
#include <fstream>
#include "LinkedList.hpp"

#define BUCKETS 1000

template<class K, class V>
class Dict {
    using Pair = std::pair<K, V>;
private:
    int _size = 0;
    List<Pair> *_dictionary = new List<Pair>[BUCKETS];
    Pair _helper;
    Pair _checker;

    unsigned int hash_function(const std::string &key) {
        unsigned int hash = 1;
        int magicNumber = 13;
        for (char i: key) {
            hash = hash + i;
            hash *= magicNumber;
        }
        return hash % BUCKETS;
    }

    unsigned int hash_function(const int &key) {
        std::string sKey = std::to_string(key);
        unsigned int hash = 1;
        int magicNumber = 13;
        for (char i: sKey) {
            hash = hash + i;
            hash *= magicNumber;
        }
        return hash % BUCKETS;
    }

public:
    Dict() = default;

    ~Dict() {
        delete[] _dictionary;
    }

    // Clears the dictionary
    void clear() {
        for (auto &i: _dictionary) {
            i.Clear();
        }
    }

    // Adds pair - key & value - to the dictionary
    bool insert(const Pair &p) {
        int hash = hash_function(p.first);
        if (!find(p.first)) {
            _dictionary[hash].push_front(p);
            _size++;
            return true;
        }
        for (int i = 0; i < _dictionary[hash].size(); i++) {
            if (p.first == _dictionary[hash].get(i).first) {
                _dictionary[hash].get(i).second = p.second;
                return false;
            }
        }
        return false;
    }

    // Checks if the dictionary contains the key
    bool find(const K &k) {
        int hash = hash_function(k);
        for (int i = 0; i < _dictionary[hash].size(); i++) {
            if (_dictionary[hash].get(i).first == k && _dictionary[hash].get(i).second != _checker.second) {
                return true;
            }
        }
        return false;
    }

    // Returns value for the key
    V &operator[](const K &k) {
        int hash = hash_function(k);
        for (int i = 0; i < _dictionary[hash].size(); i++) {
            if (_dictionary[hash].get(i).first == k) {
                return _dictionary[hash].get(i).second;
            }
        }
        _helper.first = k;
        _dictionary[hash].push_front(_helper);
        return _dictionary[hash].get(0).second;
    }

    // Removes pair for provided key
    bool erase(const K &k) {
        int hash = hash_function(k);
        for (int i = 0; i <= _dictionary[hash].size(); i++) {
            if (k == _dictionary[hash].get(i).first) {
                _dictionary[hash].erase(i);
                _size--;
                return true;
            }
        }
        return false;
    }

    // Returns amount of pairs
    int size() {
        return _size;
    }

    // Checks if the dictionary is empty
    bool empty() {
        return size() == 0;
    }

    // Returns information about the dictionary
    void buckets() {
        int longest_class = 0;
        for (auto &i: _dictionary)
            if (i.size() > longest_class)
                longest_class = i.size();
        int shortest_class = longest_class;
        for (auto &i: _dictionary)
            if (i.size() < shortest_class)
                shortest_class = i.size();

        std::cout << "# ";
        std::cout << size() << " ";
        std::cout << BUCKETS << " ";
        std::cout << shortest_class << " ";
        std::cout << longest_class << " ";
        std::cout << std::endl;
    }
};

#endif //LEMPEL_ZIV_WELCH_DICT_HPP
