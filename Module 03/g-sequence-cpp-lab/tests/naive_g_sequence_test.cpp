#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/gSequenceCalculator.hpp"

TEST_CASE( "it computes the nth term in the Hofstadter G Sequence" ) {
    REQUIRE( naiveGSequence(0) == 0 );
    REQUIRE( naiveGSequence(1) == 1 );
    REQUIRE( naiveGSequence(2) == 1 );
    REQUIRE( naiveGSequence(3) == 2 );
    REQUIRE( naiveGSequence(4) == 3 );
    REQUIRE( naiveGSequence(5) == 3 );
    REQUIRE( naiveGSequence(6) == 4 );
    REQUIRE( naiveGSequence(7) == 4 );
    REQUIRE( naiveGSequence(8) == 5 );
    REQUIRE( naiveGSequence(9) == 6 );
    REQUIRE( naiveGSequence(10) == 6 );
    REQUIRE( naiveGSequence(11) == 7 );
}

TEST_CASE("benchmarking the naive g sequence function") {
    BENCHMARK("naiveGSequence(0)") {
        return naiveGSequence(0);
    };
    
    BENCHMARK("naiveGSequence(1)") {
        return naiveGSequence(1);
    };

    BENCHMARK("naiveGSequence(5)") {
        return naiveGSequence(5);
    };

    BENCHMARK("naiveGSequence(10)") {
        return naiveGSequence(10);
    };

    BENCHMARK("naiveGSequence(15)") {
        return naiveGSequence(15);
    };

    BENCHMARK("naiveGSequence(20)") {
        return naiveGSequence(20);
    };

    BENCHMARK("naiveGSequence(25)") {
        return naiveGSequence(25);
    };

    BENCHMARK("naiveGSequence(30)") {
        return naiveGSequence(30);
    };

    BENCHMARK("naiveGSequence(35)") {
        return naiveGSequence(35);
    };

    BENCHMARK("naiveGSequence(40)") {
        return naiveGSequence(40);
    };

    BENCHMARK("naiveGSequence(45)") {
        return naiveGSequence(45);
    };

    BENCHMARK("naiveGSequence(50)") {
        return naiveGSequence(50);
    };

    BENCHMARK("naiveGSequence(55)") {
        return naiveGSequence(55);
    };

    BENCHMARK("naiveGSequence(60)") {
        return naiveGSequence(60);
    };

    BENCHMARK("naiveGSequence(65)") {
        return naiveGSequence(65);
    };

    BENCHMARK("naiveGSequence(70)") {
        return naiveGSequence(70);
    };
     
    BENCHMARK("naiveGSequence(75)") {
        return naiveGSequence(75);
    };

    BENCHMARK("naiveGSequence(80)") {
        return naiveGSequence(80);
    };

    BENCHMARK("naiveGSequence(85)") {
        return naiveGSequence(85);
    };

    BENCHMARK("naiveGSequence(90)") {
        return naiveGSequence(90);
    };

    BENCHMARK("naiveGSequence(95)") {
        return naiveGSequence(95);
    };

    BENCHMARK("naiveGSequence(100)") {
        return naiveGSequence(100);
    };
}

