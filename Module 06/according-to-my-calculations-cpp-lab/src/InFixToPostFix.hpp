#ifndef INFIXTOPOSTFIX_CLASS
#define INFIXTOPOSTFIX_CLASS

#include "Stack.hpp"
#include "Queue.hpp"

class InFixToPostFix 
{
    private: // -----------------------------------------------------------

    std::string expStorage; // practically temp varaible to allow user to store an expression out of convenience (pre or postfix)
    bool isPostFix = false; 
    Stack<char> operators; // only ops
    Queue<char> finalExpression; // holds numbers and ops in order

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
    std::string rawConvert(std::string inputPrefixExpression, bool storeValueFlag);

    // Exports the postfix expression to match the original data type to be a portable value
    std::string exportExpression(Queue<char>& expression);

    public: // -----------------------------------------------------------

    // Intializes an empty converter with no expression stored and empty stack and queue
    InFixToPostFix(void);

    // Intializes a converter with an expression stored and still empty stack and queue
    InFixToPostFix(std::string prefixExpression);
    
    // Converts expression stored and returns it but does NOT affect current stored expression
    std::string convert(void);

    // Same thing as convert but with input without expression being stored
    std::string convert(std::string prefixExpression);

    // Same as convert() but does store the converted expression
    std::string convertAndStore(void);

    // Same as convert(T pE) and stores expression
    std::string convertAndStore(std::string prefixExpression);
};

#endif
