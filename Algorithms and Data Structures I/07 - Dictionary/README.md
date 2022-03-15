# Dictionary

Kraków 21 January 2022

## Task instructions

### Interface

```cpp
template<classK,classV>classDict {
   
   // Constructor
   usingPair = std::pair<K, V>;Dict();

   // Clears the dictionary
   clear();

   // Adds a key-value pair to the dictionary
   bool insert(const Pair& p);

   // Checks whether the dictionary contains a key
   bool find(const K& k);

   // Returns a value for a key
   V&operator[](const K& k);

   // Deletes a pair from a given key
   bool erase(const K& k);

   // Returns the number of pairs
   int size();

   // Checks if the dictionary is empty
   bool empty();

   // Prints information about the dictionary
   void buckets();
}
```

### Task 1. Dictionary

Implement a Dictionary using hash table and your own implementation of list.

---

### Task 2. Words

Create 20 pairs of words starting with the same letter as your name. Pair should be Polish world and it's English translation.
