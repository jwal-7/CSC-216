
template<typename T>
Queue<T>::Queue(void) : list{} {}

template<typename T>
Queue<T>::Queue(T firstItem) : list{} 
{
    list.insertTail(firstItem);
}

template<typename T>
void Queue<T>::push(T item)
{
    list.insertTail(item); // queue grows from tail (whatever was inserted first stays first)
}

template<typename T>
T Queue<T>::pop(void)
{
    T returnData = list.getHEAD()->getData();
    list.removeHead();
    return returnData;
}

template<typename T>
T Queue<T>::peek(void)
{
    return list.getHEAD()->getData();
}

template<typename T>
bool Queue<T>::isEmpty(void) 
{
    if (list.getCurrent() == nullptr &&
       list.getHEAD()     == nullptr &&
       list.getTAIL()       == nullptr ) {
            return true;
       } // implied else
    return false;
}
