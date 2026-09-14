#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <vector>

#include "../src/gSequenceCalculator.hpp"

std::vector<int> history;

TEST_CASE( "it computes the nth term in the Hofstadter G Sequence" ) {
    REQUIRE( optimizedGSequence(0, history) == 0 );
    REQUIRE( optimizedGSequence(1, history) == 1 );
    REQUIRE( optimizedGSequence(2, history) == 1 );
    REQUIRE( optimizedGSequence(3, history) == 2 );
    REQUIRE( optimizedGSequence(4, history) == 3 );
    REQUIRE( optimizedGSequence(5, history) == 3 );
    REQUIRE( optimizedGSequence(6, history) == 4 );
    REQUIRE( optimizedGSequence(7, history) == 4 );
    REQUIRE( optimizedGSequence(8, history) == 5 );
    REQUIRE( optimizedGSequence(9, history) == 6 );
    REQUIRE( optimizedGSequence(10, history) == 6 );
    REQUIRE( optimizedGSequence(11, history) == 7 );
}
   
TEST_CASE("benchmarking the optimized g sequence function") {
    BENCHMARK("optimizedGSequence(0)") {
        return optimizedGSequence(0, history);
    };
    
    BENCHMARK("optimizedGSequence(1)") {
        return optimizedGSequence(1, history);
    };

    BENCHMARK("optimizedGSequence(5)") {
        return optimizedGSequence(5, history);
    };

    BENCHMARK("optimizedGSequence(10)") {
        return optimizedGSequence(10, history);
    };

    BENCHMARK("optimizedGSequence(15)") {
        return optimizedGSequence(15, history);
    };

    BENCHMARK("optimizedGSequence(20)") {
        return optimizedGSequence(20, history);
    };

    BENCHMARK("optimizedGSequence(25)") {
        return optimizedGSequence(25, history);
    };

    BENCHMARK("optimizedGSequence(30)") {
        return optimizedGSequence(30, history);
    };

    BENCHMARK("optimizedGSequence(35)") {
        return optimizedGSequence(35, history);
    };

    BENCHMARK("optimizedGSequence(40)") {
        return optimizedGSequence(40, history);
    };

    BENCHMARK("optimizedGSequence(45)") {
        return optimizedGSequence(45, history);
    };

    BENCHMARK("optimizedGSequence(50)") {
        return optimizedGSequence(50, history);
    };

    BENCHMARK("optimizedGSequence(55)") {
        return optimizedGSequence(55, history);
    };

    BENCHMARK("optimizedGSequence(60)") {
        return optimizedGSequence(60, history);
    };

    BENCHMARK("optimizedGSequence(65)") {
        return optimizedGSequence(65, history);
    };

    BENCHMARK("optimizedGSequence(70)") {
        return optimizedGSequence(70, history);
    };
     
    BENCHMARK("optimizedGSequence(75)") {
        return optimizedGSequence(75, history);
    };

    BENCHMARK("optimizedGSequence(80)") {
        return optimizedGSequence(80, history);
    };

    BENCHMARK("optimizedGSequence(85)") {
        return optimizedGSequence(85, history);
    };

    BENCHMARK("optimizedGSequence(90)") {
        return optimizedGSequence(90, history);
    };

    BENCHMARK("optimizedGSequence(95)") {
        return optimizedGSequence(95, history);
    };

    BENCHMARK("optimizedGSequence(100)") {
        return optimizedGSequence(100, history);
    };

    
}

