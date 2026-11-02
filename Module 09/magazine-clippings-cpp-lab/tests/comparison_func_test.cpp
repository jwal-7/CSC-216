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
    REQUIRE(book2.is_open());
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

TEST_CASE("benchmark") {
    ComparisonHashmap new_map;

    std::ifstream book1("../plays/romeo_and_juliet.txt");
    REQUIRE(book1.is_open());
    std::stringstream buffer1;
    buffer1 << book1.rdbuf();
    std::string book_to_construct = buffer1.str();

    std::ifstream book2("../plays/othello.txt");
    REQUIRE(book2.is_open());                       
    std::stringstream buffer2;
    buffer2 << book2.rdbuf();
    std::string resource_book = buffer2.str();

    size_t max_size = std::min(book_to_construct.size(), resource_book.size());

    std::vector<size_t> sizes;
    for (size_t s = 100; s <= max_size; s *= 2) {
        sizes.push_back(s);

        for (size_t i = 0; i < sizes.size(); i++) {
            for (size_t j = i; j < sizes.size(); j++) {
                std::string note     = book_to_construct.substr(0, sizes[i]);
                std::string articles = note + resource_book.substr(0, sizes[j] - sizes[i]);

                BENCHMARK("note " + std::to_string(note.size()) + 
                    " / articles " + std::to_string(articles.size())) {
                    return new_map.can_create_note(note, articles);
                };
            }
        }
        
    }
}
