#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/ArrayBinaryTree.hpp"

TEST_CASE( "sample test case" ) {
    ArrayBinaryTree<int> tree = ArrayBinaryTree<int>();
    tree.add_to_end(2);
    tree.add_to_end(4);
    tree.add_to_end(7);
    tree.add_to_end(77);

    size_t left_child = tree.left(tree.root());
    size_t right_child = tree.right(tree.root());
    size_t second_left = tree.left(tree.left(tree.root()));
    
    REQUIRE(tree.root_value() == 2);
    REQUIRE(tree.end_value() == 77);
    REQUIRE(left_child == 1);
    REQUIRE(right_child == 2);
    REQUIRE(second_left == 3);
    REQUIRE(tree.end() == 3);
    REQUIRE(tree.value_at(3) == 77);

    tree.swap(3, tree.root());

    REQUIRE(tree.root_value() == 77);
    REQUIRE(tree.end_value() == 2);

    REQUIRE(tree.get_size() == 4);
    REQUIRE(!tree.is_empty());

    tree.remove();

    REQUIRE(tree.root_value() == 2);
    REQUIRE(tree.get_size() == 3);
    REQUIRE(!tree.is_empty());
    
}


