
template<typename T>
Stack<T>::Stack(void) : list{} {}

template<typename T>
Stack<T>::Stack(T firstItem) : list{} 
{
    list.insertHead(firstItem);
}

template<typename T>
void Stack<T>::push(T item) 
{
    list.insertHead(item); // stack grows from the head 
}

template<typename T>
T Stack<T>::pop(void) 
{
    T returnData = list.getHEAD()->getData(); // get data to return
    list.removeHead(); // remove item from stack
    return returnData; // return data that's to be used
}

template<typename T>
T Stack<T>::peek(void)
{
    return list.getHEAD()->getData();
}

template<typename T>
bool Stack<T>::isEmpty(void) 
{
    if (list.getCurrent() == nullptr &&
       list.getHEAD()     == nullptr &&
       list.getTAIL()     == nullptr ) {
            return true;
       } // implied else
    return false;
}
