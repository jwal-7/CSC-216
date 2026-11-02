#include <iostream>
#include "src/file_indexer.hpp"
#include "src/file_writer.hpp"
#include "src/file_parser.hpp"

int main() {
  FileParser parser;
  FileIndexer indexer;
  FileWriter writer;

  std::string s = parser.convertFileToString("../texts/test_file.txt");
  std::vector<std::string> v = parser.splitUpString(s);

  std::cout << v.size() << std::endl;

  std::string s2 = parser.convertFileToString("../texts/test_file2.txt");
  std::vector<std::string> v2 = parser.splitUpString(s2);

  std::cout << v2.size() << std::endl;

  std::string s3 = parser.convertFileToString("../texts/tortoise_and_hare.txt");
  std::vector<std::string> v3 = parser.splitUpString(s3);

  std::cout << v3.size() << std::endl;

  std::string s4 = parser.convertFileToString("../texts/moby_dick.txt");
  std::vector<std::string> v4 = parser.splitUpString(s4);

  std::cout << v4.size() << std::endl;

  std::string s5 = parser.convertFileToString("../texts/war_and_peace.txt");
  std::vector<std::string> v5 = parser.splitUpString(s5);

  std::cout << v5.size() << std::endl;

  std::string s6 = parser.convertFileToString("../texts/words.txt");
  std::vector<std::string> v6 = parser.splitUpString(s6);

  std::cout << v6.size() << std::endl;

  std::string s7 = parser.convertFileToString("../texts/1000_words.txt");
  std::vector<std::string> v7 = parser.splitUpString(s7);

  std::cout << v7.size() << std::endl;

}
