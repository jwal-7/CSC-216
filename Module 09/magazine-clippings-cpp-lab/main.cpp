#include <iostream>
#include <fstream>
#include <sstream>

#include "src/factorial.hpp"

int main() {
  std::cout << "The factorial of 5 is " << factorial(5) << std::endl;

  std::cout << __cplusplus << std::endl;


  std::ifstream book1("../plays/romeo_and_juliet.txt");
  std::stringstream buffer1;
  buffer1 << book1.rdbuf();
  std::string book_to_construct = buffer1.str();

  std::cout << book_to_construct << std::endl;

  std::ifstream book2("../plays/othello.txt");
  std::stringstream buffer2;
  buffer2 << book2.rdbuf();
  std::string resource_book = buffer2.str();

  std::cout << resource_book << std::endl;

}
