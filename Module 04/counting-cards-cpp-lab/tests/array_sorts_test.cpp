#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/array_sorts.hpp"
#include <vector>

TEST_CASE("benchmarking the naiveShuffle, partlyOptmizedShuffle, and optimizeShuffle functions") {
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    std::vector<int> v4;
    std::vector<int> v5;

    for (int i = 0; i < 100; i++) {
        v1.push_back(i);
    }

    for (int i = 0; i < 250; i++) {
        v2.push_back(i);
    }

    for (int i = 0; i < 500; i++) {
        v3.push_back(i);
    }

    for (int i = 0; i < 750; i++) {
        v4.push_back(i);
    }

    for (int i = 0; i < 100000; i++) {
        v5.push_back(i);
    }

    SECTION("naiveShuffle"){
        BENCHMARK("naiveShuffle(v1)") {
            return naiveShuffle(v1);
        };

        BENCHMARK("naiveShuffle(v2)") {
            return naiveShuffle(v2);
        };

        BENCHMARK("naiveShuffle(v3)") {
            return naiveShuffle(v3);
        };

        BENCHMARK("naiveShuffle(v4)") {
            return naiveShuffle(v4);
        };

        BENCHMARK("naiveShuffle(v5)") {
            return naiveShuffle(v5);
        };
    }

    SECTION("partlyOptimizedShuffle") {
        BENCHMARK("partlyOptimizedShuffle(v1)") {
            return partlyOptimizedShuffle(v1);
        };

        BENCHMARK("partlyOptimizedShuffle(v2)") {
            return partlyOptimizedShuffle(v2);
        };

        BENCHMARK("partlyOptimizedShuffle(v3)") {
            return partlyOptimizedShuffle(v3);
        };

        BENCHMARK("partlyOptimizedShuffle(v4)") {
            return partlyOptimizedShuffle(v4);
        };

        BENCHMARK("partlyOptimizedShuffle(v5)") {
            return partlyOptimizedShuffle(v5);
        };
    }

    SECTION("optimizedShuffle") {
        BENCHMARK("optimizedShuffle(v1)") {
            return optimizedShuffle(v1);
        };

        BENCHMARK("optimizedShuffle(v2)") {
            return optimizedShuffle(v2);
        };

        BENCHMARK("optimizedShuffle(v3)") {
            return optimizedShuffle(v3);
        };

        BENCHMARK("optimizedShuffle(v4)") {
            return optimizedShuffle(v4);
        };

        BENCHMARK("optimizedShuffle(v5)") {
            return optimizedShuffle(v5);
        };
    }
}


