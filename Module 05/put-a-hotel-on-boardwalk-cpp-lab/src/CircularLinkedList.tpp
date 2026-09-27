#include "CircularLinkedList.hpp"

template<typename T>
CLL<T>::CLL(void) : currentNode{nullptr}, HEAD{nullptr} {}

template<typename T>
CLL<T>::CLL(T data) : currentNode{nullptr}, HEAD{nullptr} 
{
    Node* node1 = new Node(data);
    currentNode = node1;
    HEAD = node1;
}

template<typename T>
void CLL<T>::insertHead(T data) 
{
    Node* newNode = new Node(data); // create node
    if (HEAD == nullptr) { // if list is empty
        HEAD = newNode; // node is now head
        currentNode = newNode;
        newNode->setNext(newNode); // link newNode to rest of list (itself since list is empty)
        return;
    }
    
    Node* tail = HEAD;
    while (tail->next() != HEAD) {
        tail = tail->next(); // takes note of tail (one before head)
    }
    newNode->setNext(HEAD);  // link node to rest of list (becomes new head)
    HEAD = newNode;         // node is now head
    tail->setNext(HEAD);    // link rest of list to new head
    
    
}

template<typename T>
void CLL<T>::insertTail(T data) 
{
    Node* newNode = new Node(data);  // create new node
    if (HEAD == nullptr) { // if list is empty
        HEAD = newNode; 
        currentNode = newNode;
        newNode->setNext(newNode); // link newNode to rest of list (itself since list is empty)
        return;
    }
    
    Node* tail = HEAD;
    while (tail->next() != HEAD) { // increment to find to last in list
        tail = tail->next();
    }
    newNode->setNext(HEAD); // list newNode to rest of list
    tail->setNext(newNode); // list rest of list to newNode
}

template<typename T>
void CLL<T>::append(T data) 
{
    insertTail(data);
}

template<typename T>
const T CLL<T>::getValue(void) 
{
    return currentNode->getData();
}

template<typename T>
void CLL<T>::setValue(T data) 
{
    currentNode->setData(data);
}

template<typename T>
void CLL<T>::next(void) 
{
    currentNode = currentNode->next();
}

template<typename T>
void CLL<T>::step(void) 
{
    this->next();
}

template <typename T>
void CLL<T>::diceRoll(void) 
{
    int d1 = rand() % 6;
    int d2 = rand() % 6;

    for (int i = 0; i < (d1 + d2); i++) {
        this->step();
    } 
}


