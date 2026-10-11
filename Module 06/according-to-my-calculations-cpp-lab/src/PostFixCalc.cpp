#include "PostFixCalc.hpp"

PostFixCalc::PostFixCalc(void) : inFixConverter{} {}

double PostFixCalc::evaluate(std::string inputExpression) 
{
    std::string expression = inFixConverter.convert(inputExpression);
    
    if (expression.size() == 0) { // empty check
        std::cerr << "Expression is too short" << std::endl;
        return -1.0; // error value
    } 

    Stack<double> values;

    for (int i = 0; i < expression.size(); i++) {
        char c = expression[i];
        if (std::isdigit(c)) {
            values.push(c - '0');
        } else if (c == '+' || c == '-' || c =='*' || c == '/' ) {
            if (values.isEmpty()) {
                return -1.0;
            }
            double right = values.pop();
            
            if (values.isEmpty()) {
                return -1.0;
            }        
            double left = values.pop();

            double result = 0.0;
            switch(c) {
                case '*': {result = left * right; break;}
                case '/': {result = left / right; break;}
                case '+': {result = left + right; break;}
                case '-': {result = left - right; break;}
            }
            values.push(result);
        }
    }

    if (values.isEmpty()) {
        return -1.0;
    }        
    return (values.pop());
} 


