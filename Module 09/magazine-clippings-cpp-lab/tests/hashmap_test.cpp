#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hashmap.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

TEST_CASE("basic test case") {
    Hashmap<char,int> map = Hashmap<char,int>();

    REQUIRE(map.get_count() == 0);
    REQUIRE(map.get_table_size() == 29);

    map.put('c', 15);
    REQUIRE(map.get('c') == 15);
    REQUIRE(map.get_count() == 1);

    map.put('e', 20);
    map.put('b', 250);
    map.put('m', 11111);

    REQUIRE(map.get_count() == 4);

    REQUIRE(map.erase('b'));
    REQUIRE(map.get_count() == 3);

    map['o'];
    REQUIRE(map.get_count() == 4);
    REQUIRE(map.get('o') == 0);

    map['o']++;

    REQUIRE(map.get('o') == 1);
    

}
