#include "../InFixToPostFix/InFixToPostFix.hpp"

template<typename T>
InFixToPostFix::InFixToPostFix(void) : expStorage{nullptr}, operators{nullptr}, finalExpression{nullptr} 
{
    operators = new Stack<T>();
    finalExpression = new Queue<T>;
}

template<typename T>
InFixToPostFix::InFixToPostFix(T prefixExpression) : expStorage{nullptr}, operators{nullptr}, finalExpression{nullptr}
{
    expStorage = prefixExpression;
    operators = new Stack<T>();
    finalExpression = new Queue<T>();
}

template<typename T>
T InFixToPostFix::rawConvert(T inputPrefixExpression, storeValueFlag) 
{
    if (inputPrefixExpression = nullptr) { // no input expression call one in storage
        inputPrefixExpression = this.expStorage;
    }

    T returnValue;
    if (inputPrefixExpression.size() = 0 || inputPrefixExpression = nullptr ) { // empty check
        std::cerr << "No expression stored / expression is too short"
        retunValue = dynamic_cast<T>(-1);
    } 

    for (int i = 0; i < inputPrefixExpression.size(); i++) {
        if (inputPrefixExpression[i] = '+' ||
            inputPrefixExpression[i] = '-' ||
            inputPrefixExpression[i] = '*' ||
            inputPrefixExpression[i] = '/' ) {
            
            if (operators.peek() = nullptr)) { // empty stack check
                operators.push(inputPrefixExpression[i]);
            } else if (opPrec(inputPrefixExpression[i]) >= opPrec(operators.peek())) { // if input op has higher precedence than op in stack simply push
                operators.push(inputPrefixExpression[i]);
            } else if (opPrec(inputPrefixExpression[i])) < opPrec(operators.peek()) { // if input op has lower precedence than op in stack then pop until it no longer 
                while (opPrec(inputPrefixExpression[i])) < opPrec(operators.peek()) { 
                    finalExpression.push(operators.pop());
                }
                operators.push(inputPrefixExpression[i]);
            }
        }

        if (inputPrefixExpression[i] = '(') { // ( always gets to be pushed
            operators.push(inputPrefixExpression[i]);
        }
        if (inputPrefixExpression[i] = ')') { // after seeing ) pop and push to queue 
            while(operators.peek() != '(') {
                finalExpression.push(operators.pop());
            }
        }`

        if (std::isdigit(inputPrefixExpression[i])){
            finalExpression.push(inputPrefixExpression[i])
        }
    }

    if (storeValueFlag == 1) {
        expStorage = exportExpression(finalExpression);
    }
    returnValue = exportExpression(finalExpression);
    return returnValue;
}

T InFixToPostFix::exportExpression(Queue<T> expression) 
{
    T retunValue = dynamic_cast<T>(-1);
    while (expression.peek() != nullptr) {
        returnValue += expression.pop();
    }
    return returnValue;
}

T InFixToPostFix::convert(void) 
{
    return rawConvert(nullptr, 0);
}

T InFixToPostFix::convert(T prefixExpression) 
{
    return rawConvert(prefixExpression, 0);
}

T InFixToPostFix::convertAndStore(void) 
{
    return rawConvert(nullptr, 1);
}

T InFixToPostFix::convertAndStore(T prefixExpression) 
{
    return rawConvert(prefixExpression, 1);
}
