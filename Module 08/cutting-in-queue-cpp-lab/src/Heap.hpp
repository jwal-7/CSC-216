#include <iostream>
#include "ArrayBinaryTree.hpp"

#ifndef ARRAYBASEDHEAP_LIBRARY 
#define ARRAYBASEDHEAP_LIBRARY

template<typename T> class Heap 
{
    private:

    ArrayBinaryTree<T> t = ArrayBinaryTree<T>();

    public:

    void bubble_up(size_t i) // SWAPS UP FOR A MAX HEAP
    {
      while (i > 0) {
        size_t p = t.parent(i);
        if (t.value_at(i) > t.value_at(p)) {
            t.swap(i, p);
            i = p;
        } else {
            break;
        }
      }   
    }

    void bubble_down(size_t i) // SWAPS DOWN FOR A MAX HEAP
    {
        while (t.has_left(i)) {
            size_t big_child = t.left(i);
            if (t.has_right(i)) {
                if (t.value_at(t.right(i)) > t.value_at(t.left(i))) {
                    big_child = t.right(i);
                }
            }

            if (t.value_at(big_child) > t.value_at(i)) {
                t.swap(i, big_child);
                i = big_child;
            } else {
                break;
            }
        }
    }


    Heap(void) {}

    void insert(T input) 
    {
        t.add_to_end(input);
        bubble_up(t.end());
    }

    void push(T input) 
    {
        insert(input);
    }

    void remove(size_t i) 
    {
        if (t.is_empty()) {
            return;
        }

        t.remove(i);
        if (!t.is_empty()) {
            bubble_down(i);
        }
    }

    void pop() 
    {
        return remove(t.root());
    }

    T extract() 
    {
        T value = peek();
        pop();
        return value;
    }

    T peek() 
    {
        return t.root_value();
    }

    int size() 
    {
        return t.get_size();
    }

    bool empty() 
    {
        return t.is_empty();
    }
};

#endif
