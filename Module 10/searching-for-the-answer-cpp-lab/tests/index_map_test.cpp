#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/file_index_map.hpp"
#include <vector>
#include <sstream>

TEST_CASE( "can convert a file into a string and then split it up" ) {
    FileIndexMap map; 

    map.insert("test", 0);
    REQUIRE(map.size() == 1);
    map.insert("test", 4);
    map.insert("test", 123);

    std::ostringstream out;

    out << map;

    REQUIRE(out.str() == "{\n"
    "    \"test\": [0, 4, 123]\n"
    "}\n"
    );
    
}
