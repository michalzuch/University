#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

class BinaryNode {
public:
    int value;
    BinaryNode* left;
    BinaryNode* right;
};

class BinaryTree {
private:
    BinaryNode* _root = nullptr;
    BinaryNode* _helper = nullptr;
    int _size = 0;
    int _depth = 0;

public:
    // Adds element to the tree
    void insert(int x) {
        BinaryNode* temp = new BinaryNode();
        temp->value = x;
        if (size() == 0) {
            _root = temp;
            _depth = 1;
        } else {
            int temp_depth = 1;
            BinaryNode* iterate;
            iterate = _root;
            
            while (true) {
                if (x >= iterate->value) {
                    if (iterate->right != nullptr) {
                        iterate = iterate->right;
                        temp_depth++;
                    } else {
                        iterate->right = temp;
                        temp_depth++;
                        break;
                    }
                } else {
                    if (iterate->left != nullptr) {
                        iterate = iterate->left;
                        temp_depth++;
                    } else {
                        iterate->left = temp;
                        temp_depth++;
                        break;
                    }
                }
            }
            if (temp_depth > _depth) _depth = temp_depth;
        }
        _size++;
    }

    // Checks if element belongs to the tree, returns pointer to node or nullptr

    // Iterative
    BinaryNode* search(int x) {
        BinaryNode* temp;
        temp = _root;

        while (temp->value != x) {
            if (x > temp->value) {
                temp = temp->right;
                if (temp == nullptr)
                    return nullptr;
            } else {
                temp = temp->left;
                if (temp == nullptr)
                    return nullptr;
            }
        }
        return temp;
    }

    // Recursive
    BinaryNode* searchRecursive(int x) {
        if (_helper == nullptr)
            _helper = _root;

        if (_helper == nullptr)
            return nullptr;

        if (_helper->value == x) {
            BinaryNode* temp = _helper;
            _helper = nullptr;
            return temp;
        }

        if (x > _helper->value) {
            _helper = _helper->right;
            if (_helper != nullptr)
                searchRecursive(x);
            else
                return nullptr;
        } else {
            _helper = _helper->left;
            if (_helper != nullptr)
                searchRecursive(x);
            else
                return nullptr;
        }
        _helper = nullptr;
        return nullptr;
    }

    // Returns amount of nodes
    int size() {
        return _size;
    }

    // Returns value of the smallest element
    int minimum() {
        BinaryNode* temp;
        temp = _root;

        while (temp->left != nullptr)
            temp = temp->left;
        
        return temp->value;
    }

    // Returns value of the biggest element
    int maximum() {
        BinaryNode* temp;
        temp = _root;

        while (temp->right != nullptr)
            temp = temp->right;
        
        return temp->value;
    }

    // Returns height of the tree
    int depth() {
        return _depth;
    }

    // Prints values of all nodes in [function name] order

    // Left Root Right
    void inorder() {
        if (_helper == nullptr)
            _helper = _root;
        BinaryNode* temp = _helper;

        if (temp->left != nullptr) {
            _helper = temp->left;
            inorder();
        }

        std::cout << temp->value << std::endl;

        if (temp->right != nullptr) {
            _helper = temp->right;
            inorder();
        }
    }

    // Root Left Right
    void preorder() {
        if (_helper == nullptr)
            _helper = _root;
        BinaryNode* temp = _helper;

        std::cout << temp->value << std::endl;

        if (temp->left != nullptr) {
            _helper = temp->left;
            preorder();
        }

        if (temp->right != nullptr) {
            _helper = temp->right;
            preorder();
        }
    }

    // Left Right Root
    void postorder() {
        if (_helper == nullptr)
            _helper = _root;
        BinaryNode* temp = _helper;

        if (temp->left != nullptr) {
            _helper = temp->left;
            postorder();
        }

        if (temp->right != nullptr) {
            _helper = temp->right;
            postorder();
        }

        std::cout << temp->value << std::endl;
    }
};

#endif //BINARYTREE_HPP