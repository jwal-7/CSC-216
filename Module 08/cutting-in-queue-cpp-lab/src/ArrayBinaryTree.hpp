#include <vector>
#include <iostream>

#ifndef ARRAYBINARYTREE_LIBRARY
#define ARRAYBINARYTREE_LIBRARY

template<typename T> class ArrayBinaryTree {
    
    private:
    
    std::vector<T> data;
    int size{0};
    size_t tail{0};

    public:

    ArrayBinaryTree(void) : data(), size(), tail()  {}

    int get_size() const { return size; }

    bool is_empty() const { return size == 0; }

    void swap(size_t i, size_t j) // swapping second onto first position and vice versa
    {
        T temp;
        temp = data[i];
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

    void remove() 
    {
        swap(root(), end());
        data.pop_back();
        size--;
        tail = data.size() - 1;
    }
};

#endif
