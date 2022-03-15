template<class T>
class List {

public:
    struct Node {
        Node *next;
        T data;
        Node *prev;
    };

    struct iterator {
        Node *ptr;

        int operator*() {
            return ptr->data;
        }

        iterator &operator++() {
            ptr = ptr->next;
            return *this;
        }

        iterator &operator--() {
            ptr = ptr->next;
            return *this;
        }
    };

    Node *guard;
    int _size;

    List() {
        _size = 0;
        guard = new Node();
        guard->prev = guard;
        guard->next = guard;
    }

    void push_front(T x) {
        // Create new node
        Node* temp = new Node();
        // Add value
        temp->data = x;
        // Change linking
        temp->next = guard->prev;
        temp->prev = guard->next;
        temp->next->prev = temp;
        temp->prev->next = temp;
        guard->prev = temp;
        // Increment size
        _size++;
    }

    int size() {
        return _size;
    }

    T erase(int i) {
        iterator it{};
        it.ptr = guard->prev;
        // Go to element at index i
        for (int j = 0; j < i; j++)
            ++it;
        Node *temp = new Node();
        temp = it.ptr;
        // Change linking
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        // Decrement size
        _size--;
        return *it;
    }

    T &get(int i) {
        iterator it{};
        it.ptr = guard->prev;
        // Go to element at index i
        for (int j = 0; j < i; j++)
            ++it;
        return it.ptr->data;
    }
};