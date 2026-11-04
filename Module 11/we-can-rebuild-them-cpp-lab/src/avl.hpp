#include <vector>
#include <iostream>
#include <algorithm>

// using class from module 8 lab as base

#ifndef AVL_CLASS_LIBRARY
#define AVL_CLASS_LIBRARY

template<typename T> class AVL {
    
    private:
    
    std::vector<T> data;
    int size{0};
    size_t tail{0};

    // calcualtes balance facto
    int bf(size_t node) 
    {
        int left_node_height = (static_cast<int>(node.left()) == nullptr) ? -1 : static_cast<int>(node.left()).height();
        int right_node_height = (static_cast<int>(node.right()) == nullptr) ? -1 : static_cast<int>(node.right()).height();
        return right_node_height - left_node_height;
    }

    void rebalance_tree()
    {

    }

    public:

    AVL(void) : data(), size(), tail()  {}

    int get_size() const { return size; }

    bool is_empty() const { return size == 0; }

    int height(size_t parent) const 
    {
        if (parent == null) {
            return -1;
        }
        return 1 + std::max(height(parent.left(), parent.right()));
    }

    void swap(size_t i, size_t j) // swapping second onto first position and vice versa
    {
        T temp = data[i];
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

    void add_to_end(T input) 
    {
        data.push_back(input);
        size++;
        tail = data.size() - 1;
    }
    
    T end_value() 
    {
        return data.back();
    }

    size_t end() 
    {
        return tail;
    }

    T root_value() 
    {
        return data.front();
    }

    size_t root() 
    {
        return 0; // root is always going to be the 0th index of the array
    }

    T value_at(size_t i) 
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
