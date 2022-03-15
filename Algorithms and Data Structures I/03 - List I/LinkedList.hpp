class List {
private:
    struct Node {
        Node* next;
        int data;
        Node* prev;
    };

    struct iterator {
        Node *ptr;
        int operator*() {
            return ptr->data;
        }

        iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }
        
        iterator& operator--() {
            ptr = ptr->next;
            return *this;
        }
    };

    Node* guard = new Node();
    
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
};