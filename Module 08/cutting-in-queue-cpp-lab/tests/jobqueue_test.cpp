#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/JobQueue.hpp"

TEST_CASE("are able to add jobs, run them, and then remove them") {
    JobQueue jobQueue;

    REQUIRE(jobQueue.is_empty());

    Job jobA("This is job a", 5);
    Job jobB("This is job b", 2);
    Job jobC("This is job c", 9);
    Job jobD("This is job d", 8);
    Job jobE("This is job e", 1);
    jobQueue.insert(jobA);
    jobQueue.insert(jobB);
    jobQueue.insert(jobC);
    jobQueue.insert(jobD);
    jobQueue.insert(jobE);

    REQUIRE(!jobQueue.is_empty());

    jobQueue.runHighestPriority(); 
    jobQueue.runHighestPriority(); 
    jobQueue.runHighestPriority(); 
    jobQueue.runHighestPriority(); 
    jobQueue.runHighestPriority(); 

    REQUIRE(jobQueue.is_empty());
}