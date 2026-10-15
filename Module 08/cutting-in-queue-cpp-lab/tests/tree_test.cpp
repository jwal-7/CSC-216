#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/ArrayBinaryTree.hpp"

TEST_CASE( "sample tests" ) {
    ArrayBinaryTree<int> tree = ArrayBinaryTree<int>();
    tree.add_to_end(2);
    REQUIRE(tree.print_end() == 2);
}


