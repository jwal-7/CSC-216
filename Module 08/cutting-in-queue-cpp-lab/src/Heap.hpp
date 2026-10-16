#include <iostream>
#include "ArrayBinaryTree.hpp"

#ifndef ARRAYBASEDHEAP_LIBRARY 
#define ARRAYBASEDHEAP_LIBRARY

template<typename T> class Heap 
{
    private:

    ArrayBinaryTree<T> t = ArrayBinaryTree<T>();

    public:

    void bubble_up(size_t i) // SWAPS UP FOR A MIN HEAP
    {
      while (i > 0) {
        size_t p = t.parent(i);
        if (t.value_at(i) < t.value_at(p)) {
            t.swap(i, p);
            i = p;
        } else {
            break;
        }
      }   
    }

    void bubble_down(size_t i) // SWAPS DONW FOR A MIN HEAP
    {
        
    }


    Heap(void) {}

    void insert(T input) 
    {
        t.add_to_end(input);
    }

    void push(T input) 
    {
        insert(input);
    }

    void remove() 
    {
        t.remove();
    }

    void pop() 
    {
        remove();
    }

    T peek() 
    {
        return t.root_value();
    }
};

#endif
