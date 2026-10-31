#include <iostream>


#include "src/file_index_map.hpp"

int main() {
  FileIndexMap map; 

  map.insert("test", 0);
  map.insert("test", 4);
  map.insert("test", 123);

  std::cout << map;
    
}
