#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/PostFixCalc.hpp"

TEST_CASE( "converts prefix expression to postfix and evaluates" ) {
    PostFixCalc calc;

    REQUIRE( calc.evaluate("2+5") == 7.0 );
    REQUIRE( calc.evaluate("3+6*5") == 33.0 );
    REQUIRE( calc.evaluate("4*(2+3)") == 20.0 );
    REQUIRE( calc.evaluate("(7+9)/8") == 2.0 );
}


