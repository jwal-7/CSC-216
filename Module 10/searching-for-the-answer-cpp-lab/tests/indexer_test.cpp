#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/file_indexer.hpp"
#include "../src/file_parser.hpp"
#include "../src/file_writer.hpp"
#include <vector>
#include <sstream>

TEST_CASE( "basic indexing test with file 1" ) {
   FileParser parser;
   FileIndexer indexer;
   FileWriter writer;

   std::string s = parser.convertFileToString("../texts/test_file.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   indexer.makeIndex(v);

   BENCHMARK("short test file indexing") {
      FileIndexer temp;
      return temp.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;

   writer.outputToFile(indexer, "test1.txt");
   std::string s2 = parser.convertFileToString("test1.txt");

   REQUIRE(out.str() == "{\n"
    "    \"string\": [5]\n"
    "    \"test-file\": [3]\n"
    "}\n"
    );

   REQUIRE(out.str() == s2);
}

TEST_CASE("basic indexing test with file 2") {
   FileParser parser;
   FileIndexer indexer;
   FileWriter writer;

   std::string s = parser.convertFileToString("../texts/test_file2.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   indexer.makeIndex(v);

   BENCHMARK("test file indexing") {
      FileIndexer temp;
      return temp.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;

   writer.outputToFile(indexer, "test2.txt");
   std::string s2 = parser.convertFileToString("test2.txt");

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

   REQUIRE(out.str() == s2);
}

TEST_CASE("expanding the test_file2 into its final form") {
   FileParser parser;
   FileIndexer indexer;
   FileWriter writer;

   std::string s = parser.convertFileToString("../texts/tortoise_and_hare.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   indexer.makeIndex(v);

   BENCHMARK("tortoise and hare indexing") {
      FileIndexer temp;
      return temp.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;

   writer.outputToFile(indexer, "test3.txt");
   std::string s2 = parser.convertFileToString("test3.txt");
   REQUIRE(out.str() == s2);
}

TEST_CASE("the real test...") {
   FileParser parser;
   FileIndexer indexer;
   FileWriter writer;

   std::string s = parser.convertFileToString("../texts/moby_dick.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   indexer.makeIndex(v);
   
   BENCHMARK("moby dick indexing") {
      FileIndexer temp;
      return temp.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;

   writer.outputToFile(indexer, "test4.txt");
   std::string s2 = parser.convertFileToString("test4.txt");
   REQUIRE(out.str() == s2);
}

TEST_CASE("the real test 2...") {
   FileParser parser;
   FileIndexer indexer;
   FileWriter writer;

   std::string s = parser.convertFileToString("../texts/war_and_peace.txt");
   std::vector<std::string> v = parser.splitUpString(s);
   
   indexer.makeIndex(v);

   BENCHMARK("war and peace indexing") {
      FileIndexer temp;
      return temp.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;

   writer.outputToFile(indexer, "test5.txt");
   std::string s2 = parser.convertFileToString("test5.txt");
   REQUIRE(out.str() == s2);
}
/*
TEST_CASE("the real test 3...") {
   FileParser parser;
   FileIndexer indexer;
   FileWriter writer;

   std::string s = parser.convertFileToString("../texts/words.txt");
   std::vector<std::string> v = parser.splitUpString(s);

   indexer.makeIndex(v);

   BENCHMARK("all words indexing") {
      FileIndexer temp;
      return temp.makeIndex(v);
   };

   std::ostringstream out;

   out << indexer;

   writer.outputToFile(indexer, "test6.txt");
   std::string s2 = parser.convertFileToString("test6.txt");
   REQUIRE(out.str() == s2);
} */

TEST_CASE("benchmark") {
   FileParser parser;

   std::string full = parser.convertFileToString("../texts/war_and_peace.txt");
   std::vector<std::string> v = parser.splitUpString(full);

   //splitting war_and_peace into 8 sections
   size_t chunk = v.size() / 8;

   for (int i = 1; i <= 8; i++) {
      size_t n;
      if (i == 8) {
         n = v.size();
      } else {
         n = chunk * i;
      }

      std::vector<std::string> subset(v.begin(), v.begin() + n);

      BENCHMARK("section " + std::to_string(i) + "/8 - " +  std::to_string(n) + " words") {
         FileIndexer indexer;
         return indexer.makeIndex(subset);
      };
   }
   
}
    