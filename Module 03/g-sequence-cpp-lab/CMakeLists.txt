cmake_minimum_required(VERSION 3.24)

project(the_hofstadter_g_sequence)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(naive_g_sequence_test tests/naive_g_sequence_test.cpp src/gSequenceCalculator.cpp)
add_executable(optimized_g_sequence_test tests/optimized_g_sequence_test.cpp src/gSequenceCalculator.cpp)
add_executable(main main.cpp src/gSequenceCalculator.cpp)

target_link_libraries(naive_g_sequence_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(optimized_g_sequence_test PRIVATE Catch2::Catch2WithMain)
