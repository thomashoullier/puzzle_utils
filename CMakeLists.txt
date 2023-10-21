cmake_minimum_required(VERSION 3.26)
project(puzzle_utils)

set(CMAKE_CXX_STANDARD 23)

# External libraries
include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.1.1
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(fmt)

# Examples
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")
set(EXAMPLES_DIR "${CMAKE_CURRENT_LIST_DIR}/examples")

add_executable(ex_iota "${EXAMPLES_DIR}/ex_iota.cpp")

add_executable(ex_range_printing "${EXAMPLES_DIR}/ex_range_printing.cpp")
target_link_libraries(ex_range_printing PRIVATE fmt::fmt-header-only)
