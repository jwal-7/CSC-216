#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/file_parser.hpp"
#include <vector>

TEST_CASE( "can convert a file into a string and then split it up" ) {
    FileParser parse;

    std::string s = parse.convertFileToString("../texts/test_file.txt");

    REQUIRE(s == "This is a test-file and string.\n"); // idk why vscode INSISTS on adding a newline everytime i open this file and it's so annoying

    std::vector<std::string> v = parse.splitUpString(s);

    REQUIRE(v[0] == "this");
    REQUIRE(v[1] == "is");
    REQUIRE(v[2] == "a");
    REQUIRE(v[3] == "test-file");
    REQUIRE(v[4] == "and");
    REQUIRE(v[5] == "string");
}
