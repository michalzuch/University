# List II

Kraków 26 November 2021

---

## Task instructions

### Interface

```cpp
class List {
    // Appends an item to the beginning of the list
    void push_front(int x);

    // Removes and returns an item from the top of the list
    int pop_front();

    // Appends an item to the end of the list
    void push_back(int x);

    // Removes and returns an item from the end of the list
    int pop_back();

    // Returns the number of items in a list
    int size();

    // Returns true if the list is empty
    bool empty();

    // Clears the list
    void clear();

    // Returns the position of the first element with value x
    int find(int x);

    // Deletes and returns the element at position i
    int erase(int i);

    // Inserts x before i
    void insert(int i, int x);

    // Removes the occurrences of x and returns their number
    int remove(int x);
}
```

### Task 1. Array implementation

Write array implementation of the stack.

---

### Task 2. Cursor implementation

Write cursor implementation of the stack.
