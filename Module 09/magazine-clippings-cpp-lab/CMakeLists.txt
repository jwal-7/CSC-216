cmake_minimum_required(VERSION 3.24)

project(magazine_clippings)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(main main.cpp src/hashmap.hpp)
add_executable(hashmap_test tests/hashmap_test.cpp src/hashmap.hpp)
add_executable(comparison_func_test tests/comparison_func_test.cpp src/hashmap.hpp)

target_link_libraries(comparison_func_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(hashmap_test PRIVATE Catch2::Catch2WithMain)
