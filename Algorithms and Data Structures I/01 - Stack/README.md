# Stack

Kraków 22 October 2021

---

## Task instructions

### Interface

```c++
class Stack {
    // Constructor. The argument is the size of the array.
    Stack(int capacity);
    
    // Puts an item on the stack
    void push(int x);
    
    // Removes an item from the stack and returns its value
    int pop();
    
    // Returns the number of items in the stack
    int size();
    
    // Checks if the stack is empty
    bool empty();
};
```

---

### Task 1. Stack array implementation

Write array implementation of the stack.

---

### Task 2. Stack pointer implementation

Write pointer implementation of the stack.

---

### Task 3. Stack

Write program that performs adding, taking elemnt and checking size of the stack.

---

### Task 4. Input generator

Write input generator for the `Stack.x`.

---

### Task 5. Reverse Polish notation

Write program that converts math input to RPN.

Assumption - all possible brackets are added, they replace the sequence of actions

Example:

```plain
Input:
( 11 + ( ( ( ( 1 + 2 ) * ( 4 - 3 ) ) + ( 4 / 2 ) ) * ( 8 - 6 ) ) )
Output:
11 1 2 + 4 3 - * 4 2 / + 8 6 - * +
```
