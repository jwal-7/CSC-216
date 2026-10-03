#include "../Queue/Queue.hpp"

template<typename T>
Queue<T>::Queue(void) : list{nullptr} 
{
    list = LinkedList<T>(void);
}

template<typename T>
Queue<T>::Queue(T firstItem) : list{nullptr} 
{
    list = LinkedList<T>(T firstItem)
}

template<typename T>
void Queue<T>::push(T item)
{
    list.insertTail(T item); // queue grows from tail (whatever was inserted first stays first)
}

template<typename T>
T Queue<T>::pop(void)
{
    T returnData = list.HEAD->getValue();
    list.removeHead();
    return returnData;
}

template<typename T>
T Queue<T>::peek(void)
{
    return list.HEAD->getValue();
}