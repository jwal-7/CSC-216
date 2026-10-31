#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/vector_wrapper.hpp"
#include <vector>
#include <sstream>

TEST_CASE( "populated vector wrapper output test" ) {
   IndexList<size_t> list;

   list.v = {3, 5, 8, 11, 90};

   std::ostringstream out;

   out << list;

   REQUIRE(out.str() == "[3, 5, 8, 11, 90]");
}

TEST_CASE( "empty vector wrapper output test" ) {
   IndexList<size_t> list;

   list.v = {};

   std::ostringstream out;

   out << list;

   REQUIRE(out.str() == "[]");
}
