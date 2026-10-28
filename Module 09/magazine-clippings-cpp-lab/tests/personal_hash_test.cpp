#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hashmap.hpp"

#include <fstream>
#include <sstream>
#include <string>

TEST_CASE("basic test case") {
    Hashmap<char,int> map = Hashmap<char,int>();

    //REQUIRE(map.get_count() == 0);
    //REQUIRE(map.get_table_size() == 29);

    map.put('c', 15);
    REQUIRE(map.get('c') == 15);
    //REQUIRE(map.get_count() == 1);



}
