#include "InFixToPostFix.hpp"

InFixToPostFix::InFixToPostFix(void) : expStorage{}, operators{}, finalExpression{} {}


InFixToPostFix::InFixToPostFix(std::string prefixExpression) : expStorage{}, operators{}, finalExpression{}
{
    expStorage = prefixExpression;
}


std::string InFixToPostFix::rawConvert(std::string inputPrefixExpression, bool storeValueFlag) 
{
    if (inputPrefixExpression.empty()) { // no input expression call one in storage
        inputPrefixExpression = expStorage;
    }

    std::string returnValue;
    if (inputPrefixExpression.empty()) { // empty check
        std::cerr << "No expression stored / expression is too short" << std::endl;
        return "";
    } 

    for (int i = 0; i < inputPrefixExpression.size(); i++) {
        char c = inputPrefixExpression[i];
        
        if (std::isdigit(c)) {
            finalExpression.push(c);
        } 
        
        else if (c == '+' || c == '-' || c == '*' || c == '/' ) {
            while (!operators.isEmpty() &&
                 operators.peek() != '(' &&
                 opPrec(operators.peek()) >= opPrec(c)) {
                    finalExpression.push(operators.pop());
                }
            operators.push(c);
        }

        else if (c == '(') { // ( always gets to be pushed
            operators.push(c);
        }
        else if (c == ')') { // after seeing ) pop and push to queue 
            while (!operators.isEmpty() && operators.peek() != '(') {
                finalExpression.push(operators.pop());
            }
            if (!operators.isEmpty()) {
                operators.pop(); // one extra pop to remove the '('
            }
        }
    }  
        
    while (!operators.isEmpty()){
        char op = operators.pop();
        if (op != '(') {
            finalExpression.push(op);
        }
    }
    
    returnValue = exportExpression(finalExpression); 
    if (storeValueFlag == 1) {
        expStorage = returnValue;
    }
    return returnValue;
}


std::string InFixToPostFix::exportExpression(Queue<char>& expression) 
{
    std::string returnValue;
    while (!expression.isEmpty()) {
        //std::cout << "current symbol: " << expression.peek() << std::endl;
        returnValue += expression.pop();
    }
    return returnValue;
}


std::string InFixToPostFix::convert(void) 
{
    return rawConvert("", 0);
}


std::string InFixToPostFix::convert(std::string prefixExpression) 
{
    return rawConvert(prefixExpression, 0);
}


std::string InFixToPostFix::convertAndStore(void) 
{
    return rawConvert("", 1);
}


std::string InFixToPostFix::convertAndStore(std::string prefixExpression) 
{
    return rawConvert(prefixExpression, 1);
}
