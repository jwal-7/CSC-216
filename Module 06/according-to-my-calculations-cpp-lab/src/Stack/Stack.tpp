#include "../Stack/Stack.hpp"

template<typename T>
Stack<T>::Stack(void) : list{nullptr} 
{
    list = LinkedList<T>(void);
}

template<typename T>
Stack<T>::Stack(T firstItem) : list{nullptr} 
{
    list = LinkedList<T>(T firstItem);
}

template<typename T>
void Stack<T>::push(T item) 
{
    list.insertHead(T item); // stack grows from the head 
}

template<typename T>
T Stack<T>::pop(void) 
{
    T returnData = list.HEAD->getValue(); // get data to return
    list.removeHead(); // remove item from stack
    return returnData; // return data that's to be used
}

template<typename T>
T Stack<T>::peek(void)
{
    return list.HEAD->getValue();
}
