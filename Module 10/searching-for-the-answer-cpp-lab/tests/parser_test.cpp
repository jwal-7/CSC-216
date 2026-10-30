#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/file_parser.hpp"
#include <vector>

TEST_CASE( "can convert a file into a string and then split it up" ) {
    FileParser parse;

    std::string s = parse.convertFileToString("../texts/test_file.txt");

    REQUIRE(s == "This is a test file and string.");

    std::vector<std::string> v = parse.splitUpString(s);

    REQUIRE(v[0] == "This");
    REQUIRE(v[1] == "is");
    REQUIRE(v[2] == "a");
    REQUIRE(v[3] == "test");
    REQUIRE(v[4] == "file");
    REQUIRE(v[5] == "and");
    REQUIRE(v[6] == "string");
}