#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/comparison_map.hpp"

#include <fstream>
#include <sstream>
#include <string>

TEST_CASE("can_create_note() test with provided scenario") {
    ComparisonHashmap new_map = ComparisonHashmap();

    std::ifstream book1("../plays/romeo_and_juliet.txt");
    REQUIRE(book1.is_open());
    std::stringstream buffer1;
    buffer1 << book1.rdbuf();
    std::string book_to_construct = buffer1.str();
    
    std::ifstream book2("../plays/othello.txt");
    REQUIRE(book1.is_open());
    std::stringstream buffer2;
    buffer2 << book2.rdbuf();
    std::string resource_book = buffer2.str();
    
    REQUIRE(new_map.can_create_note("test123", "test123"));
    REQUIRE(new_map.can_create_note(book_to_construct, book_to_construct));
    REQUIRE(new_map.can_create_note(resource_book, resource_book));
    REQUIRE(new_map.can_create_note("round", "Look at the rotund dog"));
    REQUIRE_FALSE(new_map.can_create_note("abc", "def"));
    REQUIRE_FALSE(new_map.can_create_note(book_to_construct, resource_book));
}
