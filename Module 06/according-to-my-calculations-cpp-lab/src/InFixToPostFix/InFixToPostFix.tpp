#include "../InFixToPostFix/InFixToPostFix.hpp"

template<typename T>
InFixToPostFix() expStorage{nullptr}, operators{nullptr}, finalExpression{nullptr} 
{
    operators = new Stack<T>();
    finalExpression = new Queue<T>;
}