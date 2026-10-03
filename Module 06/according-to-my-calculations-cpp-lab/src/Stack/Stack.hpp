#ifndef STACKSTRUCTURE_H
#define STATCKSTRUCTURE_H

#include "../LinkedList/LinkedList.hpp"
#include "../LinkedList/LinkedList.tpp"

template<typename T> class Stack 
{
    LinkedList<T> list;

    // Intiatlize with no items
    Stack Stack(void);

    // Intialize with 1 item
    Stack Stack(T firstItem);

    // push onto the stack following FILO / LIFO
    void push(T item);

    // return item at top of stack and remove it in the process
    T pop(void);

    // return the data of the item but DO NOT remove it from the stack
    T peek(void);
};

#include "../Stack/Stack.tpp"

#endif
