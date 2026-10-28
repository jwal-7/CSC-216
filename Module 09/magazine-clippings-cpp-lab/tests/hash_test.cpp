#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/old_hashmap.hpp"

#include <fstream>
#include <sstream>
#include <string>

TEST_CASE("can_create_note() test with provided scenario") {
    ComparisonHashmap new_map = ComparisonHashmap();
    /*
    std::ifstream book1;
    std::string filename = "plays/romeo_and_juliet.txt";
    std::string book_to_construct;
    book1.open(filename);
    while (!book1) {
        std::string line;
        while (getline(book1, line)) {
            book_to_construct += line;
        }
    }
    book1.close();

    std::ifstream book2;
    std::string filename2 = "plays/othello.txt";
    std::string resource_book;
    book2.open(filename2);
    while (!book2) {
        std::string line;
        while (getline(book2, line)) {
            resource_book += line;
        }
    }
    book2.close();
    */


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
    
    REQUIRE(new_map.can_create_note("sigma", "sigma"));
    REQUIRE(new_map.can_create_note(book_to_construct, book_to_construct));
    REQUIRE(new_map.can_create_note("sigma", "i love among us"));
    REQUIRE(new_map.can_create_note("sigma", "sussy"));
    REQUIRE(new_map.can_create_note(book_to_construct, resource_book));
}
