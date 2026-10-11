#ifndef QUEUESTRUCTURE_H
#define QUEUESTRUCTURE_H

#include "LinkedList.hpp"

template<typename T> class Queue  
{
    private:

    LinkedList<T> list;

    public:
    
    // Intiatlize with no items
    Queue(void);

    // Intialize with 1 item
    Queue(T firstItem);

    // push onto the queue following FIFO
    void push(T item);

    // return item at front of queue and remove it in the process
    T pop(void);

    // return the data of the front item but DO NOT remove it from the queue
    T peek(void);

    // Checks if the pointers of the list are all nullptr, T = empty, F = non empty
    bool isEmpty(void);
};

#include "Queue.tpp"

#endif
