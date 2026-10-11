
template<typename T>
LinkedList<T>::LinkedList(void) : currentNode{nullptr}, HEAD{nullptr}, TAIL{nullptr} {}

template<typename T>
LinkedList<T>::LinkedList(T data) : currentNode{nullptr}, HEAD{nullptr}, TAIL{nullptr} 
{
    Node* node1 = new Node(data);
    currentNode = node1;
    HEAD = node1;
    TAIL = node1;
    TAIL->setNext(nullptr);
}

template<typename T>
LinkedList<T>::~LinkedList(void) 
{
    while (HEAD != nullptr) {
        removeHead();
    }
}

template<typename T>
void LinkedList<T>::insertHead(T data) 
{
    Node* newNode = new Node(data); // create node
    if (HEAD == nullptr) { // if list is empty
        HEAD = newNode; // node is now head
        currentNode = newNode;
        TAIL = newNode;
        TAIL->setNext(nullptr); // link tail to nullptr since end of list
        // newNode->setNext(newNode); // link newNode to rest of list (newNode since list is empty)
        return;
    }
    /*
    Node* tail = HEAD;
    while (tail->next() != HEAD) {
        tail = tail->next(); // takes note of tail (one before head)
    } */
    newNode->setNext(HEAD);  // link node to rest of list (
    HEAD = newNode;         // node is now head
    // tail->setNext(HEAD);    // link rest of list to new head -- no longer needed becuase tail is going to stay nullptr
    
    
}

template<typename T>
void LinkedList<T>::insertTail(T data) 
{
    Node* newNode = new Node(data);  // create new node
    if (HEAD == nullptr) { // if list is empty
        HEAD = newNode; // node is now head
        currentNode = newNode;
        TAIL = newNode;
        TAIL->setNext(nullptr); // link tail to nullptr since end of list
        // newNode->setNext(newNode); // link newNode to rest of list (newNode since list is empty)
        return;
    }
    /*
    Node* oneBefore = HEAD;
    while (oneBefore->next() != TAIL) { // increment to find one beforelast in list
        oneBefore = oneBefore->next();
    } 
    newNode->setNext(HEAD); // list newNode to rest of list
    tail->setNext(newNode); // list rest of list to newNode
    */
    newNode->setNext(nullptr); // set newNode to nullptr since end of list
    TAIL->setNext(newNode); // connect rest of list to newNode (new Tail)
    TAIL = newNode; // newNode is now new TAIL    
}

template<typename T>
void LinkedList<T>::append(T data) 
{
    insertTail(data);
}

template<typename T>
void LinkedList<T>::removeHead(void) 
{
    if (HEAD == nullptr) return;

    Node* toBeDeleted = HEAD; // mark for deleted
    HEAD = HEAD->next();  // unlink current head from list via incrementing
    delete toBeDeleted; // delete previous HEAD to make sure there's no memory leak
    if (HEAD == nullptr) {
        TAIL = nullptr;
        currentNode = nullptr;
    }
}

template<typename T>
LinkedList<T>::Node* LinkedList<T>::getHEAD(void) 
{
    return HEAD;
}

template<typename T>
LinkedList<T>::Node* LinkedList<T>::getTAIL(void) 
{
    return TAIL;
}

template<typename T>
LinkedList<T>::Node* LinkedList<T>::getCurrent(void) 
{
    return currentNode;
}


template<typename T>
const T LinkedList<T>::getValue(void) 
{
    return currentNode->getData();
}

template<typename T>
void LinkedList<T>::setValue(T data) 
{
    currentNode->setData(data);
}

template<typename T>
void LinkedList<T>::next(void) 
{
    currentNode = currentNode->next();
}

template<typename T>
void LinkedList<T>::step(void) 
{
    this->next();
}

template <typename T>
void LinkedList<T>::diceRoll(void) 
{
    int d1 = rand() % 6;
    int d2 = rand() % 6;

    for (int i = 0; i < (d1 + d2); i++) {
        this->step();
    } 
}


