cmake_minimum_required(VERSION 3.24)

project(cutting_in_queue)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(main main.cpp src/JobQueue.hpp)
add_executable(tree_test tests/tree_test.cpp src/ArrayBinaryTree.hpp)
add_executable(heap_test tests/heap_test.cpp src/Heap.hpp)
add_executable(jobqueue_test tests/jobqueue_test.cpp src/JobQueue.hpp)

target_link_libraries(tree_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(heap_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(jobqueue_test PRIVATE Catch2::Catch2WithMain)