#ifndef INFIXTOPOSTFIX_CLASS
#define INFIXTOPOSTFIX_CLASS

#include "../Stack/Stack.hpp"
#include "../Queue/Queue.hpp"

template<typename T> class InFixToPostFix 
{
    private: // -----------------------------------------------------------

    T expStorage; // practically temp varaible to allow user to store an expression out of convenience (pre or postfix)
    bool isPostFix = false; 
    Stack<T> operators // only ops
    Queue<T> finalExpression // holds numbers and ops in order

    int opPrec(char op)
    { // higher number = higher precendece
        switch (op)
        {
            case '*': return 2;
            case '/': return 2;
            case '+': return 1;
            case '-': return 1;
            default: return -1; // not an operator
        }
    }

    // Meant to be the raw underlying convert logic all others are wrappers with differnt args
    T rawConvert(T inputPrefixExpression, bool storeValueFlag);

    T exportExpression(Queue<T> expression);

    public: // -----------------------------------------------------------

    // Intializes an empty converter with no expression stored and empty stack and queue
    InFixToPostFix(void);

    // Intializes a converter with an expression stored and still empty stack and queue
    InFixToPostFix(T prefixExpression);
    
    // Converts expression stored and returns it but does NOT affect current stored expression
    T convert(void);

    // Same thing as convert but with input incase expression is not stored
    T convert(T prefixExpression);

    // Same as convert() but does store the converted expression
    T convertAndStore(void);

    // Same as convert(T pE) and stores expression
    T convertAndStore(T prefixExpression);
};

#include "../InFixToPostFix/InFixToPostFix.tpp"
#endif
