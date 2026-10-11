#include <iostream>

#include "src/PostFixCalc.hpp"

int main() {
  PostFixCalc calc;
  InFixToPostFix converter;
  std::cout << calc.evaluate("2+5") << std::endl;
  std::cout << converter.convert("2+5") << std::endl;
  std::cout << calc.evaluate("3+6*5") << std::endl;
  std::cout << converter.convert("3+6*5") << std::endl;
  std::cout << calc.evaluate("4*(2+3)") << std::endl;
  std::cout << converter.convert("4*(2+3)") << std::endl;
  std::cout << calc.evaluate("(7+9)/8") << std::endl;
  std::cout << converter.convert("(7+9)/8") << std::endl;
}
