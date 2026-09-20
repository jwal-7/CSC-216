cmake_minimum_required(VERSION 3.24)

project(counting_cards)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(array_sorts_test tests/array_sorts_test.cpp src/array_sorts.cpp)
add_executable(main main.cpp src/array_sorts.cpp)

target_link_libraries(array_sorts_test PRIVATE Catch2::Catch2WithMain)
