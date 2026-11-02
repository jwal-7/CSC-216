#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/file_writer.hpp"
#include "../src/file_indexer.hpp"
#include "../src/file_parser.hpp"
#include <vector>

TEST_CASE( "can convert a file into a string and then split it up" ) {
    FileWriter writer;
    FileIndexer indexer;
    FileParser parse;

    std::string s = parse.convertFileToString("../texts/test_file.txt");

    std::vector<std::string> v = parse.splitUpString(s);

    indexer.makeIndex(v);

    writer.outputToFile(indexer, "test_output.txt");

    std::string s2 = parse.convertFileToString("test_output.txt");

    REQUIRE(s2 == "{\n"
    "    \"string\": [5]\n"
    "    \"test-file\": [3]\n"
    "}\n"
    );
}
