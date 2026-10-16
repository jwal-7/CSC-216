#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/Heap.hpp"

TEST_CASE( "insertion / bubble_up" ) {
    Heap<int> h = Heap<int>();
    REQUIRE(h.empty());
    h.insert(1);
    h.push(15);
    h.push(20);
    h.insert(50);
    REQUIRE(h.size() == 4);
    REQUIRE(h.peek() == 50);
    REQUIRE(!h.empty());
}

TEST_CASE("insertion / bubble_up 2") {
    Heap<int> h = Heap<int>();
    REQUIRE(h.empty());
    h.insert(9);
    h.insert(10);
    h.insert(15);
    h.insert(20);
    h.insert(50);
    REQUIRE(h.peek() == 50);
    h.insert(60);
    REQUIRE(h.peek() == 60);
    REQUIRE(h.size() == 6);
    REQUIRE(!h.empty());
}

TEST_CASE("removal / pop / bubble_down") {
    Heap<int> h = Heap<int>();
    REQUIRE(h.empty());
    h.insert(10);
    h.insert(12);
    h.insert(15);
    REQUIRE(h.peek() == 15);
    h.insert(20);
    h.insert(50);
    REQUIRE(h.peek() == 50);
    REQUIRE(h.size() == 5);
    h.remove(0);
    REQUIRE(h.peek() == 20);
    REQUIRE(h.size() == 4);
    REQUIRE(!h.empty());
}

TEST_CASE("removal / pop / bubble_down 2") {
    Heap<int> h = Heap<int>();
    REQUIRE(h.empty());
    h.insert(10);
    h.insert(12);
    h.insert(15);
    REQUIRE(h.peek() == 15);
    h.insert(20);
    h.insert(50);
    REQUIRE(h.peek() == 50);
    REQUIRE(h.size() == 5);
    h.pop();
    REQUIRE(h.peek() == 20);
    REQUIRE(h.size() == 4);
    REQUIRE(!h.empty());
}

TEST_CASE("extract") {
    Heap<int> h = Heap<int>();
    REQUIRE(h.empty());
    h.insert(10);
    h.insert(12);
    h.insert(15);
    REQUIRE(h.peek() == 15);
    h.insert(20);
    h.insert(50);
    REQUIRE(h.peek() == 50);
    REQUIRE(h.size() == 5);
    int data = h.extract();
    REQUIRE(data == 50);
    REQUIRE(h.peek() == 20);
    REQUIRE(h.size() == 4);
    REQUIRE(!h.empty());
}