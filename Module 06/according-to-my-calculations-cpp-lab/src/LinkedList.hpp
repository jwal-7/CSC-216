#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<typename T> class LinkedList 
{
    private:
    class Node 
    {
        private:
        T data;
        Node* nextNode;

        public: 
        // Intializer with no data within it
        Node(void) : data(), nextNode() {
            nextNode = this;
        } 

        // Intializer with data declaration
        Node(T startingData) : data(startingData), nextNode() {
            nextNode = this;
        }

        // destructor
        ~Node(void) 
        {
            delete [] nextNode;
            // nextNode == nullptr;
            data = dynamic_cast<T>(0);
        }

        // Returns pointer to next node
        Node* next(void) {
            return nextNode;
        }

        // Setter for data present within node
        void setData(T inputData) {
            this->data = inputData;
        }

        // Setter for next node
        void setNext(Node* inputNode) {
            this->nextNode = inputNode;
        }

        // Getter for data within node
        const T getData(void) {
            return this->data;
        }
    };

    Node* currentNode;
    Node* HEAD;
    Node* TAIL;

    public:

    // Intializes object with no data (have it make a pointer to null) -- in a one item list the one node is both head and tail
    LinkedList(void);

    // Intializes object with a node placed -- in a one item list the one node is both head and tail
    LinkedList(T data);
    // if CLL.head currently points to null reassign and make head
    // if CLL.head is NOT NULL then make next of insertion node equal head
    // and then reassign next of CURRENT head to point to the insertion node 

    // destructor
    ~LinkedList(void);
    
    // Inserts new node at head of list
    void insertHead(T data);

    // Inserts new node at tail of list
    void insertTail(T data);

    // Append node to end of list (insertTail() wrapper)
    void append(T data);

    // Removes the node at the head 
    void removeHead(void);

    // Gets value at current node
    const T getValue(void);

    // Sets value at current node
    void setValue(T data);

    // Increments the current node to the next node in the list
    void next(void);

    // Steps through the list by one node (next() wrapper)
    void step(void);

    // Simulates two six-sided dice rolling and then steps for whatever combined result is
    void diceRoll(void);
};

#include "LinkedList.tpp"

#endif
