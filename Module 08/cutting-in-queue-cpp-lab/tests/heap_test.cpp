#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/Heap.hpp"

TEST_CASE( "bubble_up" ) {
    Heap<int> h = Heap<int>();
    h.insert(50);
    h.insert(20);
    h.insert(15);
    h.insert(1);
    REQUIRE(h.peek() == 50);
    h.bubble_up(3);
    REQUIRE(h.peek() == 1);
}

// TEST_CASE("")
