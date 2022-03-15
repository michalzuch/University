class List {
private:
    // Max size
    const int _capacity = 10000;

    // Nested node class
    struct Node {
        int x;          // Data stored in node
        int next;       // Pointer to next node
    };

    Node _data[10000];  // Array of nodes
    int _head;          // Index of the first node
    int _tail;          // Index of the last node
    int _size;          // Size of the list
    int _spare;         // Index of the first unused array element
    
public:

    // Constructor, that creates empty list
    List();

    // Adds element in front of the list
    void push_front(int x);

    // Removes and returns element from the begining of the list
    int pop_front();

    // Adds element in the back of the list
    void push_back(int x);

    // Removes and returns element from the back of the list
    int pop_back();

    // Returns amount of elemnt in list
    int size();

    // Returns true if list is empty
    bool empty();

    // Clears the list
    void clear();

    // Returns position of first elemnt of value x
    int find(int x);

    // Removes and returns element on position i
    int erase(int i);

    // Inserts element x before position i
    void insert(int i, int x);

    // Removes all x occurences and returns its amount
    int remove(int x);

    // Replace value for x at index i
    void replace(int i, int x);

    // Allocate memory for new node
    int allocate();
};