#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/file_indexer.hpp"
#include "../src/file_parser.hpp"
#include <vector>
#include <sstream>

TEST_CASE( "basic indexing test with file 1" ) {
   FileParser parser;
   FileIndexer indexer;

   std::string s = parser.convertFileToString("../texts/test_file.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   indexer.makeIndex(v);

   std::ostringstream out;

   out << indexer;

   REQUIRE(out.str() == "{\n"
    "    \"string\": [5]\n"
    "    \"test-file\": [3]\n"
    "}\n"
    );
}

TEST_CASE("basic indexing test with file 2") {
   FileParser parser;
   FileIndexer indexer;

   std::string s = parser.convertFileToString("../texts/test_file2.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   indexer.makeIndex(v);

   std::ostringstream out;

   out << indexer;

   REQUIRE(out.str() == "{\n"
   "    \"anywhere\": [18]\n"
   "    \"asked\": [20]\n"
   "    \"being\": [11]\n"
   "    \"day\": [9]\n"
   "    \"ever\": [16]\n"
   "    \"fun\": [4]\n"
   "    \"get\": [17]\n"
   "    \"hare\": [1]\n"
   "    \"laugh\": [24]\n"
   "    \"making\": [3]\n"
   "    \"mocking\": [23]\n"
   "    \"one\": [8]\n"
   "    \"slow\": [13]\n"
   "    \"so\": [12]\n"
   "    \"tortoise\": [7]\n"
   "    \"was\": [2]\n"
   "}\n");
}

TEST_CASE("expanding the test_file2 into its final form") {
   FileParser parser;
   FileIndexer indexer;

   std::string s = parser.convertFileToString("../texts/tortoise_and_hare.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   
   BENCHMARK("tortoise and hare indexing") {
      return indexer.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;
}

TEST_CASE("the real test...") {
   FileParser parser;
   FileIndexer indexer;

   std::string s = parser.convertFileToString("../texts/moby_dick.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   
   BENCHMARK("moby dick indexing") {
      return indexer.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;
}

TEST_CASE("the real test 2...") {
   FileParser parser;
   FileIndexer indexer;

   std::string s = parser.convertFileToString("../texts/war_and_peace.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   
   BENCHMARK("war and peace indexing") {
      return indexer.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;
}

TEST_CASE("the real test 3...") {
   FileParser parser;
   FileIndexer indexer;

   std::string s = parser.convertFileToString("../texts/words.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   
   BENCHMARK("all words indexing") {
      return indexer.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;
}
    