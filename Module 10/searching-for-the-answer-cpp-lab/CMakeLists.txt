cmake_minimum_required(VERSION 3.24)

project(ive-got-the-power)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(main main.cpp src/factorial.cpp)
add_executable(parser_test tests/parser_test.cpp src/file_parser.hpp)
add_executable(index_map_test tests/index_map_test.cpp src/file_index_map.hpp)
add_executable(indexer_test tests/indexer_test.cpp src/file_indexer.hpp)
add_executable(vector_wrapper_test tests/vector_wrapper_test.cpp src/vector_wrapper.hpp)

target_link_libraries(parser_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(index_map_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(indexer_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(vector_wrapper_test PRIVATE Catch2::Catch2WithMain)
