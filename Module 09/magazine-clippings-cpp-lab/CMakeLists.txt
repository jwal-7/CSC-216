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

add_executable(factorial_test tests/factorial_test.cpp src/factorial.cpp)
add_executable(main main.cpp src/factorial.cpp)
add_executable(hash_test tests/hash_test.cpp src/old_hashmap.hpp)
add_executable(personal_hash_test tests/personal_hash_test.cpp src/hashmap.hpp)

target_link_libraries(factorial_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(hash_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(personal_hash_test PRIVATE Catch2::Catch2WithMain)
