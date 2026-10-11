#ifndef STACKSTRUCTURE_H
#define STATCKSTRUCTURE_H

#include "LinkedList.hpp"

template<typename T> class Stack 
{
    private:

    LinkedList<T> list;

    public:
    
    // Intiatlize with no items
    Stack(void);

    // Intialize with 1 item
    Stack(T firstItem);

    // push onto the stack following FILO / LIFO
    void push(T item);

    // return item at top of stack and remove it in the process
    T pop(void);

    // return the data of the item but DO NOT remove it from the stack
    T peek(void);

    // Checks if the pointers of the list are all nullptr, T = empty, F = non empty
    bool isEmpty(void);
};

#include "Stack.tpp"

#endif
