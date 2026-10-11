#ifndef POSTFIXCALC_CLASS
#define POSTFIXCALC_CLASS

#include "InFixToPostFix.hpp"

class PostFixCalc 
{
    private:
    InFixToPostFix inFixConverter;

    public:

    // Initializes calculator object
    PostFixCalc(void);

    // Evaluate/solve prefix expression that inputed
    double evaluate(std::string inputExpression);
};

#endif
