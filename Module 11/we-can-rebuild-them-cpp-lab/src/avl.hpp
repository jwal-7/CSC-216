#include <vector>
#include <iostream>
#include <algorithm>

// using class from module 8 lab as base

#ifndef AVL_CLASS_LIBRARY
#define AVL_CLASS_LIBRARY

class AVL {
    
    private:
    
    std::vector<int> data;
    int size{0};
    size_t tail{0};

    // calcualtes balance facto
    int bf(size_t node) 
    {
        int left_node_height = (static_cast<int>(left(node) == -1) ? -1 : static_cast<int>(height(left(node))));
        int right_node_height = (static_cast<int>(right(node) == -1) ? -1 : static_cast<int>(height(right(node))));
        return right_node_height - left_node_height;
    }

    void rebalance_tree()
    {

    }

    void fill_tree_nulls(size_t node) {
        if (static_cast<int>(node) > size) {
            int count = node - size;
            for (int i = 0; i < count; i++) {
                data.push_back(INT32_MIN);
            }
        }
    }

    public:

    AVL(void) : data(), size(), tail()  {}

    int get_size() const { return size; }

    bool is_empty() const { return size == 0; }

    void insert(size_t node, int elem) {
        if (!has_child(node)) { // base case: leaf
            fill_tree_nulls(node); // FILLS TREE WITH NULLS BUT FUNCTION DNW NEED TO LOOK AT
            data[node] = elem;
            size++;
            tail = data.size() - 1;
        }
        else {
            if (value_at(node) < elem) {
                insert(left(node), elem);
            } else {
                insert(right(node), elem);
            }
        }
    }

    int height(size_t parent) 
    {
        if (!has_child(parent)) {
            return -1;
        }
        return 1 + std::max(static_cast<int>(height(left(parent))), static_cast<int>(height(right(parent))));
    }

    void swap(size_t i, size_t j) // swapping second onto first position and vice versa
    {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp; 
    }

    size_t left(size_t parent) // read as left of parent 
    {
        return (2 * parent) + 1;
    }

    bool has_left(size_t parent) 
    {
        return (static_cast<int>(left(parent)) < size); 
    }

    size_t right(size_t parent) // read as right of parent 
    {
        return (2 * parent) + 2;
    }

    size_t has_right(size_t parent) 
    {
        return (static_cast<int>(right(parent)) < size);
    }

    size_t parent(size_t child) 
    {
        return (child - 1) / 2;
    }

    bool has_child(size_t parent) 
    {
        return has_left(parent) || has_right(parent);
    }

    void add_to_end(int input) 
    {
        data.push_back(input);
        size++;
        tail = data.size() - 1;
    }
    
    int end_value() 
    {
        return data.back();
    }

    size_t end() 
    {
        return tail;
    }

    int root_value() 
    {
        return data.front();
    }

    size_t root() 
    {
        return 0; // root is always going to be the 0th index of the array
    }

    int value_at(size_t i) 
    {
        return data[i];
    }

    void remove(size_t i) 
    {
        swap(i, end());
        data.pop_back();
        size--;
        tail = data.size() - 1;
    }

    void remove()
    {
        remove(root());
    }

};

#endif
